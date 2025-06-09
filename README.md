# push_swap
`push_swap` is a sorting algorithm visualizer and command generator built in C. The program outputs the most efficient sequence of stack operations needed to sort a set of integers using a restricted instruction set.

## Objective
Given a list of integers, the goal is to sort them in ascending order using two stacks (a and b) and a limited set of operations, while producing the fewest possible instructions.

## Features
- Input Parsing & Validation
  - Detects duplicates, invalid integers, and malformed input.
- Custom Stack Data Structures
  - Implements two stacks using linked lists or arrays with efficient operation handling.
- Instruction Set
  - The following operations are used:
    - `sa`, `sb`, `ss` – swap top elements
    - `pa`, `pb` – push from one stack to another
    - `ra`, `rb`, `rr` – rotate up
    - `rra`, `rrb`, `rrr` – rotate down
- Optimized Sorting Algorithms
  - Specialized sort for small sets (3–5 numbers)
  - Tailored optimizations to reduce total instruction count
- Performance-Oriented Design
  - Targets minimal operation count in compliance with project constraints
