# Double Depth First Search (Double-DFS) Algorithm

## Overview
This project implements the Double Depth First Search algorithm for checking emptiness of Büchi automata in C++. The implementation is based on the algorithm described in Section 7.5.1 of the book "Model Checking, Second Edition" by Edmund M. Clarke Jr., Orna Grumberg, Daniel Kroening, Doron Peled, and Helmut Veith.

## Algorithm Description
The Double-DFS algorithm efficiently determines whether the language accepted by a Büchi automaton is empty. Specifically, it detects whether there exists a cycle containing an accepting state that is reachable from an initial state of the automaton.

The algorithm combines two depth-first searches:
1. **DFS1**: Explores all states reachable from the initial states
2. **DFS2**: Starting from accepting states found in DFS1, searches for cycles that return to these states

If a cycle is found, the automaton is not empty (it accepts some language). If no cycle is found, the automaton is empty.

## Implementation Details
- Language: C++
- Data Structures:
  - Graph representation using vectors of adjacency lists
  - Stacks for DFS traversal
  - Hash sets for tracking visited states
- The implementation uses recursive DFS functions for both searches

## Usage
The program reads input from a text file in the `input/` directory. The default input file is specified in the code (currently set to `./input/double_dfs4.txt`).

### Input Format
The input file should follow this format:
1. First line: Number of edges (e)
2. Next e lines: Source and target vertices of each edge (s t)
3. Next line: Number of initial states (ns)
4. Next ns lines: Initial state identifiers
5. Next line: Number of accepting states (nf)
6. Next nf lines: Accepting state identifiers

### Running the Program
Compile the C++ file and run the executable:
```
g++ -o double_dfs double_dfs.cpp
./double_dfs
```

To use a different input file, modify the file path in the code.

## Output
The program outputs one of the following:
- "Empty" if the automaton does not accept any language
- "Not empty" followed by the accepting cycle if the automaton accepts some language

## References
- Clarke, E. M., Grumberg, O., Kroening, D., Peled, D., & Veith, H. (2018). Model Checking, Second Edition. MIT Press.
