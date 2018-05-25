/*

SRM 734
(this is only for programming practise)
CardCounter
The problem statement:
https://community.topcoder.com/stat?c=problem_statement&pm=14021&rd=17158&rm=&cr=22907549

difficulty level: medium

*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
int const MAX_N = 11;
 
int deck [MAX_N];
int total;
int player;
int playerAces;
int playerScore;
int dealer;
int dealerAces;
int dealerScore;
 
int score (int sum, int aces)
{
  return sum + (aces && (sum <= 11)) * 10;
}
 
bool win (int p, int d)
{
  if (p > 21)
  {
    return false;
  }
  if (d > 21)
  {
    return true;
  }
  return (p > d);
}

double moveDealer (double p)
{
  dealerScore = score (dealer, dealerAces);
  if (dealerScore >= 17)
  {
    return p * win (playerScore, dealerScore);
  }
 
  double res = 0.0;
  for (int i = 1; i < MAX_N; i++)
  {
    if (deck[i] > 0)
    {
      double q = deck[i] * 1.0 / total;
      dealer += i;
      dealerAces += (i == 1);
      deck[i] -= 1;
      total -= 1;
      res += moveDealer (p * q);
      total += 1;
      deck[i] += 1;
      dealerAces -= (i == 1);
      dealer -= i;
    }
  }
  return res;
}
 
double movePlayer (double p)
{
  playerScore = score (player, playerAces);
  if (playerScore > 21)
  {
    return 0.0;
  }
 
  double res = 0;
  for (int i = 1; i < MAX_N; i++)
  {
    if (deck[i] > 0)
    {
      double q = deck[i] * 1.0 / total;
      player += i;
      playerAces += (i == 1);
      deck[i] -= 1;
      total -= 1;
      res += movePlayer (p * q);
      total += 1;
      deck[i] += 1;
      playerAces -= (i == 1);
      player -= i;
    }
  }
  playerScore = score (player, playerAces);
  res = max (res, moveDealer (p));
  return res;
}
 
class CardCounter
{
public:
  double winningChance (vector <int> deck, int dealer,
      vector <int> player)
  {
    memset (::deck, 0, sizeof (::deck));
    total = 0;
    for (int i = 0; i < 10; i++)
    {
      ::deck[i + 1] = deck[i];
      total += deck[i];
    }
    ::dealer = dealer;
    dealerAces = (dealer == 1);
    ::player = player[0] + player[1];
    playerAces = (player[0] == 1) + (player[1] == 1);
 
    dealerScore = score (dealer, dealerAces);
    return movePlayer (1.0);
  }
};

typedef double (CardCounter::*METHOD)(vector<int>, int, vector<int>);

int main(){
	//input
	vector<int> deck= {0, 0, 0, 0, 0, 0, 0, 4, 0, 4};
	int dealer =10;
	vector<int> player= {5, 5};
	CardCounter* obj =new CardCounter;
	METHOD Action =&CardCounter::winningChance;
	double res =(obj->*Action)(deck, dealer, player);
	printf("%f\n\n", res);
	delete obj;
	return 0;
}






