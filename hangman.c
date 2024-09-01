#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6

void printWord(char word[], int length, int guessed[]) {
    for (int i = 0; i < length; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char word[] = "programming";
    int wordLength = strlen(word);
    int guessed[wordLength];
    for (int i = 0; i < wordLength; i++) {
        guessed[i] = 0;
    }

    int tries = 0;
    char guess;
    int correctGuesses = 0;

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES && correctGuesses < wordLength) {
        printWord(word, wordLength, guessed);
        printf("Guess a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);する

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                correctGuesses++;
                found = 1;
            }
        }

        if (!found) {
            tries++;
            printf("Wrong guess! You have %d tries left.\n", MAX_TRIES - tries);
        }
    }

    if (correctGuesses == wordLength) {
        printf("Congratulations! You guessed the word '%s'.\n", word);
    } else {
        printf("Game Over! The word was '%s'.\n", word);
    }

    return 0;
}
