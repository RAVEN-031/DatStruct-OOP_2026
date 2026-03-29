#include <iostream>
#include <string>

// tfw no premade format to fill :(
class listNode {
public:
    listNode(std::string name, int energy) : name(name), energy(energy), _next(nullptr) {};

    std::string name;
    int energy;
    
    listNode* _next;
};

class list {
private:
    listNode* _head;
    listNode* _tail;
    int energy;
    int size;

public:
    list() : _head(nullptr), _tail(nullptr), energy(0), size(0) {};

    // [Insert comment for empty list check] am bored, gonna mess around in the comments
    bool isEmpty() {
        return _head == nullptr;
    }

    // Since I'm naming these based on the conventions, the comments are very unnecessary
    void pushFront(std::string name, int energy) {
        listNode* pNewNode = new listNode(name, energy);

        if (isEmpty()) _head = _tail = pNewNode;
        else { pNewNode->_next = _head; _head = pNewNode; }
        // onelining cuz why not
        size++;
        this->energy += energy;
    }

    // Nevermind, onelining causes inconsistency in my code format 7-7
    void pushBack(std::string name, int energy) {
        listNode* pNewNode = new listNode(name, energy);

        if (isEmpty()) _head = _tail = pNewNode;
        else {
            _tail->_next = pNewNode;
            _tail = pNewNode;
        }
        size++;
        this->energy += energy;
        // Yup, won't oneline the code, I just got confused with size incrementation
    }

    // Man, index addition \u[unicode_number_for_wilted_flower_emoji]
    void insertAt(std::string name, int energy, int index) {
        if (index < 0 || index > size) {
            std::cout << "Index tidak valid!\n";
        }
        else {
            if (index == 0) pushFront(name, energy);
            else if (index == size) pushBack(name, energy);
            else {
                listNode* pNewNode = new listNode(name, energy);
                listNode* pTrav = _head;

                for (int i = 0; i < index - 1; i++) {
                    pTrav = pTrav->_next;
                }
                pNewNode->_next = pTrav->_next;
                pTrav->_next = pNewNode;
                size++;
            }
            std::cout << "Kegiatan berhasil disisipkan!\n";
            this->energy += energy;
        }
    }

    // I wanna maimai
    void deleteAt(int index) {
        if (index < 0 || index >= size || isEmpty()) {
            std::cout << "Index tidak ditemukan!\n";
        }
        else {
            listNode* pTrash;

            if (index == 0) {
                pTrash = _head;
                if (_head == _tail) _head = _tail = nullptr;
                else _head = pTrash->_next;
            }
            else {
                listNode* pTrav = _head;

                for (int i = 0; i < index - 1; i++) {
                    pTrav = pTrav->_next;
                }
                if (index == size-1) _tail = pTrav;
                pTrash = pTrav->_next;
                pTrav->_next = pTrash->_next;
            }
            std::cout << "Kegiatan berhasil dihapus!\n";
            this->energy -= pTrash->energy;
            delete pTrash;
            size--;
        }
    }

    /*
    If a man is scared of talking to girls, what if said man thinks of girls as femboys?
    Would it allow the man to talk normally?
    */
   void showList() {
        std::cout << "\nDaftar Kegiatan\n";
        if (isEmpty()) {
            std::cout << "Belum ada kegiatan.\n";
        }
        else {
            listNode* pTrav = _head;
            int index = 0;
            while (pTrav != nullptr) {
                std::cout << "[" << index << "] " << pTrav->name << " (Energi: " << pTrav->energy << ")\n";
                index++;
                pTrav = pTrav->_next;
            }
        }
   }
   
   // Fitgirl Repacks for life!!!
   void showEnergy() {
        std::cout << "Total Energi yang dibutuhkan: " << energy << std::endl;
   }
};

int main() {
    list rencana;
    std::string input;
    std::string dat1;
    int dat2;
    int index;
    bool flag = true;

    while (flag) {
        std::cin >> input;
        // Data Parsing
        if (input == "TAMBAH" || input == "KEGIATAN") std::cin >> dat1 >> dat2;
        if (input == "SISIPKAN") std::cin >> dat1 >> dat2 >> index;
        if (input == "HAPUS") std::cin >> index;
        
        // Execution
        if (input == "TAMBAH") {
            rencana.pushFront(dat1, dat2);
            std::cout << "Kegiatan " << dat1 << " berhasil ditambahkan di depan!\n";
        }
        else if (input == "KEGIATAN") {
            rencana.pushBack(dat1, dat2);
            std::cout << "Kegiatan " << dat1 << " berhasil ditambahkan!\n";
        }
        else if (input == "SISIPKAN") rencana.insertAt(dat1, dat2, index);
        else if (input == "HAPUS") rencana.deleteAt(index);
        else if (input == "HISTORI") rencana.showList();
        else if (input == "STATUS") rencana.showEnergy();
        else if (input == "KELUAR") flag = false;
        else {
            std::cout << "Perintah tidak dikenali!\n";
        }
    }
    

    return 0;
}