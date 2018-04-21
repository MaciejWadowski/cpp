//
// Created by wadziuxxx on 4/20/18.
//

#include "MemoryChunk.h"

using namespace memorychunk;

MemoryChunk::MemoryChunk(size_t sz) {
    memory_block = new int8_t[sz];
    memory_size = sz;
}

MemoryChunk::MemoryChunk(const MemoryChunk &object): memory_block(new int8_t[object.memory_size]), memory_size(object.memory_size) {
    std::copy(object.memory_block, object.memory_block + object.memory_size, memory_block);
}

MemoryChunk &MemoryChunk::operator=(const MemoryChunk &object) {
    if(this == &object) return *this;
    delete [] memory_block;
    memory_size = object.memory_size;
    memory_block = new int8_t[memory_size];
    std::copy(object.memory_block, object.memory_block + object.memory_size, memory_block);
    return *this;
}

MemoryChunk::MemoryChunk(MemoryChunk &&object) noexcept : memory_block(nullptr), memory_size(0) {
    swap(*this, object);
}

MemoryChunk &MemoryChunk::operator=(MemoryChunk &&object) {
    if(this == &object) return *this;
    delete [] memory_block;
    memory_block = nullptr;
    swap(*this, object);
}

MemoryChunk::~MemoryChunk() {
    delete [] memory_block;
    memory_size = 0;
}

int8_t *MemoryChunk::MemoryAt(size_t offset) const {
    if(&memory_block[offset]) return &memory_block[offset];
    return nullptr;
}

size_t MemoryChunk::ChunkSize() const {
    return memory_size;
}

void memorychunk::swap(MemoryChunk &o1, MemoryChunk &o2) noexcept {
    std::swap(o1.memory_block, o2.memory_block);
    std::swap(o1.memory_size, o2.memory_size);
}
