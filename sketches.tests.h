#ifndef MUSICGRID_SKETCHES_TESTS_H
#define MUSICGRID_SKETCHES_TESTS_H

#include <cxxtest/TestSuite.h>

#include "misc/Estd/filesystem.hpp"

#include "sketches.h"

using namespace Estd;
using namespace MusicGrid;
using CxxTest::TestSuite;

class MusicGridTestSuite : public TestSuite {
  public:
    void testTrackList(void) {
        TrackList testList;
        TS_ASSERT_THROWS_NOTHING(testList.populate("testtree", ""));

        TS_ASSERT_DIFFERS(testList.size(),0);

        TS_TRACE(testList.size());

        TS_TRACE(testList.debugPrint());
        TS_TRACE(testList.debugPrint().size());
        testList.sort();
        TS_TRACE(testList.debugPrint());
        TS_TRACE(testList.debugPrint().size());
    }
};

// Tests for used library components; mostly debug remnants.
class LibTestSuite : public TestSuite {
  public:
    void testWalk (void) {
        std::vector<boost::filesystem::path> walked = walk("testtree");

        TS_ASSERT(!walked.empty());
    }

    void testTagLib (void) {
        Track tester1{TagLib::FileName{"testtree/Walton-Bulldoze.mp3"}};

        TS_ASSERT_THROWS_NOTHING(tester1.fileRef());
        TS_TRACE("called fileRef");
        auto fR = tester1.fileRef();
        auto ta = fR.tag();
        TS_TRACE("called tag");
        auto ti = ta->title();
        TS_TRACE("called title");
    }
};

#endif //MUSICGRID_SKETCHES_TESTS_H
