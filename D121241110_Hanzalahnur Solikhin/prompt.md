# AI Prompt dan Analisis
**Link Percakapan:**  
- [AI Prompt for Stack](https://chatgpt.com/c/682330b9-24d8-800d-94f1-27904c14d370)

---

### Sumber Soal
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

## TUJUAN PROGRAM

Menangani 3 jenis operasi stack:

1. `1 x`: Push elemen x ke stack
2. `2`: Pop elemen dari top stack
3. `3`: Cetak nilai maksimum saat ini di stack

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

## BAGIAN-BAGIAN KODE

### 1. **Inisialisasi dan Import**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

* `stdio.h`: untuk fungsi input/output (`scanf`, `printf`, dll).
* `stdlib.h`: (opsional di sini), digunakan jika kita ingin pakai `malloc`, `atoi`, dll.
* `string.h`: untuk operasi string seperti `strcmp`, `strcpy`, dsb.

---

### 2. **Membuat Stack**

```c
#define MAX_SIZE 100000

int mainStack[MAX_SIZE];
int maxStack[MAX_SIZE];
int mainTop = -1;
int maxTop = -1;
```

#### Penjelasan:

* Kita menggunakan **dua stack**:

  * `mainStack`: Stack utama yang menyimpan semua elemen.
  * `maxStack`: Stack kedua yang menyimpan **nilai maksimum** saat ini.

#### Konsep penting:

* `mainTop` dan `maxTop`: menyimpan indeks paling atas (top) dari kedua stack.
* `-1` berarti stack kosong.

---

### 3. **Fungsi Push**

```c
void push(int x) {
    mainStack[++mainTop] = x;
```

* Tambahkan `x` ke stack utama, tingkatkan `mainTop`.

```c
    if (maxTop == -1 || x >= maxStack[maxTop]) {
        maxStack[++maxTop] = x;
    } else {
        maxStack[maxTop + 1] = maxStack[maxTop];
        maxTop++;
    }
}
```

#### Konsep:

* Jika stack maksimum kosong **atau** `x` lebih besar dari maksimum sebelumnya:

  * Tambahkan `x` ke `maxStack`.
* Jika tidak:

  * Tetap salin nilai maksimum sebelumnya ke atas (`maxTop+1`), agar nilai maksimum tetap akurat saat nanti pop.

---

### 4. **Fungsi Pop**

```c
void pop() {
    if (mainTop != -1) {
        mainTop--;
        maxTop--;
    }
}
```

#### Penjelasan:

* `mainTop--`: Hapus elemen dari stack utama.
* `maxTop--`: Ikut hapus dari stack maksimum karena kita maintain max secara paralel.

---

### 5. **Fungsi GetMax**

```c
int getMax() {
    return maxStack[maxTop];
}
```

#### Penjelasan:

* Karena setiap saat `maxStack` menyimpan nilai maksimum hingga posisi sekarang, cukup kembalikan elemen top-nya.

---

### 6. **Fungsi Main**

```c
int main() {
    int q;
    scanf("%d", &q);
    getchar(); // consume newline
```

* Membaca jumlah query (`q`) dari input.
* `getchar()` untuk menyerap newline setelah angka, agar `fgets()` berikutnya tidak salah baca.

```c
    char operation[20];
    for (int i = 0; i < q; i++) {
        fgets(operation, sizeof(operation), stdin);
```

* Membaca tiap baris perintah (maksimal 20 karakter).
* Misalnya `"1 97\n"`, `"2\n"`, `"3\n"`.

---

### 7. **Eksekusi Query**

```c
        if (operation[0] == '1') {
            int x;
            sscanf(operation, "1 %d", &x);
            push(x);
        }
```

* Jika operasi adalah `1 x`, ambil `x` dan panggil `push(x)`.

```c
        else if (operation[0] == '2') {
            pop();
        } else if (operation[0] == '3') {
            printf("%d\n", getMax());
        }
```

* Jika operasi `2`, hapus elemen paling atas.
* Jika `3`, cetak nilai maksimum saat ini.

---

## KONTEKS STACK MAKSIMUM

### Kenapa pakai 2 stack?

Misalkan input:

```
1 10
1 5
1 15
3
```

* `mainStack` → `[10, 5, 15]`
* `maxStack` → `[10, 10, 15]`

Saat kita push:

* `10`: max = 10
* `5`: max tetap 10
* `15`: max jadi 15

Saat kita pop:

* Hapus 15, max jadi 10 lagi karena `maxStack` juga di-pop.

> Ini membuat kita bisa mengambil nilai maksimum dalam **O(1)** waktu (konstan), tanpa harus scan stack setiap saat.

---

## KESIMPULAN

* Konsep kunci: stack, operasi paralel dengan stack maksimum.
* Waktu eksekusi:

  * `push` → O(1)
  * `pop` → O(1)
  * `getMax` → O(1)
