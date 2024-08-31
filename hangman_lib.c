// Header Files
#include "hangman_lib.h"

// Initialize variables and constants
const char* FRUITS[LEN_FRUITS] = {"abiu",  "acai", "acerola", "akebi", "ackee", 
    "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry",
    "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel",
    "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut",
    "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian",
    "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin",
    "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia",
    "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit",
    "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo",
    "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe",
    "galia", "melon", "honeydew", "watermelon", "mulberry", "nance",
    "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya",
    "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum", 
    "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate",
    "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant",
    "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry",
    "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};

//Functions
int getSecretWord(char *secretWord)
{
	// Randomly generate an index 0 - LEN_FRUITS
	srand(time(NULL));
	// store in variable
	int random_index = rand() % LEN_FRUITS;

	//Select appropriate secret word from FRUITS
	// store in variable
	char word[MAX_FRUIT_SIZE];

	strcpy(word, FRUITS[random_index]);
	

	// Copy the fruit name into output parameter secretWord[]
	strcpy(secretWord, word);
	// Find length of fruit name
	// store in variable
	int len_word = strlen(secretWord);

	// Return lenght of fruit name
	return len_word;
}

void buildOutputArray(int length, char *outputArray)
{
	// creates outputArray of length 'length'
	// fill in array with underscores
	// should only have one underscore for each position
	for(int i = 0; i <= length - 1; i++)
	{
		outputArray[i] = '_';
	}
	outputArray[length] = '\0';



}

void buildAttemptArray(char *attemptArray)
{
	// initialize with '*', '*', '*', '*', '*', '*', '\0'
	for(int i = 0; i <= 5; i++)
	{
		attemptArray[i] = '*';
	}
	attemptArray[6] = '\0';

	
}

bool checkGuess(char guess, const char *secretWord, int length)
{
	// loop through array secretWord
	for(int i = 0; i <= length - 1; i++)
	{
		// check if elements of secretWord == guess
		if(secretWord[i] == guess)
		{
			// if true, return true
			return true;
		}

		
	}
	// else return false
	return false;
}	

bool fillOutputArray(char guess, const char *secretWord, 
	char *outputArray, int length)
{
	// initialize variables
	int numOfReplaces = 0;
	// loop through array secretWord
	for(int i = 0; i <= length - 1; i++)
	{
		// check if secretWord[iteration] == guess
		if(secretWord[i] == guess)
		{
			// if so, outputArray[iteration] = guess
			outputArray[i] = guess;
			// new variable to count num of replaces ++
			numOfReplaces++;
		}
		// else
			// continue
		
	}	
	// if num of replaces > 0
	if(numOfReplaces > 0)
	{
		// return true
		return true;
	}
	// else
	else
	{
		// return false
		return false;
	}

}

bool fillAttemptsArray(char guess, char *attemptArray, int length)
{
	// loop through *attemptArray in order to find the index
	// of the next '*' character.
	for(int i = 0; i <= 6; i++)
	{
		// if *attemptArray[iteration] == guess
		if(attemptArray[i] == guess)
		{
			// return false
			return false;
		}
		// if *attemptArray[iteration] != '*'
		if(attemptArray[i] == '*')
		{
			// store iteration in variable
			int starIndex = i;

			// replace attemptArray[iteration] with guess
			attemptArray[starIndex] = guess;

			// return true
			return true;
		
		}
	}
	

	return true;

}

bool checkVictory(int length, char *outputArray)
{

	// loop through outputArray
	for(int i = 0; i <= length - 1; i++)
	{
		// check if element is '_'
		if(outputArray[i] == '_')
		{
			// if it is return false

			return false;
		}
	}

	// return true

	return true;
}

bool checkDefeat(char *attemptArray)
{
	// loop through attemptArray
	for(int i = 0; i <= 6; i++)
	{
		// check if element is '*'
		if(attemptArray[i] == '*')
		{
			// if it is, return false

			return false;
		}
	}

	// return true

	return true;
}

bool checkIfGuessed(char *alreadyGuessed, char guess)
{
	for(int i = 0; i <= 27; i++)
	{
		if(alreadyGuessed[i] == guess)
		{
			return true;
		}
		
	}	
	return false;
}

void play()
{

// Declare variables

	// initialize secretWord[MAX_FRUIT_SIZE]
	char secretWord[MAX_FRUIT_SIZE];
		// call getSecretWord
	int length = getSecretWord(secretWord);

	// initialize attempt array
	char attemptArray[7];
		// call buildAttemptArray
	buildAttemptArray(attemptArray);

	// initialize output array
	char outputArray[length];
		// call buildOutputArray
	buildOutputArray(length, outputArray);

	// initialize big array with wierd numbers to alreadyGuessed
	char alreadyGuessed[27] = {'!'};

	// user input
	char guess;

	// giveup
	bool giveup = 1;



// Play game

	// Print out intro message
	printf("\n***************************\n");
	printf("Welcome to the Hangman Game\n");
	printf("***************************\n\n");


	// Ask user to guess
	printf("\nWhich letter? (0 to exit the game):\n");
	// read input
	scanf(" %c", &guess);

	

	// check if guess is 0
	if(guess =='0')
	{
		// print message
		printf("You gave up!");
		// if so exit funciton
		return;
	}

	
	// check if in alreadyGuessed array
	bool guessed = checkIfGuessed(alreadyGuessed, guess);
	// while guessed
	while(guessed)
	{	
		// print message to user
		printf("Repeated guess. Try another letter!\n");
		// read new input
		scanf(" %c", &guess);
		// check if it has been guessed
		guessed = checkIfGuessed(alreadyGuessed, guess);
	}

	// put guess into alreadyGuessed
	for(int i = 0; i <= 26; i++)
	{
		// check if char is !
		if(alreadyGuessed[i] == '!')
		{
			// replace element with guess
			alreadyGuessed[i] = guess;
			// exit loop
			break;
		}
		
	}
	// check if guess is in secret word
		// call checkGuess
		// store in variable
	bool check = checkGuess(guess, secretWord, length);

	// if guess is correct
	if(check)
	{
		printf("\ncheckGuess is true\n");
		// call fillOutputArray
		fillOutputArray(guess, secretWord, outputArray, length);
		puts(outputArray);
		// check if user won
		//call checkVictory
		bool victory = checkVictory(length, outputArray);
			// if true
		if(victory)
		{
				// set giveup to false
			giveup = false;
		}
	}
	// if guess is incorrect
	if(!check)
	{

		// call fillAttemptsArray
		fillAttemptsArray(guess, attemptArray, length);

		// print message and array
		printf("The letter doesn't exist in the word.\n");
		printf("Mistakes: ");
		puts(attemptArray);
		printf("\n");
		// check if user lost
		// call checkDefeat
		int defeat = checkDefeat(attemptArray);
			// if true
		// check if defeat is true
		if(defeat == 1)
		{
			// giveup = false
			giveup = false;
			// print the secret word
			printf("The secret word was: ");
			//puts(secretWord);
			printf("\n");
			// tell user they lost
			printf("You lost the round!\n");
		}
	}

	// run while loop while user has not won or lost or quit(NAND?)
	// while(userInput == giveup)
	while(giveup)
	{
		// Ask user to guess
		printf("\nWhich letter? (0 to exit the game):\n");
		// read input
		scanf(" %c", &guess);

		
		// check if guess is 0
			// if so, exit function
		if(guess =='0')
		{
			// print message
			printf("You gave up!");
			// if so exit funciton
			return;
		}

		// check if guess is in alreadyGuessed
		bool guessed = checkIfGuessed(alreadyGuessed, guess);
		// while it has been guessed
		while(guessed)
		{
			// print message to user
			printf("Repeated guess. Try another letter!\n");
			// read and store
			scanf(" %c", &guess);
			// check again
			guessed = checkIfGuessed(alreadyGuessed, guess);
		}
		

		// put guess into alreadyGuessed
		for(int i = 0; i <= 26; i++)
		{	
			// check if element is !
			if(alreadyGuessed[i] == '!')
			{
				// replace element with guess
				alreadyGuessed[i] = guess;
				// exit loop
				break;
			}
			
		}


		// check if guess is in secret word
			// call checkGuess
			// store in variable
		bool check = checkGuess(guess, secretWord, length);

		// if guess is correct
		if(check)
		{
			// call fillOutputArray
			fillOutputArray(guess, secretWord, outputArray, length);
			//print the array
			printf("\n");
			puts(outputArray);
			// check if user won
			//call checkVictory
			bool victory = checkVictory(length, outputArray);
				// if true
			if(victory)
			{
				// set giveup to false
				giveup = false;
				// print message
				printf("You won the round! Well done!");
			}
			// if not victory
			else
			{
				// giveup is true
				giveup = true;
			}
		}

		// if guess is incorrect
		if(!check)
		{
			// call fillAttemptsArray
			fillAttemptsArray(guess, attemptArray, length);
			// print attempt array
			printf("The letter doesn't exist in the word.\n");
			printf("Mistakes: ");
			puts(attemptArray);
			// check if user lost
			// call checkDefeat
			bool defeat = checkDefeat(attemptArray);
				// if true

			if(defeat)
			{
				// giveup = false
				giveup = false;
				// print the secret word
				printf("The secret word was: ");
				puts(secretWord);
				printf("\n");
				// tell user they lost
				printf("You lost the round!\n");
			}
			else
			{
				giveup = true;
			}

		}
	}
	// new round variable intialized
	char newRound;
	// ask if user wants to play another round
	printf("\nDo you want to play a new round? [y|n]");
	// read input
	scanf(" %c", &newRound);

	// go into while loop if invalid response
	while(newRound != 'y' && newRound != 'n')
	{
		// print error message
		printf("I didn't get that. Please use y to yes and n to no.");
		// ask to play new round
		printf("\nDo you want to play a new round? [y|n]\n");
		// scan input
		scanf(" %c", &newRound);
	}
	// check if the user input y
	if(newRound == 'y')
	{
		// call play again

		play();
	}
	// if it was n
	else if( newRound == 'n')
	{
		// exit function
		return;
	}
	
}