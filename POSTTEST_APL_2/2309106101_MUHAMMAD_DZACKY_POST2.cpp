#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

const int maks_percobaan = 3;

bool login(string username, string password);

void delay(int detik) {
    this_thread::sleep_for(chrono::seconds(detik));
}

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
        delay(2);
    } else {
        cout << "Tidak bisa menambah kostum. Pesanannya penuh.\n";
        delay(2);
    }
}

void lihat_kostum() {
    cout << "Kostum:\n";
    for (int i = 0; i < jumlah_kostum; ++i) {
        cout << "Nama: " << kostum[i].nama << ", Tersedia: " << (kostum[i].tersedia ? "Yes" : "No") << "\n";
        delay(2);
    }
}

void ketersediaan_kostum(const string& nama, bool tersedia) {
    for (int i = 0; i < jumlah_kostum; ++i) {
        if (kostum[i].nama == nama) {
            kostum[i].tersedia = tersedia;
            cout << "Ketersediaan kostum berhasil diubah.\n";
            return;
        }
    }
    cout << "Kostum tidak ditemukan.\n";
    delay(2);
}

void hapus_kostum(const string& nama) {
    for (int i = 0; i < jumlah_kostum; ++i) {
        if (kostum[i].nama == nama) {
            // guna menggeser array untuk tidak kosong
            for (int j = i; j < jumlah_kostum - 1; ++j) {
                kostum[j] = kostum[j + 1];
            }
            jumlah_kostum--;
            cout << "Kostum berhasil dihapus.\n";
            return;
        }
    }
    cout << "Kostum tidak ditemukan.\n";
    delay(2);
}

int main() {
    string usernames[] = {"Muhammad Dzacky"};
    string passwords[] = {"2309106101"};

    int percobaan = 0;

    while (percobaan < maks_percobaan) {
        string input_username, input_password;
        cout << "Masukkan username: ";
        getline(cin, input_username);
        cout << "Masukkan password: ";
        cin >> input_password;
        cin.ignore();

        bool masuk_login = false;
        for (int i = 0; i < 1; ++i) {
            if (input_username == usernames[i] && input_password == passwords[i]) {
                masuk_login = true;
                cout << "Login sukses!\n";
                break;
            }
        }

        if (masuk_login) {
            break;
        } else {
            ++percobaan;
            cout << "username or password invalid. sisa percobaan: " << maks_percobaan - percobaan << endl;
        }
    }

    if (percobaan == maks_percobaan) {
        cout << "Anda melebihi batas percobaan. keluar program." << endl;
        return 0;
    }

    int pilihan;
    string nama;

    do {
        system("clear");
        cout << "\nMenu\n";
        cout << "------------------------\n";
        cout << "1. Tambah Kostum\n";
        cout << "2. Lihat Kostum\n";
        cout << "3. Ketersediaan Kostum\n";
        cout << "4. Hapus Kostum\n";
        cout << "5. Keluar\n";
        cout << "------------------------\n";
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama kostum: ";
                cin >> nama;
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
                cout << "apakah tersedia? (1 = iya, 0 = tidak): ";
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
                break;
            default:
                cout << "pilihan tidak tersedia.\n";
        }
    } while (pilihan != 5);

    return 0;
}