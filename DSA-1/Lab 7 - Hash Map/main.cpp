#include "CourseGradebook.h"
#include "Gradebook.h"
#include "TestUtility.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool TestGetScoreAndSetScore();
bool TestGetAssignmentScores();
bool TestGetSortedAssignmentNames();
bool TestGetSortedStudentIDs();
bool TestGetStudentScores();

int main(int argc, char *argv[]) {
  bool result1 = TestGetScoreAndSetScore();
  bool result2 = TestGetAssignmentScores();
  bool result3 = TestGetSortedAssignmentNames();
  bool result4 = TestGetSortedStudentIDs();
  bool result5 = TestGetStudentScores();

  cout << endl << "Summary:" << endl;
  cout << "TestGetScoreAndSetScore(): " << (result1 ? "PASS" : "FAIL") << endl;
  cout << "TestGetAssignmentScores(): " << (result2 ? "PASS" : "FAIL") << endl;
  cout << "TestGetSortedAssignmentNames(): " << (result3 ? "PASS" : "FAIL")
       << endl;
  cout << "TestGetSortedStudentIDs(): " << (result4 ? "PASS" : "FAIL") << endl;
  cout << "TestGetStudentScores(): " << (result5 ? "PASS" : "FAIL") << endl;
  cout << endl;

  return 0;
}

bool TestGetScoreAndSetScore() {
  cout << endl << "---- TestGetScoreAndSetScore() ----" << endl;

  // Create a gradebook with sample data for testing
  CourseGradebook gradebook = TestUtility::MakeSampleGradebook();

  // Each test case is a (assignmentName, studentID, expectedScore) tuple
  std::tuple<std::string, int, double> testCases[] = {
      std::make_tuple("Midterm", 11111, 91.0),
      std::make_tuple("Homework 1", 22222, NAN), // no entry
      std::make_tuple("Homework 3", 55555, 71.5),
      std::make_tuple("Course project", 66666, 0.0),
      std::make_tuple("Homework 2", 10000, 90.0),
      std::make_tuple("Homework 4", 55555, 77.5),
      std::make_tuple("Homework 5", 33333, NAN), // no such assignment
      std::make_tuple("Final exam", 44444, NAN), // no entry
      std::make_tuple("Homework 2", 77777, 76.0),
      std::make_tuple("Homework 1", 88888, 64.5)};

  // Iterate through test cases
  for (auto testCase : testCases) {
    string assignmentName = std::get<0>(testCase);
    int studentID = std::get<1>(testCase);
    double expected = std::get<2>(testCase);
    double actual = gradebook.GetScore(assignmentName, studentID);

    // Reminder: Can't compare NAN with ==, so a special case is needed
    bool areEqual = isnan(expected) ? isnan(actual) : (actual == expected);

    if (areEqual) {
      cout << "PASS: GetScore(\"" << assignmentName << "\", ";
      cout << studentID << ") returned " << actual << endl;
    } else {
      cout << "FAIL: GetScore(\"" << assignmentName << "\", ";
      cout << studentID << ") returned " << actual;
      cout << ", but expected is " << expected << endl;
      return false;
    }
  }
  return true;
}

bool TestGetAssignmentScores() {
  cout << endl << "---- TestGetAssignmentScores() ----" << endl;

  // Create a gradebook with sample data for testing
  CourseGradebook gradebook = TestUtility::MakeSampleGradebook();

  unordered_map<int, double> hw2Scores = {
      pair<int, double>(11111, 89.0),  pair<int, double>(22222, 75.0),
      pair<int, double>(33333, 100.0), pair<int, double>(44444, 50.0),
      pair<int, double>(55555, 76.5),  pair<int, double>(66666, 84.5),
      pair<int, double>(77777, 76.0),  pair<int, double>(88888, 74.5),
      pair<int, double>(99999, 100.0), pair<int, double>(10000, 90.0),
      pair<int, double>(90000, 85.0)};
  unordered_map<int, double> midtermScores = {
      pair<int, double>(11111, 91.0), pair<int, double>(22222, 77.5),
      pair<int, double>(33333, 88.0), pair<int, double>(44444, 40.0),
      pair<int, double>(55555, 64.5), pair<int, double>(66666, 91.0),
      pair<int, double>(77777, 75.0), pair<int, double>(88888, 88.0),
      pair<int, double>(99999, 88.0), pair<int, double>(10000, 92.0),
      pair<int, double>(90000, 90.0)};
  unordered_map<int, double> projectScores = {
      pair<int, double>(11111, 100.0), pair<int, double>(22222, 60.0),
      pair<int, double>(33333, 90.0),
      // pair<int, double>(44444, 80.0), // no entry for student 44444
      pair<int, double>(55555, 87.0), pair<int, double>(66666, 0.0),
      pair<int, double>(77777, 72.0), pair<int, double>(88888, 85.5),
      pair<int, double>(99999, 80.0), pair<int, double>(10000, 77.5),
      pair<int, double>(90000, 85.0)};

  // Each test case is a (assignmentName, mapOfExpectedScores) pair
  vector<pair<string, unordered_map<int, double> *>> testCases = {
      make_pair("Homework 2", &hw2Scores), make_pair("Midterm", &midtermScores),
      make_pair("Course project", &projectScores)};

  // Iterate through all test cases
  for (auto &testCase : testCases) {
    string assignmentName = testCase.first;
    unordered_map<int, double> &expectedMap = *(testCase.second);

    // Get the actual map from the gradebook
    cout << "Calling GetAssignmentScores(\"" << assignmentName;
    cout << "\")" << endl;
    unordered_map<int, double> actualMap =
        gradebook.GetAssignmentScores(assignmentName);

    // Compare sizes first
    if (expectedMap.size() != actualMap.size()) {
      cout << "FAIL: GetAssignmentScores(\"" << assignmentName;
      cout << "\") returned a map with ";
      if (1 == actualMap.size()) {
        cout << "1 score, ";
      } else {
        cout << actualMap.size() << " scores, ";
      }
      cout << "but the expected map has " << expectedMap.size();
      cout << " scores" << endl;
      return false;
    }

    // Sizes are equal, so now compare each ID/score pair
    for (auto expectedPair : expectedMap) {
      const int studentID = expectedPair.first;
      if (0 == actualMap.count(studentID)) {
        cout << "FAIL: GetAssignmentScores(\"" << assignmentName;
        cout << "\") returned a map that is missing an entry ";
        cout << "for student ID " << studentID << endl;
        return false;
      }

      // Actual map has student ID, so now compare corresponding score
      double expectedScore = expectedPair.second;
      double actualScore = actualMap[studentID];
      bool areEqual = isnan(expectedScore) ? isnan(actualScore)
                                           : (actualScore == expectedScore);
      if (!areEqual) {
        cout << "FAIL: GetAssignmentScores(\"" << assignmentName;
        cout << "\") returned a map that has a score of ";
        cout << actualScore << " for student ID " << studentID;
        cout << ", but the expected score is ";
        cout << expectedScore << endl;
        return false;
      }
    }

    // All entries match
    cout << "PASS: GetAssignmentScores(\"" << assignmentName;
    cout << "\") returned a map with " << actualMap.size();
    cout << " correct scores" << endl;
  }
  return true;
}

bool TestGetSortedAssignmentNames() {
  cout << endl << "---- TestGetSortedAssignmentNames() ----" << endl;
  CourseGradebook gradebook = TestUtility::MakeSampleGradebook();

  vector<string> expected = {"Course project", "Final exam", "Homework 1",
                             "Homework 2",     "Homework 3", "Homework 4",
                             "Midterm"};
  vector<string> actual = gradebook.GetSortedAssignmentNames();

  bool areEqual = true;
  if (actual.size() == expected.size()) {
    // Compare elements in order
    for (size_t i = 0; areEqual && i < expected.size(); i++) {
      if (actual[i] != expected[i]) {
        areEqual = false;
      }
    }
  } else {
    areEqual = false;
  }

  // Show pass or fail message along with expected and actual vector contents
  if (areEqual) {
    cout << "PASS: GetSortedAssignmentNames()" << endl;
  } else {
    cout << "FAIL: GetSortedAssignmentNames()" << endl;
  }
  cout << "  Expected: { ";
  TestUtility::PrintVector(expected, std::cout, ", ");
  cout << " }" << endl << "  Actual:   { ";
  TestUtility::PrintVector(actual, std::cout, ", ");
  cout << " }" << endl;

  return areEqual;
}

bool TestGetSortedStudentIDs() {
  cout << endl << "---- TestGetSortedStudentIDs() ----" << endl;
  CourseGradebook gradebook = TestUtility::MakeSampleGradebook();

  vector<int> expected = {10000, 11111, 22222, 33333, 44444, 55555,
                          66666, 77777, 88888, 90000, 99999};
  vector<int> actual = gradebook.GetSortedStudentIDs();

  bool areEqual = true;
  if (actual.size() == expected.size()) {
    // Compare elements in order
    for (size_t i = 0; areEqual && i < expected.size(); i++) {
      if (actual[i] != expected[i]) {
        areEqual = false;
      }
    }
  } else {
    areEqual = false;
  }

  // Show pass or fail message along with expected and actual vector contents
  if (areEqual) {
    cout << "PASS: GetSortedStudentIDs()" << endl;
  } else {
    cout << "FAIL: GetSortedStudentIDs()" << endl;
  }
  cout << "  Expected: { ";
  TestUtility::PrintVector(expected, std::cout, ", ");
  cout << " }" << endl << "  Actual:   { ";
  TestUtility::PrintVector(actual, std::cout, ", ");
  cout << " }" << endl;

  return areEqual;
}

bool TestGetStudentScores() {
  cout << endl << "---- TestGetStudentScores() ----" << endl;
  CourseGradebook gradebook = TestUtility::MakeSampleGradebook();

  unordered_map<string, double> student22222Scores = {
      // Student has no score for "Homework 1"
      pair<string, double>("Homework 2", 75.0),
      pair<string, double>("Midterm", 77.5),
      pair<string, double>("Homework 3", 80.5),
      pair<string, double>("Homework 4", 81.0),
      pair<string, double>("Course project", 60.0),
      pair<string, double>("Final exam", 54.0)};
  unordered_map<string, double> student44444Scores = {
      pair<string, double>("Homework 1", 60.0),
      pair<string, double>("Homework 2", 50.0),
      pair<string, double>("Midterm", 40.0),
      pair<string, double>("Homework 3", 30.0)
      // Student has no score for "Homework 4"
      // Student has no score for "Course project"
      // Student has no score for "Final exam"
  };
  unordered_map<string, double> student88888Scores = {
      pair<string, double>("Homework 1", 64.5),
      pair<string, double>("Homework 2", 74.5),
      pair<string, double>("Midterm", 88.0),
      pair<string, double>("Homework 3", 84.0),
      pair<string, double>("Homework 4", 84.0),
      pair<string, double>("Course project", 85.5),
      pair<string, double>("Final exam", 81.5)};
  unordered_map<string, double> student90000Scores = {
      pair<string, double>("Homework 1", 80.0),
      pair<string, double>("Homework 2", 85.0),
      pair<string, double>("Midterm", 90.0),
      pair<string, double>("Homework 3", 95.0),
      pair<string, double>("Homework 4", 100.0),
      pair<string, double>("Course project", 85.0),
      pair<string, double>("Final exam", 94.5)};

  // Each test case is a (studentID, mapOfExpectedScores) pair
  vector<pair<int, unordered_map<string, double> *>> testCases = {
      make_pair(22222, &student22222Scores),
      make_pair(44444, &student44444Scores),
      make_pair(88888, &student88888Scores),
      make_pair(90000, &student90000Scores)};

  // Iterate through all test cases
  for (auto &testCase : testCases) {
    int studentID = testCase.first;
    unordered_map<string, double> &expectedMap = *(testCase.second);

    // Get the actual map from the gradebook
    cout << "Calling GetStudentScores(" << studentID;
    cout << ")" << endl;
    unordered_map<string, double> actualMap =
        gradebook.GetStudentScores(studentID);

    // Compare sizes first
    if (expectedMap.size() != actualMap.size()) {
      cout << "FAIL: GetStudentScores(" << studentID;
      cout << ") returned a map with ";
      if (1 == actualMap.size()) {
        cout << "1 score, ";
      } else {
        cout << actualMap.size() << " scores, ";
      }
      cout << "but the expected map has " << expectedMap.size();
      cout << " scores" << endl;
      return false;
    }

    // Sizes are equal, so now compare each assignment name/score pair
    for (auto expectedPair : expectedMap) {
      string assignmentName = expectedPair.first;
      if (0 == actualMap.count(assignmentName)) {
        cout << "FAIL: GetStudentScores(" << studentID;
        cout << ") returned a map that is missing an entry for ";
        cout << "assignment \"" << assignmentName << "\"" << endl;
        return false;
      }

      // Actual map has assignment name, so now compare corresponding score
      double expectedScore = expectedPair.second;
      double actualScore = actualMap[assignmentName];
      bool areEqual = isnan(expectedScore) ? isnan(actualScore)
                                           : (actualScore == expectedScore);
      if (!areEqual) {
        cout << "FAIL: GetStudentScores(" << studentID;
        cout << ") returned a map that has a score of ";
        cout << actualScore << " for assignment \"";
        cout << assignmentName << "\", but the expected score is ";
        cout << expectedScore << endl;
        return false;
      }
    }

    // All entries match
    cout << "PASS: GetStudentScores(" << studentID;
    cout << ") returned a map with " << actualMap.size();
    cout << " correct scores" << endl;
  }
  return true;
}
