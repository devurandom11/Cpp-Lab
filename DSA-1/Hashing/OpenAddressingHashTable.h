#ifndef OPENADDRESSINGHASHTABLE_H
#define OPENADDRESSINGHASHTABLE_H

#include <vector>

#include "HashTable.h"


// OpenAddressingBucket represents a bucket with a key and a value.
template <typename K, typename V>
struct OpenAddressingBucket {
  K* key;
  V* value;

  OpenAddressingBucket() {
    key = nullptr;
    value = nullptr;
  }

  OpenAddressingBucket(const K& bucketKey, const V& bucketValue) {
    key = new K(bucketKey);
    value = new V(bucketValue);
  }

  virtual ~OpenAddressingBucket() {
    if (key) {
      delete key;
    }
    if (value) {
      delete value;
    }
  }

  // Two special bucket types exist: empty since start and empty after removal
  inline static OpenAddressingBucket<K, V> EMPTY_SINCE_START;
  inline static OpenAddressingBucket<K, V> EMPTY_AFTER_REMOVAL;

  bool IsEmpty() const {
    return this == &EMPTY_SINCE_START || this == &EMPTY_AFTER_REMOVAL;
  }
};

// OpenAddressingHashTable is an abstract base class for an open addressing hash
// table
template <typename K, typename V>
class OpenAddressingHashTable : public HashTable<K, V> {
 protected:
  std::vector<OpenAddressingBucket<K, V>*> table;
  virtual int Probe(const K& key, int i) const = 0;

 public:
  OpenAddressingHashTable(int initialCapacity) {
    table.resize(initialCapacity,
                 &OpenAddressingBucket<K, V>::EMPTY_SINCE_START);
  }

  virtual ~OpenAddressingHashTable() {
    // Free all non-empty buckets
    for (int i = 0; i < table.size(); i++) {
      if (!table[i]->IsEmpty()) {
        // Deleting the bucket calls OpenAddressingBucket's destructor,
        // which deallocates the bucket's key and value.
        delete table[i];
      }
    }
  }

  // Inserts the specified key/value pair. If the key already exists, the
  // corresponding value is updated. If inserted or updated, true is returned.
  // If not inserted, then false is returned.
  bool Insert(const K& key, const V& value) override {
    // First search for the key in the table. If found, update bucket's value.
    for (int i = 0; i < table.size(); i++) {
      int bucketIndex = Probe(key, i);

      // An empty-since-start bucket implies the key is not in the table
      if (table[bucketIndex] ==
          &OpenAddressingBucket<K, V>::EMPTY_SINCE_START) {
        break;
      }

      if (table[bucketIndex] !=
          &OpenAddressingBucket<K, V>::EMPTY_AFTER_REMOVAL) {
        // Check if the non-empty bucket has the key
        if (key == *table[bucketIndex]->key) {
          // Update the value
          delete table[bucketIndex]->value;
          table[bucketIndex]->value = new V(value);
          return true;
        }
      }
    }

    // The key is not in the table, so insert into first empty bucket
    for (int i = 0; i < table.size(); i++) {
      int bucketIndex = Probe(key, i);
      if (table[bucketIndex]->IsEmpty()) {
        table[bucketIndex] = new OpenAddressingBucket(key, value);
        return true;
      }
    }

    return false;  // no empty bucket found
  }

  // Searches for the specified key. If found, the key/value pair is removed
  // from the hash table and true is returned. If not found, false is returned.
  bool Remove(const K& key) override {
    for (int i = 0; i < table.size(); i++) {
      int bucketIndex = Probe(key, i);

      // An empty-since-start bucket implies the key is not in the table
      if (table[bucketIndex] ==
          &OpenAddressingBucket<K, V>::EMPTY_SINCE_START) {
        return false;
      }

      if (table[bucketIndex] !=
          &OpenAddressingBucket<K, V>::EMPTY_AFTER_REMOVAL) {
        // Check if the non-empty bucket has the key
        if (key == *table[bucketIndex]->key) {
          // Remove by deleting and setting the bucket to empty-after-removal
          delete table[bucketIndex];
          table[bucketIndex] = &OpenAddressingBucket<K, V>::EMPTY_AFTER_REMOVAL;
          return true;
        }
      }
    }

    return false;  // key not found
  }

  // Searches for the key, returning the corresponding value if found, null if
  // not found.
  V* Search(const K& key) const override {
    for (int i = 0; i < table.size(); i++) {
      int bucketIndex = Probe(key, i);

      // An empty-since-start bucket implies the key is not in the table
      if (table[bucketIndex] ==
          &OpenAddressingBucket<K, V>::EMPTY_SINCE_START) {
        return nullptr;
      }

      if (table[bucketIndex] !=
          &OpenAddressingBucket<K, V>::EMPTY_AFTER_REMOVAL) {
        // Check if the non-empty bucket has the key
        if (key == *table[bucketIndex]->key) {
          return table[bucketIndex]->value;
        }
      }
    }

    return nullptr;  // key not found
  }

  void PrintTable(std::ostream& printStream) const override {
    for (int i = 0; i < table.size(); i++) {
      printStream << i << ": ";
      if (table[i] == &OpenAddressingBucket<K, V>::EMPTY_SINCE_START) {
        printStream << "EMPTY_SINCE_START" << std::endl;
      } else if (table[i] == &OpenAddressingBucket<K, V>::EMPTY_AFTER_REMOVAL) {
        printStream << "EMPTY_AFTER_REMOVAL" << std::endl;
      } else {
        printStream << *table[i]->key << ", ";
        printStream << *table[i]->value << std::endl;
      }
    }
  }
};

#endif