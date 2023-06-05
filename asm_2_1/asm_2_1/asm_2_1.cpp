#include <iostream>
using namespace std;

bool isPrime(int num) {
    bool res;
    __asm {
        mov eax, num
        sub eax, 2
        mov eax, eax
        mov ecx, eax
        mov ebx, 2
        repeat:
        mov eax, num
            cdq
            div ebx
            cmp edx, 0
            je done
            inc ebx
            loop repeat;
        mov al, 1
            jmp exit1
            done :
        mov al, 0
            jmp exit1
            exit1 :
        mov res, al
    }
    return res;
}
void laba2_3(int n,int m) {
    int a1, a2, count = 0;
    for (int i = n; i < m; i++) {
        a1 = i;
        a2 = a1 + 2;
        if (isPrime(a1) && isPrime(a2)) {
            count += 1;
            cout << a1 << " " << a2 << endl;
        }
    }
    cout << count;
}

void laba2_1(int n1) {
    int sum = 0;
    int n2 = n1 * 2;
    while (n1 < n2) {
        if (isPrime(n1)) {
            sum++;
            cout << n1 << endl;
        }
        n1++;
    }
    cout << sum;
}

int main()
{
    laba2_3(2, 10);
    cout << endl;
    cout << endl;
    laba2_1(5);
}