#include "interface.h"
using namespace std;

void getDecision(int& d,double win , double stand)
{
    cout<<"P(win) = "<< win*100 << " % !"<<endl<< "P(stand) = " << stand * 100 << endl<<"Enter Your decision(1 for hit 0 for stand): "<<endl;
    cin>> d;
}

void dealtCard(int card)
{
    cout<< "THE CARD "<<card<< " WAS DEALT"<<endl;
}

void showStartHand(const player& p , const dealer& d)
{
    cout<<"PLAYER: "<<endl;
    cout<<"FIRST CARD: "<<p.cards[0] << " SECOND CARD " <<p.cards[1]<<endl;
    cout<<"DEALER: "<<endl;
    cout<<"FIRST CARD: "<<" UnKnown " << " SECOND CARD " <<d.cards[1]<<endl;

}
void sayBusted()
{
    cout<<"BUSTED!"<<endl;
}

void sayWinner(int w,const dealer&d , const player&p)
{
    if (w == 1)
        cout<<"PLAYER WON! ( P: " << p.sum << " , D: " <<d.sum <<" )"<<endl;
    else if (w == 0)
        cout<<"DEALER WON! ( P: " << p.sum << " , D: " <<d.sum <<" )"<<endl;
    else
        cout<<"PUSH! ( P: " << p.sum << " , D: " <<d.sum <<" )"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
}
