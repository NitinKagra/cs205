// Task.cpp
#include "Task.h"

Task::Task(MemoryManager& memoryManager) : memoryManager(memoryManager), pageHits(0), pageMisses(0) {}

void Task::allocateMemory(uint32_t logicalAddress, uint32_t size) {
    uint32_t numPages = (size + PAGE_SIZE - 1) / PAGE_SIZE;
    for (uint32_t i = 0; i < numPages; ++i) {
        uint32_t logicalPage = (logicalAddress + i * PAGE_SIZE) / PAGE_SIZE;
        if (pageTable.find(logicalPage) != pageTable.end()) {
            ++pageHits;
        } else {
            uint32_t physicalPage = memoryManager.allocatePage();
            pageTable[logicalPage] = physicalPage;
            ++pageMisses;
        }
    }
}

uint32_t Task::getPageHits() const {
    return pageHits;
}

uint32_t Task::getPageMisses() const {
    return pageMisses;
}