#include <iostream>
using namespace std;

int main() {

    string nama[100];
    int harga[100];
    int jumlah = 0;
    int pilih;

    do {
        cout << "\n=== PROGRAM TOKO BONEKA ===\n";
        cout << "1. Tambah Boneka\n";
        cout << "2. Lihat Stok Boneka\n";
        cout << "3. Ubah Nama Boneka\n";
        cout << "4. Hapus Data Boneka\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan Nama Boneka: ";
            cin >> nama[jumlah];
            cout << "Masukkan Harga Boneka: ";
            cin >> harga[jumlah];
            jumlah++;
        }

        else if (pilih == 2) {
            cout << "\nSTOK BONEKA\n";
            for (int i = 0; i < jumlah; i++) {
                cout << i+1 << ". " << nama[i] << " - Rp" << harga[i] << endl;
            }
        }

        else if (pilih == 3) {
            int no;
            cout << "Nomor boneka yang diubah: ";
            cin >> no;
            cout << "Nama baru: ";
            cin >> nama[no-1];
        }

        else if (pilih == 4) {
            int no;
            cout << "Nomor boneka yang dihapus: ";
            cin >> no;

            for (int i = no-1; i < jumlah-1; i++) {
                nama[i] = nama[i+1];
                harga[i] = harga[i+1];
            }

            jumlah--;
        }

    } while (pilih != 5);

    cout << "Program selesai\n";

    return 0;
}