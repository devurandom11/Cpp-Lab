#ifndef QUADRATICPROBINGHASHTABLE_H
#define QUADRATICPROBINGHASHTABLE_H

#include "OpenAddressingHashTable.h"

template <typename K, typename V>
class QuadraticProbingHashTable : public OpenAddressingHashTable<K, V> {
private:
  int c1;
  int c2;

public:
  QuadraticProbingHashTable(int c1 = 1, int c2 = 1, int initialCapacity = 11)
      : OpenAddressingHashTable<K, V>(initialCapacity) {
    this->c1 = c1;
    this->c2 = c2;
  }

protected:
  // Returns the bucket index for the specified key and i value using the
  // quadratic probing sequence.
  int Probe(const K &key, int i) const override {
    return (this->Hash(key) + c1 * i + c2 * i * i) % this->table.size();
  }
};

#endif
