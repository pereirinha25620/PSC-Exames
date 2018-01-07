#include <stdio.h>

/**
 *  Algorithm: get the least significant bit (LSB) from value and compare with next.
 */

#define TRUE 1
#define FALSE 0
#define GET_LSB (value & 1)

int check_for_alt_bit(int value)
{
    int prev, cur;
    prev = GET_LSB;

    while (value > 0) {
        value >>= 1;
        cur = GET_LSB;

        if (prev == cur)
            return FALSE;
        
        prev = cur;
    }

    return TRUE;
}

int main() {
    printf("0x%x - %d\n", 0x0005, check_for_alt_bit(0x0005));
    printf("0x%x - %d\n", 0x00AA, check_for_alt_bit(0x00AA));
    printf("0x%x - %d\n", 0x8555, check_for_alt_bit(0x8555));
    printf("0x%x - %d\n", 0x1AAAA, check_for_alt_bit(0x1AAAA));
    printf("0x%x - %d\n", 0x2AAAA, check_for_alt_bit(0x2AAAA));
    printf("0x%x - %d\n", 0xAA4AA, check_for_alt_bit(0xAA4AA));
}
