#ifndef ESTD_FILESYSTEM_H
#define ESTD_FILESYSTEM_H

#include <boost/filesystem.hpp>
#include <vector>

namespace Estd {
  // walk baseDir recursively, returning path of all files; if baseDir is a file, not a dir, return it only.
  std::vector<boost::filesystem::path> walk(const boost::filesystem::path& baseDir); //TODO: predicate
}

#endif //ESTD_FILESYSTEM_H
