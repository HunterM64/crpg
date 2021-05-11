#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameProperties.h"
#include "players.h"

// function prototypes
int fight (player *attacker, player *target);

int main() {
    player *Hero = NewPlayer(WARRIOR, "HERO");
    player *Villian = NewPlayer(MAGE, "BADDY");

    DisplayStatsFull(Hero);
    DisplayStatsFull(Villian);
    fight(Hero, Villian);
    DisplayStats(Villian);

    return 0;
}

int fight (player *attacker, player *target) {
    // effective attack, atk - def
    int effatk = attacker->attack - target->defense;
    // take damage
    target->health -= effatk;
    // might use this number
    return effatk;
}