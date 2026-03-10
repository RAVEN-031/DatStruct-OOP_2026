#include <iostream>
#include <string>

class Character {
    protected:
        std::string name;
        char tier;
        int hp;
        int power;
    public:
        //Constructor
        Character(std::string a, char b, int c, int d) : name(a), tier(b), hp(c), power(d){}

        //Setters & Getters
        void setName(std::string a){
            name = a;
        }
        void setTier(char a){
            tier = a;
        }
        void setHp(int a){
            hp = a;
        }
        void setPower(int a){
            power = a;
        }
        std::string getName(){
            return name;
        }
        char getTier(){
            return tier;
        }
        int getHp(){
            return hp;
        }
        int getPower(){
            return power;
        }

        //Methods
        virtual void displayInfo(){
            std::cout << "Name: " << getName() << "\nTier: " << getTier() << "\nHP: " << getHp() << "\nAttack Power: " << getPower() << std::endl;
        }
        virtual void useSkill() = 0;
        
        //Destructor
        virtual ~Character() {
            std::cout << "Character " << name << " has been deleted";
        }

};

class Warrior : public Character {
    private:
        int stamina;
    public:
        //Constructor
        Warrior(std::string a, char b, int c, int d, int e) : Character(a, b, c, d){
            stamina = e;
        }

        //Setter & Getter
        void setStamina(int a){
            stamina = a;
        }
        int getStamina(){
            return stamina;
        }

        //Methods
        void displayInfo() override{
            Character::displayInfo();
            std::cout << "Stamina: " << getStamina() << std::endl;
        }
        void useSkill() override{
            if (getStamina() >= 20){
                setStamina(getStamina() - 20);
                std::cout << "Character " << getName() << " slashes the enemy with a sword!\n";
            }
            else {
                std::cout << getName() << "'s stamina is insufficient\n";
            }
        }
};

class Mage : public Character {
    private:
        int mana;
    public:
        //Constructor
        Mage(std::string a, char b, int c, int d, int e) : Character(a, b, c, d){
            mana = e;
        }

        //Setter & Getter
        void setMana(int a){
            mana = a;
        }
        int getMana(){
            return mana;
        }

        //Methods
        void displayInfo() override{
            Character::displayInfo();
            std::cout << "Mana: " << getMana() << std::endl;
        }
        void useSkill() override{
            if (getMana() >= 30){
                setMana(getMana()-30);
                std::cout << "Character " << getName() << " casts Elemental Burst\n";
            }
            else {
                std::cout << getName() << "'s mana is not enough\n";
            }
        }
};

void createCharacter(Character *pArr[]){
    //Character Creation
    int choice;
    std::string name;
    char tier;
    int hp;
    int power;
    Character *pNewCharacter;
    std::cout << "1. Warrior\n2. Mage\nPick a class: ";
    std::cin >> choice;
    if (choice == 1){
        int stamina;
        std::cin.ignore();
        std::cout << "Enter Name: "; std::getline(std::cin, name);
        std::cout << "Enter Tier: "; std::cin >> tier; //I know that the tier input is unsanitized, I am too lazy to deal with ts just for a practice
        std::cout << "Enter HP: "; std::cin >> hp;
        std::cout << "Enter Attack Power: "; std::cin >> power;
        std::cout << "Enter Stamina: "; std::cin >> stamina;
        pNewCharacter = new Warrior(name, tier, hp, power, stamina);
    }
    else if (choice == 2){
        int mana;
        std::cin.ignore();
        std::cout << "Enter Name: "; getline(std::cin, name);
        std::cout << "Enter Tier: "; std::cin >> tier;
        std::cout << "Enter HP: "; std::cin >> hp;
        std::cout << "Enter Attack Power: "; std::cin >> power;
        std::cout << "Enter Mana: "; std::cin >> mana;
        pNewCharacter = new Mage(name, tier, hp, power, mana);
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
            pArr[i]->displayInfo();
            std::cout << "\n";
        }
    }
    if (flag == 0) std::cout << "No character stored in list\n";
}
void promoteCharacter(Character *pArr[]){
    std::string name;
    std::cin.ignore();
    std::cout << "Input character name: "; std::getline(std::cin, name);
    for(int i = 0; i < 100; i++){
        if(pArr[i] != nullptr && pArr[i]->getName() == name){
            if(pArr[i]->getTier() == 'A'){
                std::cout << "Character already in highest tier\n";
                return;
            }
            else {
                pArr[i]->setTier(pArr[i]->getTier()-1);
                std::cout << "Character " << pArr[i]->getName() << " promoted to tier " << pArr[i]->getTier() << std::endl;
                return;
            }
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
void skillSimulation(Character *pArr[]){
    std::string name;
    std::cin.ignore();
    std::cout << "Input character name: "; std::getline(std::cin, name);
    for (int i = 0; i < 100; i++){
        if(pArr[i] != nullptr && pArr[i]->getName() == name){
            pArr[i]->useSkill();
            return;
        }
    }
    std::cout << "Character not found\n";
}

int main(){
    //tfw no specified need for dynamic array <3
    Character *pCharacterList[100] = {};
    int input;
    while (true) {
        std::cout << "1. Create character\n2. Character list\n3. Promote character\n4. Delete character\n5. Skill simulation\n6. Exit\nInput: ";
        std::cin >> input;
        if (input == 1) createCharacter(pCharacterList);
        if (input == 2) showCharacters(pCharacterList);
        if (input == 3) promoteCharacter(pCharacterList);
        if (input == 4) deleteCharacter(pCharacterList);
        if (input == 5) skillSimulation(pCharacterList);
        if (input == 6) break;
    }
    
    
    

    return 0;
}