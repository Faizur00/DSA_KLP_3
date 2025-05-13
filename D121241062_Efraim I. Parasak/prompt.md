# AI Prompt dan Analisis

**Link Percakapan:**  
- https://chatgpt.com/share/6822e705-dd60-800b-8c92-88663fb74580

### Prompt (Sumber Soal)
In this challenge, you must first implement a queue using two stacks. Then process queries, where each query is one of the following types: 
1. 1 x: Enqueue element into the end of the queue. 
2. 2: Dequeue the element at the front of the queue. 
3. 3: Print the element at the front of the queue.

Input Format The first line contains a single integer, , denoting the number of queries. Each line of the subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query , but only query is followed by an additional space-separated value, , denoting the value to be enqueued. 

Output Format For each query of type , print the value of the element at the front of the queue on a new line. 

kerjakan dalam program c++



### Penjelasan Soal
Antrian (queue) adalah struktur data abstrak yang mengikuti prinsip **First-In-First-Out (FIFO)**, artinya elemen yang pertama dimasukkan akan menjadi elemen pertama yang dikeluarkan.

📎 **Detail:**
1. **Operasi Dasar:**
   - **Enqueue**: Menambahkan elemen baru ke ujung belakang antrian.
   - **Dequeue**: Menghapus elemen dari depan antrian.
   - **Front/Peek**: Melihat elemen di depan antrian tanpa menghapusnya.

2. **Implementasi dengan Dua Stack:**
   - Stack bersifat **LIFO (Last-In-First-Out)**, kebalikan dari queue.
   - Untuk mengimplementasikan queue, kita perlu dua stack:
     - **Stack1** untuk operasi enqueue.
     - **Stack2** untuk operasi dequeue.
   - Ketika `stack2` kosong, pindahkan semua elemen dari `stack1` ke `stack2` (membalik urutan elemen).

3. **Contoh Input/Output:**
   - **Input:**
     ```
     10      (jumlah query)
     1 42    (enqueue 42)
     2       (dequeue)
     1 14    (enqueue 14)
     3       (print front → 14)
     1 28    (enqueue 28)
     3       (print front → 14)
     1 60    (enqueue 60)
     1 78    (enqueue 78)
     2       (dequeue)
     2       (dequeue)
     ```
   - **Output:**
     ```
     14
     14
     ```

### Pertanyaan Soal
- Bagaimana cara mengimplementasikan operasi queue (enqueue, dequeue, front) menggunakan dua stack?
- Bagaimana memastikan prinsip FIFO tetap terjaga meskipun menggunakan struktur LIFO?

### Tujuan
- Mengimplementasikan antrian dengan dua tumpukan secara efisien.
- Memproses query sesuai jenis operasinya (enqueue/dequeue/front).
- Menjamin kompleksitas waktu amortized O(1) untuk setiap operasi.

### Analisis dan Pendekatan Solusi

#### 1. **Struktur Data**
   - **Stack1**: Digunakan untuk menampung elemen yang di-enqueue.
   - **Stack2**: Digunakan untuk operasi dequeue/front. Jika kosong, elemen dari `stack1` dipindahkan ke `stack2` (membalik urutan).

#### 2. **Operasi Utama**
   - **Enqueue**:
     - Langsung push ke `stack1` → O(1).
   - **Dequeue**:
     - Jika `stack2` kosong, pindahkan semua elemen dari `stack1` ke `stack2` → O(n) (kasus terburuk, tapi amortized O(1)).
     - Pop dari `stack2` → O(1).
   - **Front**:
     - Mirip dengan dequeue, tetapi hanya melihat elemen teratas `stack2` tanpa menghapus.

#### 3. **Kompleksitas Waktu**
   - **Enqueue**: O(1).
   - **Dequeue**: O(1) amortized (karena setiap elemen hanya dipindahkan sekali dari `stack1` ke `stack2`).
   - **Front**: O(1) amortized.

#### 4. **Ilustrasi Contoh**
   - **Enqueue 42, 14, 28**:
     - `stack1`: [42, 14, 28] (top = 28)
     - `stack2`: []
   - **Dequeue**:
     - Pindahkan semua ke `stack2`: [28, 14, 42] (top = 42)
     - Pop 42 → `stack2`: [28, 14]
   - **Front**:
     - Lihat 14 (tanpa pop).

#### 5. **Keuntungan Pendekatan**
   - Memanfaatkan sifat stack untuk membalik urutan elemen saat dipindahkan ke `stack2`.
   - Operasi dequeue/front efisien karena tidak perlu membalik stack setiap saat.


### Kesimpulan
- Dengan dua stack, kita bisa mensimulasikan antrian yang memenuhi FIFO.
- Kunci solusi adalah memindahkan elemen dari `stack1` ke `stack2` hanya ketika `stack2` kosong, sehingga operasi dequeue/front tetap efisien.
