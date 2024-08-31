//Header files /  Guards
#ifndef HANGMAN_LIB
#define HANGMAN_LIB
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
// Global constants
#define LEN_FRUITS 104
#define ATTEMPTS 6
#define MAX_FRUIT_SIZE 25
#define LEN_FRUITS 104
extern const char* FRUITS[LEN_FRUITS];

// Function prototypes
/**
 * Name: initializeRandom
 * Process: initializes radom number generator based
 * 		based on system time
 * Function input/parameters: none
 * Function output/parameters: none         
 * Function output/returned: none
 * Dependencies: time.h
 **/
void initializeRandom();

/**
 * Name: getSecretWord
 * Process: selects secret word and copies the fruit name into output
 * 		parameter secretWord[]. Then returns the length of the word
 * Function input/parameters: secretWord
 * Function output/parameters: secretWord        
 * Function output/returned: integer value of length of secret word
 * Dependencies: LEN_FRUITS, FRUITS
 **/
int getSecretWord(char *secretWord);

/**
 * Name:buildOutputArray
 * Process: Takes the length of the secret word and an outputArray
 * Function input/parameters: length, *outputArray
 * Function output/parameters: *outputArray        
 * Function output/returned:none
 * Dependencies: none
 **/
void buildOutputArray(int length, char *outputArray);

/**
 * Name: buildAttemptArray
 * Process: Takes a pointer to an array with 7 positions to store
 * 		the user's incorrect guesses. Initialized with stars in each position
 * 		except for the last which recieves null terminator '\0'. The other 
 * 		6 stars represent that no guesses have been made yet.
 * Function input/parameters: *attemptArray
 * Function output/parameters: *attemptArray      
 * Function output/returned: none
 * Dependencies: none
 **/
void buildAttemptArray(char *attemptArray);

/**
 * Name: checkGuess
 * Process: checks if thee user's guess is a letter that exists
 * 		in the secret word.
 * Function input/parameters: guess, secretWord, length
 * Function output/parameters: none   
 * Function output/returned: true or false
 * Dependencies: bool.h
 **/
bool checkGuess(char guess, const char *secretWord, int length);

/**
 * Name: fillOutputArray
 * Process: Verifies whether each letter in the secret word is the
 * 		user's guess. If it is, it replaces the underscore in the array
 * 		with the guess. Returns false if no underscore is replaced.
 * 		Returns true vice versa.
 * Function input/parameters: guess, *secretWord, *outputArray, length
 * Function output/parameters: *outputArray  
 * Function output/returned: true or false
 * Dependencies: bool.h
 **/
bool fillOutputArray(char guess, const char *secretWord, 
	char *outputArray, int length);

/**
 * Name: fillAttemptArray
 * Process: replaces next '*' in the attemptArray with the letter that
 * 		represents an incorrect guess from the user. Returns true if a
 * 		star was replaced, and false if otherwise.
 * Function input/parameters: guess, *attemptArray, length
 * Function output/parameters: *attemptArray 
 * Function output/returned: true or false
 * Dependencies: bool.h
 **/
bool fillAttemptsArray(char guess, char *attemptArray, int length);

/**
 * Name: checkVictory
 * Process: checks whether the outputArray is filled with letters only
 * 		with no underscores. Returns false if there is a single underscore
 * 		in the entire array.
 * Function input/parameters: length, *outputArray
 * Function output/parameters: none 
 * Function output/returned: true or false
 * Dependencies: bool.h
 **/
bool checkVictory(int length, char *outputArray);

/**
 * Name: checkDefeat
 * Process: Checks if there are any '*' characters in the attemptArray
 * Function input/parameters: *attemptAray
 * Function output/parameters: none 
 * Function output/returned: true or false
 * Dependencies: bool.h
 **/
bool checkDefeat(char *attemptArray);

/**
 * Name: play
 * Process: Game control function. 
 		1. Generates random secret word
 		2. declares necessary variables
 		3. asks for user to guess
 		4. for each guess, decides if it is in the secret word
 		5. repeat from step 3 WHILE the user doesnt win, lose, or give up
 * Function input/parameters: none
 * Function output/parameters: none 
 * Function output/returned: none
 * Dependencies: all other functions
 **/
void play();

#endif