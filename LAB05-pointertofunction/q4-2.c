/*LAB 5 QUESTION 4    Written by Er Lin using skeleton provided
Program that obtains the public's opinion on topics*/
#include <stdio.h>
#define ISSUES 5
#define RATINGS 10

// function prototypes
void recordResponse (int issue, int response); //prototype of function to record user's ratings
void highestRatings (); //protoype of function to find the highest rated topic
void lowestRatings (); //prototype of function to find the lowest rated topic
void displayResults(int numbRatings); //prototype of function to display the results

int responses[ISSUES][RATINGS]; //Two-dimensional array to store poll-ratings
const char *topics[ISSUES] = {"Healthcare", "Transport", "Unemployment Rate", "Economy", "Housing"}; //array of topics

int main (void)//main function
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
		for (size_t i = 0; i < ISSUES; i++)
		{
			printf("%s: ", *(topics + i));
			recordResponse(i, response); //calling record response function
		}
		numbRatings++;//increase numbRatings by 1

		printf("\nEnter 1 to stop or a different to allow a new person to rate the issues again: "); // Ask if the user wants to stop
		scanf("%d", &response); // get the user's response
	} while(response != 1);

	displayResults(numbRatings); //calling function to display results in tabular form
}

//Function definition to record user's inputs(ratings)
void recordResponse(int issue, int response)
{
	//do-while loop to valid the input by the user and read it in
	do {
		scanf("%d", &response);
		if (response > 10 || response < 1) //if not a valid entry, display warning message
		{
			printf("Please enter a valid rating!!\n");
		}
	} while(response > 10 || response < 1);

	responses[issue][response-1] += 1; //if entry is valid, store it into the reponses array
}

//get the highest rated topic (highest point total)
void highestRatings()
{
	//create variables and initialize to 0
  int highRating = 0;
  int highTopic = 0;

	//for loop to find out the highest rated topic
  for (unsigned int i = 0; i < ISSUES ; i++)
	{
    int topicRating = 0;

    for (unsigned int j = 0; j < RATINGS; j++)
		{
			topicRating += responses[i][j] * (j +1);
		}
		if (highRating < topicRating) {
			highRating = topicRating;
			highTopic = i;
		}
	}
	//prompt message to display the results
	printf("\nThe highest rated topic was %s with a total rating of %d\n", topics[highTopic], highRating);
}

// get the lowest rated topic (lowest point total)
void lowestRatings(void)
{
	//create varibales and initialize
	int lowRating = 100;
	int lowTopic = 0;

	//for loop to find out the low rated topic and its total rating
	for (unsigned int i = 0; i < ISSUES; i++)
	{
		int topicRating = 0;

		for (unsigned int j = 0; j < RATINGS; j++)
		{
			topicRating += responses[i][j] * (j +1);
		}
		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	//prompt message to display the results
	printf("The lowest rated topic was %s with a total rating of %d\n\n", topics[lowTopic], lowRating);
}

// Output in tabular form the number of ratings per issue
void displayResults(int numbRatings)
{
	float average[ISSUES]; //create floating number array to contain average rating of each issue

	// Output table header
	printf("\n%20s", "TOPIC");
	for (unsigned int i = 1; i <= RATINGS; ++i)
	{
		printf("%4d", i);
	}
	printf("%12s", "Average\n");

	//output table contents summarising all results entered by the users
	for (unsigned int i = 0; i < ISSUES; i++)
	{
		float average = 0;
		printf("%20s", *(topics + i));

		for (unsigned int j = 0; j < RATINGS; j++)
		{
			printf("%4d", responses[i][j]);
			average += responses[i][j] * (j+1); //adding all ratings of an issue to then calculate the average
		}
		printf("%11.2f\n", average/numbRatings);
	}

	// Output the highest and lowest ratings for this poll
	highestRatings();
	lowestRatings();
}
