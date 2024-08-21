#include <iostream>
#include "MemoryManager.h"
#include "Task.h"
#include "Performance.h"
#include "IO.h"
#include "Test.h"

int main() {
    MemoryManager memoryManager;

    // Generate test trace file
    Test::generateTraceFile("trace.txt", 5);

    // Read trace file and create tasks
    std::vector<Task*> tasks = IO::readTraceFile("tracefile_1KB_8GB_16GB.txt", memoryManager);

    // Report memory usage
    Performance::reportMemoryUsage(memoryManager, tasks);

    // Clean up
    for (Task* task : tasks) {
        delete task;
    }

    return 0;
}
