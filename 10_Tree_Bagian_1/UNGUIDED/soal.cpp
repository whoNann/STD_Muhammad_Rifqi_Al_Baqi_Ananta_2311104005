#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Struktur Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

// Variabel Global
Pohon *root, *baru;

// Inisialisasi Root
void init()
{
    root = NULL;
}

// Mengecek apakah Pohon Kosong
bool isEmpty()
{
    return root == NULL;
}

// Membuat Root
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat jadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Menambahkan Child Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (node->left != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kiri." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Menambahkan Child Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (node->right != NULL)
    {
        cout << "\nNode " << node->data << " sudah ada child kanan." << endl;
        return NULL;
    }

    baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Menampilkan Anak (Child) dari Node
void showChild(Pohon *node)
{
    if (node == NULL)
    {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }

    cout << "\nNode: " << node->data << endl;
    cout << "Child kiri: " << (node->left ? node->left->data : '-') << endl;
    cout << "Child kanan: " << (node->right ? node->right->data : '-') << endl;
}

// Menampilkan Keturunan (Descendants) dari Node
void showDescendants(Pohon *node)
{
    if (node == NULL)
    {
        cout << "\nNode tidak ditemukan!" << endl;
        return;
    }

    queue<Pohon *> q;
    q.push(node);

    cout << "\nDescendants of node " << node->data << ": ";
    bool hasDescendants = false;

    while (!q.empty())
    {
        Pohon *current = q.front();
        q.pop();

        if (current != node)
        {
            hasDescendants = true;
            cout << current->data << " ";
        }

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }

    if (!hasDescendants)
        cout << "(Tidak ada descendant)";
    cout << endl;
}

// Memeriksa apakah Pohon adalah Binary Search Tree
bool is_valid_bst(Pohon *node, char min_val, char max_val)
{
    if (node == NULL)
        return true;

    if (node->data <= min_val || node->data >= max_val)
        return false;

    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Menghitung Jumlah Simpul Daun
int cari_simpul_daun(Pohon *node)
{
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return 1;

    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Menu Interaktif
void menu()
{
    int choice;
    char data, parentData;
    Pohon *parent;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Buat root\n";
        cout << "2. Tambah child kiri\n";
        cout << "3. Tambah child kanan\n";
        cout << "4. Tampilkan child\n";
        cout << "5. Tampilkan descendants\n";
        cout << "6. Periksa apakah BST\n";
        cout << "7. Hitung jumlah simpul daun\n";
        cout << "8. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;
        case 2:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data child kiri: ";
            cin >> data;
            parent = root; // Assign root dulu (harus cari jika tree besar)
            insertLeft(data, parent);
            break;
        case 3:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data child kanan: ";
            cin >> data;
            parent = root; // Assign root untuk sementara
            insertRight(data, parent);
            break;
        case 4:
            cout << "Masukkan data node: ";
            cin >> parentData;
            showChild(root); // Assign root untuk sementara
            break;
        case 5:
            cout << "Masukkan data node: ";
            cin >> parentData;
            showDescendants(root); // Assign root untuk sementara
            break;
        case 6:
            cout << "Pohon adalah BST: " << (is_valid_bst(root, CHAR_MIN, CHAR_MAX) ? "Ya" : "Tidak") << endl;
            break;
        case 7:
            cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
            break;
        case 8:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 8);
}

// Main Program
int main()
{
    init();
    menu();
    return 0;
}
