#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Untuk metode sorting dan pencarian
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

// Deklarasi fungsi-fungsi
void sortAscendingKostum();
void sortDescendingKostum();
void sortAscendingNumber();
void searchAscendingKostum();
void searchDescendingKostum();

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
           "5. Sort Kostum (Huruf Ascending)\n"
           "6. Sort Kostum (Huruf Descending)\n"
           "7. Sort Kostum (Angka Ascending)\n"
           "8. Search Kostum (Huruf Ascending)\n"
           "9. Search Kostum (Huruf Descending)\n"
           "10. Keluar\n"
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
                sortAscendingKostum();
                cout << "Kostum berhasil diurutkan (Huruf Ascending).\n";
                break;
            case 6:
                sortDescendingKostum();
                cout << "Kostum berhasil diurutkan (Huruf Descending).\n";
                break;
            case 7:
                sortAscendingNumber();
                cout << "Kostum berhasil diurutkan (Angka Ascending).\n";
                break;
            case 8:
                searchAscendingKostum();
                break;
            case 9:
                searchDescendingKostum();
                break;
            case 10:
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

// Metode sorting huruf secara ascending
void sortAscendingKostum() {
    sort(kostum.begin(), kostum.begin() + jumlah_kostum, [](const Kostum& a, const Kostum& b) {
        return a.nama < b.nama;
    });
}

// Metode sorting huruf secara descending
void sortDescendingKostum() {
    sort(kostum.begin(), kostum.begin() + jumlah_kostum, [](const Kostum& a, const Kostum& b) {
        return a.nama > b.nama;
    });
}

// Metode sorting angka secara ascending
void sortAscendingNumber() {
    sort(kostum.begin(), kostum.begin() + jumlah_kostum, [](const Kostum& a, const Kostum& b) {
        // Menggunakan operator '<' untuk membandingkan angka di sini
        // Anda dapat mengganti dengan properti yang sesuai dari objek Kostum jika perlu
        // Misalnya, jika setiap Kostum memiliki nomor unik, Anda bisa membandingkan nomor tersebut.
        // Di sini saya anggap setiap Kostum memiliki nomor yang tersimpan dalam string nama.
        // Anda mungkin perlu mengubah logika ini sesuai dengan kebutuhan Anda.
        return stoi(a.nama) < stoi(b.nama);
    });
}

// Metode pencarian pada kumpulan data yang terurut secara ascending
void searchAscendingKostum() {
    string target;
    cout << "Masukkan nama kostum yang ingin dicari (Huruf Ascending): ";
    getline(cin, target);

    auto it = lower_bound(kostum.begin(), kostum.begin() + jumlah_kostum, target, [](const Kostum& a, const string& b) {
        return a.nama < b;
    });

    if (it != kostum.begin() + jumlah_kostum && it->nama == target) {
        cout << "Kostum ditemukan.\n";
    } else {
        cout << "Kostum tidak ditemukan.\n";
    }
}

// Metode pencarian pada kumpulan data yang terurut secara descending
void searchDescendingKostum() {
    string target;
    cout << "Masukkan nama kostum yang ingin dicari (Huruf Descending): ";
    getline(cin, target);

    auto it = lower_bound(kostum.begin(), kostum.begin() + jumlah_kostum, target, [](const Kostum& a, const string& b) {
        return a.nama > b;
    });

    if (it != kostum.begin() + jumlah_kostum && it->nama == target) {
        cout << "Kostum ditemukan.\n";
    } else {
        cout << "Kostum tidak ditemukan.\n";
    }
}

int main() {
    vector<User> users = {{"Muhammad Dzacky", "2309106101"}};

    if (login(users)) {
        tambah_kostum("Costume Kurumi Tokisaki");
        tambah_kostum("Costume Beta");
        tambah_kostum("Costume Vestia Zeta");
        tambah_kostum("Costume yelan");
        tambah_kostum("Costume yae miko");
        tambah_kostum("Costume Raiden Shougun");

        // Add more costumes here if needed

        menu();
    }

    return 0;
}