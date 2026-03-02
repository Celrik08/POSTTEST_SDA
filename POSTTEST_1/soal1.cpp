#include <iostream>
using namespace std;

/*
KOMPLEKSITAS WAKTU
Algoritma : FindMin

Pseudocode:

procedure FindMin(A : array of n elements)
  min ← A[0]
  for i ← 1 to n − 1 do
    if A[i] < min then
      min ← A[i]
    end if
  end for
  return min
end procedure

--------------------------------------------------------------------
TABEL COST (disesuaikan dengan nodulnya)

Pseudocode              Cost   Tmin      Tmax
------------------------------------------------
procedure FindMin        C1      1         1
min ← A[0]               C2      1         1
for i ← 1 to n−1         C3      n         n
if A[i] < min            C4     n−1       n−1
min ← A[i]               C5      0        n−1
end if                   C6     n−1       n−1
end for                  C7      n         n
return min               C8      1         1
end procedure            C9      1         1

--------------------------------------------------------------------
BEST CASE

Jika Tmin(n) adalah
C1 + C2 + C3n + C4(n−1) + 0 + C6(n−1) + C7n + C8 + C9

Kalau di uraikan:
C4(n−1) = C4n − C4
C6(n−1) = C6n − C6

Maka yang di atas, jadi seperti di bawah ini:
Tmin(n) =
C1 + C2 + C3n + C4n − C4 + C6n − C6 + C7n + C8 + C9

Gabungkan suku n:

= (C3 + C4 + C6 + C7)n
  + (C1 + C2 + C8 + C9 − C4 − C6)

Jika semua Ci adalah 1:

= (1+1+1+1)n + (1+1+1+1−1−1)
= 4n + 4

Karena linear,
maka Big-O Best Case = O(n)

--------------------------------------------------------------------
WORST CASE

Jika Tmax(n) adalah
C1 + C2 + C3n + C4(n−1) + C5(n−1)
+ C6(n−1) + C7n + C8 + C9

Klaua di uraikan, maka:
C4(n−1) = C4n − C4
C5(n−1) = C5n − C5
C6(n−1) = C6n − C6

Maka yang di atas jadi:

Tmax(n) =
C1 + C2 + C3n + C4n − C4 + C5n − C5
+ C6n − C6 + C7n + C8 + C9

dan ketika di gabungkan:

= (C3 + C4 + C5 + C6 + C7)n
  + (C1 + C2 + C8 + C9 − C4 − C5 − C6)

Jika semua Ci adalah 1, maka:

= (1+1+1+1+1)n + (1+1+1+1−1−1−1)
= 5n + 3

Karena linear,
maka Big-O Worst Case = O(n)

jadi hasilnya adalah
Tmin(n) = 4n + 4  → O(n)
Tmax(n) = 5n + 3  → O(n)
*/

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }

    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int indexMin;

    int minimum = FindMin(A, n, indexMin);

    cout << "Ini nilai minimum : " << minimum << endl;
    cout << "Ini indeks minimum: " << indexMin << endl;

    return 0;
}