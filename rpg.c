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
int fightmenu();

int main() {
    player *Hero = NewPlayer(ACCOUNTANT, "HERO");
    player *Villian = NewPlayer(MAGE, "BADDY");

    fight(Hero, Villian);

    system("clear");

    return 0;
}

void fight (player *attacker, player *target) {
    
    // effective attack, atk - def
    int effatk = attacker->attack - target->defense;

    while (target->health > 0) {

        system("clear");

        int x = fightmenu();

        printf("%d\n\n", x);

        switch(x) {
            case 1:
                printf("%s dealt %d damage to %s!\n\n", attacker->name, effatk, target->name);
                target->health -= effatk;
                DisplayStats(target);
                // wait for a button push
                getch();
                break;
            case 2:
                printf("wimp\n\n");
                getch();
                break;
            default:
                printf("you really messed up bud\n");
                getch();
                break;
        }
    }

    printf("final fantasy music\n");
    getch();

    return;
}

int fightmenu() {
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
    mvprintw(LINES - 2, 0, "F1 to Exit");
    post_menu(my_menu);
    refresh();

    while((c = getch()) != KEY_F(1)) {
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

    free_item(my_items[0]);
    free_item(my_items[1]);
    free_menu(my_menu);
    endwin();

    return choice;

}