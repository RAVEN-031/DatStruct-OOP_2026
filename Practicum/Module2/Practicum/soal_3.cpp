#include <iostream>
#include <string>

using namespace std;

class CListNode {
public:
    string name;
    CListNode *next;

    CListNode(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class CircularSinglyList {
private:
    CListNode *_head;
    CListNode *_heroNow;
    int _size;

public:
    CircularSinglyList() : _head(nullptr), _heroNow(nullptr), _size(0) {}

    bool isEmpty() {
        return _head == nullptr;
    }

    void addHero(string name) {
        
        CListNode* pNewNode = new CListNode(name);
        if (isEmpty()) {
            pNewNode->next = pNewNode;
            _head = pNewNode;
            _heroNow = pNewNode;
        }
        else {
            CListNode* pTrav = _head;
            for (int i = 0; i < _size - 1; i++) {
                pTrav = pTrav->next;
            }
            pNewNode->next = _head;
            pTrav->next = pNewNode;
        }
        _size++;
    }

    void whoIsNext() { 
        if (isEmpty()) std::cout << "The domain crumbles, alll heroes have perished...\n";
        else std::cout << "The next is " << _heroNow->next->name << std::endl;
    }

    void nextTurn() {  
        if (isEmpty()) return;
        _heroNow = _heroNow->next;
    }

    void timeSkip(int jumlah) {
        if (isEmpty()) return;
        for (int i = 0; i < jumlah; i++) {
            _heroNow = _heroNow->next;
        }
    }

    void slainHero(string name) {
        if (isEmpty()) return;
        CListNode* pTrav = _head;

        do {
            if (pTrav->next->name == name) {
                CListNode* pTrash = pTrav->next;
                pTrav->next = pTrash->next;
                if (pTrash == _heroNow) _heroNow = _heroNow->next;
                std::cout << pTrash->name << " has been slain in battle...\n";
                if (pTrash == _head) _head = pTrash->next;
                delete pTrash;
            }
            else {
                pTrav = pTrav->next;
            }
        }
        while (pTrav != _head);
        _size--;
        if (_size == 0) _head = nullptr;
    }

    void display() {
        if (isEmpty()) std::cout << "The domain crumbles, alll heroes have perished...\n";
        else {
            CListNode* pTrav = _head;

            do {
                std::cout << pTrav->name << " ";
                pTrav = pTrav->next;
            }
            while (pTrav != _head);
            std::cout << std::endl;
        }
    }
};

int main() {
    CircularSinglyList myHero;
    string command;

    while (cin >> command) {

        if (command == "SUMMON") {
            string name;
            cin >> name;
            myHero.addHero(name);
        } else if (command == "WHO_IS_NEXT") {
            myHero.whoIsNext();
        } else if (command == "NEXT_TURN") {
            myHero.nextTurn();
        } else if (command == "TIME_SKIP") { 
            int jumlah;
            cin >> jumlah;
            myHero.timeSkip(jumlah);
        } else if (command == "SLAIN") {
            string name;
            cin >> name;
            myHero.slainHero(name);
        } else if (command == "DISPLAY") {
            myHero.display();
            break;
        } 
        
    }

    return 0;
}