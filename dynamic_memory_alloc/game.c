// Simple betting Game
//  "Jack Queen King" - Computer shuffles these cards
//  Player has to guess the postion of Queen
//  If he/she wins get 3 * bet money
//  If lose, he looses the bet money
//  player has 100 $ initially

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100; // Initial money


void play(int bet)
{

    char C[3] = {'J', 'Q', 'K'};
    printf("Shuffling cards\n");
    srand(time(NULL));
    for (int i=0;i<5;i++)
        {
            int x = rand() %3;
            int y = rand() %3;
            int temp = C[x];
            C[x] = C[y];
            C[y] = temp;
        }
    int PlayerGuess;
    printf("What is your Guess?\n");
    scanf("%d", &PlayerGuess);
    
    if (C[PlayerGuess-1] == 'Q')
        {
            cash += 3 * bet;
            printf("You Win! | Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
        }

    else
        {
            cash -= bet;
            printf("You Lose! | Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
        }
    
    }


int main()

{

    int bet;
    while (cash > 0)
    {
        printf("What is your bet? $\n");
        scanf("%d", &bet);
        printf("Bet money is %d\n", bet);

        if (bet < 0 || bet > cash)
            {
                printf("Game Over\n");
                break;
            }

        play(bet);

        printf("\n_____________________________________________________________________________\n");
        }

    return 0;
}