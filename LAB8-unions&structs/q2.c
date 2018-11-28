/*LAB 8 QUESTION 2    Written by Er Lin
Program that fills and initialises structs with data from files and outputs this data
in the specified format.*/
#include <stdio.h>
#include <string.h>
#define MAX 50
#define MIN 5

int countLines(void); //function prototype to count lines from the file

//struct definition to store the data from counties.txt
struct county{
  char *longName;
  char *shortName;
  unsigned int population;
};

//struct definition to store the data from towns.txt
struct town{
  char *name;
  unsigned int population;
  struct county aCounty;
};

int main(void)//main function
{
  FILE *countyPtr; //pointer to file

  //open file. If file cannot be opened prompt warning message and exit
  if ((countyPtr = fopen("counties.txt", "rb+")) == NULL)
  {
    printf("\nThe file could not be opened!\n");
  }
  else
  {
    int count = countLines(); //calling function to count lines
    struct county counties[count];//array of struct to save data fro counties.txt
    //2-d arrays to store the data from the file
    char countyLong[count][MAX];
    char countyShort[count][MIN];

    //for loop to scan elements from the file and fill in the 'struct county' array
     for (size_t i = 0; i < count; i++)
     {
       fscanf(countyPtr, "%s %s %u", countyLong[i], countyShort[i], &counties[i].population);
       counties[i].longName = countyLong[i];
       counties[i].shortName = countyShort[i];
     }

     FILE *townsPtr; //pointer to a file

     //open file. If file cannot be opened prompt warning message and exit
     if ((townsPtr = fopen("towns.txt", "rb+")) == NULL)
     {
       printf("\nThe file towns.txt could not be opened!\n");
     }
     else
     {
       struct town towns; //define struct variable
       //arrays to store the data from file
       char nameTown[MAX];
       char county[MAX];

       //while loop to scan data from file and print accordingly
       while (!feof(townsPtr))
       {
         fscanf(townsPtr, "%s %u %s", nameTown, &towns.population, county);
         towns.name = nameTown;

         //for loop to compare and fill the 'aCounty' struct
         for (size_t i = 0; i < count; i++)
         {
           if (strcmp(county, counties[i].longName) == 0)
           {
             towns.aCounty.longName = counties[i].longName;
             towns.aCounty.shortName = counties[i].shortName;
             towns.aCounty.population = counties[i].population;
           }
         }

         //prompt messages with the informatin required for each town
         printf("\nTown: %s\n", towns.name);
         printf("Population: %d\n", towns.population);
         printf("County: %s, %s\n", towns.aCounty.longName, towns.aCounty.shortName);
         printf("County's population: %d\n", towns.aCounty.population);
       }
       printf("\n");
     }

     fclose(townsPtr); //close file

    fclose(countyPtr);//close file
  }
}
//function definition to count the number of lines in the file
//this is needed if new data is added in the future
int countLines()
{
  FILE *countiesPtr; //pointer to the file
  int counter = 0;//initialize counter to 0

  //open file. If file cannot be opened prompt warning message and exit
  if ((countiesPtr = fopen("counties.txt", "r")) == NULL)
  {
    printf("The file could not be opened!\n");
  }
  else
  {
    char array[MAX];

    //while loop using fget to count the number of lines
    while (fgets(array, MAX, countiesPtr) != NULL)
    {
      counter++;
    }
    fclose(countiesPtr);//close file
  }
  return counter; //return the number of lines
}
