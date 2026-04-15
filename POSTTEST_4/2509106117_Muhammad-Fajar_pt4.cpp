#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama_hewan;
    string jenis_hewan;
    float harga;
    Hewan *next;
};

struct Antrian {
    Hewan *front = NULL;
    Hewan *rear = NULL;
};

struct Riwayat {
    Hewan *top = NULL;
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
        (arr + n)->next = NULL;
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
    Hewan *baru = new Hewan;
    *baru = h;
    baru->next = NULL;

    if(q->rear == NULL) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    cout << "Hewan anda masuk ke antrian!\n";
}

Hewan dequeue(Antrian *q) {
    Hewan kosong;
    kosong.id = -1;

    if(q->front  == NULL) {
        cout << "Antrian kosong! (Underflow), silahkan anda menyuruh pelanggan anda mengambil antrian\n";
        return kosong;
    }

    Hewan *hapus = q->front;
    Hewan h = *hapus;

    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL;

    delete hapus;

    cout << "No Panggilan Pelanggan: " << h.id << " | " << h.nama_hewan << endl;
    return h;
}

void tampilAntrian(Antrian *q) {
    if(q->front == NULL) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== DATA ANTRIAN ===\n";
    Hewan *temp = q->front;
    while(temp != NULL) {
        cout << temp->id << " | " << temp->nama_hewan << endl;
        temp = temp->next;
    }
}

void peekAntrian(Antrian *q) {
    if(q->front == NULL) {
        cout << "Antrian kosong!\n";
    } else {
        cout << "Antrian Paling Depan: " << q->front->id << " | " << q->front->nama_hewan << endl;
    }
}

void push(Riwayat *s, Hewan h) {
    Hewan *baru = new Hewan;
    *baru = h;

    baru->next = s->top;
    s->top = baru;

    cout << "Masuk riwayat!\n";
}

void pop(Riwayat *s) {
    if(s->top == NULL) {
        cout << "Riwayat kosong! (Underflow), silahkan masukkan riwayat antrian pelanggan\n";
        return;
    }

    Hewan *hapus = s->top;
    cout << "Hapus: " << hapus->id << " | " << hapus->nama_hewan << endl;

    s->top = s->top->next;
    delete hapus;
}

void tampilRiwayat(Riwayat *s) {
    if(s->top == NULL) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== DATA RIWAYAT ===\n";
    Hewan *temp = s->top;
    while(temp != NULL) {
        cout << temp->id << " | " << temp->nama_hewan << endl;
        temp = temp->next;
    }
}

void peekRiwayat(Riwayat *s) {
    if(s->top == NULL) {
        cout << "Riwayat kosong!\n";
    } else {
        cout << "RiwayatTerakhir Pelanggan: " << s->top->id << " | " << s->top->nama_hewan << endl;
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