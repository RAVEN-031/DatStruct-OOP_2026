#include <iostream>
#include <string>

class Pengeluaran {
public:
    std::string item;
    int harga;
    Pengeluaran(std::string item, int harga) : item(item), harga(harga) {}

    std::string getItem() {return item;}
    int getHarga() {return harga;}
};

class Node {
public:
    Pengeluaran* pData;
    Node* _next;
    Node(std::string item, int harga) : _next(nullptr) {
        pData = new Pengeluaran(item, harga);
    }
};

class CatatanPengeluaran {
private:
    Node* _head;
    Node* _tail;
    int size;
public:
    CatatanPengeluaran() : _head(nullptr), _tail(nullptr), size(0) {}

    bool isEmpty() {
        return _head == nullptr;
    }

    void pushBack(std::string item, int harga) {
        Node* pNewNode = new Node(item, harga);

        if (isEmpty()){
            _head = _tail = pNewNode;
        }
        else {
            _tail->_next = pNewNode;
            _tail = pNewNode;
        }
        size++;
    }

    void pushFront(std::string item, int harga) {
        Node* pNewNode = new Node(item, harga);

        if (isEmpty()) _head = _tail = pNewNode;
        else { pNewNode->_next = _head; _head = pNewNode; }
        size++;
    }

    void insertAt(std::string item, int harga, int index) {
        if (index < 0 || index > size) {
            std::cout << "Index tidak valid!\n";
        }
        else {
            if (index == 0) pushFront(item, harga);
            else if (index == size) pushBack(item, harga);
            else {
                Node* pNewNode = new Node(item, harga);
                Node* pTrav = _head;

                for (int i = 0; i < index - 1; i++) {
                    pTrav = pTrav->_next;
                }
                pNewNode->_next = pTrav->_next;
                pTrav->_next = pNewNode;
                size++;
            }
        }
    }

    void deleteAt(int index) {
        if (index < 0 || index >= size || isEmpty()) {
            std::cout << "Index tidak valid!\n";
        }
        else {
            Node* pTrash;

            if (index == 0) {
                pTrash = _head;
                if (_head == _tail) _head = _tail = nullptr;
                else _head = pTrash->_next;
            }
            else {
                Node* pTrav = _head;

                for (int i = 0; i < index - 1; i++) {
                    pTrav = pTrav->_next;
                }
                if (index == size-1) _tail = pTrav;
                pTrash = pTrav->_next;
                pTrav->_next = pTrash->_next;
            }
            delete pTrash;
            size--;
        }
    }

    void showList() {
        int total = 0;
        if (isEmpty()) {
            std::cout << "Daftar pengeluaran kosong!\n";
            return;
        }
        else {
            Node* pTrav = _head;
            int index = 0;
            while (pTrav != nullptr) {
                std::cout << "[" << index << "] " << pTrav->pData->getItem() << ": Rp" << pTrav->pData->getHarga() << "\n";
                index++;
                total += pTrav->pData->getHarga();
                pTrav = pTrav->_next;
            }
        }
        std::cout << "Total pengeluaran: Rp" << total << std::endl;
   }
};

int main() {
    CatatanPengeluaran list;
    int input;
    std::string cmd;
    std::string dat1;
    int dat2;
    int index;

    std::cin >> input;
    for (int i = 0; i < input; i++) {
        std::cin >> cmd;
        if (cmd == "TAMBAH_BELAKANG" || cmd == "TAMBAH_DEPAN"){
            std::cin >> dat1 >> dat2;
        }
        else if (cmd == "HAPUS_INDEX") {
            std::cin >> index;
        }
        else if (cmd == "SISIPKAN") {
            std::cin >> index >> dat1 >>dat2; 
        }
        if (cmd == "TAMBAH_BELAKANG") list.pushBack(dat1, dat2);
        else if (cmd == "TAMBAH_DEPAN") list.pushFront(dat1, dat2);
        else if (cmd == "HAPUS_INDEX") list.deleteAt(index);
        else if (cmd == "SISIPKAN") list.insertAt(dat1, dat2, index);
        else if (cmd == "TAMPILKAN") list.showList();
    }


}