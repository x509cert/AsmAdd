#include <iostream>
#include <stdbool.h>

// unsigned add with overflow check using the Carry flag
bool addWithOverflowCheck(unsigned int a, unsigned int b, _In_ unsigned int* result)
{
    bool overflow = false;

    __asm {
        mov eax, a
        add eax, b
        setc overflow
        mov ebx, result
        mov[ebx], eax
    }

    return overflow;
}

// signed add with overflow using the Overflow flag
bool addWithOverflowCheck(int a, int b, _In_ int* result)
{
    bool overflow = false;

    __asm {
        mov eax, a
        add eax, b
        seto overflow
        mov ebx, result
        mov[ebx], eax
    }

    return overflow;
}

int main() {
    unsigned int a1 = UINT32_MAX;
    unsigned int b1 = 1;
    unsigned int res1 = a1 + b1;
    bool overflow1 = addWithOverflowCheck(a1, b1, &res1);

    signed int a2 = INT32_MAX;
    signed int b2 = 1;
    signed int res2 = 0;
    bool overflow2 = addWithOverflowCheck(a2, b2, &res2);
}
