void DisplayStatsFull(player *target) {
    printf("%s\nHealth: %d\nMana: %d\nAtk: %d\nDef: %d\n\n", target->name, target->health, target->mana,
                                                             target->attack, target->defense);
}

void DisplayStats(player *target) {
    printf("%s\nHealth: %d\nMana: %d\n\n", target->name, target->health, target->mana);
}

int SetName(player *target, char name[50]) {
    strcpy(target->name, name);
    return 0;
}

player* NewPlayer(job job, char name[50]) {
    player *tempPlayer = malloc(sizeof(player));
    SetName(tempPlayer, name);

    switch(job) {
        case WARRIOR:
            tempPlayer->health = 60;
            tempPlayer->mana = 0;
            tempPlayer->attack = 3;
            tempPlayer->defense = 5;
            tempPlayer->job = WARRIOR;
            break;
        case RANGER:
            tempPlayer->health = 35;
            tempPlayer->mana = 0;
            tempPlayer->attack = 3;
            tempPlayer->defense = 2;
            tempPlayer->job = RANGER;
            break;
        case MAGE:
            tempPlayer->health = 20;
            tempPlayer->mana = 60;
            tempPlayer->attack = 5;
            tempPlayer->defense = 0;
            tempPlayer->job = MAGE;
            break;
        case ACCOUNTANT:
            tempPlayer->health = 100;
            tempPlayer->mana = 100;
            tempPlayer->attack = 5;
            tempPlayer->defense = 5;
            tempPlayer->job = ACCOUNTANT;
            break;
        default:
            tempPlayer->health = 10;
            tempPlayer->mana = 0;
            tempPlayer->attack = 0;
            tempPlayer->defense = 0;
            break;
    }

    return tempPlayer;
}