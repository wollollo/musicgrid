/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

bool suite_UpdateQueueTestSuite_init = false;
#include "updateQueue.tests.h"

static UpdateQueueTestSuite suite_UpdateQueueTestSuite;

static CxxTest::List Tests_UpdateQueueTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_UpdateQueueTestSuite( "updateQueue.tests.h", 11, "UpdateQueueTestSuite", suite_UpdateQueueTestSuite, Tests_UpdateQueueTestSuite );

static class TestDescription_suite_UpdateQueueTestSuite_testUpdateQueue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UpdateQueueTestSuite_testUpdateQueue() : CxxTest::RealTestDescription( Tests_UpdateQueueTestSuite, suiteDescription_UpdateQueueTestSuite, 13, "testUpdateQueue" ) {}
 void runTest() { suite_UpdateQueueTestSuite.testUpdateQueue(); }
} testDescription_suite_UpdateQueueTestSuite_testUpdateQueue;

