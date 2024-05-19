#ifndef LINEARPROBINGHASHTABLE_H
#define LINEARPROBINGHASHTABLE_H

#include "OpenAddressingHashTable.h"

template <typename K, typename V>
class LinearProbingHashTable : public OpenAddressingHashTable<K, V> {
public:
  LinearProbingHashTable(int initialCapacity = 11)
      : OpenAddressingHashTable<K, V>(initialCapacity) {}

protected:
  // Returns the bucket index for the specified key and i value using the
  // linear probing sequence.
  int Probe(const K &key, int i) const override {
    return (this->Hash(key) + i) % this->table.size();
  }
};

#endif
