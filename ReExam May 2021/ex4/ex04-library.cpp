#include "ex04-library.h"
#include <queue>


// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods
FilteringBuffer::FilteringBuffer(int v) {
    this->def = v;
}

// Task 4(b).  Write a working implementation of write() and occupancy()
void FilteringBuffer::write(int v) {
    const bool is_in = this->hist.find(v) != this->hist.end();
    if(is_in){
        return;
    }

    this->buffer.push(v);
    this->hist.insert(v);
}

unsigned int FilteringBuffer::occupancy() {
    return this->buffer.size();
}

// Task 4(c).  Write a working implementation of read()
int FilteringBuffer::read() {
    if(this->buffer.empty()){
        return this->def;
    }

    int v = this->buffer.front();
    this->buffer.pop();
    return v;
}

// Task 4(d).  Write a working implementation of reset()
void FilteringBuffer::reset() {
    std::queue<int> empty;
    std::swap( this->buffer, empty );

    std::set<int> emptySet;
    std::swap( this->hist, emptySet );
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}