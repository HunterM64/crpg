// classes are enumerated for some reason
typedef enum ClassEnum {
    WARRIOR,
    RANGER,
    MAGE,
    ACCOUNTANT
} job;

// player structure
typedef struct playerStructure {
    char name[50];
    job job;
    int health;
    int mana;
    int attack;
    int defense;
} player;