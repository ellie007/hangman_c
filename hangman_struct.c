#include <stdio.h>
#include <string.h>

struct Hangman(){
  srand(time(NULL));
  struct Hangman hangman;

  char *word_list[] = {"dog", "cat", "bird", "fish"};
  int random_number = rand() % random_divisor;

  hangman.word = word_list[random_number]

};


int terminal_display(word){
  printf("\nHANGMAN WORD: ");
    for(word_index = 0; word_index < word_length; word_index++){
      if (word_num_representation[word_index] == 1){
        printf("%c", word[word_index]);
      } else{
        printf("_");
      }
    }
}

int main(word){

  int word_num_representation[] = { 0,0,0,0 };

  int random_number = rand() % random_divisor;
  int word_index;
  int word_length = strlen(word_list[random_number]);
  char guess[16], letter_guessed;
  int num_correct = 0, correct_constant, num_incorrect = 0, num_of_lives = 5, max_lives = 5;
  char bad_guesses[6];
  int bad_guess_input_index = 0, bad_guess_display_index, x_index;

  while (num_incorrect < max_lives){

    printf("\nHANGMAN WORD: ");
    for(word_index = 0; word_index < word_length; word_index++){
      if (word_num_representation[word_index] == 1){
        printf("%c", word[word_index]);
      } else{
        printf("_");
      }
    }

    printf("\nNumber of Lives: %i", num_of_lives);
    printf("\nBad Guesses: ");

    for(x_index = 0; x_index < num_incorrect; x_index++){
      printf("X");
    }
    printf(" ");
    for(bad_guess_display_index = 0; bad_guess_display_index < num_incorrect; bad_guess_display_index++){
      printf("%c", bad_guesses[bad_guess_display_index]);
    };

    printf("\n");

    printf("Enter a guess letter: ");
    fgets(guess, 16, stdin);
    letter_guessed = guess[0];

    printf("\n");

    correct_constant = num_correct;

    for (word_index = 0; word_index < word_length; word_index++){
      if(word_list[random_number][word_index] == letter_guessed){
        word_num_representation[word_index] = 1;
        num_correct++;
      }
    }

    if (num_correct == correct_constant){
      num_of_lives--;
      num_incorrect++;
      bad_guesses[bad_guess_input_index] = letter_guessed;
      bad_guess_input_index++;
    }

    if(num_correct == word_length){
      printf("You won!  The word was: ");
      for(word_index = 0; word_index <= word_length; word_index++){
        printf("%c",word_list[random_number][word_index]);
      }
      printf("\n");
      break;
    }

    if(num_of_lives == 0){
      printf("You lose, sorry.  The word was: ");
      for(word_index = 0; word_index <= word_length; word_index++){
        printf("%c",word_list[random_number][word_index]);
      }
      printf("\n");
    }

  }

  return 0;
}
