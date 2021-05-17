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


void clear_messages() {
    move(LINES -3, 0);
    clrtoeol();

    return;
}