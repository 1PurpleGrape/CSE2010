#include <iostream>
#include "RPG.h"

using namespace std;


void displayEnd(RPG player1, RPG player2) {
    if(player1.isAlive()){
        printf("Player 1 wins\n");
    }
    else{
        printf("Player 2 wins\n");
    }

}
void displayStats (RPG player1, RPG player2){
    printf("%s Health: %i %s Health: %i \n",player1.getName().c_str(), player1.getHealth(), player2.getName().c_str(), player2.getHealth());
}

void gameLoop(RPG * player1, RPG * player2){
    int x=1;
    while((*player1).isAlive() && (*player2).isAlive()){
        displayStats((*player1),(*player2));
        if(x%2==1){
            printf("%s turn \n",((*player1).getName()).c_str());
            (*player1).useSkills(player2);
        }
        else{
            printf("%s turn \n",((*player2).getName()).c_str());
            (*player2).useSkills(player1);
        }
        x++;
    }
}
int main(){

    RPG p1 = RPG("Wiz", 70, 45, 3, "mage") ;
    RPG p2 = RPG();
 
    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;


}
