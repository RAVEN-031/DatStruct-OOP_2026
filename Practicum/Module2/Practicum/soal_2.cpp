#include <iostream>
#include <string>

/*
Personal notes:
_varname : Pointer for in-node variables *head, tail, etc
pObjectName : Pointer for objects * pNewNode
*/


// Node untuk setiap lagu dalam playlist
class SongNode {
public:
    SongNode(std::string judul) : lagu(judul), _next(nullptr) {}

    std::string lagu;
    SongNode* _next;
};

// Singly Linked List untuk playlist
class Playlist {
private:
    SongNode* _head;
    SongNode* _tail;

public:
    Playlist() : _head(nullptr), _tail(nullptr) {}

    bool isEmpty() {
        return _head == nullptr;
    }

    // Tambah lagu di akhir playlist
    void tambahBelakang(std::string judul) {
        SongNode* pNewSong = new SongNode(judul);

        if (isEmpty()){
            _head = _tail = pNewSong;
        }
        else {
            _tail->_next = pNewSong;
            _tail = pNewSong;
        }
    }

    // Tambah lagu di awal playlist
    void tambahDepan(std::string judul) {
        SongNode* pNewSong = new SongNode(judul);
        
        if(isEmpty()) {
            _head = _tail = pNewSong;
        }
        
        else {
            pNewSong->_next = _head;
            _head = pNewSong;
        }
    }

    // Hapus lagu paling awal
    void hapusDepan() {
        if (isEmpty()) {
            std::cout << "Playlist kosong, Kamu belum pilih lagu!\n";
        }
        else {
            SongNode* pTrash = _head;

            if (_head == _tail) _tail = nullptr; //Checks if head = tail
            _head = _head->_next;
            delete pTrash;
        }

    }

    // Hapus lagu paling akhir
    void hapusBelakang() {
        if (isEmpty()) {
            std::cout << "Playlist kosong, Kamu belum pilih lagu!\n";
        }
        else {
            SongNode* pTrash = _tail;
            SongNode* pTrav = _head;

            if (_head == _tail) {   // Checks if there's only one object
                _head = _tail = nullptr;
                delete pTrash;
                return;
            }
            while (pTrav->_next != _tail) {
                pTrav = pTrav->_next;
            }
            _tail = pTrav;
            _tail->_next = nullptr;
            delete pTrash;
        }
    }

    // Hapus lagu tertentu berdasarkan judul
    void hapusLagu(std::string judul) {
        if (isEmpty()) {
            std::cout << "NOT FOUND\n";
        }
        else {
            if (_head->lagu == judul) { // Case if head is the deleted
                SongNode* pTrash  = _head;

                if (_head == _tail) _head =_tail = nullptr; // Case if 
                else _head = _head->_next;
                delete pTrash;
                return;
            }
            
            SongNode* pTrav = _head;
            //man, I wish this was double linked list
            while (pTrav->_next != nullptr) {
                if (pTrav->_next->lagu == judul) {
                    SongNode* pTrash = pTrav->_next;
                    pTrav->_next = pTrash->_next;
                    if (pTrash->_next == nullptr) _tail = pTrav; // Checks if deleted is tail and updates it
                    delete pTrash;
                    return;
                    // Note: Doesn't traverse if deletion happens
                }
                else {
                    pTrav = pTrav->_next;
                }
            }
            std::cout << "NOT FOUND\n";
        }
    }

    // Tampilkan semua lagu
    void tampilkan() {
        if (isEmpty()) {
            std::cout << "EMPTY\n";
        }
        else {
            SongNode* pTrav = _head;
            while (pTrav != nullptr) {
                std::cout << pTrav->lagu << " ";
                pTrav = pTrav->_next;
            }
            std::cout << std::endl;
            
        }


    }
};

int main() {
    int len;
    Playlist list;
    std::cin >> len;
    std::string cmd;
    std::string dat;

    for (int i = 0; i < len; i++) {
        std::cin >> cmd;
        if (cmd == "PUSH_FRONT" || cmd == "PUSH_BACK" || cmd == "DELETE"){
            std::cin >> dat;
        }
        if (cmd == "PUSH_BACK") list.tambahBelakang(dat);
        else if (cmd == "PUSH_FRONT") list.tambahDepan(dat);
        else if (cmd == "DELETE") list.hapusLagu(dat);
        else if (cmd == "PRINT") list.tampilkan();
    }
}