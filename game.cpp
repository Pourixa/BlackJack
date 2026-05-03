#include "interface.h"


int randomNumber(int a ,int b)
{
        return a + rand() % (b - a + 1);
}

int drawCard ()
{
    int index = randomNumber(0,12);
    int card = CARDS[index];
    return card;
}

void dealToPlayer(player& p)
{
    int card = drawCard();
    dealtCard(card);
    p.cards[p.nbc] = card;
    p.nbc++;
    p.sum +=card;
}

void dealToDealer( dealer& d)
{
    int card = drawCard();
    dealtCard(card);
d.cards[d.nbc] = card;
d.nbc++;
d.sum += card;
}

    double dealerBustOrLoseProb(int dealerSum, int playerSum)
    {
        // base case 1 : dealer busts
        if(dealerSum > 21)
            return 1;
        // base case 2 : dealer stands (>=17) , compare to player
        else if(dealerSum >= 17)
        {
            if(dealerSum >= playerSum)
                return 0;
            return 1;
        }
        // recursive case : dealer hits
        double prob = 0;
        for (int i = 1 ; i <= 9 ;i++)
            prob += 1.0/13 * dealerBustOrLoseProb(dealerSum + i,playerSum);
        prob += 4.0/13 * dealerBustOrLoseProb(dealerSum + 10 ,playerSum);

        return prob;
    }

    double hitWinProb(int playerSum, int dealerCard)
    {

        // base case 1: player busts
        if(playerSum>21)
            return 0;
        // base case 2: player at good sum, return stand win prob
        // (you decide the threshold)
        double standProb = dealerBustOrLoseProb(dealerCard,playerSum);

        // recursive case: hit again
        double prob = 0;
        // loop cards 1-9
        // prob += 1.0/13 * hitWinProb(playerSum + i, dealerCard)
        // don't forget 10-value cards
        for (int i = 1 ; i <= 9 ;i++)
            prob += 1.0/13 * hitWinProb(playerSum + i,dealerCard);
        prob += 4.0/13 * hitWinProb(playerSum + 10 ,dealerCard);

        return max(standProb, prob);
    }


int game(player&p , dealer&d) {
    p.sum = 0 ; d.sum = 0 ; p.nbc = 0 ; d.nbc = 0;
    //intial deal
    for (int i = 1; i <= 2; i++)
    {
        dealToPlayer(p);
        dealToDealer(d);
    }
    showStartHand(p,d);
    //checkblackJack

    if(d.sum == 21 && p.sum == 21)
        return -1;
    else if(d.sum == 21)
        return 0;
    else if (p.sum ==21)
        return 1;

    //playerTurn
    int des;
    int winner = -2;
    getDecision(des, hitWinProb(p.sum,d.cards[1]), dealerBustOrLoseProb(d.cards[1],p.sum));
    while (p.sum<=21 && des==1)
    {
        dealToPlayer(p);

        if(p.sum>21)
            //bust
        {
            des = 0;
            winner = 0;
            sayBusted();
        }
        else
            getDecision(des,hitWinProb(p.sum,d.cards[1]),dealerBustOrLoseProb(d.cards[1],p.sum));
    }
    if(winner>-2)
        return winner;
    //dealers turn
    while((winner <=-2  && d.sum < 21))
    {
        dealToDealer(d);
        if(d.sum > 21)
            winner = 1;
        else if (d.sum>=17)
        {
            if(d.sum > p.sum)
                winner = 0;
            else if (d.sum == p.sum)
                winner = -1;
            else
                winner = 1;
        }

    }
    return winner;
}

