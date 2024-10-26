#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};
typedef struct Node* address;

typedef struct {
    address head;
} List;

address createNode_2311104005(int nilai) {
    address nodeBaru = (address)malloc(sizeof(struct Node));
    if (nodeBaru != NULL) {
        nodeBaru->info = nilai;
        nodeBaru->next = NULL;
    }
    return nodeBaru;
}

void insertFirst_2311104005(List *L, int nilai) {
    address nodeBaru = createNode_2311104005(nilai);
    if (nodeBaru != NULL) {
        nodeBaru->next = L->head;
        L->head = nodeBaru;
    }
}

int searchElement_2311104005(List L, int i) {
    address current = L.head;
    int posisi = 1;
    
    while (current != NULL && current->info != i) {
        current = current->next;
        posisi++;
    }
    
    if (current != NULL) {
        printf("Elemen ditemukan pada alamat %p, urutan ke-%d\n", current, posisi);
        return posisi;
    } else {
        printf("Elemen tidak ditemukan dalam list\n");
        return -1;
    }
}

void printList_2311104005(List L) {
    address current = L.head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    printf("\n");
}

void freeList_2311104005(List *L) {
    address current = L->head;
    while (current != NULL) {
        address temp = current;
        current = current->next;
        free(temp);
    }
    L->head = NULL;
}

int main() {
    List L;
    L.head = NULL;
    int nilaiCari;
    
    printf("=== Program Pencarian Elemen dalam Single Linked List ===\n");
    printf("Oleh: Nanta (2311104005)\n\n");
    
    // Memasukkan 6 elemen
    printf("Masukkan 6 bilangan bulat:\n");
    for(int i = 0; i < 6; i++) {
        int nilai;
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", &nilai);
        insertFirst_2311104005(&L, nilai);
    }
    
    printf("\nIsi list saat ini: ");
    printList_2311104005(L);
    
    printf("\nMasukkan nilai yang ingin dicari: ");
    scanf("%d", &nilaiCari);
    searchElement_2311104005(L, nilaiCari);
    
    freeList_2311104005(&L);
    
    return 0;
}