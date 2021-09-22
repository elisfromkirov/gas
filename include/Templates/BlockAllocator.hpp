#ifndef __BLOCK_ALLOCATOR_HPP__
#define __BLOCK_ALLOCATOR_HPP__

#include <new>
#include <utility>

template <class T>
struct BlockPointer {
    T*       pointer;
    uint32_t block;
};

template <uint32_t block_size>
class BlockAllocator {
public:
    BlockAllocator(uint32_t blocks_count);
    ~BlockAllocator();

    template <class T, class... Args>
    BlockPointer New(Args&& args);

    template <class T>
    void Delete(BlockPointer<T> block_pointer);

private:
    uint32_t* buffer_;
    uint32_t  blocks_count_;

    uint32_t  free_block_;
};

// -------------------------------------------------------------------------- //

template <uint32_t block_size>
BlockAllocator<block_size>::BlockAllocator(uint32_t blocks_count) 
    : buffer_{nullptr}, blocks_count_{blocks_count}, free_block_{0} {
    buffer_ = new uint32_t[blocks_count*block_size];
}

template <uint32_t block_size>
BlockAllocator<block_size>::~BlockAllocator() {
    delete buffer_;
}

template <uint32_t block_size>
template <class T, class... Args>
BlockPointer<T> BlockAllocator<block_size>::New(Args&& args) {
    uint32_t prev_free_block = buffer_[free_];

    T* pointer = new(buffer_ + free_) T(std::forward<Args>(args)...);
    BlockPointer<T> block_pointer{pointer, free_};

    free_ = prev_free_block;

    return block_pointer;
}

template <uint32_t block_size>
template <class T>
void BlockAllocator<block_size>::Delete(BlockPointer<T> block_pointer) {
    block_pointer->~T();

    buffer_[block_pointer.block] = free_;
    free_ = block_pointer.block;
}

#endif // __BLOCK_ALLOCATOR_HPP__
