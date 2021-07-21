# Set

## Ordered Set

1. In backend, set is implemented as binary search tree.
2. All the elements in set will be sorted in ascending order.

## Time Complexity

| Operation            | Time Complexity |
| -------------------- | --------------- |
| Insertion (`insert`) | log(n)          |
| Deletion (`erase`)   | log(n)          |

## Operations

| Need                     | Syntax                                                                               |
| ------------------------ | ------------------------------------------------------------------------------------ |
| Insert element           | `s.insert(val)` OR `s.emplace(val)`                                                  |
| Erase one value          | `s.erase(iterator)` <br /> eg: `s.erase(s.begin()+2)`                                |
| Erase range of values    | `s.erase(start_iterator, end_iterator)` <br /> eg: `s.erase(s.begin(), s.begin()+3)` |
| Erase a particular value | `s.erase(key)` eg: suppose set has value 5 then `s.erase(5)`                         |
| To find any value in set | `s.find(val)` if val present then return iterator otherwise `s.end()`                |
| Delete entire set        | `s.clear()` OR `s.erase(s.begin(), s.end())`                                         |

### All the above operation takes O(log(n)) time

<br><br><br><br><br>

## Unordered Set

- Everything is same as set.
- The differences are
  - Average time for all operation is O(1) and worst case is O(n) { But worst case will occur very rarely }
  - Elements are not in ascending or descending order, it's not fixed. Everytime storing the same nos would result in different order. Ordering basically depends on the hash function implemented in backend at the moment you declared unordered_set
