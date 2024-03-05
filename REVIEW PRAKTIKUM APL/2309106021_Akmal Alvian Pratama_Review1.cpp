#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    char op;

    cout << "Masukkan angka pertama: ";
    cin >> num1;

    cout << "Masukkan operator (+ atau -): ";
    cin >> op;

    cout << "Masukkan angka kedua: ";
    cin >> num2;

    if (op == '+') {
        cout << "Hasil penambahan: " << num1 + num2;
    } else if (op == '-') {
        cout << "Hasil pengurangan: " << num1 - num2;
    } else {
        cout << "Operator tidak valid";
    }

    return 0;
}
