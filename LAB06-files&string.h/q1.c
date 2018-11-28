/*LAB 6 QUESTION 1    Written by Er Lin
Program prompts the user for student records and then writes each record to a file called students.txt*/
#include <stdio.h>
int main(void) //main function
{
  FILE *filePtr; //pointer to student.txt file

  char name[20], surname[20], studyField[30]; //create character arrays to store name, surname and the field of study
  int studentNumber, phoneNumber; //create integer variables to store the student number and the phone number
  double GPA; //create float variable to store GPA

  printf("\nWelcome to a program to save student records into a text file.\n");//prompt message introducing the program

  //open file. If file cannot be opened or created prompt warning message and exit
  if ((filePtr = fopen("student.txt", "w")) == NULL)
  {
    printf("\nThe file could not be opened/created!! Restart the program.\n");
  }
  else //if file is created/opened
  {
    //inform user the order in which data must be input
    printf("\nPlease enter the details of each student in the following order:\n");
    printf("Name, Surname, Student Number, Phone Number, Field of Study and GPA.\n");
    printf("Enter only one word for name, surname and field of study.\n");
    printf("To end input, enter EOF.\n");

    printf("\nStudent 1: \n"); //read in the data of the first student
    scanf("%s %s %d %d %s %lf", name, surname, &studentNumber, &phoneNumber, studyField, &GPA);

    int i = 2;
    while (!feof(stdin)) //while the end of file is not entered by user, keep receiving data
    {
      //print data into text file
      fprintf(filePtr,"%s %s %d %d %s %.2lf\n",name, surname, studentNumber, phoneNumber, studyField, GPA);

      printf("\nStudent %d\n", i);
      //read in the different inputs by the user
      scanf("%s %s %d %d %s %lf", name, surname, &studentNumber, &phoneNumber, studyField, &GPA);
      i++;
    }
  }
  fclose(filePtr); //close the file
}
