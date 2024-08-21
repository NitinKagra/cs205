// Performance.h
#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include "MemoryManager.h"
#include "Task.h"
#include <vector>

class Performance {
public:
    static void reportMemoryUsage(const MemoryManager& memoryManager, const std::vector<Task*>& tasks);
};

#endif // PERFORMANCE_H