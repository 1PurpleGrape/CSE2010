#include "RPG.h"
#include <iostream>
using namespace std;


//public:
    RPG :: RPG()
    {
        name = "NPC";
        health = 100;
        strength = 10;
        defense = 10;
        type = "warrior";
        skills[0] = "slash";
        skills[1] = "parry";

    }
    RPG :: RPG(string name, int health, int strength, int defense, string type)
    {

        this->name = name;
        this->health = abs(health);
        this->strength = abs(strength);
        this->defense = abs(defense);
        this->type = type;
        setSkills();

    }
    void RPG :: setSkills()
    {
        if (type == "mage" ) {
            skills [0] = "fire";
            skills [1] = "thunder";
        } else if (type == "thief"){
            skills [0] = "pilfer";
            skills[1] = "jab";
        } else if(type == "archer") {
            skills[0] = "parry";
            skills [1] = "crossbow_attack";
        } else{
            skills [0] = "slash";
            skills [1] = "parry";
    }
    }
    /**
    * @brief returns whether health is greater than 0
    *
    * @return true
    * @return false
    */
     void RPG::printAction(string skill, RPG opponent)
    {
        printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
    }
    /**
    *    @brief updates health into new_health
    *
    * @param new_health
    */
    void RPG::updateHealth(int new_health)
    {
        health = new_health;

    }
    
    void RPG::attack(RPG*opponent)
    {
        if((*opponent).getDefense()<=getStrength())
        {
            (*opponent).updateHealth((*opponent).getHealth()-(getStrength()-(*opponent).getDefense()));
        }
    }
     void RPG::useSkills(RPG* opponent)
    {
        int skillIndex;
        for(int i=0;i<2;i++){
            printf("Skill %i: %s\n", i, skills[i]. c_str());
        }
        cout << "Choose a skill to use: Enter 0 or 1\n";
        cin>> skillIndex;
        while(skillIndex!=0 && skillIndex!= 1){
            cout<< "Error try again\n";
            cin>> skillIndex;
        }
        string chosen_skill = skills [skillIndex];
        printAction(chosen_skill,*opponent);
        attack(opponent);
    }
    
   
     bool RPG::isAlive() const
    {
        return health> 0;

    }
     string RPG::getName()const
    {
        return name;
    }
     int RPG::getHealth() const
    {
        return health;
    }
     int RPG::getStrength() const
    {
        return strength;
    }
    int RPG ::getDefense() const
    {
        return defense;
    }
//private:
        string name;
        int health;
        int strength;
        int defense;
        string type; // warrior, mage, thief, archer
        string skills [SKILL_SIZE];





