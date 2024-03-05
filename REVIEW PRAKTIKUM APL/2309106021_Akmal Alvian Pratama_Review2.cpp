#include <iostream>
#include <limits>

using namespace std;

int main() {
    // Deklarasi array dengan 5 elemen
    int angka[5];

    // Memasukkan nilai ke dalam array
    cout << "Masukkan 5 angka:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Angka ke-" << i + 1 << ": ";

        // Looping hingga pengguna memasukkan angka yang valid
        while (!(cin >> angka[i])) {
            // Membersihkan buffer input yang error
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Mohon masukkan angka.\n";
            cout << "Angka ke-" << i + 1 << ": ";
        }
    }

    // Menampilkan isi array
    cout << "\nAngka yang dimasukkan:\n";
    for (int i = 0; i < 5; ++i) {
        cout << angka[i] << " ";
    }
    cout << endl;

    return 0;
}