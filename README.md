# StackBenchmark
A simple benchmark comparing the perfomance of an array-based stack and linked-list-based stack.
This pushes a set number of elements to two stacks, one using an array-based implementation, and the other using a list-based implementation

# Findings
Perhaps surprisingly, when testing with one million elements, it was found that, across benchmark runs, neither implemenation has a clear performance advantage, with both implementations being reported as faster on different test runs, and the performances differences often being under ten percent. More testing across different machines may prove useful. Going forward, it may be useful to experiment with different intial sizes of the array-based stack.

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
