#include <iostream>
using namespace std;

struct Akun {
    string username;
    string password;
};

Akun dataAkun[50];
int jumlahAkun = 0;

void sortingID(int *id, string *nama, int *harga, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (id[j] > id[j + 1]) {
                swap(id[j], id[j + 1]);
                swap(nama[j], nama[j + 1]);
                swap(harga[j], harga[j + 1]);
            }
        }
    }
}

int binarySearch(int *id, int n, int cari) {
    int kiri = 0, kanan = n - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (id[tengah] == cari)
            return tengah;
        else if (cari < id[tengah])
            kanan = tengah - 1;
        else
            kiri = tengah + 1;
    }
    return -1;
}

int sequentialSearch(string *nama, int n, string cari) {
    for (int i = 0; i < n; i++) {
        if (nama[i] == cari)
            return i;
    }
    return -1;
}

void tampil(int *id, string *nama, int *harga, int n) {
    cout << "\n=== DATA BONEKA ===\n";
    for (int i = 0; i < n; i++) {
        cout << "ID    : " << id[i] << endl;
        cout << "Nama  : " << nama[i] << endl;
        cout << "Harga : " << harga[i] << endl;
        cout << "------------------\n";
    }
}

void updateData(int *id, string *nama, int *harga, int n) {
    int cari;
    cout << "Masukkan ID yang mau diupdate: ";
    cin >> cari;

    int idx = binarySearch(id, n, cari);

    if (idx != -1) {
        cout << "Data ditemukan!\n";
        cout << "Nama baru: ";
        cin >> nama[idx];
        cout << "Harga baru: ";
        cin >> harga[idx];
        cout << "Data berhasil diupdate!\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

int main() {
    int menuAwal;
    bool isLoginSuccess = false;

    do {
        cout << "\n=== MENU AKUN ===\n";
        cout << "1. Daftar\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih : ";
        cin >> menuAwal;

        if (menuAwal == 1) {
            cout << "\n--- Pendaftaran Akun ---\n";
            cout << "Username : ";
            cin >> dataAkun[jumlahAkun].username;
            cout << "Password : ";
            cin >> dataAkun[jumlahAkun].password;
            
            jumlahAkun++;
            cout << "Akun berhasil didaftarkan! Silakan Login.\n";
        }
        else if (menuAwal == 2) {
            if (jumlahAkun == 0) {
                cout << "Belum ada akun yang terdaftar. Silakan daftar terlebih dahulu.\n";
                continue; 
            }

            string inputUser, inputPass;
            int kesempatan = 0;
            bool loginDitemukan = false;

            while (kesempatan < 3) {
                cout << "\n--- Login ---\n";
                cout << "Username : ";
                cin >> inputUser;
                cout << "Password : ";
                cin >> inputPass;

            
                for (int i = 0; i < jumlahAkun; i++) {
                    if (dataAkun[i].username == inputUser && dataAkun[i].password == inputPass) {
                        loginDitemukan = true;
                        break;
                    }
                }

                if (loginDitemukan) {
                    cout << "Login berhasil!\n";
                    isLoginSuccess = true;
                    break; 
                } else {
                    kesempatan++;
                    cout << "Login gagal! Username atau Password salah.\n";
                    if (kesempatan < 3) {
                        cout << "Sisa percobaan: " << 3 - kesempatan << "\n";
                    }
                }
            }

            if (kesempatan == 3) {
                cout << "\nAnda telah gagal login 3 kali. Program berhenti otomatis.\n";
                return 0; 
            }

            if (isLoginSuccess) {
                break; 
            }
        }

    } while (menuAwal != 3);

    if (menuAwal == 3 && !isLoginSuccess) {
        cout << "Program selesai.\n";
        return 0;
    }

    int n;
    cout << "\n=== INPUT DATA BONEKA ===\n";
    cout << "Jumlah boneka: ";
    cin >> n;

    int id[n];
    string nama[n];
    int harga[n];

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "ID    : ";
        cin >> id[i];
        cout << "Nama  : ";
        cin >> nama[i];
        cout << "Harga : ";
        cin >> harga[i];
    }

    sortingID(id, nama, harga, n);

    int menu;
    do {
        cout << "\n=== MENU BONEKA ===\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Cari ID (Binary Search)\n";
        cout << "3. Cari Nama (Sequential Search)\n";
        cout << "4. Update Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            tampil(id, nama, harga, n);
        }
        else if (menu == 2) {
            int cari;
            cout << "Masukkan ID: ";
            cin >> cari;

            int idx = binarySearch(id, n, cari);

            if (idx != -1) {
                cout << "Nama  : " << nama[idx] << endl;
                cout << "Harga : " << harga[idx] << endl;
            } else {
                cout << "Tidak ditemukan!\n";
            }
        }
        else if (menu == 3) {
            string cari;
            cout << "Masukkan Nama: ";
            cin >> cari;

            int idx = sequentialSearch(nama, n, cari);

            if (idx != -1) {
                cout << "ID    : " << id[idx] << endl;
                cout << "Harga : " << harga[idx] << endl;
            } else {
                cout << "Tidak ditemukan!\n";
            }
        }
        else if (menu == 4) {
            updateData(id, nama, harga, n);
        }

    } while (menu != 0);

    cout << "Program selesai.\n";
    return 0;
}