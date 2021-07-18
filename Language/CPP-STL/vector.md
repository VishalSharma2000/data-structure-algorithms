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
