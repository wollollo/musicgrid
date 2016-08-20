#include "filesystem.hpp"
#include <stdexcept>

using namespace boost::filesystem;
using namespace std;

namespace Estd {
  vector<path> walk(const path& baseDir) { //TODO: predicate
      try {
          vector<path> paths;
          if (exists (baseDir)) {
              if (is_regular_file(baseDir)) {
                  paths.push_back(baseDir);
                  return paths;
              } else if (is_directory(baseDir)) {
                  for(directory_entry& x : recursive_directory_iterator(baseDir)) {
                      paths.push_back(x.path());
                  }
              } else {
                  throw runtime_error{"path is neither file nor directory"}; //TODO really want filesystem_error, see docs for ctor
              }
          }

          return paths; //TODO check this uses move not copy
      } catch (...) { //TODO: sensible stuff
          throw;
      }
  }
}
