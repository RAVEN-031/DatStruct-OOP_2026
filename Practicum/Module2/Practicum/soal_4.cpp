#include <iostream>
#include <string>

using namespace std;

class Survivor {
public:
    string name;
    Survivor *next;
    Survivor *prev;

    Survivor(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MazePatrol {
private:
    Survivor *head;
    Survivor *captain;
    int size;

public:
    MazePatrol() : head(nullptr), captain(nullptr), size(0) {}

    bool isEmpty() {
        return (head == nullptr);
    }

    void recruit(string name) {
        Survivor* pNewNode = new Survivor(name);
        if (isEmpty()) {
            head = pNewNode->next = pNewNode->prev = pNewNode;
            captain = pNewNode;
        }
        else {
            Survivor *tail = head->prev;
            pNewNode->next = head;
            pNewNode->prev = tail;
            head->prev = pNewNode;
            tail->next = pNewNode;
            head = pNewNode;
        }
    }

    void moveForward() {
        if (isEmpty()) return;
        Survivor* pTemp = captain->next;
        captain->next = pTemp->next;
        pTemp->next = captain;
        pTemp->prev = captain->prev;
        captain->prev = pTemp;
    }

    void moveBackward() {
        // TODO: Move captain to prev
    }

    void scoutForward(int n) {
        // TODO: Move captain forward n times
    }

    void scoutBackward(int n) {
        // TODO: Move captain backward n times
    }

    void bittenByZombie(string name) {
        // TODO: Search and Remove node. Update head & captain if necessary
    }

    void checkMaze() {
        // TODO: Display list and current captain
    }
};

int main() {
    MazePatrol squad;
    string command;

    while (cin >> command && command != "MAZE_EXIT") {
        if (command == "RECRUIT_SURVIVOR") {
            string name; cin >> name;
            squad.recruit(name);
        } else if (command == "MOVE_FORWARD") {
            squad.moveForward();
        } else if (command == "MOVE_BACKWARD") {
            squad.moveBackward();
        } else if (command == "SCOUT_FORWARD") {
            int n; cin >> n;
            squad.scoutForward(n);
        } else if (command == "SCOUT_BACKWARD") {
            int n; cin >> n;
            squad.scoutBackward(n);
        } else if (command == "BITTEN_BY_ZOMBIE") {
            string name; cin >> name;
            squad.bittenByZombie(name);
        } else if (command == "CHECK_MAZE") {
            squad.checkMaze();
        }
    }

    return 0;
}