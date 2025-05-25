# AI Prompt dan Analisis
**Link Percakapan:**  
- [AI Prompt for Stack](https://chatgpt.com/c/6833849a-0fd4-8000-8e2d-ce0a193433fa)

---

## Sumber Soal
You have an empty sequence, and you will be given  queries. Each query is one of these three types:

1 x  -Push the element x into the stack.

2    -Delete the element present at the top of the stack.

3    -Print the maximum element in the stack.

### Function Description

Complete the getMax function in the editor below.

getMax has the following parameters:
- string operations[n]: operations as strings

### Returns
- int[]: the answers to each type 3 query

### Input Format

The first line of input contains an integer, . The next  lines each contain an above mentioned query.

### Constraints
- 1 ≤ n ≤ 100000  
- 1 ≤ x ≤ 1000000000  
- 1 ≤ type ≤ 3  


All queries are valid.

---

### Deskripsi Soal

Anda diminta membuat program yang dapat melakukan operasi pada sebuah **stack**, yang mendukung tiga jenis operasi:

### Jenis Operasi:

1. `1 x` – Tambahkan elemen `x` ke dalam stack
2. `2` – Hapus elemen paling atas dari stack
3. `3` – Cetak **elemen maksimum** yang ada di dalam stack

---
### Contoh Input:

```
10
1 97
2
1 20
1 26
1 20
3
2
3
2
3
```

### Contoh Output:

```
26
26
20
```

---

## **Tujuan Fungsi `getMax`:**

* Menerima array string (`operations`) berisi perintah:

  * `"1 x"` → push x ke stack
  * `"2"` → pop elemen dari stack
  * `"3"` → simpan nilai maksimum saat ini di stack ke dalam hasil (`result`)
* Mengembalikan array hasil dari semua operasi `"3"`.

---

## **Strategi Penyelesaian**

* **`mainStack`** menyimpan semua elemen yang di-*push*.
* **`maxStack`** menyimpan nilai maksimum saat ini di posisi yang sama dengan elemen di `mainStack`.

  * Misalnya, jika `mainStack = [20, 26, 20]`, maka `maxStack = [20, 26, 26]`, karena 26 adalah nilai maksimum yang masih bertahan.
* Dengan begitu, kita bisa:

  * Menambahkan (`push`) nilai dan nilai maksimum bersamaan.
  * Menghapus (`pop`) dengan tetap menjaga struktur.
  * Mendapatkan nilai maksimum hanya dengan melihat `maxStack.top()` dalam O(1) waktu.
---

## **Implementasi Fungsi `getMax`**

Fungsi getMax yang dilengkapi dan dikomentari:

```cpp
vector<int> getMax(vector<string> operations) {
    stack<int> mainStack;     // Stack utama untuk menyimpan elemen
    stack<int> maxStack;      // Stack pembantu untuk menyimpan nilai maksimum saat ini
    vector<int> result;       // Menyimpan hasil dari setiap query '3'

    for (const string& op : operations) {
        if (op[0] == '1') { // Query '1 x' => push x ke stack
            // Ambil angka setelah spasi
            int x = stoi(op.substr(2));
            mainStack.push(x); // Push ke stack utama

            // Jika maxStack kosong atau x >= nilai maksimum sebelumnya, push x
            if (maxStack.empty() || x >= maxStack.top()) {
                maxStack.push(x);
            } else {
                // Push kembali nilai maksimum terakhir agar selalu tersedia
                maxStack.push(maxStack.top());
            }
        } else if (op[0] == '2') { // Query '2' => pop elemen dari stack
            if (!mainStack.empty()) {
                mainStack.pop();  // Hapus dari stack utama
                maxStack.pop();   // Hapus juga dari maxStack
            }
        } else if (op[0] == '3') { // Query '3' => ambil nilai maksimum
            if (!maxStack.empty()) {
                result.push_back(maxStack.top()); // Tambahkan nilai maksimum ke hasil
            }
        }
    }

    return result; // Kembalikan hasil dari semua query '3'
}

```

---

## Catatan Tambahan:

* Fungsi `substr(2)` digunakan karena input `'1 x'` memiliki spasi setelah angka 1, jadi kita ambil dari indeks ke-2 untuk mendapatkan nilai `x`.
* Fungsi `stoi()` mengubah string menjadi integer.
