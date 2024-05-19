#ifndef STATICSETTESTCASES_H
#define STATICSETTESTCASES_H

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#include "StaticSet.h"

class StaticSetTestCase {
public:
  template <typename T>
  static double CompareSets(std::ostream &testFeedback, StaticSet<T> &actual,
                            std::unordered_set<T> &expected, std::string title,
                            double points) {
    using namespace std;
    bool pass = true;

    // Compare actual vs. expected sets
    if (actual.GetSize() != (int)expected.size()) {
      pass = false;
    } else {
      // Expected and actual have equal sizes, so compare contents
      for (const T &item : expected) {
        if (!actual.Contains(item)) {
          pass = false;
        }
      }
    }

    // Print the pass or fail message with expected and actual sets
    testFeedback << (pass ? "PASS: " : "FAIL: ");
    testFeedback << title << endl;
    StaticSetTestCase::Print<unordered_set<T>, T>(testFeedback, expected, ", ",
                                                  "  Expected: {", "}\n");
    actual.Print(testFeedback, ", ", "  Actual:   {", "}\n");

    return pass ? points : 0.0;
  }

  template <typename ContainerType, typename ItemType>
  static void Print(std::ostream &output, const ContainerType &iterable,
                    std::string separator = ", ", std::string prefix = "",
                    std::string suffix = "") {
    // Print the prefix first
    output << prefix;

    bool firstItem = true;
    for (const ItemType &item : iterable) {
      if (firstItem) {
        // Print first item without separator
        output << item;
        firstItem = false;
      } else {
        // Print item preceeded by separator
        output << separator << item;
      }
    }

    // Print the suffix last
    output << suffix;
  }

  virtual int Execute(std::ostream &testFeedback) = 0;
};

// BinaryOpsTestCase represents an executable test case for the StaticSet's
// Union(), Intersection(), and Difference() member functions
template <typename T> class BinaryOpsTestCase : public StaticSetTestCase {
private:
  std::unordered_set<T> setA;
  std::unordered_set<T> setB;
  std::unordered_set<T> expectedUnion;
  std::unordered_set<T> expectedIntersection;
  std::unordered_set<T> expectedAMinusB;
  std::unordered_set<T> expectedBMinusA;

public:
  BinaryOpsTestCase(const std::unordered_set<T> &setA,
                    const std::unordered_set<T> &setB,
                    const std::unordered_set<T> &expectedUnion,
                    const std::unordered_set<T> &expectedIntersection,
                    const std::unordered_set<T> &expectedAMinusB,
                    const std::unordered_set<T> &expectedBMinusA) {
    this->setA = setA;
    this->setB = setB;
    this->expectedUnion = expectedUnion;
    this->expectedIntersection = expectedIntersection;
    this->expectedAMinusB = expectedAMinusB;
    this->expectedBMinusA = expectedBMinusA;
  }

  virtual int Execute(std::ostream &testFeedback) override {
    using namespace std;

    // Print sets A and B first
    Print<unordered_set<T>, T>(testFeedback, setA, ", ", "A = {", "}\n");
    Print<unordered_set<T>, T>(testFeedback, setB, ", ", "B = {", "}\n");

    // Create the two StaticSet objects from the unordered_set objects
    StaticSet<T> staticSetA(setA);
    StaticSet<T> staticSetB(setB);

    // Create the union, intersection, and differences
    StaticSet<T> actualUnion = staticSetA.Union(staticSetB);
    StaticSet<T> actualIntersection = staticSetA.Intersection(staticSetB);
    StaticSet<T> actualAMinusB = staticSetA.Difference(staticSetB);
    StaticSet<T> actualBMinusA = staticSetB.Difference(staticSetA);

    // Verify that performing operations didn't change either StaticSet's size
    vector<tuple<StaticSet<T> *, unordered_set<T> *, string>> sizeChecks = {
        make_tuple(&staticSetA, &setA, "A"),
        make_tuple(&staticSetB, &setB, "B")};
    for (auto &sizeCheckTuple : sizeChecks) {
      StaticSet<T> *staticSet = std::get<0>(sizeCheckTuple);
      unordered_set<T> *unorderedSet = std::get<1>(sizeCheckTuple);
      string staticSetName = std::get<2>(sizeCheckTuple);
      if (staticSet->GetSize() != (int)unorderedSet->size()) {
        testFeedback << "FAIL: Creating the union/intersection/difference ";
        testFeedback << " of StaticSets A and B changed set ";
        testFeedback << staticSetName << "'s size from ";
        testFeedback << unorderedSet->size();
        testFeedback << " to " << staticSetA.GetSize() << std::endl;
        return 0.0;
      }
    }

    // Compare actual vs. expected sets
    double totalPoints = 0.0;
    totalPoints += StaticSetTestCase::CompareSets<T>(
        testFeedback, actualUnion, expectedUnion, "Union operation", 1.0);
    totalPoints += StaticSetTestCase::CompareSets<T>(
        testFeedback, actualIntersection, expectedIntersection,
        "Intersection operation", 1.0);
    totalPoints += StaticSetTestCase::CompareSets<T>(
        testFeedback, actualAMinusB, expectedAMinusB, "A \\ B operation", 0.5);
    totalPoints += StaticSetTestCase::CompareSets<T>(
        testFeedback, actualBMinusA, expectedBMinusA, "B \\ A operation", 0.5);

    return (int)totalPoints;
  }
};

// UnaryOpsTestCase represents an executable test case for the StaticSet's
// Filter() and Map() member functions
template <typename T, typename MappedItemType>
class UnaryOpsTestCase : public StaticSetTestCase {
private:
  std::unordered_set<T> sourceSet;
  std::function<bool(const T &)> filterPredicate;
  std::function<MappedItemType(const T &)> mapFunction;
  std::unordered_set<T> expectedFiltered;
  std::unordered_set<MappedItemType> expectedMapped;

public:
  UnaryOpsTestCase(const std::unordered_set<T> &sourceSet,
                   std::function<bool(const T &)> filterPredicate,
                   std::function<MappedItemType(const T &)> mapFunction,
                   const std::unordered_set<T> &expectedFiltered,
                   const std::unordered_set<MappedItemType> &expectedMapped) {
    this->sourceSet = sourceSet;
    this->filterPredicate = filterPredicate;
    this->mapFunction = mapFunction;
    this->expectedFiltered = expectedFiltered;
    this->expectedMapped = expectedMapped;
  }

  virtual int Execute(std::ostream &testFeedback) override {
    using namespace std;

    // Print the source set first
    Print<unordered_set<T>, T>(testFeedback, sourceSet, ", ", "Set = {", "}\n");

    // Create the StaticSet object from the unordered_set source
    StaticSet<T> staticSet(sourceSet);

    // Create the filtered and mapped sets
    StaticSet<T> actualFiltered = staticSet.Filter(filterPredicate);
    StaticSet<MappedItemType> actualMapped = staticSet.Map(mapFunction);

    // Verify that performing operations didn't staticSetA's size
    if (staticSet.GetSize() != (int)sourceSet.size()) {
      testFeedback << "FAIL: Filtering and/or mapping StaticSet S changed ";
      testFeedback << "S's size from " << sourceSet.size();
      testFeedback << " to " << staticSet.GetSize() << std::endl;
      return 0.0;
    }

    // Compare actual vs. expected sets
    double totalPoints = 0.0;
    totalPoints += StaticSetTestCase::CompareSets<T>(
        testFeedback, actualFiltered, expectedFiltered, "Filter operation",
        1.0);
    totalPoints += StaticSetTestCase::CompareSets<MappedItemType>(
        testFeedback, actualMapped, expectedMapped, "Map operation", 1.0);

    return (int)totalPoints;
  }
};

#endif
