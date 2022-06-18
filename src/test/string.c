#include <stdio.h>
#include <string.h>

typedef struct Player
{
    /* data */
    signed char nom[256];
    signed char prenoms[256];
} Player;

void create_Player(Player *p);


int main(void) {
    Player p1 = { "Harvey", "Konan" };
    printf("Informations sur le Joueur : { %s, %s }\n", p1.nom, p1.prenoms);
    return 0;
} 