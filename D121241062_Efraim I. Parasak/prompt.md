
###  **Penjelasan Singkat:**

Kita menggunakan dua stack:

* `stack_enqueue` untuk **menambahkan elemen (push)**.
* `stack_dequeue` untuk **menghapus atau mengakses elemen paling depan**.

Saat `stack_dequeue` kosong dan kita perlu melakukan dequeue atau melihat elemen depan (query 2 dan 3), kita **pindahkan semua elemen dari `stack_enqueue` ke `stack_dequeue`** (proses ini membalik urutan, sehingga elemen pertama akan berada di atas `stack_dequeue`).

---


### ✅ **Contoh Input:**

```
10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
```

### ✅ **Output:**

```
14
14
```

---

##  **Tujuan Program**

Membuat antrian (queue) menggunakan **dua buah stack**, lalu menjalankan perintah berdasarkan input:

* **1 x** → Tambahkan elemen ke belakang antrian.
* **2** → Hapus elemen dari depan antrian.
* **3** → Cetak elemen yang ada di depan antrian.

---

##  **Struktur Data yang Digunakan**

```cpp
stack<int> stack_enqueue;  // untuk enqueue (penambahan)
stack<int> stack_dequeue;  // untuk dequeue dan melihat elemen depan
```

Kenapa dua stack?

* Karena **stack bersifat LIFO (Last-In, First-Out)**, sedangkan **queue harus FIFO (First-In, First-Out)**.
* Maka, kita menggunakan dua stack untuk **membalik urutan**, sehingga kita bisa meniru perilaku queue.

---

##  **Penjelasan Fungsi `shiftStacks`**

```cpp
void shiftStacks(stack<int>& s1, stack<int>& s2) {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
}
```

### Fungsi ini melakukan:

* Memindahkan semua elemen dari `stack_enqueue` (s1) ke `stack_dequeue` (s2) **jika** `stack_dequeue` kosong.
* Saat dipindah, elemen yang duluan masuk akan berada di atas `stack_dequeue`, sehingga bisa diakses pertama → mirip antrian (FIFO).

---

##  **Bagian `main()`**

```cpp
int q;
cin >> q;
```

* Membaca banyaknya query dari input.

```cpp
stack<int> stack_enqueue;
stack<int> stack_dequeue;
```

* Dua stack untuk menyimpan dan memproses data antrian.

---

###  Perulangan untuk memproses query:

```cpp
for (int i = 0; i < q; ++i) {
    int type;
    cin >> type;
```

* Baca jenis query (1, 2, atau 3).

---

###  **Query 1 x → Enqueue**

```cpp
if (type == 1) {
    int x;
    cin >> x;
    stack_enqueue.push(x);
}
```

* Tambahkan elemen `x` ke `stack_enqueue`.

---

###  **Query 2 → Dequeue**

```cpp
else if (type == 2) {
    shiftStacks(stack_enqueue, stack_dequeue);
    if (!stack_dequeue.empty()) {
        stack_dequeue.pop();
    }
}
```

* Pertama, **pindahkan** elemen dari `stack_enqueue` ke `stack_dequeue` **jika perlu**.
* Kemudian, hapus elemen paling atas dari `stack_dequeue`, yang mewakili elemen paling depan dalam antrian.

---

###  **Query 3 → Print front element**

```cpp
else if (type == 3) {
    shiftStacks(stack_enqueue, stack_dequeue);
    if (!stack_dequeue.empty()) {
        cout << stack_dequeue.top() << endl;
    }
}
```

* Sama seperti query 2, tapi **tidak menghapus**, hanya mencetak elemen paling depan.

---

##  **Ilustrasi Sederhana**

Misalnya input:

```
1 5
1 10
1 15
3
2
3
```

1. Enqueue 5 → stack\_enqueue = \[5]
2. Enqueue 10 → stack\_enqueue = \[5, 10]
3. Enqueue 15 → stack\_enqueue = \[5, 10, 15]
4. Cetak front:

   * Pindahkan semua dari stack\_enqueue → stack\_dequeue = \[15, 10, 5]
   * Cetak top dari stack\_dequeue → hasil = **5**
5. Dequeue → hapus top dari stack\_dequeue (5)
6. Cetak front → top dari stack\_dequeue = **10**

---

Kalau kamu ingin, saya juga bisa bantu buat versi dengan visualisasi langkah per langkah atau animasi stack-nya (teks). Mau?


