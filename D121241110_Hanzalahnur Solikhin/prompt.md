# AI Prompt dan Analisis
**Link Percakapan:**  
- [AI Prompt for Stack](https://chatgpt.com/c/682330b9-24d8-800d-94f1-27904c14d370)

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

Kita butuh **dua stack**:

1. `mainStack`: untuk elemen biasa
2. `maxStack`: untuk melacak maksimum saat ini

---

## **Langkah-langkah:**

### 1. Alokasikan stack dinamis atau statis

### 2. Untuk setiap operasi:

* Jika `"1 x"`: push ke `mainStack`, dan update `maxStack`
* Jika `"2"`: pop dari keduanya
* Jika `"3"`: ambil `top` dari `maxStack`, tambahkan ke hasil output

### 3. Kembalikan array hasil ke `main()`

---

## **Implementasi Fungsi `getMax`**

Tambahkan ke bawah kode kamu:

```c
int* getMax(int operations_count, char** operations, int* result_count) {
    // Maksimum jumlah operasi "3" tidak melebihi operations_count
    int* result = malloc(operations_count * sizeof(int));
    int resultIndex = 0;

    // Stack utama dan stack maksimum
    int* stack = malloc(operations_count * sizeof(int));
    int* maxStack = malloc(operations_count * sizeof(int));
    int top = -1;
    int maxTop = -1;

    for (int i = 0; i < operations_count; i++) {
        if (operations[i][0] == '1') {
            // Push operation
            int x;
            sscanf(operations[i], "1 %d", &x);

            // Push ke stack utama
            stack[++top] = x;

            // Push ke maxStack jika kosong atau x lebih besar/sama
            if (maxTop == -1 || x >= maxStack[maxTop]) {
                maxStack[++maxTop] = x;
            } else {
                // Salin nilai maksimum sebelumnya (agar tetap sinkron saat pop)
                maxStack[++maxTop] = maxStack[maxTop];
            }

        } else if (operations[i][0] == '2') {
            // Pop operation
            if (top >= 0) {
                top--;
                maxTop--;
            }
        } else if (operations[i][0] == '3') {
            // Get max operation
            if (maxTop >= 0) {
                result[resultIndex++] = maxStack[maxTop];
            }
        }
    }

    // Set jumlah hasil yang dikembalikan
    *result_count = resultIndex;
    return result;
}
```

---

## Penjelasan Konsep:

| Operasi | Penjelasan                                                         |
| ------- | ------------------------------------------------------------------ |
| `"1 x"` | Simpan x di `stack` dan perbarui `maxStack`                        |
| `"2"`   | Hapus dari `stack` dan `maxStack`                                  |
| `"3"`   | Ambil nilai maksimum dari `maxStack[top]` dan simpan ke `result[]` |

---

## Output:

* Fungsi `getMax()` akan menghasilkan array `int*` berisi semua nilai maksimum dari setiap perintah `"3"`.

---

## Catatan Tambahan:

* Gunakan `malloc()` untuk semua array karena data akan dikembalikan keluar fungsi.
* Jangan lupa atur nilai `*result_count` agar `main()` bisa tahu panjang array hasil.
