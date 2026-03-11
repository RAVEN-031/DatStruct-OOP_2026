#include <iostream>
#include <string>

class Character {
    protected:
        std::string name;
        std::string expression;
        int level;
    public:
        //Constructor
        Character(std::string a, std::string b, int c) : name(a), expression(b), level(c){}

        //Setter & Getter
        void setName(std::string a) {name = a;}
        void setExpression(std::string a) {expression = a;}
        void setLevel(int a) {level = a;}
        std::string getName() {return name;}
        std::string getExpression() {return expression;}
        int getLevel() {return level;}
        
        //Methods
        virtual void displayCharacter(){}

    //Helper method
    protected:
        std::string getFace() {
            if (expression == "normal") {
                return "( o_o )";
            }
            if (expression == "happy"){
                return "( ^_^ )";
            }
            if (expression == "sad"){
                return "( T_T )";
            }
        }
};