#ifndef STATICSET_H
#define STATICSET_H

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

template <typename T>
class StaticSet {
 private:
  std::unordered_set<T> set;

 public:
  // Constructs an empty StaticSet
  StaticSet() {}

  // Constructs the StaticSet by adding all vector items
  StaticSet(const std::vector<T>& items) {
    for (const T& item : items) {
      set.insert(item);
    }
  }

  // Constructs the StaticSet by copying itemsToCopy's items
  StaticSet(const std::unordered_set<T>& itemsToCopy) : set(itemsToCopy) {}

  virtual ~StaticSet() {}

  bool Contains(const T& item) const { return 1 == set.count(item); }

  int GetSize() const { return (int)set.size(); }

  void Print(std::ostream& output, std::string separator,
             std::string prefix = "", std::string suffix = "") const {
    output << prefix;
    bool firstItem = true;
    for (const T& item : set) {
      if (firstItem) {
        output << item;
        firstItem = false;
      } else {
        output << separator << item;
      }
    }
    output << suffix;
  }

  StaticSet<T> Difference(const StaticSet& otherSet) const {
    StaticSet<T> copy;
    for (const T& item : set) {
      if (!otherSet.Contains(item)) {
        copy.set.insert(item);
      }
    }
    return copy;
  }

  StaticSet<T> Filter(std::function<bool(const T&)> predicate) const {
    StaticSet<T> copy;
    for (const T& item : set) {
      if (predicate(item)) {
        copy.set.insert(item);
      }
    }
    return copy;
  }

  StaticSet<T> Intersection(const StaticSet& otherSet) const {
    StaticSet<T> copy;
    for (const T& item : set) {
      if (otherSet.Contains(item)) {
        copy.set.insert(item);
      }
    }
    return copy;
  }
  template <typename U>
  StaticSet<U> Map(std::function<U(const T&)> mapFunction) const {
    std::unordered_set<U> mapped_set;
    for (const auto& item : set) {
      mapped_set.insert(mapFunction(item));
    }
    return StaticSet<U>(mapped_set);
  }

  StaticSet<T> Union(const StaticSet& otherSet) const {
    StaticSet<T> combined(set);
    for (const auto& item : otherSet.set) {
      combined.set.insert(item);
    }
    return combined;
  }
};

#endif
