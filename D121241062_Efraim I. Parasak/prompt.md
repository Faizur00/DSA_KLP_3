# AI Prompt dan Analisis


**Link Percakapan:**  
- https://chatgpt.com/share/6822e705-dd60-800b-8c92-88663fb74580
  

### Pertanyaan Soal
- Bagaimana cara mengimplementasikan operasi queue (enqueue, dequeue, front) menggunakan dua stack?
- Bagaimana memastikan prinsip FIFO tetap terjaga meskipun menggunakan struktur LIFO?
  

##  Tujuan Program

Implementasi **Queue (antrian)**, tapi menggunakan **dua Stack** (tumpukan).

> Queue: First-In-First-Out (FIFO)
> Stack: Last-In-First-Out (LIFO)

---


### Prompt (Sumber Soal)
In this challenge, you must first implement a queue using two stacks. Then process queries, where each query is one of the following types: 
 1 x: **Enqueue** element into the end of the queue. 
 2: **Dequeue** the element at the front of the queue. 
 3: **Print** the element at the front of the queue.

Input Format The first line contains a single integer, , denoting the number of queries. Each line of the subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query , but only query is followed by an additional space-separated value, , denoting the value to be enqueued. 

Output Format For each query of type , print the value of the element at the front of the queue on a new line. 

kerjakan dalam program c++


###  **Penjelasan Singkat:**

Untuk membuat queue dengan dua stack (`stack_enqueue` dan `stack_dequeue`):

* `stack_enqueue` untuk **menambahkan elemen (push)**.
* `stack_dequeue` untuk **menghapus atau mengakses elemen paling depan**:

  * Jika `stack_dequeue` kosong, pindahkan semua elemen dari `stack_enqueue` ke `stack_dequeue`.
  * Lalu untuk `dequeue`, `pop` dari `stack_dequeue`.
  * Untuk `print front`, `print top()` dari `stack_dequeue`.

---

###  **Contoh Input:**

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

###  **Output:**

```
14
14
```




Berikut adalah penjelasan **baris demi baris dan konsep per konsep** dari kode **C++** yang membuat **Queue dengan dua Stack**.

---

##  Struktur Kode

Kode ini memiliki:

1. **Class `QueueUsingTwoStacks`** – berisi dua stack dan fungsi queue (`enqueue`, `dequeue`, `printFront`)
2. **Fungsi `main()`** – membaca input query dan menjalankan perintah yang sesuai.

---

##  Penjelasan Class `QueueUsingTwoStacks`



###  Dua Stack:

```cpp
class QueueUsingTwoStacks {
private:
    stack<int> stack_enqueue;
    stack<int> stack_dequeue;
```

* `stack_enqueue`: tempat masuknya data baru (seperti ujung belakang queue)
* `stack_dequeue`: tempat keluarnya data (seperti ujung depan queue)

---


###  Fungsi `transferStack()`

```cpp
    void transferStack() {
        if (stack_dequeue.empty()) {
            while (!stack_enqueue.empty()) {
                stack_dequeue.push(stack_enqueue.top());
                stack_enqueue.pop();
            }
        }
    }
```

* Tujuannya: memindahkan data dari `stack_enqueue` ke `stack_dequeue`
* Ini dibutuhkan karena stack tidak bisa langsung mengakses elemen pertama yang masuk (FIFO).
* Saat memindah dari `enqueue` ke `dequeue`, urutan data akan dibalik, sehingga urutan FIFO bisa dicapai.

---


###  `enqueue(x)`

```cpp
    void enqueue(int x) {
        stack_enqueue.push(x);
    }
```

* Menambahkan elemen baru ke stack `enqueue`.

---


###  `dequeue()`

```cpp
    void dequeue() {
        transferStack();
        if (!stack_dequeue.empty()) {
            stack_dequeue.pop();
        }
    }
```

* Pastikan data sudah dipindah ke `stack_dequeue` jika perlu.
* Hapus elemen paling depan (dari `stack_dequeue`).

---


###  `printFront()`

```cpp
    void printFront() {
        transferStack();
        if (!stack_dequeue.empty()) {
            cout << stack_dequeue.top() << endl;
        }
    }
```

* Memastikan urutan FIFO dulu, lalu tampilkan elemen depan queue (top dari `stack_dequeue`).

---

##  Fungsi `main()`


* Input jumlah query (`q`).

```cpp
int main() {
    int q;
    cin >> q;
```


---


* Membuat objek `queue` dari class `QueueUsingTwoStacks`.

```cpp
    QueueUsingTwoStacks queue;
```

---


* Membaca setiap query satu per satu.
* Query selalu diawali angka `1`, `2`, atau `3`.

```cpp
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
```

---


* `1 x`: enqueue x → panggil `enqueue(x)`
* `2`: dequeue → panggil `dequeue()`
* `3`: tampilkan elemen depan → panggil `printFront()`

```cpp
        if (type == 1) {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (type == 2) {
            queue.dequeue();
        } else if (type == 3) {
            queue.printFront();
        }
```


---

##  Contoh Simulasi

Input:

```
10
1 42      // Enqueue 42
2         // Dequeue 42
1 14      // Enqueue 14
3         // Print -> 14
1 28      // Enqueue 28
3         // Print -> 14
1 60      // Enqueue 60
1 78      // Enqueue 78
2         // Dequeue 14
2         // Dequeue 28
```

**Urutan Queue (secara FIFO):**
`14 -> 28 -> 60 -> 78`
Setelah dua dequeue:
`60 -> 78`

---



###  **Kesimpulan Singkat**

Queue adalah struktur data FIFO (First-In-First-Out), sedangkan stack bersifat LIFO (Last-In-First-Out). Untuk membuat queue dengan dua stack:

* Gunakan satu stack (`stack_enqueue`) untuk **memasukkan data**.
* Gunakan stack kedua (`stack_dequeue`) untuk **mengeluarkan data**.
* Saat `stack_dequeue` kosong, pindahkan semua isi `stack_enqueue` ke `stack_dequeue` agar urutan data menjadi sesuai FIFO.

Dengan cara ini, kita bisa menjalankan operasi **enqueue, dequeue, dan print front** seperti queue, meskipun menggunakan stack.












