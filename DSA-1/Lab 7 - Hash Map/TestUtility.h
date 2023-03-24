#ifndef TESTUTILITY_H
#define TESTUTILITY_H

#include <math.h>

#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "CourseGradebook.h"
#include "Gradebook.h"

class TestUtility {
 public:
  // Populates a CourseGradebook from a vector of rows. Each row is a vector
  // of strings. Row 0 must be the header row. Column 0 must be the student ID
  // column.
  static void PopulateGradebookFromRows(
      Gradebook& gradebook, const std::vector<std::vector<std::string>>& rows) {
    using namespace std;

    // Iterate through non-header rows
    for (size_t rowIndex = 1; rowIndex < rows.size(); rowIndex++) {
      auto row = rows[rowIndex];

      // Parse out student ID first
      int studentID = stoi(row[0]);

      // Call SetScore for each non-empty entry
      for (size_t colIndex = 1; colIndex < row.size(); colIndex++) {
        string entry = row[colIndex];
        if (entry.length() > 0) {
          // Get the assignment name from the header row
          string assignmentName = rows[0][colIndex];

          // Convert score from string to double
          double score = stod(entry);

          // Add to gradebook
          gradebook.SetScore(assignmentName, studentID, score);
        }
      }
    }
  }

  // Returns a sample gradebook to use for testing purposes.
  static CourseGradebook MakeSampleGradebook() {
    using namespace std;
    vector<vector<string>> rows;
    rows.push_back({"Student ID", "Homework 1", "Homework 2", "Midterm",
                    "Homework 3", "Homework 4", "Course project",
                    "Final exam"});
    rows.push_back({"11111", "92", "89", "91", "100", "100", "100", "95"});
    rows.push_back({"22222", "", "75", "77.5", "80.5", "81", "60", "54"});
    rows.push_back({"33333", "100", "100", "88", "100", "100", "90", "77.5"});
    rows.push_back({"44444", "60", "50", "40", "30", "", "", ""});
    rows.push_back(
        {"55555", "73.5", "76.5", "64.5", "71.5", "77.5", "87", "63.5"});
    rows.push_back({"66666", "82.5", "84.5", "91", "92.5", "86", "0", "97"});
    rows.push_back({"77777", "77", "76", "75", "74", "73", "72", "71"});
    rows.push_back({"88888", "64.5", "74.5", "88", "84", "84", "85.5", "81.5"});
    rows.push_back({"99999", "100", "100", "88", "100", "100", "80", "79"});
    rows.push_back({"10000", "88", "90", "92", "87", "88.5", "77.5", "90"});
    rows.push_back({"90000", "80", "85", "90", "95", "100", "85", "94.5"});

    CourseGradebook gradebook;
    PopulateGradebookFromRows(gradebook, rows);
    return gradebook;
  }

  template <typename T>
  static void PrintVector(const std::vector<T>& vectorToPrint,
                          std::ostream& output, std::string separator = ",") {
    using namespace std;

    // Special case for empty vector
    if (0 == vectorToPrint.size()) {
      return;
    }

    // Print first element with no separator
    output << vectorToPrint[0];

    // Print remaining elements, each preceded by the separator
    for (size_t i = 1; i < vectorToPrint.size(); i++) {
      output << separator << vectorToPrint[i];
    }
  }
};

#endif