#ifndef CHAININGHASHTABLE_H
#define CHAININGHASHTABLE_H

#include <vector>

#include "HashTable.h"


template <typename K, typename V>
struct ChainingHashTableItem {
  K key;
  V value;
  ChainingHashTableItem<K, V>* next;

  ChainingHashTableItem(const K& itemKey, const V& itemValue)
      : key(itemKey), value(itemValue) {
    next = nullptr;
  }
};

template <typename K, typename V>
class ChainingHashTable : public HashTable<K, V> {
 private:
  std::vector<ChainingHashTableItem<K, V>*> table;

 public:
  ChainingHashTable(int initialCapacity = 11) {
    table.resize(initialCapacity, nullptr);
  }

  virtual ~ChainingHashTable() {
    // Delete each ChainingHashTableItem in the table
    for (int i = 0; i < table.size(); i++) {
      ChainingHashTableItem<K, V>* item = table[i];
      while (item) {
        ChainingHashTableItem<K, V>* itemToDelete = item;
        item = item->next;
        delete itemToDelete;
      }
    }
  }

  // Inserts the specified key/value pair. If the key already exists, the
  // corresponding value is updated. If inserted or updated, true is returned.
  // If not inserted, then false is returned.
  bool Insert(const K& key, const V& value) override {
    // Hash the key to get the bucket index
    int bucketIndex = this->Hash(key) % table.size();

    // Traverse the linked list, searching for the key. If the key exists in
    // an item, the value is replaced. Otherwise a new item is appended.
    ChainingHashTableItem<K, V>* item = table[bucketIndex];
    ChainingHashTableItem<K, V>* previous = nullptr;
    while (item) {
      if (key == item->key) {
        item->value = value;
        return true;
      }

      previous = item;
      item = item->next;
    }

    // Append to the linked list
    if (table[bucketIndex] == nullptr) {
      table[bucketIndex] = new ChainingHashTableItem(key, value);
    } else {
      previous->next = new ChainingHashTableItem(key, value);
    }
    return true;
  }

  // Searches for the specified key. If found, the key/value pair is removed
  // from the hash table and true is returned. If not found, false is returned.
  bool Remove(const K& key) override {
    // Hash the key to get the bucket index
    int bucketIndex = this->Hash(key) % table.size();

    // Search the bucket's linked list for the key
    ChainingHashTableItem<K, V>* item = table[bucketIndex];
    ChainingHashTableItem<K, V>* previous = nullptr;
    while (item) {
      if (key == item->key) {
        if (previous == nullptr) {
          // Remove linked list's first item
          table[bucketIndex] = item->next;
        } else {
          previous->next = item->next;
        }
        delete item;
        return true;
      }

      previous = item;
      item = item->next;
    }

    return false;  // key not found
  }

  // Searches for the key, returning the corresponding value if found, null if
  // not found.
  V* Search(const K& key) const override {
    // Hash the key to get the bucket index
    int bucketIndex = this->Hash(key) % table.size();

    // Search the bucket's linked list for the key
    ChainingHashTableItem<K, V>* item = table[bucketIndex];
    while (item) {
      if (key == item->key) {
        return &item->value;
      }
      item = item->next;
    }

    return nullptr;  // key not found
  }

  void PrintTable(std::ostream& printStream) const override {
    for (int i = 0; i < table.size(); i++) {
      printStream << i << ": ";

      if (table[i] == nullptr) {
        printStream << "(empty)" << std::endl;
      } else {
        ChainingHashTableItem<K, V>* item = table[i];
        while (item) {
          printStream << item->key << ", " << item->value << " --> ";
          item = item->next;
        }
        printStream << std::endl;
      }
    }
  }
};

#endif