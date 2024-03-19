#ifndef RPG_H
#define RPG_H
#include <iostream>
using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
    //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);
        void setSkills();
        void printAction(string, RPG);
        void updateHealth(int new_health);
        void attack(RPG*);
        void useSkills(RPG*);
        bool isAlive() const;
        string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getDefense() const;


    // COMPLETE THE REST

    private:
    // COMPLETE THE REST
        string name;
        int health;
        int strength;
        int defense;
        string type; // warrior, mage, thief, archer
        string skills [SKILL_SIZE];

};
#endif