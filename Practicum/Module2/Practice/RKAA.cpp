#include <iostream>
#include <string>

class Station {
public:
    std::string name;
    Station* _next;
    Station* _prev;

    Station(std::string name) : name(name), _next(nullptr), _prev(nullptr) {};
};

class System {
public:
    Station* _head;
    Station* _tail;
    Station* pCurrent;
    int _size;

    System() : _head(nullptr), _tail(nullptr), pCurrent(nullptr), _size(0) {};

    bool isEmpty() {return _head == nullptr;}
    
    void checkDelete(Station* pTrash) {
        if (pTrash == pCurrent && pCurrent->_next != nullptr) {
            pCurrent = pCurrent->_next;
        } 
        else if (pTrash == pCurrent && pCurrent->_prev != nullptr) {
            pCurrent = pCurrent->_prev;
        }
        else if (_head == _tail && _head == pCurrent){
            pCurrent = nullptr;
        }
    }

    void pushBack(std::string name) {
        Station* pNewNode = new Station(name);

        if (isEmpty()) _head = _tail = pCurrent = pNewNode;

        else {
            _tail->_next = pNewNode;
            pNewNode->_prev = _tail;
            _tail = pNewNode;
        }
        _size++;
    }

    void insertAt(std::string name, int index) {
        if (index < 0 || index >= _size) return;

        Station* pNewNode = new Station(name);

        if (isEmpty()) _head = _tail = pCurrent = pNewNode;
        else if (index == 0) {
            pNewNode->_next = _head;
            _head->_prev = pNewNode;
            _head = pNewNode;
        }
        else {
            Station* pTrav = _head;

            for (int i = 0; i < index - 1; i++) {
                pTrav = pTrav->_next;
            }
            pNewNode->_next = pTrav->_next;
            pTrav->_next->_prev = pNewNode;
            pNewNode->_prev = pTrav;
            pTrav->_next = pNewNode;
        }
        _size++;
    }
    
    void removeNode(std::string name) {
        if (isEmpty()) return;

        Station* pTrav = _head;
        Station* pTrash = nullptr;

        while (pTrav != nullptr) {
            if (pTrav == _head && pTrav->name == name) {
                pTrash = pTrav;
                checkDelete(pTrav);
                if (pTrav->_next != nullptr) pTrav->_next->_prev = nullptr;
                _head = _head->_next;
                pTrav = pTrav->_next;
                delete pTrash;
                _size--;
            }
            else if (pTrav == _tail && pTrav->name == name) {
                pTrash = pTrav;
                checkDelete(pTrav);
                if (pTrav->_prev != nullptr) pTrav->_prev->_next = nullptr;
                _tail = pTrav->_prev;
                pTrav = pTrav->_next;
                delete pTrash;
                _size--;
            }
            else if (pTrav->name == name) {
                pTrash = pTrav;
                checkDelete(pTrav);
                pTrav->_prev->_next = pTrav->_next;
                pTrav->_next->_prev = pTrav->_prev;
                pTrav = pTrav->_next;
                delete pTrash;
                _size--;
            }
            else pTrav = pTrav->_next;
        }
    }

    void moveForward() {
        if (pCurrent != nullptr && pCurrent->_next != nullptr) {
            pCurrent = pCurrent->_next;
        }
        else std::cout << "Kereta tidak bisa bergerak, salju terlalu tebal!\n";
    }

    void moveBackwards() {
        if (pCurrent != nullptr && pCurrent->_prev != nullptr) {
            pCurrent = pCurrent->_prev;
        }
        else {
            std::cout << "Kereta tidak bisa bergerak, salju terlalu tebal!\n";
        }
    }

    void showCurrent() {
        if (isEmpty()) {
            std::cout << "Takaki tersesat di tengah badai salju...\n";
        }
        else if (pCurrent != nullptr) {
            std::cout << "Takaki sekarang berada di: " << pCurrent->name << std::endl;
        }
        else {
            std::cout << "Takaki tersesat di tengah badai salju...\n";
        }
    }
};

int main() {
    System Train;

    int input;
    std::string cmd;
    int index;
    std::string dat;

    std::cin >> input;
    
    for (int i = 0; i < input; i++) {
        std::cin >> cmd;
        if (cmd == "ADD_STATION" || cmd == "REMOVE_STATION") std::cin >> dat;
        if (cmd == "INSERT_EMERGENCY") std::cin >> index >> dat;

        if (cmd == "ADD_STATION") Train.pushBack(dat);
        if (cmd == "INSERT_EMERGENCY") Train.insertAt(dat, index);
        if (cmd == "REMOVE_STATION") Train.removeNode(dat);
        if (cmd == "MOVE_FORWARD") Train.moveForward();
        if (cmd == "MOVE_BACKWARD") Train.moveBackwards();
        if (cmd == "WHERE_AM_I") Train.showCurrent();
    }
}