#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <cstddef>

enum {
    BIT_ZERO = 0,
    BIT_ONE = 1,
    BYTE = 8,
    // sizeof(size_t) = 8 bytes
    BITS_COUNT = 8 * sizeof(std::size_t) // 64 bit spaces
};

namespace skt {

class BitVector 
{
public:
    BitVector();
    BitVector(const std::size_t size);
    ~BitVector();

public:
    void set(const std::size_t index, const bool value);
    bool get(const std::size_t index);
    void show();

private:
    std::size_t *m_ptr;
    std::size_t m_capacity;
    std::size_t m_size;

}; // class end - BitVector

} // namespace end - skt

#endif // BITVECTOR_H