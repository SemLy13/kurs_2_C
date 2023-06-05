#include <iostream>

int strlen2(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int searchSubstr(const char* str, const char* substr) {
    const char* p1;
    const char* p2;
    int position = -1; // Переменная для хранения позиции подстроки

    p1 = str;
    p2 = substr;

    __asm {
        mov esi, str
        mov edi, substr
        mov ecx, 0
        mov edx, substr

        start_outer_loop :
        mov al, byte ptr[esi]
            cmp al, 0
            je end_outer_loop

            mov dl, byte ptr[edi]
            cmp dl, 0
            je end_outer_loop

            cmp al, dl
            jne continue_outer_loop

            mov edi, substr
            mov ebx, esi

            start_inner_loop :
        mov al, byte ptr[ebx]
            cmp al, 0
            je end_inner_loop

            mov dl, byte ptr[edi]
            cmp dl, 0
            je substring_not_found

            cmp al, dl
            jne substring_not_found

            inc ebx
            inc edi
            jmp start_inner_loop

            substring_not_found :
        mov position, -1 // Здесь используется переменная C++
            jmp end_outer_loop

            continue_outer_loop :
        inc esi
            mov ebx, esi
            jmp start_outer_loop

            end_inner_loop :
        mov eax, esi
            sub eax, str
            mov position, eax // И здесь тоже
            jmp end_outer_loop

            end_outer_loop :
    }

    return position;
}

int main() {
    const char* str = "Hello, World";
    const char* substr = "World1";
    int res = searchSubstr(str, substr);
    std::cout << res << std::endl;
    return 0;
}
