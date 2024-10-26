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

void insertSorted_2311104005(List *L, address P) {
    address Q = L->head;
    address Prev = NULL;
    int found = 0;
    
    while (Q != NULL && !found) {
        if (Q->info < P->info) {
            Prev = Q;
            Q = Q->next;
        } else {
            found = 1;
        }
    }
    
    if (Q == L->head) {
        P->next = L->head;
        L->head = P;
    }
    else if (Q == NULL) {
        Prev->next = P;
        P->next = NULL;
    }
    else {
        P->next = Q;
        Prev->next = P;
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
    
    
    printf("Masukkan 4 bilangan bulat secara terurut (dari kecil ke besar):\n");
    for(int i = 0; i < 4; i++) {
        int nilai;
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", &nilai);
        address nodeBaru = createNode_2311104005(nilai);
        insertSorted_2311104005(&L, nodeBaru);
    }
    
    printf("\nList saat ini: ");
    printList_2311104005(L);
    
    printf("\nMasukkan nilai baru yang akan disisipkan: ");
    int nilaiBaru;
    scanf("%d", &nilaiBaru);
    address nodeBaru = createNode_2311104005(nilaiBaru);
    insertSorted_2311104005(&L, nodeBaru);
    
    printf("Setelah penyisipan: ");
    printList_2311104005(L);
    
    freeList_2311104005(&L);
    
    return 0;
}