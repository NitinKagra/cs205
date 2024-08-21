// Task.h
#ifndef TASK_H
#define TASK_H

#include <vector>
#include <unordered_map>
#include "MemoryManager.h"
#include "config.h"

class Task {
public:
    Task(MemoryManager& memoryManager);
    void allocateMemory(uint32_t logicalAddress, uint32_t size);
    uint32_t getPageHits() const;
    uint32_t getPageMisses() const;

private:
    MemoryManager& memoryManager;
    std::unordered_map<uint32_t, uint32_t> pageTable; // Simple map-based page table
    uint32_t pageHits;
    uint32_t pageMisses;
};

#endif // TASK_H
