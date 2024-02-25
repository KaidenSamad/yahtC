/*
yahtC
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void seed(int argc, char **argv){
    srand(time(NULL)); // Initialize random seed
    if (argc > 1){
        int i;
        if (1 == sscanf(argv[1], "%d", &i)) {
            srand(i);
        }
    }
}
void instructions(){
    printf("\n\n\n\n"
           "\t**********************************************************************\n"
           "\t*                         Welcome to YahtC                            *\n"
           "\t**********************************************************************\n"
           "\tYahtC is a dice game (very) loosely modeled on Yahtzee\n"
           "\tBUT YahtC is not Yahtzee.\n\n"
           "\tRules:\n"
           "\t5 dice are rolled\n"
           "\tThe user selects which dice to roll again.\n"
           "\tThe user may choose to roll none or all 5 or any combination.\n"
           "\tAnd then the user selects which dice to roll, yet again.\n"
           "\tAfter this second reroll the turn is scored.\n\n"
           "\tScoring is as follows:\n"
           "\t\t*\t50 points \t5 of a kind scores 50 points.\n"
           "\t\t*\t45 points \tNo pairs (all unique) scores 45 points.\n"
           "\t\t*\t40 points \t4 of a kind scores 40 points.\n"
           "\t\t*\t30 points \t3 of a kind scores 30 points.\n"
           "\t\t*\tTotal Dice\tOtherwise score the dice total.\n\n"
           "\tTo indicate nothing to reroll the user will input 0\n"
           "\tThis should end the players turn.\n"
           "\tOtherwise the user will indicate which dice to reroll by position\n"
           "\t135 would indicate to reroll the first, third and last die.\n"
           "\tThe numbers do not have to be given in order\n"
           "\tThe game ends after 7 turns.\n"
           "\t**********************************************************************\n\n\n");
}

int sum(int dice[], int diceNum){
    int value = 0;
    for (int i = 0; i < diceNum; i++){
        value += dice[i];
    }
    return value;
}

int returnScore(int dice[], int diceNum){
    int max = 1;
    int give = 0;
    for (int i = 0; i < diceNum; i++){
        int tempMax = 0;
        int num = dice[i];
        for (int j = 0; j < diceNum; j++){
            if (num == dice[j]){
                tempMax++;
            }
        }
        if (tempMax > max){
            max = tempMax;
        }
    }
    if (max == 1){
        give = 45;
    }
    else if (max == 3){
        give = 30;
    }
    else if (max == 4){
        give = 40;
    }
    else if (max == 5){
        give = 50;
    }
    else{
        give = sum(dice, diceNum);
    }
    return give;
}

int main(int argc, char **argv){
    seed(argc, argv);
    instructions();

    int score[7];

    for (int i = 0; i < 7; i++)
    {
        int diceNum = 5;
        int dice[diceNum];
        char reroll[5];
        for (int i = 0; i < diceNum; i++)
        {
            dice[i] = rand() % 6 + 1;
        }
        printf("First Roll = ");
        for (int i = 0; i < diceNum; i++)
        {
            printf("%d", dice[i]);
        }
        printf("\n");
        
        for (int q = 0; q < 2; q++){
            printf("Select dice to reroll:");
            scanf(" %s", reroll);
            if (strcmp(reroll, "0") == 0)
            {
                break;
            }
            if (q == 0)
            {
                printf("second: ");
            }
            else
                printf("final: ");
            for (int x = 0; x < strlen(reroll); x++)
            {
                int j = reroll[x] - '1';
                dice[j] = rand() % 6 + 1;
            }
            for (int i = 0; i < diceNum; i++)
            {
                printf("%d", dice[i]);
            }
            printf("\n");
        }
        score[i] = returnScore(dice, diceNum);
        printf("score for ");
        for (int i = 0; i < diceNum; i++)
        {
            printf("%d", dice[i]);
        }
        printf(" is %d\n", score[i]);
    }

    int sumDice = 0;
    sumDice = sum(score, 7);
    printf("\n\n----------\nSCORESHEET\n----------\n");
    for (int i = 1; i <= 7; i++)
    {
        printf("Turn %d: %d\n", i, score[i - 1]);
    }
    printf("==========\n");
    printf("Total: %d\n", sumDice);

    return 0;
}