#include "updateQueue.h"

using namespace std;

namespace MusicGrid {
  void UpdateQueue::push(const TrackType& track)
  {
      unique_lock<mutex> lck{mutex_};
      queue_.push(track);
      cv_.notify_one();
  }
  // TODO supply unsafe_push if potential blocking is an issue.

  UpdateQueue::TrackType UpdateQueue::top() const
  {
      unique_lock<mutex> lck{mutex_};
      if (queue_.empty())
          throw std::out_of_range{"Attempted to read from update queue: empty."};
      return queue_.front();
  }

  void UpdateQueue::write()
  {
      while (!stop_ && !hard_stop_) {
          while (!queue_.empty()) { //No locking: pop and top do it; writes between top and pop happen at opposite end of queue so will not interfere.
              if (hard_stop_) return;
              auto track{top()};
              track.save();
              pop();
          }
          unique_lock<mutex> lck{mutex_};
          cv_.wait(lck,[this]{ return stop_ || hard_stop_ || !queue_.empty(); });
      }
      return;
  }
}
