/*LAB 6 QUESTION 2    Written by Er Lin
Program which reads in the contents of the sequential file students.tx*/
#include <stdio.h>

int main(void) //main funtion
{
  FILE *filePtr; //pointer to student.txt file
  char name[20], surname[20], studyField[30]; //create character arrays to store name, surname and the field of study
  int studentNumber, phoneNumber; //create integer variables to store the student number and the phone number
  double GPA; //create float variable to store GPA

  //open file. If file cannot be opened or created prompt warning message and exit
  if ((filePtr = fopen("student.txt", "r")) == NULL)
  {
    printf("The file could not be opened!!\n");
  }
  else //else if the file is opened
  {
    //display table heading for table
    printf("\n%-15s%-12s%-19s%-17s%-19s%s\n", "First name", "Surname", "Student Number", "Phone Number", "Field of Study", "GPA");
    //scan values from the text file
    fscanf(filePtr,"%s %s %d %d %s %lf", name, surname, &studentNumber, &phoneNumber, studyField, &GPA);

    while (!feof(filePtr))//while the end of file is not entered by user, keep receiving data
    {
      if (GPA > 3.2)
      {
        //print dta in tabular form
        printf("%-15s%-12s%-19d%-17d%-19s%.2lf\n", name, surname, studentNumber, phoneNumber, studyField, GPA);
      }
      else
      {
        //if the GPA is lower than 3.2 do not print the student
        printf("**************************************************************************************\n");
      }
      //scan values again for text file
      fscanf(filePtr,"%s %s %d %d %s %lf", name, surname, &studentNumber, &phoneNumber, studyField, &GPA);
    }
    printf("\n");
  }
  fclose(filePtr); //close text file
}
