# Here You will learn everything about vector in CPP STL

## Different Ways to Initialize vector

| Syntax                                            | Description                                                                               |
| ------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| `vector<int> vec1;`                               | Declare Vector without any size or default value                                          |
| `vector<int> vec1(10);`                           | With some predefined size                                                                 |
| `vector<int> vec1(10, 5);`                        | With some predefined size and value                                                       |
| `vector<int> vec2(vec1);`                         | Used to initialize current new vector with any old vector (all elements will be copied)   |
| `vector<int> vec1(vec1.begin(), vec1.end());`     | Another way to initialize with old vector (can be used if we want to copy only some part) |
| `vector<int> vec2(vec1.begin(), vec1.begin()+2);` | Copy first two elements from vec1                                                         |

## Operations on vector

| Need                                                                                                                                                                                | Syntax                                                                                         |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------- |
| Push Element                                                                                                                                                                        | `vec1.push_back(val)`                                                                          |
| Push Element (Takes Less Time)                                                                                                                                                      | `vec1.emplace_back(val)`                                                                       |
| Pop Element from back                                                                                                                                                               | `vec1.pop_back(val)`                                                                           |
| Clear the vector                                                                                                                                                                    | `vec1.clear()`                                                                                 |
| Size of Vector                                                                                                                                                                      | `vec1.size()`                                                                                  |
| Resize Vector to any size (Keep care of data loss if you resize to a size which is less than current size)                                                                          | `vec1.resize(size)`                                                                            |
| Fill or Update value to a range of index in vector (You can update from any index to any index)                                                                                     | `fill(vec1.begin(), vec1.end(), val)`                                                          |
| Fill or update (Using staring iterator and number of elements to update or fill)                                                                                                    | `fill_n(vec1.begin(), no_of_elemets, 5)`                                                       |
| Copy vec1 into vec2                                                                                                                                                                 | `vec2 = vec1`                                                                                  |
| Swap vectors                                                                                                                                                                        | `swap(vec1, vec2)`                                                                             |
| Copy some range of one vector (vec2) into another vector (vec1) - (This can be used after you have already declared the vector - Here we are copying all elements of vec2 into vec1 | `copy(vec2.begin(), vec2.end(), back_inserter(vec1)) OR vec1.assign(vec2.begin(), vec2.end())` |

## Accessing Elements

| Need                 | Syntax                               |
| -------------------- | ------------------------------------ |
| Access Any Element   | `vec1[index]`                        |
| Access First Element | `vec1.front() OR vec1[0]`            |
| Access Last Element  | `vec1.back() OR vec1[vec1.size()-1]` |
