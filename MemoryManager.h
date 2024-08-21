// MemoryManager.h
#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <unordered_map>
#include <cstdint>
#include "config.h"

class MemoryManager {
public:
    MemoryManager();
    uint32_t allocatePage(); // Returns the physical page number
    void deallocatePage(uint32_t page_number);
    uint32_t getFreePagesCount() const;

private:
    std::vector<bool> freePages; // Bitmap to track free/used pages
};

#endif // MEMORY_MANAGER_H