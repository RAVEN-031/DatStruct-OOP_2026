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
        Station* pTrav = _head;

        while (pTrav != nullptr) {
            if (pTrav->name == name && pTrav == _head) {
                pTrav->_next->_prev = nullptr;
                _head = _head->_next;
                delete pTrav;
                _size--;
            }
            else if (pTrav->name == name) {
                pTrav->_prev->_next = pTrav->_next;
                pTrav->_next->_prev = pTrav->_prev;
            }
        }
    }
};
