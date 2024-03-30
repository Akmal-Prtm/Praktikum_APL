#include <iostream>
#include <string>
#include <vector>
#include <limits> // Untuk membersihkan buffer

using namespace std;

// Struct untuk menyimpan data spesifikasi motor
struct Spesifikasi {
    string warna;
    int cc;
};

// Struct untuk menyimpan data motor Honda
struct DataMotor {
    string merk;
    string tipe;
    int tahun;
    Spesifikasi spesifikasi;
};

// ANSI escape codes untuk warna teks
const string GREEN = "\033[1;32m";
const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string RESET = "\033[0m";

// Fungsi untuk membersihkan buffer
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape code untuk membersihkan layar
}

// Fungsi untuk melakukan login
bool login() {
    string username, password;
    const string correct_username = "akmal_alvian_pratama";
    const string correct_password = "2309106021";
    const int max_attempts = 3;
    int attempts = 0;

    do {
        cout << "Masukkan Username: "<< BLUE;
        cin >> username;    
        cout << RESET << "Masukkan Password: "<< BLUE;
        cin >> password;

        if (username == correct_username && password == correct_password) {
            cout << GREEN << "Login berhasil.\n" << RESET;
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(); // Menunggu sampai pengguna menekan Enter
            cin.get();
            return true;
        } else {
            cout << RED << "Login gagal. Silakan coba lagi.\n" << RESET;
            attempts++;
        }
    } while (attempts < max_attempts);

    cout << RED << "Anda telah melebihi batas percobaan login. Program berhenti.\n" << RESET;
    return false;
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    clearScreen();
    cout << YELLOW << "Menu:\n";
    cout << "1. Tambah Data Motor\n";
    cout << "2. Lihat Data Motor\n";
    cout << "3. Edit Data Motor\n";
    cout << "4. Hapus Data Motor\n";
    cout << "5. Keluar\n" << RESET;
}

// Fungsi untuk menambah data motor ke dalam array
void tambahData(vector<DataMotor>& dataMotor) {
    DataMotor motor;
    cout << RESET << "Masukkan Merk Motor: ";
    getline(cin, motor.merk);
    cout << "Masukkan Tipe Motor: ";
    getline(cin, motor.tipe);
    cout << "Masukkan Tahun Produksi: ";
    while (!(cin >> motor.tahun)) {
        cout << RED << "Input tahun tidak valid. Masukkan tahun kembali: " << RESET;
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    cout << "Masukkan Warna Motor: ";
    getline(cin, motor.spesifikasi.warna);
    cout << "Masukkan Kapasitas Mesin (cc): ";
    while (!(cin >> motor.spesifikasi.cc)) {
        cout << RED << "Input kapasitas mesin tidak valid. Masukkan cc kembali: " << RESET;
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    dataMotor.push_back(motor);
    cout << GREEN << "\nData motor berhasil ditambahkan.\n" << RESET;
}

// Fungsi untuk menampilkan data motor yang ada dalam array
void lihatData(const vector<DataMotor>& dataMotor) {
    clearScreen();
    if (dataMotor.empty()) {
        cout << RESET << "Tidak ada data motor.\n";
        return;
    }
    cout << YELLOW << "Data Motor Honda:\n" << RESET;
    for (size_t i = 0; i < dataMotor.size(); ++i) {
        cout << "Data ke-" << i + 1 << ":\n";
        cout << "  Merk: " << dataMotor[i].merk << endl;
        cout << "  Tipe: " << dataMotor[i].tipe << endl;
        cout << "  Tahun: " << dataMotor[i].tahun << endl;
        cout << "  Spesifikasi:\n";
        cout << "    Warna: " << dataMotor[i].spesifikasi.warna << endl;
        cout << "    CC: " << dataMotor[i].spesifikasi.cc << endl;
    }
}

// Fungsi untuk mengedit data motor yang ada dalam array
void editData(vector<DataMotor>* dataMotor) {
    lihatData(*dataMotor);
    if (dataMotor->empty()) {
        cout << RED << "Tidak ada data motor untuk diedit.\n" << RESET;
        return;
    }
    int index;
    cout << RESET << "Masukkan nomor data motor yang ingin diedit: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataMotor->size())) {
        cout << RED << "Nomor tidak valid. Masukkan nomor kembali: " << RESET;
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int

    DataMotor& motor = (*dataMotor)[index - 1];
    cout << "Masukkan Merk Motor yang baru: ";
    getline(cin, motor.merk);
    cout << "Masukkan Tipe Motor yang baru: ";
    getline(cin, motor.tipe);
    cout << "Masukkan Tahun Produksi yang baru: ";
    while (!(cin >> motor.tahun)) {
        cout << RED << "Input tahun tidak valid. Masukkan tahun kembali: " << RESET;
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    cout << "Masukkan Warna Motor yang baru: ";
    getline(cin, motor.spesifikasi.warna);
    cout << "Masukkan Kapasitas Mesin (cc) yang baru: ";
    while (!(cin >> motor.spesifikasi.cc)) {
        cout << RED << "Input kapasitas mesin tidak valid. Masukkan cc kembali: " << RESET;
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int
    cout << GREEN << "\nData motor berhasil diubah.\n" << RESET;
}

// Fungsi untuk menghapus data motor dari array
void hapusData(vector<DataMotor>* dataMotor) {
    lihatData(*dataMotor);
    if (dataMotor->empty()) {
        cout << RED << "Tidak ada data motor untuk dihapus.\n" << RESET;
        return;
    }
    int index;
    cout << RESET << "Masukkan nomor data motor yang ingin dihapus: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataMotor->size())) {
        cout << RED << "Nomor tidak valid. Masukkan nomor kembali: " << RESET;
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer setelah menerima input int

    dataMotor->erase(dataMotor->begin() + index - 1);
    cout << GREEN << "Data motor berhasil dihapus.\n" << RESET;
}

int main() {
    vector<DataMotor> dataMotor;
    char opsi;

    if (!login()) {
        return 1; // Keluar dari program jika login gagal
    }

    do {
        displayMenu();
        cout << "\nMasukkan pilihan: "<< BLUE;
        cin >> opsi;
        clearBuffer(); // Membersihkan buffer setelah menerima input char

        switch (opsi) {
            case '1':
                tambahData(dataMotor);
                break;
            case '2':
                lihatData(dataMotor);
                break;
            case '3':
                editData(&dataMotor);
                break;
            case '4':
                hapusData(&dataMotor);
                break;
            case '5':
                cout << YELLOW << "Program berhenti.\n" << RESET;
                break;
            default:
                cout << RED << "Pilihan tidak valid.\n" << RESET;
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore(); // Menunggu sampai pengguna menekan Enter
        cin.get();
    } while (opsi != '5');

    return 0;
}