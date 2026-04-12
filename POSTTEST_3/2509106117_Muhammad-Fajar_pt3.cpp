#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama_hewan;
    string jenis_hewan;
    float harga;
};

struct Antrian {
    Hewan data[100];
    int front = 0;
    int rear = -1;
};

struct Riwayat {
    Hewan data[100];
    int atas = -1;
};

int jumlah = 0;

void swapPointer(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void tambahData(Hewan *arr, int &n) {
    int x;
    cout << "\nJumlah data: ";
    cin >> x;

    for(int i = 0; i < x; i++) {
        cout << "\nData ke-" << i+1 << endl;
        cout << "ID: "; cin >> (arr + n)->id;
        cout << "Nama: "; cin >> (arr + n)->nama_hewan;
        cout << "Jenis: "; cin >> (arr + n)->jenis_hewan;
        cout << "Harga: "; cin >> (arr + n)->harga;
        n++;
    }
}

void tampilData(Hewan *arr, int n) {
    cout << "\n=== DATA HEWAN ===\n";
    for(int i = 0; i < n; i++) {
        cout << (arr+i)->id << " | "
             << (arr+i)->nama_hewan << " | "
             << (arr+i)->jenis_hewan << " | "
             << (arr+i)->harga << endl;
    }
}

void sortById(Hewan *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if((arr+j)->id < (arr+min)->id) {
                min = j;
            }
        }
        swapPointer(arr+i, arr+min);
    }
}

void linearSearch(Hewan *arr, int n) {
    string cari;
    cout << "Cari nama: ";
    cin >> cari;

    for(int i = 0; i < n; i++) {
        if((arr+i)->nama_hewan == cari) {
            cout << "Ditemukan!\n";
            swapPointer(arr, arr+i);

            cout << arr->id << " | "
                 << arr->nama_hewan << endl;
            return;
        }
    }
    cout << "Tidak ditemukan!\n";
}

void fibonacciSearch(Hewan *arr, int n) {
    int x;
    cout << "Cari ID: ";
    cin >> x;

    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;

    while(fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while(fib > 1) {
        int i = min(offset + fib2, n-1);

        if((arr+i)->id < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if((arr+i)->id > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            cout << "Ditemukan!\n";
            swapPointer(arr, arr+i);

            cout << arr->id << " | "
                 << arr->nama_hewan << endl;
            return;
        }
    }

    if(fib1 && (arr+offset+1)->id == x) {
        cout << "Ditemukan!\n";
        swapPointer(arr, arr+offset+1);

        cout << arr->id << " | "
             << arr->nama_hewan << endl;
        return;
    }

    cout << "Tidak ditemukan!\n";
}

void bubbleSort(Hewan *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if((arr+j)->nama_hewan > (arr+j+1)->nama_hewan) {
                swapPointer(arr+j, arr+j+1);
            }
        }
    }
    cout << "Urut nama berhasil!\n";
}

void selectionSort(Hewan *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if((arr+j)->harga < (arr+min)->harga) {
                min = j;
            }
        }
        swapPointer(arr+i, arr+min);
    }
    cout << "Urut harga berhasil!\n";
}

void enqueue(Antrian *q, Hewan h) {
    q->rear++;
    q->data[q->rear] = h;
}

Hewan dequeue(Antrian *q) {
    Hewan kosong;
    kosong.id = -1;

    if(q->front > q->rear) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Hewan h = q->data[q->front];
    q->front++;

    cout << "Dipanggil: " << h.id << " | " << h.nama_hewan << endl;
    return h;
}

void tampilAntrian(Antrian *q) {
    if(q->front > q->rear) {
        cout << "Kosong!\n";
        return;
    }

    for(Hewan *ptr = q->data + q->front; ptr <= q->data + q->rear; ptr++) {
        cout << ptr->id << " | " << ptr->nama_hewan << endl;
    }
}

void peekAntrian(Antrian *q) {
    if(q->front <= q->rear) {
        cout << "Bagian depan antrian: " << q->data[q->front].nama_hewan << endl;
    }
}

void push(Riwayat *s, Hewan h) {
    s->atas++;
    s->data[s->atas] = h;
}

void pop(Riwayat *s) {
    if(s->atas == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus: " << s->data[s->atas].nama_hewan << endl;
    s->atas--;
}

void tampilRiwayat(Riwayat *s) {
    if(s->atas == -1) {
        cout << "Kosong!\n";
        return;
    }

    for(Hewan *ptr = s->data; ptr <= s->data + s->atas; ptr++) {
        cout << ptr->id << " | " << ptr->nama_hewan << endl;
    }
}

void peekRiwayat(Riwayat *s) {
    if(s->atas != -1) {
        cout << "Bagian belakang riwayat: " << s->data[s->atas].nama_hewan << endl;
    }
}

void menu() {
    Hewan data[100];
    Antrian antrian;
    Riwayat riwayat;

    int pilih;

    do {
        cout << "\n=== SILAHKAN PILIH MENU PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama Hewan (Linear)\n";
        cout << "4. Cari ID (Fibonacci)\n";
        cout << "5. Sort Nama Hewan\n";
        cout << "6. Sort Harga\n";
        cout << "7. Tambah Antrian\n";
        cout << "8. Panggil Antrian\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Hapus Riwayat\n";
        cout << "12. Tampil Bagian Depan Antrian dan Belakang Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih) {
            case 1: tambahData(data, jumlah); break;
            case 2: tampilData(data, jumlah); break;
            case 3: linearSearch(data, jumlah); break;
            case 4: sortById(data, jumlah); fibonacciSearch(data, jumlah); break;
            case 5: bubbleSort(data, jumlah); break;
            case 6: selectionSort(data, jumlah); break;

            case 7: {
                int id;
                cout << "ID: "; cin >> id;
                for(int i = 0; i < jumlah; i++) {
                    if(data[i].id == id) {
                        enqueue(&antrian, data[i]);
                    }
                }
                break;
            }

            case 8: {
                Hewan h = dequeue(&antrian);
                if(h.id != -1) push(&riwayat, h);
                break;
            }

            case 9: tampilAntrian(&antrian); break;
            case 10: tampilRiwayat(&riwayat); break;
            case 11: pop(&riwayat); break;

            case 12:
                peekAntrian(&antrian);
                peekRiwayat(&riwayat);
                break;
        }

    } while(pilih != 0);
}

int main() {
    menu();
    return 0;
}