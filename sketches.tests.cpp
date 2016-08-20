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

bool suite_MusicGridTestSuite_init = false;
#include "sketches.tests.h"

static MusicGridTestSuite suite_MusicGridTestSuite;

static CxxTest::List Tests_MusicGridTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MusicGridTestSuite( "sketches.tests.h", 14, "MusicGridTestSuite", suite_MusicGridTestSuite, Tests_MusicGridTestSuite );

static class TestDescription_suite_MusicGridTestSuite_testTrackList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MusicGridTestSuite_testTrackList() : CxxTest::RealTestDescription( Tests_MusicGridTestSuite, suiteDescription_MusicGridTestSuite, 16, "testTrackList" ) {}
 void runTest() { suite_MusicGridTestSuite.testTrackList(); }
} testDescription_suite_MusicGridTestSuite_testTrackList;

static LibTestSuite suite_LibTestSuite;

static CxxTest::List Tests_LibTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LibTestSuite( "sketches.tests.h", 33, "LibTestSuite", suite_LibTestSuite, Tests_LibTestSuite );

static class TestDescription_suite_LibTestSuite_testWalk : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LibTestSuite_testWalk() : CxxTest::RealTestDescription( Tests_LibTestSuite, suiteDescription_LibTestSuite, 35, "testWalk" ) {}
 void runTest() { suite_LibTestSuite.testWalk(); }
} testDescription_suite_LibTestSuite_testWalk;

static class TestDescription_suite_LibTestSuite_testTagLib : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LibTestSuite_testTagLib() : CxxTest::RealTestDescription( Tests_LibTestSuite, suiteDescription_LibTestSuite, 41, "testTagLib" ) {}
 void runTest() { suite_LibTestSuite.testTagLib(); }
} testDescription_suite_LibTestSuite_testTagLib;

