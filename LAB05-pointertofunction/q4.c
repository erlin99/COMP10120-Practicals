/*LAB 5 QUESTION 4    Written by Er Lin using skeleton provided
Program that obtains the public's opinion on topics*/
#include <stdio.h>
#define ISSUES 5
#define RATINGS 10

void recordResponse (int issue, int rating); //prototype of function to record user's ratings
void highestRatings (int numbRatings); //protoype of function to find the highest rated topic
void lowestRatings (int numbRatings); //prototype of function to find the lowest rated topic
void displayResults(); //prototype of function to display the results

int responses[ISSUES][RATINGS]; //Two-dimensional array to store poll-ratings
const char *topics[ISSUES] = {"Healthcare", "Transport", "Unemployment Rate", "Economy", "Housing"}; //array of topics

int main (void) //main function
{
	int response; //the user's response
	int numbRatings = 0; //create numbRatingsrating and initialize to 0

	//nested for loops to set elements of array to 0
	for (size_t i = 0; i < ISSUES; i++) {
		for (size_t j = 0; j < RATINGS; j++) {
			responses[i][j] = 0;
		}
	}
	//prompt messages introduce the program to user
	printf("\nWelcome, please rate the following issues in Ireland from 1 to 10\n");
	printf("10 being very important and 1 not important at all.\n\n");

	// do-while loop to administer the poll.
	do {
		//for loop to record the ratings input by user
		for (size_t i = 0; i < ISSUES; i++)
		{
			printf("%s: ", topics[i]);
			recordResponse(i, numbRatings); //calling record response function
		}
		numbRatings++;//increase numbRatings by 1

		printf("\nEnter 1 to stop or a different to allow a new person to rate the issues again: "); // Ask if the user wants to stop
		scanf("%d", &response); //reads an integer
	} while(response != 1);

	displayResults(numbRatings); //calling function to display results in tabular form
}

//Function definition to record user's inputs(ratings)
void recordResponse(int issue, int numbRatings)
{
	int answer;
	//do-while loop to valid the input by the user and read it in
	do {
		scanf("%d", &answer);
		if (answer > 10 || answer < 1) //if not a valid entry, display warning message
		{
			printf("Please enter a valid rating!!\n");
		}
	} while(answer > 10 || answer < 1);

	responses[issue][numbRatings] = answer; //if entry is valid, store it into the reponses array
}

//get the highest rated topic (highest point total)
void highestRatings(int numbRatings)
{
	//create variables and initialize to 0
  int highRating = 0;
  int highTopic = 0;

	//for loop to find out
  for (unsigned int i = 0; i < ISSUES ; i++) {
    int topicRating = 0;

    for (unsigned int j = 0; j < numbRatings ; j++) {
			topicRating += responses[i][j];
		}
		if (highRating < topicRating) {
			highRating = topicRating;
			highTopic = i;// index of the highest rated topic
		}
	}
	printf("The highest rated topic was %s with a total rating of %d\n", topics[highTopic], highRating);
}

// get the lowest rated topic (lowest point total)
void lowestRatings(int numbRatings)
{
	int lowTopic = 10;
	int lowRating;

	for (unsigned int i = 0; i < ISSUES; i++)
	{
		int topicRating = 0;

		for (unsigned int j = 0; j < numbRatings; j++)
		{
			topicRating += responses[i][j]*(j+1);
		}

		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
   printf("The lowest rated topic was %s with a total rating of %d\n", topics[lowTopic], lowRating);
}

// Output in tabular form the number of ratings per issue
void displayResults(int numbRatings)
{
	float average[ISSUES]; //create floating number array to contain average rating of each issue

	//output table header
	printf("%17s", "TOPIC");
	for (unsigned int i = 0; i < numbRatings; i++)
	{
		printf("%8s%d", "User", i);
	}
	printf("%12s", "Average\n");

	//output table contents summarising the all results entered by the users
	for (unsigned int i = 0; i < ISSUES; i++)
	{
		average[i] = 0;
		printf("%17s", topics[i]);

		for (unsigned int j = 0; j < numbRatings; j++)
		{
			printf("%9d", responses[i][j]);
			average[i] += responses[i][j]; //adding all ratings of an issue to then calculate the average
		}
		printf("%11.2f\n", average[i]/numbRatings);
	}

   // Output the highest and lowest ratings for this poll
   highestRatings(numbRatings);
   lowestRatings(numbRatings);
}
