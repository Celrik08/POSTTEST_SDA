#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama_hewan;
    string jenis_hewan;
    float harga;
};

int jumlah = 0;

// Ini adalah swapPointer
void swapPointer(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

// Ini adalah tambahData
void tambahData(Hewan *arr, int &n) {
    int x;
    cout << "\nSilahkan masukkan jumlah data hewan: ";
    cin >> x;

    for(int i = 0; i < x; i++) {
        cout << "\nData ke-" << i+1 << endl;

        cout << "ID     : "; cin >> (arr + n)->id;
        cout << "Nama  Hewan : "; cin >> (arr + n)->nama_hewan;
        cout << "Jenis Hewan  : "; cin >> (arr + n)->jenis_hewan;
        cout << "Harga  : "; cin >> (arr + n)->harga;

        n++;
    }
}

// Ini adalah tampilData
void tampilData(Hewan *arr, int n) {
    cout << "\n=== MENU DATA HEWAN ===\n";

    for(int i = 0; i < n; i++) {
        cout << (arr + i)->id << " | "
             << (arr + i)->nama_hewan << " | "
             << (arr + i)->jenis_hewan << " | "
             << (arr + i)->harga << endl;
    }
}

// Ini adalah linearSearch
void linearSearch(Hewan *arr, int n) {
    string cari;
    cout << "\nSilahkan masukkan nama hewan: ";
    cin >> cari;

    for(int i = 0; i < n; i++) {

        if((arr + i)->nama_hewan == cari) {
            cout << "Data yang anda cari telah ditemukan!\n";

            swapPointer(arr, arr + i);

            cout << "Ini adalah data yang setelah di-swap ke depan:\n";
            cout << arr->id << " | "
                 << arr->nama_hewan << " | "
                 << arr->jenis_hewan << " | "
                 << arr->harga << endl;
            return;
        }
    }

    cout << "Data yang anda cari tidak ditemukan!\n";
}

// Ini adalah sortById (Selection Sort berdasarkan ID), yang berfungsi untuk mengurutkan data berdasarkan ID sebelum melakukan pencarian dengan 
void sortById(Hewan *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if((arr + j)->id < (arr + min)->id) {
                min = j;
            }
        }
        swapPointer(arr + i, arr + min);
    }
}

// Ini adalah fibonacciSearch
void fibonacciSearch(Hewan *arr, int n) {
    int x;
    cout << "\nSilahkan masukkan ID: ";
    cin >> x;

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    // Membentuk bilangan fibonacci sampai >= jumlah data
    while(fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    // Proses pencarian:
    // 1. Menentukan index i = offset + fib2
    // 2. Jika nilai di index i lebih kecil dari x → geser ke kanan
    // 3. Jika lebih besar → geser ke kiri
    // 4. Jika sama → data ditemukan

    while(fib > 1) {
        int i = min(offset + fib2, n - 1);

        if((arr + i)->id < x) {
            // Geser ke kanan
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if((arr + i)->id > x) {
            // Geser ke kiri
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            cout << "Data yang anda cari telah ditemukan!\n";

            swapPointer(arr, arr + i);

            cout << "Ini adalah data yang setelah di-swap ke depan:\n";
            cout << arr->id << " | "
                 << arr->nama_hewan << " | "
                 << arr->jenis_hewan << " | "
                 << arr->harga << endl;
            return;
        }
    }

    // Mengecek sisa 1 elemen terakhir
    if(fib1 && (arr + offset + 1)->id == x) {
        cout << "Data yang anda cari telah ditemukan!\n";
        swapPointer(arr, arr + offset + 1);

        cout << "Ini adalah data yang setelah di-swap ke depan:\n";
        cout << arr->id << " | "
             << arr->nama_hewan << " | "
            << arr->jenis_hewan << " | "
            << arr->harga << endl;
        return;
    }

    cout << "Data yang anda cari tidak ditemukan!\n";
}

// Ini adalah bubbleSort
void bubbleSort(Hewan *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if((arr + j)->nama_hewan > (arr + j + 1)->nama_hewan) {
                swapPointer(arr + j, arr + j + 1);
            }
        }
    }
    cout << "Data sudah diurutkan (Nama Hewan dari A-Z)\n";
}

// Ini adalah selectionSort
void selectionSort(Hewan *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;

        for(int j = i+1; j < n; j++) {
            if((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }

        swapPointer(arr + i, arr + min);
    }
    cout << "Data sudah diurutkan (Dari harga termurah sampai termahal)\n";
}

// Ini adalah menu
void menu() {
    Hewan data[100];
    int pilih;

    do {
        cout << "\n=== SILAHKAN PILIH MENU PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama Hewan (Linear)\n";
        cout << "4. Cari ID (Fibonacci)\n";
        cout << "5. Sort Nama Hewan\n";
        cout << "6. Sort Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambahData(data, jumlah); break;
            case 2: tampilData(data, jumlah); break;
            case 3: sortById(data, jumlah);linearSearch(data, jumlah); break;
            case 4: fibonacciSearch(data, jumlah); break;
            case 5: bubbleSort(data, jumlah); break;
            case 6: selectionSort(data, jumlah); break;
        }

    } while(pilih != 0);
}

// Ini adalah main yang berfungsi untuk menjalankan program dengan memanggil menu
int main() {
    menu();
    return 0;
}