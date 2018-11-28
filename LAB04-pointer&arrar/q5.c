/*LAB 4 QUESTION 5    Written by: Er Lin on ideas from skeleton provided
Program that simulates a race between two horses, Napoleon (N) and Pegasus (P)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void moveHorse(int *horse); //function that moves Napoleon
void printCurrentPositions(unsigned int, unsigned int); //function that keeps track of their position

int main(void) //main function
{
   srand(time(NULL));
   int Napoleon = 1; //Napoleon current position
   int Pegasus = 1; //Pegasus current position
   int counter = 0; //counter for the for loop controling the race.

   puts("The Race has started"); //prompt message informing start of the race

   //while loop to keep race going until one of them reaches the end
   while (Napoleon != 100 && Pegasus != 100)
   {
     moveHorse(&Napoleon); //calling function to move Napoleon
     moveHorse(&Pegasus); //calling function to move Pegasus
     printCurrentPositions(Napoleon, Pegasus); //calling function to display position of horses
     counter++; //add 1 to counter of iterations
   }

   //display the final positions of both horses
   printf("Final positions --> P: %d, N: %d\n", Pegasus, Napoleon);

   //determine the winner of the race or if it is a tie
   if (Napoleon > Pegasus)
   {
      printf("Napoleon WINS!!\n");
   }
   if (Napoleon < Pegasus)
   {
      printf("Pegasus WINS!!\n");
   }
   else
   {
     printf("The race has ended on a TIE\n");
   }

   printf("Iterations: %d\n", counter); //display the number of iterations before end of race
}

//progress for chosen horse function definition
void moveHorse(int *horse)
{
   //generate random number from 1-10
   int x = 1 + (rand()%10);

   //determine space covered by horse
   if (x >= 1 && x <= 5)
   {
     //50% of the time progress at full speed(3 poles)
     *horse += 3;
   }
   else if (x == 6)
   {
     //10% of the time march backwards 2 poles
     *horse -= 2;
   }
   else if (x == 7)
   {
     //10% of the time stay still
     *horse = *horse;
   }
   else if (x >= 8 && x <= 10)
   {
     //30% of the time progress 1 pole
     *horse += 1;
   }
   //check boundaries
   if (*horse < 1)
   {
      *horse = 1;
   }
   if (*horse > 100)
   {
      *horse = 100;
   }
}

//display new positions
void printCurrentPositions(unsigned int Napoleon, unsigned int Pegasus)
{
   //for loop to display progression of the horses throug the race
   for (unsigned int count = 1; count <= 100; count++)
   {
     if (count == Napoleon && count == Pegasus)
     {
       printf("T"); //if they are tied, display T in their position
     }
     else if (count == Pegasus)
     {
       printf("P"); //display P where Pegasus is (position)
     }
     else if (count == Napoleon)
     {
       printf("N"); //display N where Napoleon is (position)
     }
     else
     {
       printf(" "); //display spaces where the horses are not at that iteration
     }
   }
   printf("\n");
}
