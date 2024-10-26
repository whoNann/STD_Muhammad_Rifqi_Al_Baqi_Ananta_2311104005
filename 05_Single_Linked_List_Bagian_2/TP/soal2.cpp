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

void bubbleSort_2311104005(List *L) {
    int ditukar;
    address current;
    address akhir = NULL;
    
    if (L->head == NULL)
        return;
        
    do {
        ditukar = 0;
        current = L->head;
        
        while (current->next != akhir) {
            if (current->info > current->next->info) {
                int temp = current->info;
                current->info = current->next->info;
                current->next->info = temp;
                ditukar = 1;
            }
            current = current->next;
        }
        akhir = current;
    } while (ditukar);
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
    
    
    printf("Masukkan 5 bilangan bulat:\n");
    for(int i = 0; i < 5; i++) {
        int nilai;
        printf("Masukkan angka ke-%d: ", i+1);
        scanf("%d", &nilai);
        insertFirst_2311104005(&L, nilai);
    }
    
    printf("\nSebelum diurutkan: ");
    printList_2311104005(L);
    
    bubbleSort_2311104005(&L);
    
    printf("Setelah diurutkan: ");
    printList_2311104005(L);
    
    freeList_2311104005(&L);
    
    return 0;
}