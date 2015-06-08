// https://leetcode.com/problems/reverse-bits/
static unsigned char lookup[16] = {
    0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
    0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf,
};

class Solution {
public:
    uint8_t reverse(uint8_t n) {
       // Reverse the top and bottom nibble then swap them.
       return (lookup[n&0b1111] << 4) | lookup[n>>4];
    }
    uint32_t reverseBits(uint32_t n) {
        n = __builtin_bswap32(n);
        uint8_t* start = reinterpret_cast<uint8_t*>(&n);
        uint8_t* end = start + sizeof(uint32_t);
        while (start != end) {
            *start = reverse(*start);
            ++start;
        }
        return n;
    }
};

