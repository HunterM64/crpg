#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <menu.h>

#include "gameProperties.h"
#include "players.h"
#include "fightMenu.h"

// function prototypes
void fight (player *attacker, player *target);

int main() {
    // create hero and villain
    player *Hero = NewPlayer(ACCOUNTANT, "HERO");
    player *Villian = NewPlayer(MAGE, "BADDY");

    // make them fight
    fight(Hero, Villian);

    system("clear");

    return 0;
}

// determines the correct actions to take based on player input in fightMenu
void fight (player *attacker, player *target) {
    
    // effective attack, atk - def, dont want this being less than 0
    int effAtkAtkr = (attacker->attack - target->defense < 0) ? 0: attacker->attack - target->defense;
    int effAtkTarg = (target->attack - attacker->defense < 0) ? 0: target->attack - attacker->defense;

    // keep looping combat til its over
    bool theFightIsOn = true;
    // how the fight ended, 0 = win, 1 = loss, 2 = run
    int result;
    while (theFightIsOn) {

        system("clear");

        // get player input from fight menu
        int x = fightmenu(attacker, target);

        // debugging
        //printf("%d\n\n", x);

        // switch case for input
        switch(x) {
            case 1: // FIGHT
                printf("%s dealt %d damage to %s!\n\n", attacker->name, effAtkAtkr, target->name);

                // deal damage to target
                target->health -= effAtkAtkr;

                DisplayStats(target);

                printf("%s counterattacks for %d damage to %s! \n\n", target->name, effAtkTarg, attacker->name);

                // deal damage to attacker
                attacker->health -= effAtkTarg;

                DisplayStats(attacker);

                // game ends when someone's health is zero
                if(target->health <= 0 || attacker->health <= 0) {
                    theFightIsOn = false;
                    // i learned how to use this and now im going to abuse this
                    result = (target->health <= 0) ? 0 : 1;
                }

                // wait for a button push
                getch();
                break;

            case 2: // RUN 
                theFightIsOn = false;
                result = 2;
                break;

            default:
                printf("you really messed up bud\n");
                getch();
                break;
        }
    }

    switch(result) {
        case 0: // WIN
            printf("YOU WIN\n* final fantasy music *\n");
            break;

        case 1: // LOSE
            printf("YOU LOSE\n* losers don't get music *\n");
            break;

        case 2: // RUN
            printf("YOU RAN\n* runners don't get music either *\n");
            break;

        default: 
            printf("WHAT\n");
            break;
    }

    getch();

    return;
}