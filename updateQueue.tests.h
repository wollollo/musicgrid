#ifndef MUSICGRID_UPDATEQUEUE_TESTS_H
#define MUSICGRID_UPDATEQUEUE_TESTS_H

#include <cxxtest/TestSuite.h>

#include "updateQueue.h"

using namespace MusicGrid;
using CxxTest::TestSuite;

class UpdateQueueTestSuite : public TestSuite {
  public:
    void testUpdateQueue(void) {
        TS_ASSERT(true);
    }
};

#endif //MUSICGRID_UPDATEQUEUE_TESTS_H
