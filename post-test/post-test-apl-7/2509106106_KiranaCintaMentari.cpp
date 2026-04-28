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
        if (id[tengah] == cari) return tengah;
        else if (cari < id[tengah]) kanan = tengah - 1;
        else kiri = tengah + 1;
    }
    return -1;
}

int sequentialSearch(string *nama, int n, string cari) {
    for (int i = 0; i < n; i++) {
        if (nama[i] == cari) return i;
    }
    return -1;
}
void tampil(int *id, string *nama, int *harga, int n) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }
    cout << "\n=== DATA BONEKA ===\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << id[i]
             << " | Nama: " << nama[i]
             << " | Harga: " << harga[i] << endl;
    }
}

void tambahData(int *id, string *nama, int *harga, int &n) {
    try {
        cout << "Masukkan ID: ";
        cin >> id[n];

        if (id[n] < 0) throw "ID tidak boleh negatif!";

        cout << "Masukkan Nama: ";
        cin >> nama[n];

        cout << "Masukkan Harga: ";
        cin >> harga[n];

        if (harga[n] < 0) throw "Harga tidak boleh negatif!";

        n++;
        sortingID(id, nama, harga, n);

        cout << "Data berhasil ditambahkan!\n";
    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

void updateData(int *id, string *nama, int *harga, int n) {
    try {
        int cari;
        cout << "Masukkan ID: ";
        cin >> cari;

        int idx = binarySearch(id, n, cari);

        if (idx == -1) throw "Data tidak ditemukan!";

        cout << "Nama baru: ";
        cin >> nama[idx];

        cout << "Harga baru: ";
        cin >> harga[idx];

        if (harga[idx] < 0) throw "Harga tidak valid!";

        cout << "Data berhasil diupdate!\n";

    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

void hapusData(int *id, string *nama, int *harga, int &n) {
    try {
        int cari;
        cout << "Masukkan ID yang mau dihapus: ";
        cin >> cari;

        int idx = binarySearch(id, n, cari);

        if (idx == -1) throw "Data tidak ditemukan!";

        for (int i = idx; i < n - 1; i++) {
            id[i] = id[i + 1];
            nama[i] = nama[i + 1];
            harga[i] = harga[i + 1];
        }

        n--;
        cout << "Data berhasil dihapus!\n";

    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }
}

int main() {
    int menuAwal;
    bool isLoginSuccess = false;

    do {
        cout << "\n=== MENU AKUN ===\n";
        cout << "1. Daftar\n2. Login\n3. Keluar\nPilih: ";
        cin >> menuAwal;

        if (menuAwal == 1) {
            cout << "Username: ";
            cin >> dataAkun[jumlahAkun].username;
            cout << "Password: ";
            cin >> dataAkun[jumlahAkun].password;
            jumlahAkun++;
            cout << "Akun berhasil dibuat!\n";
        }

        else if (menuAwal == 2) {
            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            for (int i = 0; i < jumlahAkun; i++) {
                if (dataAkun[i].username == u && dataAkun[i].password == p) {
                    isLoginSuccess = true;
                    cout << "Login berhasil!\n";
                }
            }
        }

    } while (!isLoginSuccess && menuAwal != 3);

    if (!isLoginSuccess) return 0;

    int n = 0;
    int id[100];
    string nama[100];
    int harga[100];

    int menu;
    do {
        cout << "\n=== MENU BONEKA ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari ID\n";
        cout << "4. Cari Nama\n";
        cout << "5. Update\n";
        cout << "6. Hapus\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) tambahData(id, nama, harga, n);
        else if (menu == 2) tampil(id, nama, harga, n);
        else if (menu == 3) {
            int cari;
            cout << "ID: ";
            cin >> cari;
            int idx = binarySearch(id, n, cari);
            if (idx != -1) cout << nama[idx] << " - " << harga[idx] << endl;
            else cout << "Tidak ditemukan\n";
        }
        else if (menu == 4) {
            string cari;
            cout << "Nama: ";
            cin >> cari;
            int idx = sequentialSearch(nama, n, cari);
            if (idx != -1) cout << id[idx] << " - " << harga[idx] << endl;
            else cout << "Tidak ditemukan\n";
        }
        else if (menu == 5) updateData(id, nama, harga, n);
        else if (menu == 6) hapusData(id, nama, harga, n);

    } while (menu != 0);

    cout << "Program selesai\n";
}