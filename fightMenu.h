#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

static char *choices[] = {
    "Fight",
    "Run",
};

static char *nums[] = {
    "1",
    "2",
};


void DisplayStatsCurses(player *target, int y, int x) {
    mvprintw(y, x, "%s\nHealth: %d\nMana: %d\n\n", target->name, target->health, target->mana);
}

void clear_messages() {
    move(LINES -3, 0);
    clrtoeol();

    return;
}

