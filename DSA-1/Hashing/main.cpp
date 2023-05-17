#include <iostream>
#include <string>
#include <vector>

#include "ChainingHashTable.h"
#include "DoubleHashingHashTable.h"
#include "LinearProbingHashTable.h"
#include "QuadraticProbingHashTable.h"

using namespace std;

int main() {
  string keys[] = {"Los Angeles", "Houston",       "Washington",
                   "Chicago",     "San Francisco", "Dallas",
                   "Tokyo",       "New York",      "Vancouver"};
  int keysLength = sizeof(keys) / sizeof(keys[0]);
  string values[] = {"LAX", "IAH", "IAD", "ORD", "SFO",
                     "DAL", "NRT", "JFK", "YVR"};

  const int initialCapacity = 11;

  // Initialize the four types of hash tables
  HashTable<string, string>* tables[] = {
      new ChainingHashTable<string, string>(initialCapacity),
      new LinearProbingHashTable<string, string>(initialCapacity),
      new QuadraticProbingHashTable<string, string>(1, 1, initialCapacity),
      new DoubleHashingHashTable<string, string>(initialCapacity)};
  int tablesLength = sizeof(tables) / sizeof(tables[0]);

  // Add the same content to each hash table
  for (int i = 0; i < keysLength; i++) {
    // Insert the item into each hash table
    for (int j = 0; j < tablesLength; j++) {
      tables[j]->Insert(keys[i], values[i]);
    }
  }

  // Print each table's buckets
  string tableNames[] = {"Chaining", "Linear probing", "Quadratic probing",
                         "Double hashing"};
  for (int j = 0; j < tablesLength; j++) {
    cout << tableNames[j] << ": initial table:" << endl;
    tables[j]->PrintTable(cout);
    cout << endl;
  }

  // Remove the 3 oldest keys from each hash table
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < tablesLength; j++) {
      tables[j]->Remove(keys[i]);
    }
  }

  // Print each table's buckets again
  cout << endl;
  for (int j = 0; j < tablesLength; j++) {
    cout << tableNames[j] << " after removal:" << endl;
    tables[j]->PrintTable(cout);
    cout << endl;
  }

  // Free each table
  for (int j = 0; j < tablesLength; j++) {
    delete tables[j];
  }
}