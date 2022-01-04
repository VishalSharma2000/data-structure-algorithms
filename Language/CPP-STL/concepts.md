### Stack and Heap
The memory that the programs uses is typically divided into segments.
1. **Code Segment / Text Segment** : Here the compiled programs resides, this place is read only 
2. **Un-Initialized Code Segment / BSS Segment** : Here zero-initialized global and static variables are stored
3. **Initialized Code Segment / Data Segment** : Initialized global and static variables are stored
4. **Heap Segment / Free Store** : Dynamically allocated variables are stored here
5. **Call Stack** : function parameters, local variables and other function related stuffs are stored.

#### Dynamic Memory allocation example
```
int *ptr = new int;
int *array = new int[10];
```
Both the variables ptr and array are created in the call stack frame when the function including these statements is called. The memory pointed by ptr and the array pointed by array are created in the heap segment.

#### Pros / Cons of Heap Segment
* Allocating memory on the heap is comparatively slow.
* Allocated memory stays allocated until it is specifically deallocated (beware memory leaks) or when the application or program ends (at which point the OS should clean it up).
* Dynamically allocated memory must be accessed through a pointer. Dereferencing(accessing a memory location by a pointer) a pointer is slower than accessing a variable directly.
* Because the heap is a big pool of memory, large arrays, structures, or classes can be allocated here.