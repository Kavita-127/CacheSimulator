#ifndef CACHE_H
#define CACHE_H

#include <vector>

struct CacheLine {
    bool valid;
    int tag;
    int lru_counter;

    CacheLine() {
        valid = false;
        tag = -1;
        lru_counter = 0;
    }
};

class Cache {
private:
    int cache_size;
    int block_size;
    int associativity;
    int num_sets;

    int hit_count;
    int miss_count;
    int global_lru_counter;

    std::vector<std::vector<CacheLine>> cache;

public:
    Cache(int c_size, int b_size, int assoc);

    void accessMemory(int address);
    void printStats();
};

#endif
