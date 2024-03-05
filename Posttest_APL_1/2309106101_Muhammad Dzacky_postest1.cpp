#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string nama, nim;
    int loginAttempt = 0;

    do {
        cout << "=== Login ===" << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "NIM: ";
        cin >> nim;

        if (nama != "Dzacky" || nim != "2309106101") {
            loginAttempt++;

            if (loginAttempt == 3) {
                cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti." << endl;
                break;
            } else {
                cout << "Login gagal. Coba lagi." << endl;
                continue;
            }
        } else {
            break;
        }
    } while (true);

    int pilihan;

    do {
        cout << "\n=== Menu Konversi Suhu ===" << endl;
        cout << "1. Konversi Celcius ke (Reamur, Fahrenheit, Kelvin)" << endl;
        cout << "2. Konversi Reamur ke (Celcius, Fahrenheit, Kelvin)" << endl;
        cout << "3. Konversi Fahrenheit ke (Celcius, Reamur, Kelvin)" << endl;
        cout << "4. Konversi Kelvin ke (Celcius, Reamur, Fahrenheit)" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Konversi Celcius
                double Celcius;
                cout << "Tolong masukkan suhu dalam Celcius: ";
                cin >> Celcius;

                double Reamur = 0.8 * Celcius;
                double Fahrenheit = 1.8 * Celcius + 32;
                double Kelvin = Celcius + 273.15;

                cout << "Hasil konversi:" << endl;
                cout << "Reamur: " << Reamur << endl;
                cout << "Fahrenheit: " << Fahrenheit << endl;
                cout << "Kelvin: " << Kelvin << endl;
                break;
            }
            case 2: {
                // Konversi Reamur  
                double Reamur;
                cout << "Tolong masukkan suhu dalam Reamur: ";
                cin >> Reamur;

                double Celcius = 5.0 / 4.0 * Reamur;
                double Fahrenheit = 9.0 / 4.0 * Reamur + 32;
                double Kelvin = 5.0 / 4.0 * Reamur + 273.15;

                cout << "Hasil konversi:" << endl;
                cout << "Celcius: " << Celcius << endl;
                cout << "Fahrenheit: " << Fahrenheit << endl;
                cout << "Kelvin: " << Kelvin << endl;
                break;
            }
            
            case 3: {
                // Konversi Fahrenheit
                double Fahrenheit;
                cout << "Tolong masukkan suhu dalam Fahrenheit: ";
                cin >> Fahrenheit;
                double Celcius = (Fahrenheit - 32) / 1.8;
                double Reamur = (Fahrenheit - 32) / 2.25;
                double Kelvin = (Fahrenheit - 32) / 1.8 + 273.15;
                cout << "Hasil konversi:" << endl;
                cout << "Celcius: " << Celcius << endl;
                cout << "Reamur: " << Reamur << endl;
                cout << "Kelvin: " << Kelvin << endl;
                break;
    
            }
            case 4: {
                // Konversi Kelvin
                double Kelvin;
                cout << "Tolong masukkan suhu dalam Kelvin: ";
                cin >> Kelvin;
                double Celcius = Kelvin - 273.15;
                double Reamur = 4/5 * Kelvin - 273.15;
                double Fahrenheit = 9/5 * Kelvin - 273.15 + 32;
                cout << "Hasil konversi:" << endl;
                cout << "Celcius: " << Celcius << endl;
                cout << "Reamur: " << Reamur << endl;
                cout << "Fahrenheit: " << Fahrenheit << endl;
                break;
                
            }
            case 0: {
                cout << "Program berhenti. Terima kasih!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }

    } while (pilihan != 0);

    return 0;
}