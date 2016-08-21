#include <iostream>

#include <boost/filesystem.hpp>

#include "Estd/filesystem.hpp"

using namespace std;
using namespace Estd;
using boost::filesystem::path;
using boost::filesystem::directory_entry;
using boost::filesystem::recursive_directory_iterator;

int main() {
    path baseDir{"/home/martin/projects/musicgrid2/testtree"};
    vector<path> paths;

    paths = walk(baseDir);
    cout << "size of paths: " << paths.size() << endl;

    paths = walk(path{"testtree"});
    cout << "size of paths: " << paths.size() << endl;

    paths = {};

    if (exists (baseDir)) {
        cout << "baseDir exists!" << endl;
        if (is_regular_file(baseDir)) {
            paths.push_back(baseDir);
        } else if (is_directory(baseDir)) {
            for(directory_entry& x : recursive_directory_iterator(baseDir)) {
                paths.push_back(x.path());
            }
        }
    }

    std::cout << "size of paths: " << paths.size() << std::endl;

    for (auto& x : paths) {
        std::cout << x << std::endl;
    }

    return 0;
}
