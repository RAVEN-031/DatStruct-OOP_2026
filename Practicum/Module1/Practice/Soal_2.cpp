#include <iostream>
#include <string>

class Character {
    protected:
        std::string name;
        std::string expression;
        int level;

        //Helper method
        std::string getFace() {
            if (getExpression()== "normal") {
                return "( o_o )";
            }
            if (getExpression() == "happy"){
                return "( ^_^ )";
            }
            if (getExpression()== "sad"){
                return "( T_T )";
            }
            else {
                return "( -_- )";
            }
        }
    public:
        //Constructor
        Character(std::string a, std::string b, int c) : name(a), expression(b), level(c){}

        //Setter & Getter
        void setName(std::string a) {name = a;}
        void setExpression(std::string a) {expression = a;}
        void setLevel(int a) {level = a;}
        virtual void setExtra(std::string) = 0;
        std::string getName() {return name;}
        std::string getExpression() {return expression;}
        int getLevel() {return level;}
        virtual std::string getExtra() = 0;
        
        //Methods
        virtual void displayInfo() = 0;
        virtual void showCharacter() = 0;
        ~Character(){
            std::cout << "Character " << getName() << " deleted";
        }
};

class Human : public Character {
    private:
        std::string feelings;

        //Helper method
        std::string processFeelings() {
            if (getExtra() == "curious") return "?";
            if (getExtra() == "loving") return "<3";
            if (getExtra() == "heartbroken") return "</3";
            else {return "error 404";}
        }
    public:
        //Constructor
        Human(std::string a, std::string b, int c, std::string d) : Character(a, b, c){
            feelings = d;
        }

        //Setter & Getter
        void setExtra(std::string a) override {feelings = a;}
        std::string getExtra() override {return feelings;}

        //Methods
        void displayInfo() override {
            std::cout << "[ " << getName() << " | Human | Lvl " << getLevel() << " | " << getExpression() << " | " << getExtra() << " ]\n";
        }
        void showCharacter() override {
            std::cout << " _____ \n";
            std::cout << getFace() << std::endl;
            std::cout << " /| |\\" << processFeelings() << std::endl;
            std::cout << "  | |\n";
            std::cout << " _/ \\_\n";
            std:: cout << "  " << processFeelings() << std::endl;
        }
};

class Vampire : public Character {
    private:
        std::string will;
        //Helper Method
        std::string processCloak(){
            if (getExtra() == "hiding") return "}|##|{";
            if (getExtra() == "confessing") return "}| |{>>";
            if (getExtra() == "protecting") return "}|[]|{";
            else {return "error 404";}
        }
        std::string processEffects(){
            if (getExtra() == "hiding") return ".  .  .";
            if (getExtra() == "confessing") return " <3  <3";
            if (getExtra() == "protecting") return "[====]";
            else return "error 404";
        }
    public:
        //Constructor
        Vampire(std::string a, std::string b, int c, std::string d) : Character(a, b, c) {
            will = d;
        }
        
        //Setter & Getter
        void setExtra(std::string a) override {will = a;}
        std::string getExtra() override {return will;}

        //Methods
        void displayInfo() override {
            std::cout << "[ " << getName() << " | Vampire | Lvl " << getLevel() << " | " << getExpression() << " | " << getExtra() << " ]\n";
        }
        void showCharacter() override {
            std::cout << " _____ \n";
            std::cout << getFace() << std::endl;
            std::cout << processCloak() << std::endl;
            std::cout << "  | |\n";
            std::cout << " _/ \\_\n";
            std::cout << processEffects() << std::endl;
        }
};

void createCharacter(Character *pArr[]){
    //Character Creation
    int choice;
    std::string name;
    std::string expression;
    int level;
    Character *pNewCharacter;
    std::cout << "1. Human\n2. Vampire\nPick a type: ";
    std::cin >> choice;
    if (choice == 1){
        std::string feelings;
        std::cin.ignore();
        std::cout << "Enter Name: "; std::getline(std::cin, name);
        std::cout << "Enter Expression: "; std::getline(std::cin, expression); //I know that the tier input is unsanitized, I am too lazy to deal with such thing just for a practice
        std::cout << "Enter Feelings: "; std::getline(std::cin, feelings);
        std::cout << "Enter Level: "; std::cin >> level;
        pNewCharacter = new Human(name, expression, level, feelings);
    }
    else if (choice == 2){
        std::string will;
        std::cin.ignore();
        std::cout << "Enter Name: "; std::getline(std::cin, name);
        std::cout << "Enter Expression: "; std::getline(std::cin, expression); //I know that the tier input is unsanitized, I am too lazy to deal with such thing just for a practice
        std::cout << "Enter Will: "; std::getline(std::cin, will);
        std::cout << "Enter Level: "; std::cin >> level;
        pNewCharacter = new Human(name, expression, level, will);
    }
    else {
        std::cout << "Invalid input";
        return;
    }
    //Character storing
    for (int i = 0; i < 100; i++){
        if (pArr[i] == nullptr){
            pArr[i] = pNewCharacter;
            std::cout << "New character created\n";
            pArr[i]->showCharacter();
            return;
        }
    }
    std::cout << "No empty slot found\n";
}
void showCharacters(Character *pArr[]){
    int flag = 0;
    for (int i = 0; i < 100; i ++){
        if (pArr[i] != nullptr){
            flag = 1;
            pArr[i]->showCharacter();
            pArr[i]->displayInfo();
            std::cout << "\n";
        }
    }
    if (flag == 0) std::cout << "No character stored in list\n";
}
void updateCharacter(Character *pArr[]){
    int choice;
    std::string name;
    std::cin.ignore();
    std::cout << "Input character name: "; std::getline(std::cin, name);
    for(int i = 0; i < 100; i++){
        if(pArr[i] != nullptr && pArr[i]->getName() == name){
            std::string newChange;
            std::cout << "\n==Before==\n";
            pArr[i]->showCharacter();
            pArr[i]->displayInfo();
            std::cout << "Change? 1. Expression 2. Feelings/Will\n>> ";
            std::cin.ignore(); std::cin >> choice;
            if (choice == 1){
                std::cout << "New Expression (normal/happy/sad): "; std::cin >> newChange;
                pArr[i]->setExpression(newChange);
                return;
            }
            if (choice == 2){
                std::cout << "New Feelings/Will (curious/loving/heartbroken) (hiding/confessing/protecting): "; std::cin >> newChange;
                pArr[i]->setExtra(newChange);
            }
            std::cout << "\n==After==\n";
            pArr[i]->showCharacter();
            pArr[i]->displayInfo();
            std::cout << "\"Something about " << pArr[i]->getName() << " changed...\"\n";
            return;
        }
    }
    std::cout << "Character not found\n";
}
void deleteCharacter(Character *pArr[]){
    std::string name;
    std::cin.ignore();
    std::cout << "Input character name: "; std::getline(std::cin, name);
    for (int i = 0; i < 100; i++){
        if(pArr[i] != nullptr && pArr[i]->getName() == name){
            delete(pArr[i]);
            pArr[i] = nullptr;
            return;
        }
    }
    std::cout << "Character not found\n";
}
int main(){
    Character *pCharacterList[100] = {};
    int input;
    while (true) {
        std::cout << "1. Write a new story\n2. Read diary\n3. Change feelings\n4. Delete from diary\n5. Exit\nInput: ";
        std::cin >> input;
        if (input == 1) createCharacter(pCharacterList);
        if (input == 2) showCharacters(pCharacterList);
        if (input == 3) updateCharacter(pCharacterList);
        if (input == 4) deleteCharacter(pCharacterList);
        if (input == 5) break;
    }
    
    return 0;
}