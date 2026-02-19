#include "Cache.h"
#include <iostream>

Cache::Cache(int c_size, int b_size, int assoc) {
    cache_size = c_size;
    block_size = b_size;
    associativity = assoc;

    int num_blocks = cache_size / block_size;
    num_sets = num_blocks / associativity;

    hit_count = 0;
    miss_count = 0;
    global_lru_counter = 0;

    cache.resize(num_sets, std::vector<CacheLine>(associativity));
}

void Cache::accessMemory(int address) {
    global_lru_counter++;

    int block_address = address / block_size;
    int index = block_address % num_sets;
    int tag = block_address / num_sets;

    // Check for HIT
    for (int i = 0; i < associativity; i++) {
        if (cache[index][i].valid && cache[index][i].tag == tag) {
            hit_count++;
            cache[index][i].lru_counter = global_lru_counter;
            return;
        }
    }

    // MISS
    miss_count++;

    // Find empty line
    for (int i = 0; i < associativity; i++) {
        if (!cache[index][i].valid) {
            cache[index][i].valid = true;
            cache[index][i].tag = tag;
            cache[index][i].lru_counter = global_lru_counter;
            return;
        }
    }

    // Replace using LRU
    int lru_index = 0;
    int min_lru = cache[index][0].lru_counter;

    for (int i = 1; i < associativity; i++) {
        if (cache[index][i].lru_counter < min_lru) {
            min_lru = cache[index][i].lru_counter;
            lru_index = i;
        }
    }

    cache[index][lru_index].tag = tag;
    cache[index][lru_index].lru_counter = global_lru_counter;
}

void Cache::printStats() {
    int total_accesses = hit_count + miss_count;

    double hit_rate = (double)hit_count / total_accesses;
    double miss_rate = (double)miss_count / total_accesses;

    int hit_time = 1;
    int miss_penalty = 50;

    double AMAT = hit_time + (miss_rate * miss_penalty);

    std::cout << "\n===== Cache Performance =====\n";
    std::cout << "Total Accesses: " << total_accesses << "\n";
    std::cout << "Hits: " << hit_count << "\n";
    std::cout << "Misses: " << miss_count << "\n";
    std::cout << "Hit Rate: " << hit_rate << "\n";
    std::cout << "Miss Rate: " << miss_rate << "\n";
    std::cout << "Average Memory Access Time (AMAT): " << AMAT << "\n";
}
