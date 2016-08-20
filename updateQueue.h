#ifndef MUSICGRID_UPDATEQUEUE_H
#define MUSICGRID_UPDATEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

#include "track.h"

namespace MusicGrid {
  class UpdateQueue {
    public:
      using TrackType = Track;
      using QueueType = std::queue< TrackType >; // TODO not queue but map.

      void push(const TrackType&);

      bool empty() const { std::unique_lock<std::mutex> lck{mutex_}; return queue_.empty(); };

      void write();
      void operator()() { write(); }
      void stop() { std::unique_lock<std::mutex> lck{mutex_}; stop_ = true; cv_.notify_one(); }

    private:
      TrackType top() const; // top/pop pair: top gives last element,
      void pop() { std::unique_lock<std::mutex> lck{mutex_}; queue_.pop(); } // pop removes it

      QueueType queue_;
    
      // Concurrency control.
      bool stop_ = false; // set this to signal write() to return when queue is empty
      bool hard_stop_ = false; // set this to signal write() to abort
      mutable std::condition_variable cv_; //notify this to get write to restart after it has emptied queue_
      mutable std::mutex mutex_; //lock this before any access of queue_
  };
}

#endif //MUSICGRID_UPDATEQUEUE_H
