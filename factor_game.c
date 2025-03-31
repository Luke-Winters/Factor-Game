#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void);
int computer_choose(void);
int human_choose(int avoid);
int count_factor(int num);

int computer_choose(void) {
    // Seed random number
    srand(time(NULL));
    // Generate a random number between 1 and 1000
    int randomNumber = (rand() % 1000) + 1;
    // Print the random number
    printf("%d\n", randomNumber);

    return randomNumber;
}

int human_choose(int avoid) {
    int humanNumber;
    bool choosing = true;
    // Reads human's number of choice
    while (choosing) {
        printf("Please enter a number other than %d between 1 and 1000\n", avoid);
        scanf("%d", &humanNumber);
        // Makes sure number is valid
        if (humanNumber <= 1000 && humanNumber >= 0 && humanNumber != avoid) {
            choosing = false;
        }
    }
    return humanNumber;
}

int count_factor(int num) {
    int count = 0;
    // Counts the factors of num
    for (int i=1; i <= num; i ++) {
        if (num % i == 0) {
            count ++;
        }
    }
    return count;
}

int main(void) {
    // Initiate variables
    int computerScore = 0;
    int humanScore = 0;
    int round = 1;
    bool playing = true;
    // Game loop
    while (playing) {
        printf("Round %d\n", round);
        // Choose numbers
        int computerNum = computer_choose();
        int humanNum = human_choose(computerNum);
        // Ends game if human enters 0
        if (humanNum == 0) {
            break;
        }
        // Find factors
        int computerFactors = count_factor(computerNum);
        int humanFactors = count_factor(humanNum);
        // Compare factors
        if (computerFactors == humanFactors) {
            humanScore ++;
            printf("Human score +1!\n\n");
        } else {
            computerScore ++;
            printf("Computer score +1!\n\n");
        }
        round ++;
    }
    // Prints final score of the game
    printf("Final scores:\nComputer - %d\nHuman - %d\n", computerScore, humanScore);
}
