# StackBenchmark
A simple benchmark comparing the perfomance of an array-based stack and linked-list-based stack.
This pushes a set number of elements to two stacks, one using an array-based implementation, and the other using a list-based implementation

# Findings
When output is enabled, there is no clear performance benefit to either implementation, however, when output is disabled, the array-based implementation performs considerably better than the list-based array, averaging between 50% and 80% better performance.

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
The benchmark prints out the value of each element in the array to verify correct functionality, however this interferes with accurate benchmarking, so to get accurate results, comment out the printf statements when before building the executable.
