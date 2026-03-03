#include <iostream>
using namespace std;

int main() {

    string nama, password;
    int salah = 0;
    int menu;
    float waktu;

    // LOGIN
    while (salah < 3) {
        cout << "Nama: ";
        cin >> nama;

        cout << "Password: ";
        cin >> password;

        if (password == "106") {
            cout << "Login berhasil\n";
            break;
        } else {
            cout << "Salah\n";
            salah++;
        }
    }

    if (salah == 3) {
        cout << "Salah 3 kali. Selesai.\n";
        return 0;
    }

    // MENU
    do {
        cout << "\n1. Jam\n";
        cout << "2. Menit\n";
        cout << "3. Detik\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan jam: ";
            cin >> waktu;
            cout << "Menit = " << waktu * 60 << endl;
            cout << "Detik = " << waktu * 3600 << endl;
        }
        else if (menu == 2) {
            cout << "Masukkan menit: ";
            cin >> waktu;
            cout << "Jam = " << waktu / 60 << endl;
            cout << "Detik = " << waktu * 60 << endl;
        }
        else if (menu == 3) {
            cout << "Masukkan detik: ";
            cin >> waktu;
            cout << "Jam = " << waktu / 3600 << endl;
            cout << "Menit = " << waktu / 60 << endl;
        }

    } while (menu != 4);

    cout << "Selesai\n";

    return 0;
}