# AI Prompt dan Analisis
**Link Percakapan:**  
- [AI Prompt for Stack](https://chatgpt.com/c/68338985-f250-800b-a8d0-7379dff0221b)

---

## Sumber Soal
Implement a simple text editor. The editor initially contains an empty string, S. Perform Q operations of the following 4 types:

1. append (W) - Append string W to the end of S.
2. delete (k) - Delete the last k characters of S.
3. print (k) - Print the k-th character of S.
4. undo () - Undo the last (not previously undone) operation of type 1 or 2, reverting S to the state it was in prior to that operation.

---

### Deskripsi Soal
Kamu diminta untuk membuat editor teks sederhana yang dapat melakukan beberapa operasi dasar terhadap sebuah string kosong yang awalnya bernilai "" (kosong). Tugasmu adalah mengimplementasikan fungsi-fungsi berikut:

### Jenis Operasi yang Didukung
Program harus mendukung 4 jenis operasi:
1. **Append**
   Format: `1 <string>`
   Tambahkan string `<string>` ke **akhir** dari string utama `S`.
2. **Delete**
   Format: `2 <k>`
   Hapus **`k` karakter terakhir** dari string `S`.
3. **Print**
   Format: `3 <k>`
   Cetak karakter ke-`k` dari string `S` (menggunakan indeks **1-based**, artinya karakter pertama adalah indeks 1).
4. **Undo**
   Format: `4`
   Batalkan operasi `append` atau `delete` terakhir yang dilakukan (yang belum di-undo sebelumnya). Kembalikan string ke kondisi **sebelum operasi itu terjadi**.

## Input Format
* Baris pertama: Sebuah bilangan bulat `Q` — jumlah total operasi yang akan dilakukan.
* Diikuti `Q` baris berikutnya, masing-masing merepresentasikan satu operasi dalam salah satu dari empat format di atas.

### Output Format
* Untuk setiap operasi bertipe `3`, cetak satu baris output yang berisi karakter ke-`k` dari string `S`.

### Batasan (Constraints)
* Total panjang semua string yang ditambahkan ke `S` tidak melebihi `10^6` karakter.
* Jumlah operasi `Q` tidak melebihi `10^5`.
* Semua karakter adalah huruf kecil (a–z).
* Operasi yang diberikan **selalu valid** (tidak akan ada operasi yang menyebabkan kesalahan seperti print dari indeks yang tidak ada, atau delete melebihi panjang string).


---
### Contoh Input:

```
STDIN   Function
-----   --------
8       Q = 8
1 abc   ops[0] = '1 abc'
3 3     ops[1] = '3 3'
2 3     ...
1 xy
3 2
4 
4 
3 1
```

### Contoh Output:

```
c
y
a
```

---

## Penjelasan

1. `1 abc` → S = "abc"
2. `3 3` → cetak karakter ke-3 = "c"
3. `2 3` → hapus 3 karakter → S = ""
4. `1 xy` → S = "xy"
5. `3 2` → cetak karakter ke-2 = "y"
6. `4` → undo `1 xy` → kembali jadi `""`
7. `4` → undo `2 3` → kembali jadi `"abc"`
8. `3 1` → cetak karakter ke-1 = "a"

---

## **Implementasi Lengkap**
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    string S = "";                   // string utama
    stack<string> history;          // menyimpan riwayat untuk undo

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) { // Append W
            string W;
            cin >> W;
            history.push(S); // simpan state sebelum berubah
            S += W;          // tambahkan ke string
        } 
        else if (op == 2) { // Delete k
            int k;
            cin >> k;
            history.push(S); // simpan state sebelum berubah
            S.erase(S.size() - k); // hapus k karakter dari belakang
        } 
        else if (op == 3) { // Print k-th character
            int k;
            cin >> k;
            cout << S[k - 1] << '\n'; // k dimulai dari 1
        } 
        else if (op == 4) { // Undo
            if (!history.empty()) {
                S = history.top(); // kembalikan state sebelumnya
                history.pop();     // hapus dari riwayat
            }
        }
    }
    
    return 0;
}
```

---

### Penjelasan Tiap Operasi:
* **`1 W`**:
  * Simpan `S` di stack → agar bisa di-*undo*.
  * Tambahkan `W` ke `S`.
* **`2 k`**:
  * Simpan `S` di stack.
  * Hapus `k` karakter terakhir dari `S`.
* **`3 k`**:
  * Cetak karakter ke-`k` dari `S`. (Karena index mulai dari 1, gunakan `S[k-1]`.)
* **`4`**:
  * Ambil nilai terakhir dari `history` dan tetapkan ke `S`.
