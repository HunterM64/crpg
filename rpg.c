#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum ClassEnum {
    WARRIOR,
    RANGER,
    MAGE,
    ACCOUNTANT
} class;

typedef struct playerStructure {
    char name[50];
    class class;
    int health;
    int mana;
} player;

void DisplayStats(player *target);
int SetName(player *target, char name[50]);
player* NewPlayer(class class, char name[50]);

int main() {
    player *Hero = NewPlayer(WARRIOR, "HERO");
    player *Villian = NewPlayer(MAGE, "BADDY");

    DisplayStats(Hero);
    DisplayStats(Villian);
    return 0;
}

void DisplayStats(player *target) {
    printf("%s\nHealth: %d\nMana: %d\n\n", target->name, target->health, target->mana);
}

int SetName(player *target, char name[50]) {
    strcpy(target->name, name);
    return 0;
}

player* NewPlayer(class class, char name[50]) {
    player *tempPlayer = malloc(sizeof(player));
    SetName(tempPlayer, name);

    switch(class) {
        case WARRIOR:
            tempPlayer->health = 60;
            tempPlayer->mana = 0;
            tempPlayer->class = WARRIOR;
            break;
        case RANGER:
            tempPlayer->health = 35;
            tempPlayer->mana = 0;
            tempPlayer->class = RANGER;
            break;
        case MAGE:
            tempPlayer->health = 20;
            tempPlayer->mana = 60;
            tempPlayer->class = MAGE;
            break;
        case ACCOUNTANT:
            tempPlayer->health = 100;
            tempPlayer->mana = 100;
            tempPlayer->class = ACCOUNTANT;
            break;
        default:
            tempPlayer->health = 10;
            tempPlayer->mana = 0;
            break;
    }

    return tempPlayer;
}