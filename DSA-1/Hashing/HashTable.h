#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>
#include <iostream>

// Abstract class for a hash table that supports the insert, remove, and search
// operations.
template <typename K, typename V>
class HashTable {
 public:
  // Returns a non-negative hash code for the specified key.
  int Hash(const K& key) const {
    // The type must have a hash<K> class or struct defined in std namespace
    std::hash<K> hashFunctionObject;
    size_t keyHash = hashFunctionObject(key);

    // size_t is unsigned and likely more than 32 bits. Convert to int by
    // masking out the lowest 31 bits.
    return (int)(keyHash & 0x7fffffff);
  }

  virtual ~HashTable() {}

  // Inserts the specified key/value pair. If the key already exists, the
  // corresponding value is updated. If inserted or updated, true is returned.
  // If not inserted, then false is returned.
  virtual bool Insert(const K& key, const V& value) = 0;

  // Searches for the specified key. If found, the key/value pair is removed
  // from the hash table and true is returned. If not found, false is returned.
  virtual bool Remove(const K& key) = 0;

  // Searches for the key, returning a pointer to corresponding value if
  // found, nullptr if not found.
  virtual V* Search(const K& key) const = 0;

  virtual void PrintTable(std::ostream& printStream) const = 0;
};

#endif