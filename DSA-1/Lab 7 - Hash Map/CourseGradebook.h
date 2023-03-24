#ifndef COURSEGRADEBOOK_H
#define COURSEGRADEBOOK_H

#include <algorithm>

#include "Gradebook.h"

class CourseGradebook : public Gradebook {
 protected:
  // Your code here

 public:
  virtual ~CourseGradebook() {
    // Your code here, if needed
  }

  std::unordered_map<int, double> GetAssignmentScores(
      std::string assignmentName) override {
    // Your code here (remove placeholder line below)
    return std::unordered_map<int, double>();
  }

  double GetScore(std::string assignmentName, int studentID) override {
    // Your code here (remove placeholder line below)
    return NAN;
  }

  std::vector<std::string> GetSortedAssignmentNames() override {
    // Your code here (remove placeholder line below)
    return std::vector<std::string>();
  }

  // GetSortedStudentIDs() returns a vector with all distinct student IDs,
  // sorted in ascending order.
  std::vector<int> GetSortedStudentIDs() override {
    // Your code here (remove placeholder line below)
    return std::vector<int>();
  }

  // GetStudentScores() gets all scores that exist in the gradebook for the
  // student whose ID equals the studentID parameter. Scores are returned as
  // an unordered_map that maps an assignment name to the student's
  // corresponding score for that assignment.
  std::unordered_map<std::string, double> GetStudentScores(
      int studentID) override {
    // Your code here (remove placeholder line below)
    return std::unordered_map<std::string, double>();
  }

  void SetScore(std::string assignmentName, int studentID,
                double score) override {
    // Your code here
  }
};

#endif