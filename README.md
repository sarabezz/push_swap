# PUSH_SWAP

A C program that sorts a stack of integers using two stacks and a limited set of operations.


## About

Push_swap receives a list of integers as arguments, loads them into stack a, and sorts them in ascending order using only two stacks (`a` and `b`) and a restricted set of operations: `sa`, `sb`, `pa`, `ra`, `rb`, `rra`, `rrb`. The goal is to produce the sorted result using the **minimum number of operations** possible.

The algorithm combines three ideas: finding the **Longest Increasing Subsequence (LIS)** of the initial stack to identify elements already in relative order, dividing the remaining elements into **chunks** by value range, and using a **minimum cost** calculation to effeciently reinsert elements from `b` back into `a`.


## Algorithm
### Step 1 - Longest Increasing Subsequence (LIS)
Before moving anything, the program converts stack `a`to an array and computes the LIS -- the longest sequence of elements that are already in relative ascending order. These elements stay in `a`and never pushed to `b`, forming the sorted base that the rest of the algorithm builds around.

## Step 2 - Chunk-based push to `b`
The full array is divided into chunks by value range. The number of chunks is calculated as teh integer square root of the stack size. Elements are moved to `b`chunk by chunk, from smallest to largest range, skipping any element that belongs to the LIS. This leaves `b` organized in descending order from top to bottom -- the largest values on top, smallest at the bottom.

### Step 3 - Minimum cost reinsertion to `a`
Elements are moved back from `b`to `a`pne by one. For each element in `b`, the program calculates how many rotations it would cost to place it in its correct position i `a`, choosing always the elemtns with the minimum total cost. Once all elements are back in `a`, a final rotation places the minimum value at the top. 

## Functions
### Validation
| Function | Description |
|----------|-------------|
| `ft_error` | Writes "Error" to stderr and exits the program |
| `ft_isnumber` | Checks that a string is a valid integer (handles +/- signs) |
| `ft_atoi_checked` | Converts a string to int, exiting if it overflows INT_MAX or INT_MIN |
| `dupl_nums` | Checks for duplicate numbers in the input array |

### Stack operations
| `sa` | Swaps the two top elements of stack `a` |
| `pb` | Moves the top element of stack `a` to the top of stack `b` |
| `pa` | Moves the top element of stack `b` to the top of stack `a` |
| `ra` | Rotates stack `a` upwards — the top element becomes the bottom |
| `rb` | Rotates stack `b` upwards |
| `rra` | Rotates stack `a` downwards — the bottom element becomes the top |
| `rrb` | Rotates stack `b` downwards |
| `push_node` | Inserts a node at the top of a stack |
| `remove_node` | Removes the top node from a stack |
| `final_rotate` | Rotates stack `a` the minimum number of steps to place the smallest element at the top |

### Algorithm
| Function | Description |
|----------|-------------|
| `longest_increasing_subsequence` | Computes the LIS of the input array using dynamic programming |
| `init_arrays` | Initializes the `dp` and `prev` arrays used by the LIS algorithm |
| `fill_dp` | Fills the `dp` array comparing each element with all previous ones |
| `get_max_index` | Finds the index of the longest subsequence in the `dp` array |
| `reconstruct` | Reconstructs the actual LIS array by backtracking through `prev` |
| `int_sqrt` | Computes the integer square root, used to determine the number of chunks |
| `create_chunks` | Creates the chunk boundaries by sorting a copy of the array and dividing it into equal ranges |
| `find_chunks_max` | Finds the maximum value of each chunk from the sorted array |
| `process_chunks` | Assigns each element to its corresponding chunk |
| `get_cost_a` | Finds the position in stack `a` where a value should be inserted |
| `adjust_cost` | Adjusts the rotation cost to always take the shortest path |
| `find_min_cost` | Finds the element in `b` with the minimum total cost to insert into `a` |
| `total_cost` | Calculates the total cost of rotating both stacks, optimizing simultaneous rotations |

### Stack utils
| Function | Description |
|----------|-------------|
| `create_node` | Allocates and initializes a new stack node with a given value |
| `push_no_count` | Inserts a new node at the top of a stack without printing any operation |
| `insert_nums` | Inserts an array of integers into stack `a` in the correct order |
| `stack_size` | Returns the number of elements in a stack |
| `stack_to_array` | Converts a stack into an integer array |
| `convert_to_array` | Converts a stack into a `t_stack_array` struct with size and capacity |
| `free_stack` | Frees all nodes of a stack |
| `get_min_index` | Returns the index of the minimum value in a stack |
| `ft_free_split` | Frees a null-terminated array of strings |
| `fill_stack` | Parses all arguments and fills stack `a` |
| `parse_args` | Parses a single string argument, splitting by spaces and inserting into stack `a` |


## Usage

```bash
git clone https://github.com/sarabezz/push_swap.git
cd push_swap
make
```

Run the program:

```bash
./push_swap 3 1 4 1 5 9 2 6
```

Check if the result is sorted correctly:

```bash
./push_swap 3 1 4 5 9 2 6 | ./checker_linux 3 1 4 5 9 2 6
```

You can also pass numbers as a single string:

```bash
./push_swap "3 1 4 5 9 2 6"
```


## Key concepts

- Stacks only allow operations on the top element — no random access
- A doubly circular linked list is used to represent each stack, allowing efficient rotation in both directions
- The LIS is computed using dynamic programming, converting the stack to an array first since linked lists don't support random access
- Chunks divide the full value range into equal groups using the integer square root of the stack size, ensuring a balanced distribution
- Rotation cost is minimized by choosing the shortest path (forward or backward) and by combining simultaneous rotations when both stacks rotate in the same direction
- Careful memory management with `malloc` and `free` to avoid leaks


## Project info 

| | |
|---|---|
| Language | C |
| School | 42 Madrid |
| Status | ✅ Completed |
