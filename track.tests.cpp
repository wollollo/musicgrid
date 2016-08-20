/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

bool suite_TrackTestSuite_init = false;
#include "track.tests.h"

static TrackTestSuite suite_TrackTestSuite;

static CxxTest::List Tests_TrackTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TrackTestSuite( "track.tests.h", 11, "TrackTestSuite", suite_TrackTestSuite, Tests_TrackTestSuite );

static class TestDescription_suite_TrackTestSuite_testTrack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TrackTestSuite_testTrack() : CxxTest::RealTestDescription( Tests_TrackTestSuite, suiteDescription_TrackTestSuite, 13, "testTrack" ) {}
 void runTest() { suite_TrackTestSuite.testTrack(); }
} testDescription_suite_TrackTestSuite_testTrack;

static class TestDescription_suite_TrackTestSuite_testPredicates : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TrackTestSuite_testPredicates() : CxxTest::RealTestDescription( Tests_TrackTestSuite, suiteDescription_TrackTestSuite, 23, "testPredicates" ) {}
 void runTest() { suite_TrackTestSuite.testPredicates(); }
} testDescription_suite_TrackTestSuite_testPredicates;

static class TestDescription_suite_TrackTestSuite_testComparators : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TrackTestSuite_testComparators() : CxxTest::RealTestDescription( Tests_TrackTestSuite, suiteDescription_TrackTestSuite, 32, "testComparators" ) {}
 void runTest() { suite_TrackTestSuite.testComparators(); }
} testDescription_suite_TrackTestSuite_testComparators;

