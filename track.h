#ifndef MUSICGRID_TRACK_H
#define MUSICGRID_TRACK_H

#include <boost/filesystem.hpp>

#include <taglib/fileref.h>
#include <taglib/tstring.h>
#include <taglib/tpropertymap.h>

//Represents a single music track
namespace MusicGrid {
  class Track {
    public:
      explicit Track(TagLib::FileName fileName) : fileRef_{fileName} {};
      explicit Track(boost::filesystem::path filePath) :
          fileRef_(filePath.string().c_str()) {}

      void save();
      TagLib::String title() const;
      void setTitle(TagLib::String title) { fileRef_.tag()->setTitle(title); }
      TagLib::PropertyMap properties() const { return fileRef_.tag()->properties(); }

      TagLib::FileRef fileRef() const { return fileRef_; } //DEBUG
  
    private:
      TagLib::FileRef fileRef_;
  };

  bool eqTitle(const Track&, const Track&);

  class Comparator {
    public:
      explicit Comparator(TagLib::String (*cmp)(const Track&)) : cmp_{cmp} {}

      bool operator()(const Track& lhs, const Track& rhs) const {
          return cmp_(lhs) < cmp_(rhs);
      }

    private:
      TagLib::String (*cmp_)(const Track&);
  };

  bool sorter(const Track&, const Track&);

  class Filter {
    public:
      //virtual explicit Filter(const Tag&) =0;
      virtual bool operator()(const Track&) const =0;
      virtual ~Filter() =default;
    protected:
      Filter() =default;
  };

  class Any : public Filter {
    public:
      explicit Any(const TagLib::PropertyMap& tags) : tags_{tags} {}

      bool operator()(const Track&) const override;
    private:
      TagLib::PropertyMap tags_;
  };

  class All : public Filter {
    public:
      explicit All(const TagLib::PropertyMap& tags) : tags_{tags} {}

      bool operator()(const Track&) const override;
    private:
      TagLib::PropertyMap tags_;
  };
}

#endif //MUSICGRID_TRACK_H
