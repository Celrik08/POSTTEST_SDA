#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* mulai = arr;
    int* selesai = arr + n - 1;

    while (mulai < selesai) {
        int temp = *mulai;
        *mulai = *selesai;
        *selesai = temp;

        mulai++;
        selesai--;
    }
}

int main() {

    int arr[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "=== INI ARRAY SEBELUM DIBALIK ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << arr[i]
             << " | Alamat: " << (arr + i) << endl;
    }

    reverseArray(arr, n);

    cout << "\n=== INI ARRAY SETELAH DIBALIK ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << arr[i]
             << " | Alamat: " << (arr + i) << endl;
    }

    return 0;
}