#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

const int maks_percobaan = 3;

struct User {
    string username;
    string password;
};

bool login(const vector<User>& users);

const int maks_kostum = 10;

struct Kostum {
    string nama;
    bool tersedia;
};

vector<Kostum> kostum(maks_kostum);
int jumlah_kostum = 0;

void tambah_kostum(const string& nama) {
    if (jumlah_kostum < maks_kostum) {
        kostum[jumlah_kostum].nama = nama;
        kostum[jumlah_kostum].tersedia = true;
        jumlah_kostum++;
        cout << "Kostum berhasil ditambah.\n";
    } else {
        cout << "Tidak bisa menambah kostum. Pesanannya penuh.\n";
        return;
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

string menu2() {
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

void menu() {
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

bool login(const vector<User>& users) {
    string input_username, input_password;

    for (int percobaan = 0; percobaan < maks_percobaan; ++percobaan) {
        cout << "Masukkan username: ";
        getline(cin, input_username);
        cout << "Masukkan password: ";
        getline(cin, input_password);

        for (const auto& user : users) {
            if (input_username == user.username && input_password == user.password) {
                cout << "Login sukses!\n";
                return true;
            }
        }
        cout << "Username atau password tidak valid. Sisa percobaan: " << maks_percobaan - percobaan - 1 << endl;
    }

    cout << "Anda melebihi batas percobaan. Keluar dari program." << endl;
    return false;
}

int main() {
    vector<User> users = {{"Muhammad Dzacky", "2309106101"}};

    if (login(users)) {
        menu();
    }

    return 0;
}