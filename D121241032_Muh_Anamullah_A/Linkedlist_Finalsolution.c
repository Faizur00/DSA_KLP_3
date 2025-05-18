#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk membaca input baris demi baris dari stdin
char* readline();

// Pendefinisian struct bertingkat untuk Node dan Linked List
typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

// Struktur node untuk single linked list
struct SinglyLinkedListNode {
    int data;                      // Menyimpan nilai data node
    SinglyLinkedListNode* next;    // Pointer ke node berikutnya
};

// Struktur untuk menyimpan head dan tail dari linked list
struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

// Fungsi untuk membuat node baru
SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode)); // Alokasi memori untuk node
    node->data = node_data;     // Set nilai data
    node->next = NULL;          // Set next ke NULL karena ini node terakhir
    return node;                // Kembalikan pointer node baru
}

// Fungsi untuk menambahkan node ke linked list
void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    // Jika linked list kosong, tetapkan head
    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        // Jika tidak kosong, tambahkan ke akhir (tail->next)
        (*singly_linked_list)->tail->next = node;
    }

    // Pindahkan tail ke node yang baru
    (*singly_linked_list)->tail = node;
}

// Fungsi untuk membebaskan memori dari linked list
void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

// ✅ FUNGSI UTAMA YANG DIMINTA: printLinkedList
void printLinkedList(SinglyLinkedListNode* head) {
    // Inisialisasi pointer current ke head
    SinglyLinkedListNode* current = head;

    // Selama current tidak NULL, cetak data
    while (current != NULL) {
        printf("%d\n", current->data);  // Cetak nilai data di node
        current = current->next;        // Pindah ke node berikutnya
    }
    // Ketika current == NULL, berarti sudah mencapai akhir list
}


int main()
{
    // Alokasi memori untuk linked list kosong
    SinglyLinkedList* llist = malloc(sizeof(SinglyLinkedList));
    llist->head = NULL;
    llist->tail = NULL;

    // Membaca jumlah elemen pada linked list
    char* llist_count_endptr;
    char* llist_count_str = readline();
    int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

    // Validasi input
    if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0') { exit(EXIT_FAILURE); }

    // Loop membaca data dan memasukkan node ke linked list
    for (int i = 0; i < llist_count; i++) {
        char* llist_item_endptr;
        char* llist_item_str = readline();
        int llist_item = strtol(llist_item_str, &llist_item_endptr, 10);

        if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0') { exit(EXIT_FAILURE); }

        insert_node_into_singly_linked_list(&llist, llist_item);
    }

    // Memanggil fungsi untuk mencetak seluruh isi linked list
    printLinkedList(llist->head);

    return 0;
}

// Fungsi untuk membaca satu baris input dari stdin
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
