#include <iostream>
#include "game.h"
void getDecision(int & d,double win,double stand);
void dealtCard(int card);
void showStartHand(const player& p , const dealer& d);
void sayBusted();
void sayWinner(int w , const dealer& d , const player& p);
