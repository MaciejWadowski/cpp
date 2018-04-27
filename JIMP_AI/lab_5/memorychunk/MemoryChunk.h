//
// Created by wadziuxxx on 4/20/18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>
#include <iostream>

namespace memorychunk{
    class MemoryChunk{
    public:
        MemoryChunk(size_t sz);
        MemoryChunk(const MemoryChunk& object);
        MemoryChunk & operator=(const MemoryChunk& object);
        MemoryChunk(MemoryChunk &&object) noexcept ;
        MemoryChunk & operator=(MemoryChunk &&object);
        ~MemoryChunk();
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;
        friend void swap(MemoryChunk &o1, MemoryChunk &o2) noexcept ;
    private:
        int8_t  *memory_block;
        size_t  memory_size;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
