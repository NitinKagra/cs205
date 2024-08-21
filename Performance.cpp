// Performance.cpp
#include "Performance.h"
#include <iostream>

void Performance::reportMemoryUsage(const MemoryManager& memoryManager, const std::vector<Task*>& tasks) {
    uint32_t totalMemoryUsed = 0;
    uint32_t pageTableMemory = 0;

    for (const Task* task : tasks) {
        totalMemoryUsed += task->getPageMisses() * PAGE_SIZE;
        pageTableMemory += task->getPageHits() * sizeof(uint32_t); // Assuming 4 bytes per entry
    }

    std::cout << "Total Memory Used: " << totalMemoryUsed << " bytes" << std::endl;
    std::cout << "Memory Used for Page Tables: " << pageTableMemory << " bytes" << std::endl;
    std::cout << "Free Physical Memory: " << memoryManager.getFreePagesCount() * PAGE_SIZE << " bytes" << std::endl;
}