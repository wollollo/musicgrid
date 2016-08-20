#ifndef MUSICGRID_SKETCHES_H
#define MUSICGRID_SKETCHES_H

#include <vector>
#include <string>

#include "track.h"

namespace MusicGrid {
  class TrackList {
    public:
      using ListType = std::vector<Track>;
      using iterator = ListType::iterator;
      using const_iterator = ListType::const_iterator;
      using size_type = ListType::size_type;

      iterator begin() { return trackList_.begin(); } // DEBUG only
      iterator end() { return trackList_.end(); } // DEBUG only
      const_iterator cbegin() { return trackList_.cbegin(); }
      const_iterator cend() { return trackList_.cend(); }

      Track operator[](size_type i) const { return trackList_[i]; } //DEBUG only? should be reference?

      void sort(); //TODO expand this greatly.

      void add(Track); // TODO Track or Track&?
      void remove(Track); // if filename is known, remove. // TODO Track or Track&?
      void update(Track); // if filename is known, update; o/w add. // TODO Track or Track&?

      void populate(std::string path, std::string filePattern);
          // search path (recursively) for files matching filePattern, add.
      
      std::wstring debugPrint() const;
      ListType::size_type size() const { return trackList_.size(); }

    private:
      ListType trackList_;
  };

  class TrackReferenceList {
    public:
      using value_type = TrackList::iterator;
      using ListType = std::vector<value_type>;
      using iterator = ListType::iterator;
      using const_iterator = ListType::const_iterator;

      explicit TrackReferenceList(TrackList&);
      explicit TrackReferenceList(TrackList& tracks, Any& filter); //TODO should be filter

      void push_back(value_type v) { refList_.push_back(v); }

    private:
      ListType refList_;
  };

//  template<class IterA, class IterB, class Pred> // these are just std::copy_if
 // void add_if(IterA src_beg, IterA src_end, IterB target, Pred);

  //template<class ContA, class ContB, class Pred>
  //void add_if(ContA src, ContB target, Pred);

  //template<class ContA, class ContB>
  //void add(ContA src, ContB target) {
      //add_if(src,target,[](ContB::iterator iter){ return true; });
  //}
}

#endif // MUSICGRID_SKETCHES_H
