#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int ask()
{   char userChoiceAsChar;
    int userChoiceAsInt;
    
    //Ask user choice
    do
    {
        printf("What do you choose?: (R)ock, (P)aper, or (S)cissors?\n");
        scanf(" %c", &userChoiceAsChar );
    }
    while (userChoiceAsChar != 'R' && userChoiceAsChar != 'P' && userChoiceAsChar != 'S' && userChoiceAsChar != 'r' && userChoiceAsChar != 'p' && userChoiceAsChar != 's');

    //  User choice print
    if (userChoiceAsChar == 'r'|| userChoiceAsChar == 'R')
    {
        userChoiceAsInt = 1;
        printf("Your choice is: Rock. ");
    }
    else if (userChoiceAsChar == 'p')
    {
        userChoiceAsInt = 2;
        printf("Your choice is: Paper. ");
    }
    else if (userChoiceAsChar == 's')
    {
        userChoiceAsInt = 3;
        printf("Your choice is: Scissors. ");
    }
    return userChoiceAsInt;

}

int generate()
{   
    int computersChoice;

    // Random number generation
    
    srand(time(0));
    computersChoice = rand() % 3 + 1;

    // Computer choice print
    if (computersChoice == 1)
    {
        printf("Computer's choice is: Rock.\n");
    }
    else if (computersChoice == 2)
    {
        printf("Computer's choice is: Paper.\n");
    }
    else if (computersChoice == 3)
    {
        printf("Computer's choice is: Scissors.\n");
    }
    return computersChoice;

}

int checkWin(int userChoiceAsInt, int computersChoice)
{   
    int result;
    

    //Check who wins the round
    if ((userChoiceAsInt == 1 && computersChoice == 3) || (userChoiceAsInt == 2 && computersChoice == 1) || (userChoiceAsInt == 3 && computersChoice == 2))
    {
        result = 1;
    }
    else if ((userChoiceAsInt == 3 && computersChoice == 1) || (userChoiceAsInt == 1 && computersChoice == 2) || (userChoiceAsInt == 2 && computersChoice == 3))
    {
        result = -1;
    }
    else if(userChoiceAsInt == computersChoice)
    {   
        result = 0;
        
    }
    return result;
    
    
}

void printResult(int userChoiceAsInt, int computersChoice,int result)
{   
    //Print the result of one round

    if (result > 0)
    {   
        
        printf("You won the round!\n----------------------------------------------------\n");
        
    }
    else if (result < 0)
    {   
        
        printf("I'm sorry, CPU won the round.\n----------------------------------------------------\n");
        
    }
    else if (result == 0)
    {   
        
        printf("Tie!\n----------------------------------------------------\n");
        
    }
}

int main()
{ 
    int rounds;
    int wins = 0;
    int computerWins = 0;
    int tie = 0;

    printf("Welcome to Rock-Paper-Scissors game!\n");

    // Rounds declaration

    printf("How many rounds do you wanna play? ");
    scanf(" %d", &rounds);

    
    // Loop that runs every round
    
    for (int i = 0; i < rounds; i++)
    {   
        
        int userChoiceAsInt = ask();
        int computersChoice = generate();
        int result = checkWin(userChoiceAsInt, computersChoice);
        printResult(userChoiceAsInt, computersChoice, result);

        if(result ==1)
    {
        wins++;
    }
    else if(result == -1)
    {
        computerWins++;
    }
    else if(result == 0)
    {
        tie++;
    }
    }
    
    printf("The game ends.\nYour wins: %d/%d. CPU wins: %d/%d. Number of tie: %d", wins, rounds, computerWins, rounds,tie);
}


