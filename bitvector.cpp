#include "bitvector.h"

#include <iostream>

///////////////////////////////// Constructors /////////////////////////////////
skt::BitVector::BitVector()
    : m_ptr{}
    , m_capacity{}
    , m_size{}
{}

skt::BitVector::BitVector(const std::size_t size)
    : m_ptr{}
    , m_capacity{}
    , m_size{size}
{
    if (size) {
        while (m_capacity < size) {
            m_capacity += BITS_COUNT; // Minimum 64 spaces, after every 65th bit adds up 64 again
        }
        // Every array cell will contain 64 bits.
        // After counting capacity, calculate how many cells to create by CAPACITY / BITS_COUNT 
        m_ptr = new size_t[m_capacity / BITS_COUNT];

        for (int i = 0; i < m_capacity / BITS_COUNT; ++i) {
            m_ptr[i] = 0;
        }
    }
}

skt::BitVector::~BitVector() 
{
    delete m_ptr;
    m_ptr = nullptr;
}


///////////////////////////////// Functions /////////////////////////////////
void skt::BitVector::set(const std::size_t index, const bool value) {
    if (m_ptr) {
        if (index <= m_size) {
            if (value) {
                // index/BITS_COUNT will show position of the array
                m_ptr[index / BITS_COUNT] ^= (BIT_ONE << (index % m_size)); // set bit to ONE
            }
            else {
                 m_ptr[index / BITS_COUNT] &= ~(BIT_ONE << (index % m_size)); // set bit to ZERO
            }
        }
    }
}

bool skt::BitVector::get(const std::size_t index) {
    return m_ptr[index / BITS_COUNT] & (BIT_ONE << (index % m_size)); // check a bit
}

void skt::BitVector::show() {
    if (m_ptr) {
        for (int i = 0; i < m_capacity / BITS_COUNT; ++i) {
            std::size_t number = BIT_ONE; // number will start from 1, then -> 2 -> 4 -> 8 so on till 64
            for (int j = 1; j <= BITS_COUNT; ++j) {
                bool bit = (bool) (m_ptr[i] & number);
                std::cout << bit << " ";
                number <<= 1;
                if (!(j % BYTE)) { // enter after every byte
                    std::cout << "\n";
                }
            }
        }
    }
}