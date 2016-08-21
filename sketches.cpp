#include "misc/Estd/algorithm.h"
#include "misc/Estd/filesystem.hpp"

#include "sketches.h"

using namespace std;
using namespace Estd;

using boost::filesystem::path;
using boost::filesystem::exists;
using boost::filesystem::is_directory;

namespace MusicGrid {
  void TrackList::add(Track track) { trackList_.push_back(track); }

  void TrackList::remove(Track track) {
      ListType::iterator match;
      //match = find_if(trackList_.begin(),trackList_.begin(),
              //[track](Track element){ return eqTitle(track,element);});
      match = find_if(trackList_, [track](Track element) { return eqTitle(track,element); });
      while ( match != trackList_.end() ) {
          trackList_.erase(match);
          //match = find_if(trackList_.begin(),trackList_.begin(),
                  //[track](Track element){ return eqTitle(track,element);});
          match = find_if(trackList_, [track](Track element) { return eqTitle(track,element); });
      }
  }

  void TrackList::populate(string baseDir, string filePattern) {
      if (!exists(baseDir)) {
          throw runtime_error{"non-existent baseDir"};
      }
      if (!is_directory(baseDir)) {
          throw runtime_error{"non-directory baseDir"};
      }

      //walk is in misc/Estd/filesystem.cpp
      for (const path& p : walk(path{baseDir})) {
          if (is_regular_file(p))
              trackList_.emplace_back(p); //TODO refactor to send this into walk?
      }
  }

  void TrackList::sort() { Estd::sort(trackList_, sorter); } //TODO expand this greatly.

  wstring TrackList::debugPrint() const {
      wstring result;
      for (const Track& track : trackList_) {
          result += track.title().toWString();
          result += '\n';
      }
      //assert("made it here"); //DEBUG ??
      return result;
  }

  TrackReferenceList::TrackReferenceList(TrackList& tracks) {
      refList_ = ListType{tracks.size()};
      copy_iterators(tracks, refList_);
  }

  TrackReferenceList::TrackReferenceList(TrackList& tracks, Any& filter) { //TODO should be Filter
      refList_ = ListType{count_if(tracks, filter)}; //TODO adds O(n) to cxity!
      copy_iterators(tracks, refList_, filter);
  }
}
