#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

static char *choices[] = {
    "FIGHT",
    "RUN",
};

static char *nums[] = {
    "1",
    "2",
};


void DisplayStatsCurses(player *target, int y, int x) {
    mvprintw(y, x, "%s\nHealth: %d\nMana: %d\nAtk: %d\nDef: %d\n\n", target->name, target->health, target->mana,
                                                             target->attack, target->defense);
}

void clear_messages() {
    move(LINES -3, 0);
    clrtoeol();

    return;
}

int fightmenu(player *attacker, player *target) {
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    ITEM *cur_item;

    int choice = 0;
    int highlight = 1;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    n_choices = ARRAY_SIZE(choices);
    // I have no idea what a calloc is 
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

    for(i = 0; i < n_choices; ++i)
            my_items[i] = new_item(nums[i], choices[i]);
    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);
    DisplayStatsCurses(attacker, 4, 0);
    post_menu(my_menu);
    refresh();

    while((c = getch())) {
        switch(c) {
            case KEY_DOWN:
                clear_messages();

                if(highlight != n_choices) {
                    highlight++;
                }

                menu_driver(my_menu, REQ_DOWN_ITEM);
                
                break;

            case KEY_UP:
                clear_messages();

                if (highlight != 1) {
                    highlight--;
                }

                menu_driver(my_menu, REQ_UP_ITEM);
                
                break;

            case 10: /*ENTER*/
                choice = highlight;
                //mvprintw(LINES - 3, 0, "You chose choice %d", choice);
                break;
        }

        if (choice == highlight) {
            break;
        }
    }

    for (int i = 0; i < n_choices; i++) {
        free_item(my_items[i]);
    }
    free_menu(my_menu);
    endwin();

    return choice;

}