#include <array>
#include <random>

using namespace std;

const array<int , 13> CARDS  = {1,2,3,4,5,6,7,8,9,10,10,10,10};

struct player
{
    array<int , 21> cards;
    int nbc = 0;
    int sum=0;
};

struct dealer
{
    array<int , 21> cards;
    int nbc = 0;
    int sum = 0;
};

int randomNumber(int a , int b);

void dealToPlayer(player& p);
void dealToDealer( dealer& d);

int game(player&p , dealer&d);

double standWinProb(const dealer& d , const player& p);

