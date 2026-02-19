#include <iostream>
#include "Cache.h"

int main() {
    int cache_size, block_size, associativity;
    int num_accesses;

    std::cout << "Enter cache size (bytes): ";
    std::cin >> cache_size;

    std::cout << "Enter block size (bytes): ";
    std::cin >> block_size;

    std::cout << "Enter associativity (1 for Direct Mapped): ";
    std::cin >> associativity;

    Cache myCache(cache_size, block_size, associativity);

    std::cout << "Enter number of memory accesses: ";
    std::cin >> num_accesses;

    std::cout << "Enter memory addresses:\n";

    for (int i = 0; i < num_accesses; i++) {
        int address;
        std::cin >> address;
        myCache.accessMemory(address);
    }

    myCache.printStats();

    return 0;
}
