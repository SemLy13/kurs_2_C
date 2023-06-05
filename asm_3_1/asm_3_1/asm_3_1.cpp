/*#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int laba_3_1(int n) {
    int sum = 1; //0
    int digit;
    __asm {
        mov eax, n
        xor ebx, ebx
        xor ecx, ecx
        start :
        cmp eax, 1 //0
            jle end_label
            mov ebx, 10
            xor edx, edx
            div ebx
            mov ecx, edx
            imul ecx, ecx
           // add sum, ecx
            mov edx, sum
            imul edx, ecx
            mov sum, edx
            jmp start
            end_label :
    }
    return sum;
}
bool laba_3_3(int number) {
    std::string num_str = std::to_string(number);
    std::set<char> unique_digits;
    bool result = true;

    __asm {
        mov esi, num_str   // Загружаем указатель на строку num_str в регистр esi
        mov edi, 0         // Инициализируем счетчик уникальных цифр нулем
        mov ecx, 2         // Устанавливаем предельное значение счетчика уникальных цифр

        // Цикл для обхода каждого символа в строке num_str
        start:
        mov al, byte ptr[esi]    // Загружаем текущий символ в регистр al
            cmp al, 0                 // Проверяем, является ли символ нулевым (конец строки)
            je end_label              // Если символ нулевой, выходим из цикла

            // Проверяем, есть ли текущий символ во множестве unique_digits
            mov edx, 0                // Инициализируем флаг присутствия символа во множестве нулем
            mov edi, unique_digits    // Загружаем указатель на множество unique_digits в регистр edi
            repne scasb               // Сравниваем символ в al с символами в множестве unique_digits
            jnz unique                // Если символ отсутствует, переходим к метке unique

            // Символ уже присутствует во множестве unique_digits
            mov result, 0             // Устанавливаем флаг результата в ноль
            jmp end_label             // Выходим из цикла

            // Символ уникален и добавляем его во множество unique_digits
            unique :
        mov byte ptr[edi], al     // Добавляем символ в множество unique_digits
            inc edi                    // Увеличиваем указатель на множество unique_digits
            inc ecx                    // Увеличиваем счетчик уникальных цифр

        // Переходим к следующему символу
            inc esi

            // Проверяем, достигнуто ли предельное значение счетчика уникальных цифр
            cmp ecx, 2
            jl start

            end_label :
    }

    return result;
}

void output(int res) {

    ofstream file("output.txt");
    if (file.is_open()) {
        file << res;
        file.close();
    }
    else {
        cout << "Error" << endl;
    }
}

int main() {

    int number = 12120;
    cout << "Number: " << number << endl;
    int lower = number, upper = number;
    while (!laba_3_3(lower) and !laba_3_3(upper)) {
        lower--;
        upper++;
    }

    if (laba_3_3(lower)) {
        cout << lower << endl;
    }
    else {
        cout << upper << endl;
    }


    int num, k, result;
    ifstream file("input.txt");
    if (file.is_open()) {
        file >> num >> k;
        cout << "N: " << num << endl;
        cout << "K: " << k << endl;
        file.close();
    }
    else {
        cout << "Error" << endl;
    }
    for (int i = 0; i < k; i++) {
        result = laba_3_1(num);
        num = result;
    }
    cout << "Result: " << result << endl;
    output(result);

    return 0;
}*/

#include <iostream>

int findNearestDvojakoe(int N) {
    int result;

    __asm {
        mov eax, %[N]
        mov ebx, 2
        start:
        call check_dvojakoe
            cmp ecx, 1
            je end
            sub eax, 1
            jmp start
            end :
        mov %[result], eax
            : "=r" (result)
            : "r" (N)
            : "eax", "ebx", "ecx"
    }

    return result;
}

int checkDvojakoe(int num) {
    int digits[10] = {0};
    int count = 0;

    while (num > 0) {
        int digit = num % 10;
        digits[digit] = 1;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (digits[i] == 1) {
            count++;
        }
    }

    return count <= 2 ? 1 : 0;
}

int main() {
    int N;
    std::cout << "Enter a natural number: ";
    std::cin >> N;

    int nearestDvojakoe = findNearestDvojakoe(N);
    std::cout << "Nearest Dvojakoe number to " << N << ": " << nearestDvojakoe << std::endl;

    return 0;
}
