#include "interface.h"

int main()
{
    player p;
    dealer d;
    for (int i = 0 ; i<3 ; i++)
    sayWinner(game(p,d),d,p);
}