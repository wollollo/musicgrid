#include <iostream>
#include <stdexcept>

#include "track.h"

namespace MusicGrid {
  TagLib::String Track::title() const {
      if (fileRef_.tag()) {
          return fileRef_.tag()->title();
      } else {
          return TagLib::String{"<no tag>"};
      }
  }

  void Track::save() {
      if(!fileRef_.save())
          throw std::runtime_error{"failed to write track " + title().to8Bit()}; //TODO more appropriate exception
  }

  bool sorter(const Track& lhs, const Track& rhs) { //TODO (See Comparator) expand! might need to be a fn obj
      if (lhs.title() < rhs.title()) {
          return true;
      }
      return false;
  }

  bool Any::operator()(const Track& track) const {
      for (auto& tag : tags_) {
          //std::cout << tag.first << ":\t"
              //<< track.properties().contains(tag.first) << " | "
              //<< track.properties()[tag.first] << " | "
              //<< tag.second << std::endl;
          if ( (track.properties().contains(tag.first)) &&
                track.properties()[tag.first] == tag.second)
              return true;
      }
      return false;
  }

  bool All::operator()(const Track& track) const {
      for (auto& tag : tags_) {
          if ( (!track.properties().contains(tag.first)) ||
                 track.properties()[tag.first] != tag.second)
              return false;
      }
      return true;
  }

  bool eqTitle(const Track& lhs, const Track& rhs) {
      return lhs.title() == rhs.title();
  }
}
