// IO.h
#ifndef IO_H
#define IO_H

#include <vector>
#include <string>
#include "Task.h"

class IO {
public:
    static std::vector<Task*> readTraceFile(const std::string& filename, MemoryManager& memoryManager);
};

#endif // IO_H