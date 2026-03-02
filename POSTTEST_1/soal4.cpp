#include <iostream>
using namespace std;

void tukar(int &n1, int &n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {

    int nilai1, nilai2;

    cout << "Silahkan Anda masukkan nilai pertama : ";
    cin >> nilai1;
    cout << "Silahkan Anda masukkan nilai kedua   : ";
    cin >> nilai2;

    cout << "\nSebelum nilai ditukar:" << endl;
    cout << "nilai 1 = " << nilai1 << endl;
    cout << "nilai 2 = " << nilai2 << endl;

    tukar(nilai1, nilai2);

    cout << "\nSetelah nilai ditukar:" << endl;
    cout << "nilai 1 = " << nilai1 << endl;
    cout << "nilai 2 = " << nilai2 << endl;

    return 0;
}