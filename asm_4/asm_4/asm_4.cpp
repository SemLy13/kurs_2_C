#include <iostream>

int laba_4_1_1(signed char arr[], int n) {
    int count = 0;//1
    __asm {
        mov ecx, n
        mov edi, arr
        xor eax, eax
        xor ebx, ebx
        dec ecx

        start :
        cmp byte ptr[edi + ebx], 0
            jns next//js
            inc count
            next :
        inc ebx
            loop start
    }
    return count;
}
signed char laba_4_2_1(signed char arr[], int n) {
    signed char maxElement = arr[0];
    __asm {
        mov ecx, n
        mov edi, arr
        movsx eax, byte ptr[edi]  // Загрузка первого элемента массива в eax с расширением знака
        mov maxElement, al  // Сохранение первого элемента как текущий максимальный
        dec ecx

        start :
        inc edi
            cmp ecx, 0
            jle endLabel
            movsx eax, byte ptr[edi]  // Загрузка текущего элемента массива в eax с расширением знака
            cmp al, maxElement  // Сравнение текущего элемента с максимальным
            jle next  //jge Если текущий элемент меньше или равен максимальному, перейти к следующему
            mov maxElement, al  // Обновление максимального элемента
            next :
        dec ecx
            jmp start

            endLabel :
    }
    return maxElement;
}

int main() {
    signed char arr[] = { -10, 20, -30, 40, -50, 60, -70, 80, -90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int Result = laba_4_1_1(arr, n);
    std::cout << "Result: " << Result << std::endl;

    signed char maxElement = laba_4_2_1(arr, n);
    std::cout << "Max: " << static_cast<int>(maxElement) << std::endl;
    return 0;
}