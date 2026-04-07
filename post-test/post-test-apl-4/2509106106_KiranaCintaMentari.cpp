#include <iostream>
using namespace std;

struct Boneka {
    string kodeBoneka;
    string namaBoneka;
    int hargaBoneka;
    Boneka *next; 
};

void tambahBoneka(Boneka *&kepala, int &jumlahData) {
    Boneka *bonekaBaru = new Boneka;

    cout << "\n=== TAMBAH DATA BONEKA ===\n";
    cout << "Kode Boneka   : ";
    cin >> bonekaBaru->kodeBoneka;
    cout << "Nama Boneka   : ";
    cin >> bonekaBaru->namaBoneka;
    cout << "Harga Boneka  : ";
    cin >> bonekaBaru->hargaBoneka;

    bonekaBaru->next = NULL;

    if (kepala == NULL) {
        kepala = bonekaBaru;
    } else {
        Boneka *bantu = kepala;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = bonekaBaru;
    }

    jumlahData++;
    cout << "Data berhasil ditambahkan!\n";
}

void tampilBoneka(Boneka *kepala) {
    cout << "\n=== DATA BONEKA ===\n";

    if (kepala == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    Boneka *bantu = kepala;
    int nomorData = 1;

    while (bantu != NULL) {
        cout << "\nData ke-" << nomorData << endl;
        cout << "Kode  : " << bantu->kodeBoneka << endl;
        cout << "Nama  : " << bantu->namaBoneka << endl;
        cout << "Harga : " << bantu->hargaBoneka << endl;

        bantu = bantu->next;
        nomorData++;
    }
}

void hapusBoneka(Boneka *&kepala, int &jumlahData) {
    string kodeCari;
    cout << "\nMasukkan kode boneka yang ingin dihapus: ";
    cin >> kodeCari;

    Boneka *bantu = kepala;
    Boneka *sebelum = NULL;

    while (bantu != NULL) {
        if (bantu->kodeBoneka == kodeCari) {

            if (sebelum == NULL) {
                kepala = bantu->next;
            } else {
                sebelum->next = bantu->next;
            }

            delete bantu;
            jumlahData--;

            cout << "Data berhasil dihapus!\n";
            return;
        }

        sebelum = bantu;
        bantu = bantu->next;
    }

    cout << "Data tidak ditemukan!\n";
}

int main() {
    Boneka *kepala = NULL;
    int jumlahData = 0;
    int pilihanMenu;

    do {
        cout << "\n=== MENU TOKO BONEKA ===\n";
        cout << "1. Tambah Boneka\n";
        cout << "2. Tampil Boneka\n";
        cout << "3. Hapus Boneka\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tambahBoneka(kepala, jumlahData); 
                break;
            case 2:
                tampilBoneka(kepala);
                break;
            case 3:
                hapusBoneka(kepala, jumlahData);
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihanMenu != 4);

    return 0;
}