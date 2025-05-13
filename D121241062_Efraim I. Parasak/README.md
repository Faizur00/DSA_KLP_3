# Tugas DSA - QUEUE

**Nama          :** Efraim Imanuel Parasak  
**NIM           :** D121241062  
**Problem Link  :** [Queue: Queue using Two Stacks - HackerRank](https://www.hackerrank.com/challenges/queue-using-two-stacks/problem)  
**Difficulty    :** Medium  

## Short Approach Summary

Queue adalah tipe data abstrak yang mempertahankan urutan elemen yang ditambahkan ke dalamnya, sehingga memungkinkan elemen tertua dihapus dari depan dan elemen baru ditambahkan ke belakang. Ini disebut struktur data First-In-First-Out (FIFO) karena elemen pertama yang ditambahkan ke dalam antrean (yaitu, elemen yang paling lama menunggu) selalu menjadi elemen pertama yang dihapus.

Sebuah antrean dasar memiliki operasi-operasi berikut:
Enqueue: menambahkan elemen baru ke akhir antrean.
Dequeue: menghapus elemen dari bagian depan antrean dan mengembalikannya.

Dalam soal ini, kita harus mengimplementasikan queue (antrian) menggunakan dua stack (tumpukan) . Kemudian proses query, di mana setiap query adalah salah satu dari tipe berikut:

1 x: Enqueue elemen ke akhir antrean.
2: Menghilangkan elemen di bagian depan antrean.
3: Mencetak elemen di bagian depan antrean.

Program harus memproses sejumlah query (perintah/permintaan) dimana masing-masing query adalah salah satu dari ketiga tipe diatas dan mencetak elemen terdepan setiap perintah tipe-3.


