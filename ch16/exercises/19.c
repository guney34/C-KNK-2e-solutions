#define NAME_LEN 40

struct pinball_machine {
    char name[NAME_LEN + 1];
    int year;
    enum type {EM, SS};
    int players;
};