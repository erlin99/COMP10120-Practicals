/*LAB 7 QUESTION 4    Written by Er Lin
Program that simulates system to record/catalogue the games that you've borrowed.*/
#include <stdio.h>

#define MAX 50

void resetFile(void);//prototype for function that resets file
void editFile(void);//prototype for function that allows user to edit the file
void printTable(void);//protoype for function that prints out information from the file in tabular format
void actions(void);//protoype for function that prints prompt messages to ask the user for the actions to perform

//gamesData structure definition
struct gamesData {
  unsigned int gameNum;
  char title[MAX];
  char platform[MAX];
  char developer[MAX];
  unsigned int year;
  char borrowed[4];
  char name[MAX];
  char date[MAX];
};

int main(void)//main function
{
  int y;
  //prompt message introducing the program
  printf("\nWELCOME TO A PROGRAM TO KEEP TRACK OF ALL YOUR GAMES.\n");

  //prompt message to know if this is the first time for the user
  printf("Is this your first time using this program? Enter 1 for YES or 0 for NO.\n");
  scanf("%d", &y); //read an integer

  if (y == 1)
  {
    //if it is first time, reset/create the file and then ask what user wants to do
    resetFile(); //calling reset function
    //prompt message informing what has been done
    printf("A file called 'gamesData.dat' has been created to store your data.\n");
    actions();//calling actions function
  }
  else
  {
    actions(); //calling actions function
  }
  printf("\nThank you for using this program.\n");
}
//function definition to reset file
void resetFile(void)
{
  FILE *filePtr; //pointer to gamesData.dat file

  //open file. If file cannot be opened or created prompt warning message and exit
  if ((filePtr = fopen("gamesData.dat", "wb")) == NULL)
  {
    printf("\nThe file could not be opened/created!! Restart the program.\n");
  }
  else
  {
    //create games data with default information
    struct gamesData blankData = {0, "", "", "", 0, "", "", ""};

    //for loop to output 1000 blank records into the gamesData.dat file
    for (unsigned int i = 1; i < 1000; i++)
    {
      fwrite(&blankData, sizeof(struct gamesData), 1, filePtr);
    }

    fclose(filePtr); //close the file
  }
}
//function definition to allow user to edit the file
void editFile(void)
{
  FILE *filePtr; //pointer to gamesData.dat file

  //open file. If file cannot be opened or created prompt warning message and exit
  if ((filePtr = fopen("gamesData.dat", "rb+")) == NULL)
  {
    printf("\nThe file could not be opened/created!! Restart the program.\n");
  }
  else
  {
    //create games data with default information
    struct gamesData game = {0, "", "", "", 0, "", "", ""};

    //prompt message asking user to enter the game number (identifier)
    printf("Please enter the game's identification number (1 - 1000), to end input enter 0:\n");
    scanf("%d", &game.gameNum); //read in an integer

    //while loop to get information about the game from the user
    while (game.gameNum != 0)
    {
      //prompt messages stating the order in which the user should enter the games' information
      printf("Please enter Title, Platform, Developer and Year of the game(please replace any spaces with '-')\n");
      printf("Did you borrowed? Enter Yes or No. If Yes enter Name of the person and the date(DD/MM/YY) that you borrowed it.\n");
      printf("If not enter '-' for person and date.\n");

      //read in the information given by user
      fscanf(stdin, "%s %s %s %d %s %s %s", game.title, game.platform, game.developer, &game.year, game.borrowed, game.name, game.date);

      //look for position in the file that corresponds to the game number
      fseek(filePtr, (game.gameNum-1)*sizeof(struct gamesData), SEEK_SET);
      //write the information into the specified position
      fwrite(&game, sizeof(struct gamesData), 1, filePtr);

      //keep asking until user exits input
      printf("Enter next game's number, to end input enter 0.\n");
      scanf("%d", &game.gameNum);
    }
    fclose(filePtr); //close the file
  }
}
//function definition to print information from the file in a tabular format
void printTable(void)
{
  FILE *filePtr; //pointer to gamesData.dat file

  //open file. If file cannot be opened or created prompt warning message and exit
  if ((filePtr = fopen("gamesData.dat", "rb")) == NULL)
  {
    printf("\nThe file could not be opened/created!! Restart the program.\n");
  }
  else
  {
    //print the table header
    printf("%-21s%-15s%-17s%-19s%-14s%-18s%-20s%s\n", "Game Number", "Title", "Platform", "Developer", "Year", "Borrowed", "Name", "Date");

    while (!feof(filePtr)) //while the end of file is not reached
    {
      //create games data with default information
      struct gamesData game = {0, "", "", "", 0, "", "", ""};

      int x = fread(&game, sizeof(struct gamesData), 1, filePtr);

      //display the records from the games under the table header
      if (x != 0 && game.gameNum != 0)
      {
        printf("%-21d%-15s%-17s%-19s%-14d%-18s%-20s%s\n", game.gameNum, game.title, game.platform, game.developer, game.year, game.borrowed, game.name, game.date);
      }
    }
    fclose(filePtr); //close the file
  }
}
//function definition for prompt messages to ask the user for the actions to perform
void actions(void)
{
  int x;

  //prompt messages asking user to enter a number depending on action
  printf("\nWhat do you wish to do?\n");
  printf("Press 1 to Reset the file containing all your games.\n");
  printf("Press 2 to Edit your information in the file.\n");
  printf("Press 3 to See your information in the file.\n");
  printf("Press 0 to Exit this program.\n");
  scanf("%d", &x); //read an integer

  //while the user doesn't exit the program:
  while (x != 0)
  {
    if (x == 1) //Reset the file
    {
      int z;
      //inform user that all data will be deleted
      printf("Are you sure you want to reset? This will delete the current data.\n");
      printf("Enter 1 for YES or 0 for NO.\n");
      scanf("%d", &z);
      //if yes, call the resetFile funtion
      while (z != 0) {
        resetFile();
        break;
      }
    }
    //edit the file
    else if (x == 2) {
      editFile();
    }
    //print data in tabular form
    else if (x == 3) {
      printTable();
    }

    //prompt messages asking user to enter a number depending on action
    printf("\nWhat do you wish to do now?\n");
    printf("Press 1 to Reset the file containing all your games.\n");
    printf("Press 2 to Edit your information in the file.\n");
    printf("Press 3 to See your information in the file.\n");
    printf("Press 0 to Exit this program.\n");
    scanf("%d", &x); //read an integer
  }
}
