#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

class Gradebook {
public:
  virtual ~Gradebook() {}

  // GetScore() returns the specified student's score for the specified
  // assignment. NAN is returned if either:
  // - the assignment does not exist in the gradebook, or
  // - the assignment exists but no score exists for the specified student.
  virtual double GetScore(std::string assignmentName, int studentID) = 0;

  // SetScore() adds or updates a score in the gradebook.
  virtual void SetScore(std::string assignmentName, int studentID,
                        double score) = 0;

  // GetAssignmentScores() returns an unordered_map that maps a student ID to
  // the student's corresponding score for the specified assignment. An entry
  // exists in the returned map only if a score has been entered with the
  // SetScore() function.
  virtual std::unordered_map<int, double>
  GetAssignmentScores(std::string assignmentName) = 0;

  // GetSortedAssignmentNames() returns a vector with all distinct assignment
  // names, sorted in ascending order.
  virtual std::vector<std::string> GetSortedAssignmentNames() = 0;

  // GetSortedStudentIDs() returns a vector with all distinct student IDs,
  // sorted in ascending order.
  virtual std::vector<int> GetSortedStudentIDs() = 0;

  // GetStudentScores() gets all scores that exist in the gradebook for the
  // student whose ID matches the function parameter. GetStudentScores()
  // returns an unordered_map that maps an assignment name to the student's
  // corresponding score for that assignment.
  virtual std::unordered_map<std::string, double>
  GetStudentScores(int studentID) = 0;
};

#endif
