#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    const int jumlah_mahasiswa = 5;
    Mahasiswa mahasiswa[jumlah_mahasiswa];

    cout << "=== SILAHKAN INPUT DATA MAHASISWA ===" << endl;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Nama : ";
        getline(cin, mahasiswa[i].nama);

        cout << "NIM  : ";
        getline(cin, mahasiswa[i].nim);

        cout << "IPK  : ";
        cin >> mahasiswa[i].ipk;
        cin.ignore();
    }

    int IndeksIpkTertinggi = 0;

    for (int i = 1; i < jumlah_mahasiswa; i++) {
        if (mahasiswa[i].ipk > mahasiswa[IndeksIpkTertinggi].ipk) {
            IndeksIpkTertinggi = i;
        }
    }

    cout << "\n=== MAHASISWA DENGAN IPK TERTINGGI ADALAH ===" << endl;
    cout << "Nama : " << mahasiswa[IndeksIpkTertinggi].nama << endl;
    cout << "NIM  : " << mahasiswa[IndeksIpkTertinggi].nim << endl;
    cout << "IPK  : " << mahasiswa[IndeksIpkTertinggi].ipk << endl;

    return 0;
}