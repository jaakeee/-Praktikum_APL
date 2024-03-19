#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int maks_percobaan = 3;

bool login();

const int maks_kostum = 10;

struct status_kostum {
    string nama;
    bool tersedia;
};

status_kostum kostum[maks_kostum];
int jumlah_kostum = 0;

void tambah_kostum(const string& nama) {
    if (jumlah_kostum < maks_kostum) {
        kostum[jumlah_kostum].nama = nama;
        kostum[jumlah_kostum].tersedia = true;
        jumlah_kostum++;
        cout << "Kostum berhasil ditambah.\n";
    } else {
        cout << "Tidak bisa menambah kostum. Pesanannya penuh.\n";
    }
    char ulang;
    cout << "ingin menambhakan kostum lagi? (y/n)";
    cin >> ulang;
    if (ulang == 'y' || ulang == 'Y') {
        string nama_baru;
        cout << "Masukkan nama kostum baru: ";
        cin >> nama_baru;
        tambah_kostum(nama_baru);
    }
}

void lihat_kostum() {
    cout << "Kostum:\n";
    for (int i = 0; i < jumlah_kostum; ++i) {
        cout << "Nama: " << kostum[i].nama << ", Tersedia: " << (kostum[i].tersedia ? "Yes" : "No") << "\n";
    }
    cout << "Tekan apapun untuk lanjut" << endl;
    getch();
}

void ketersediaan_kostum(const string& nama, bool tersedia) {
    cout << "Kostum:\n";
    for (int i = 0; i < jumlah_kostum; ++i) {
        if (kostum[i].nama == nama) {
            kostum[i].tersedia = tersedia;
            cout << "Ketersediaan kostum berhasil diubah.\n";
            return;
        }
    }
    cout << "Kostum tidak ditemukan.\n";
}

void hapus_kostum(const string& nama) {
    for (int i = 0; i < jumlah_kostum; ++i) {
        if (kostum[i].nama == nama) {
            for (int j = i; j < jumlah_kostum - 1; ++j) {
                kostum[j] = kostum[j + 1];
            }
            jumlah_kostum--;
            cout << "Kostum berhasil dihapus.\n";
            return;
        }
    }
    cout << "Kostum tidak ditemukan.\n";
}

string menu2(){
    return "Menu\n"
           "------------------------\n"
           "1. Tambah Kostum\n"
           "2. Lihat Kostum\n"
           "3. Ketersediaan Kostum\n"
           "4. Hapus Kostum\n"
           "5. Keluar\n"
           "------------------------\n"
           "Masukkan Pilihan: ";
}

void menu(){
    int pilihan;
    string nama;
    while (true) {
        cout << menu2();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama kostum: ";
                getline(cin, nama);
                tambah_kostum(nama);
                break;
            case 2:
                lihat_kostum();
                break;
            case 3:
                lihat_kostum();
                cout << "Masukkan nama kostum: ";
                cin >> nama;
                bool tersedia;
                cout << "Apakah tersedia? (1 = iya, 0 = tidak): ";
                cin >> tersedia;
                ketersediaan_kostum(nama, tersedia);
                break;
            case 4:
                lihat_kostum();
                cout << "Masukkan nama kostum: ";
                cin >> nama;
                hapus_kostum(nama);
                break;
            case 5:
                cout << "Keluar...\n";
                return;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    }
} 

bool login() {
    string usernames[] = {"Muhammad Dzacky"};
    string passwords[] = {"2309106101"};

    int percobaan = 0;

    while (percobaan < maks_percobaan) {
        string input_username, input_password;
        cout << "Masukkan username: ";
        getline(cin, input_username);
        cout << "Masukkan password: ";
        getline(cin, input_password);
        
        for (int i = 0; i < 1; ++i) {
            if (input_username == usernames[i] && input_password == passwords[i]) {
                cout << "Login sukses!\n";
                return true;
            } else {
                ++percobaan;
                cout << "Username atau password tidak valid. Sisa percobaan: " << maks_percobaan - percobaan << endl;
            }
        }
    }
    
    cout << "Anda melebihi batas percobaan. Keluar dari program." << endl;
    return false;
}

int main() {
    if (login()) {
        menu();
    }
    
    return 0;
}
