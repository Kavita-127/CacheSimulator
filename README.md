# Cache Memory Simulator in C++

## Project Overview

This project is a simple Cache Memory Simulator built using C++.  
It was developed to understand how cache memory works in computer architecture.

The simulator allows the user to configure:
- Cache size
- Block size
- Associativity (1 = Direct Mapped, >1 = Set Associative)

It then simulates memory accesses and calculates cache performance.

---

## What This Project Demonstrates

- Understanding of cache architecture
- Direct-mapped and set-associative mapping
- LRU (Least Recently Used) replacement policy
- Performance metrics such as:
  - Cache Hits
  - Cache Misses
  - Hit Rate
  - Miss Rate
  - Average Memory Access Time (AMAT)

---

## How the Simulator Works

For each memory address:
1. The address is divided into block address.
2. Index and tag are calculated.
3. The simulator checks whether it is a hit or miss.
4. If needed, LRU policy replaces the least recently used block.

---

## How to Compile and Run

### Compile
g++ -std=c++17 main.cpp Cache.cpp -o cache

### Run (Linux/Mac)
./cache

### Run (Windows)
cache.exe

---

## Sample Input

Cache size: 16  
Block size: 4  
Associativity: 1  
Memory accesses:  
0 16 32 48 0 16 32 48  

---

## Learning Outcome

Through this project, I gained practical understanding of:

- Memory hierarchy concepts
- Conflict and capacity misses
- Impact of associativity on performance
- Architectural trade-offs in cache design

