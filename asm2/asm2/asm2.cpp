#include <iostream>
#include <cstdint>

bool is_prime(uint32_t number) {
    if (number < 2) return false;
    if (number == 2) return true;

    uint32_t limit = number;
    uint32_t divisor;
    bool prime;

    _asm {
        mov ecx, number
        shr ecx, 1
        add ecx, 1
        mov prime, 1
        mov divisor, 2
        jmp check_divisor

        next_divisor :
        add divisor, 1
            cmp divisor, ecx
            jge is_prime

            check_divisor :
        mov eax, number
            cdq
            div divisor
            cmp edx, 0
            je not_prime
            jmp next_divisor

            not_prime :
        mov prime, 0

            is_prime :
    }

    return prime;
}

uint32_t count_primes_in_range(uint32_t n) {
    uint32_t count = 0;
    for (uint32_t i = n; i <= 2 * n; ++i) {
        if (is_prime(i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    uint32_t n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    uint32_t prime_count = count_primes_in_range(n);
    std::cout << "Number of prime numbers between " << n << " and " << (2 * n) << " is: " << prime_count << std::endl;

    return 0;
}
