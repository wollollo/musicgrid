#ifndef MUSICGRID_TRACK_TESTS_H
#define MUSICGRID_TRACK_TESTS_H

#include <cxxtest/TestSuite.h>

#include "track.h"

using namespace MusicGrid;
using CxxTest::TestSuite;

class TrackTestSuite : public TestSuite {
  public:
    void testTrack ( void ) {
        Track tester1{TagLib::FileName{"testtree/Walton-Bulldoze.mp3"}};
        Track tester2{boost::filesystem::path{"testtree/Walton-Bulldoze.mp3"}};
        TagLib::String title("Bulldoze");

        TS_ASSERT_EQUALS(tester1.title(), title);
        TS_ASSERT_EQUALS(tester2.title(), title);
        TS_ASSERT_THROWS_NOTHING(tester1.save());
    }
    
    void testPredicates(void) {
        Track tester1{TagLib::FileName{"testtree/Walton-Bulldoze.mp3"}};
        Track tester2{boost::filesystem::path{"Walton-Bulldoze.mp3"}};
        Track tester3{TagLib::FileName{"testtree/Wiley - Eskimo.mp3"}};

        TS_ASSERT(eqTitle(tester1,tester2));
        TS_ASSERT(!eqTitle(tester1,tester3));
        //TODO add tests for Filter, Any, All
    }

    void testComparators(void) {
        Track tester1{TagLib::FileName{"testtree/Walton-Bulldoze.mp3"}};
        Track tester2{boost::filesystem::path{"Walton-Bulldoze.mp3"}};
        Track tester3{TagLib::FileName{"testtree/Wiley - Eskimo.mp3"}};
        
        TS_ASSERT(true);
        TS_ASSERT(tester1.title() < tester3.title());

        Comparator titles{[](const Track& arg){ return arg.title(); }};
        TS_ASSERT(titles(tester1,tester3));
    }
};

#endif //MUSICGRID_TRACK_TESTS_H
