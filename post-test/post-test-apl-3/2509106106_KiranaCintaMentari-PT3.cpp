#include <iostream>
using namespace std;

string namaBoneka[100];
int hargaBoneka[100];
int jumlahBoneka = 0;

void tampilBoneka(){
    cout << "\nDaftar Boneka:\n";

    for(int indeks = 0; indeks < jumlahBoneka; indeks++){
        cout << indeks+1 << ". "
             << namaBoneka[indeks]
             << " - Rp" << hargaBoneka[indeks] << endl;
    }
}

void tambahBoneka(string namaInput, int hargaInput){
    namaBoneka[jumlahBoneka] = namaInput;
    hargaBoneka[jumlahBoneka] = hargaInput;
    jumlahBoneka++;
}

int cariBoneka(string namaDicari, int indeks){

    if(indeks >= jumlahBoneka)
        return -1;

    if(namaBoneka[indeks] == namaDicari)
        return indeks;

    return cariBoneka(namaDicari, indeks+1);
}

int main(){

    int pilihanMenu;

    do{

        cout << "\n=== MENU TOKO BONEKA ===\n";
        cout << "1. Tambah Boneka\n";
        cout << "2. Lihat Boneka\n";
        cout << "3. Cari Boneka\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihanMenu;

        if(pilihanMenu == 1){

            string namaInput;
            int hargaInput;

            cout << "Nama Boneka: ";
            cin >> namaInput;

            cout << "Harga Boneka: ";
            cin >> hargaInput;

            tambahBoneka(namaInput, hargaInput);
        }

        else if(pilihanMenu == 2){
            tampilBoneka();
        }

        else if(pilihanMenu == 3){

            string namaDicari;

            cout << "Nama Boneka yang dicari: ";
            cin >> namaDicari;

            int hasil = cariBoneka(namaDicari,0);

            if(hasil != -1)
                cout << "Boneka ditemukan di posisi " << hasil+1 << endl;
            else
                cout << "Boneka tidak ditemukan\n";
        }

    }while(pilihanMenu != 4);

}