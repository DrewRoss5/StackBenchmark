# StackBenchmark
A simple benchmark comparing the perfomance of an array-based stack and linked-list-based stack.
This pushes a set number of elements to two stacks, one using an array-based implementation, and the other using a list-based implementation

# Findings
When output is enabled, there is no clear performance benefit to either implementation, however, when output is disabled, the array-based implementation performs considerably better than the list-based array, averaging between 50% and 80% better performance, this is likely due to the array-based implementation requiring fewer memory allocations, and taking advantage of cache-locality.

# Usage
To run the benchmark on your local machine: 
- Clone this repository
- Build the `stackbench` executable using the following commands in this repository's directory:
  ```
  mkdir build
  cd build
  cmake ..
  cmake --build .
  ```
- Run the `stackbench` executable, passing the number of elements to push and pop to each stack.
- View the reported results
## Note:
By default, this benchmark does not display the values popped off of each stack to minimize overhead interfereing with results, however, to verify the stacks work as intended, one can simply uncomment the printf lines in main.cpp before building in order to verify proper functionality of the stacks.
