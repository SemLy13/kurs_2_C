#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <conio.h>
#include <stack>

using namespace std;

int prior(char v) {
    switch (v) {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}
bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool is_alpha(char c) {
    return c >= 'a' && c <= 'z';
}
void OPN(char* a, char* out) {
    stack <char> S;
    int i = 0, j = 0;
    char t;
    while (a[i] != '\0') {
        if (is_alpha(a[i])) {
            out[j] = a[i];
            j++;
        }
        else if (is_op(a[i])) {
            if (S.empty() || prior(S.top()) < prior(a[i])) {
                S.push(a[i]);
            }
            else if (prior(S.top()) >= prior(a[i])) {
                out[j] = S.top();
                S.pop();
                S.push(a[i]);
                j++;
            }
        }
        else if (a[i] == '(') {
            S.push(a[i]);
        }
        else if (a[i] == ')') {
            if (S.empty() || S.top() == '(') {
                cout << "Input error!";
                getch(); exit(1);
            }
            else {
                while (S.top() != '(') {
                    out[j] = S.top();
                    S.pop();
                    j++;
                }
            }
            S.pop();
        }
        i++;
    }
    while (!S.empty()) {
        if (S.top() == '(') {
            cout << "Input error!";
            getch(); exit(1);
        }
        else {
            out[j] = S.top();
            S.pop();
            j++;

        }
    }
}
int Calc(char* out) {
    int j = 0, c = 0, r1 = 0, r2 = 0;
    stack <double> S;
    stack <double> S1;
    while (out[j] != '\0') {
        if (out[j] >= 'a' && out[j] <= 'z') {
            cout << "\nEnter " << out[j] << ": "; cin >> c;
            S.push(c);
        }
        else if (is_op(out[j])) {
            r1 = S.top(); S.pop();
            r2 = S.top(); S.pop();
            switch (out[j]) {
                case '+': S.push(r2 + r1); break;
                case '-': S.push(r2 - r1); break;
                case '*': S.push(r2 * r1); break;
                case '/': S.push(r2 / r1); break;
            }
        }
        j++;
    }
    return (S.top());
}

int main() {
    char a[100] = { 0 };
    char out[100] = { 0 };
    stack <char> S;
    int i = 0;

    cout << "a: "; gets(a);

    OPN(a, out);

    cout << "out: " << out;

    cout << "answer: " << Calc(out);

    cout << "\nEnd.\n";
    getch();
    return 0;
}
