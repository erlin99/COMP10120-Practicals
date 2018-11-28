/*LAB 10 QUESTION 4    Written by Er Lin
Program that shows how a class works by creating a Student Class which a university
uses to represent the students in a university management system.*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
  string name; //students name
  string studentAddress; //students address
  string studentPhone; //phone number stored in a string to allow number start with 08
  string studyField; //student's field of study
  int stage; //current studying year
  float gpa; //student´s current GPA

public:
  //list of functions to set the different data members of the class
  void setStudentName() {
    cout << "Name: ";
    getline(cin, name); //get the name
  }
  void setStudentAddress() {
    cout << "Email: ";
    getline(cin, studentAddress); //get the address
  }
  void setStudentPhone() {
    cout << "Phone Number: ";
    getline(cin, studentPhone); //get the phone number
  }
  void setStudyField() {
    cout << "Field of study: ";
    getline(cin, studyField);//get the field of study
  }
  void setStage() {
    cout << "Stage: ";
    cin >> stage;//get the stage
    //ignore new line character so it doesn´t interfere with the getlline() function
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
  }
  void setGPA() {
    cout << "GPA: ";
    cin >> gpa; //get the GPA
    //ignore new line character so it doesn´t interfere with the getlline() function
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
  }

  //function to increase the stage of the student
  void increaseStage(){
    stage++;
  }
  //function to change gpa
  void changeGPA(){
    cout << "What's the new GPA?" << endl;
    cin >> gpa;
  }

  //list of functions to get the different data members
  string getStudentName() {
    return name;
  }
  string getStudentAddress() {
    return studentAddress;
  }
  string getStudentPhone() {
    return studentPhone;
  }
  string getStudyField() {
    return studyField;
  }
  int getStage() {
    return stage;
  }
  float getGPA() {
    return gpa;
  }
};

//main function
int main()
{
  Student student1 , student2; //initiate 2 student objects
  cout << "\nWelcome to a program to demonstrate the operation of the Student Class" << '\n';

  //read in the data for the first student
  cout << "Please enter data for the first student:" << '\n';
  student1.setStudentName();//set the student name
  student1.setStudentAddress();//set the student address
  student1.setStudentPhone();//set the student phone
  student1.setStudyField();//set the student field of study
  student1.setStage();//set the student stage
  student1.setGPA();//set the student GPA

  //read in the data for the second student
  cout << "Please enter data for the second student:" << endl;
  student2.setStudentName();//set the student name
  student2.setStudentAddress();//set the student address
  student2.setStudentPhone();//set the student phone
  student2.setStudyField();//set the student field of study
  student2.setStage();//set the student stage
  student2.setGPA();//set the student GPA

  //display data entered in tabular format
  cout << std::left << setw(15) << "NAME" << setw(28) << "EMAIL"
  << setw(20) << "PHONE NUMBER" << setw(22) << "FIELD OF STUDY"
  << setw(10) << "STAGE" << "GPA" << endl;
  //first studeNT
  cout << std::left << setw(15) << student1.getStudentName() << setw(28) << student1.getStudentAddress()
  << setw(20) << student1.getStudentPhone() << setw(22) << student1.getStudyField()
  << setw(10) << student1.getStage() << student1.getGPA() << endl;
  //second student
  cout << std::left << setw(15) << student2.getStudentName() << setw(28) << student2.getStudentAddress()
  << setw(20) << student2.getStudentPhone() << setw(22) << student2.getStudyField()
  << setw(10) << student2.getStage() << student2.getGPA() << endl;

  //prompt warning message if any student has GPA below 2.0
  if (student1.getGPA() < 2) {
    cout << "WARNING! " << student1.getStudentName() << "'s grades below 2.0" << endl;
  }
  if (student2.getGPA() < 2) {
    cout << "WARNING! " << student2.getStudentName() << "'s grades below 2.0" << endl;
  }

  int choice;
  //ask user if he/she wants to change the gpa or stage of any student
  cout << "Do you want to change anything?" << endl << "1. Increase Stage of a student.\n"
  << "2. Change GPA.\n" << "3. Exit program.\n";
  cin >> choice;
  //make sure only valid inputs
  while (choice > 3 || choice < 1) {
    cout << "Enter Valid Input: "; cin >> choice;
  }
  while (choice != 3) //while user doesn't exit
  {
    cout << "Who do you want to make the change to?\n" << "1. " << student1.getStudentName()
    << "\n2. " << student2.getStudentName() << endl;
    int student;
    cin >> student;
    //make sure only valid inputs
    while (student != 1 && student != 2) {
      cout << "Enter Valid Input: "; cin >> student;
    }
    //depending on the choices made call different functions
    if (choice == 1)
    {
      if (student == 1) {
        student1.increaseStage();
      }
      else {
        student2.increaseStage();
      }
    }
    else if (choice == 2)
    {
      if (student == 1) {
        student1.changeGPA();
      }
      else {
        student2.changeGPA();
      }
    }
    //display data entered in tabular format
    cout << std::left << setw(15) << "NAME" << setw(28) << "EMAIL"
    << setw(20) << "PHONE NUMBER" << setw(22) << "FIELD OF STUDY"
    << setw(10) << "STAGE" << "GPA" << endl;
    //first student
    cout << std::left << setw(15) << student1.getStudentName() << setw(28) << student1.getStudentAddress()
    << setw(20) << student1.getStudentPhone() << setw(22) << student1.getStudyField()
    << setw(10) << student1.getStage() << student1.getGPA() << endl;
    //second student
    cout << std::left << setw(15) << student2.getStudentName() << setw(28) << student2.getStudentAddress()
    << setw(20) << student2.getStudentPhone() << setw(22) << student2.getStudyField()
    << setw(10) << student2.getStage() << student2.getGPA() << endl;

    //prompt warning message if any student has GPA below 2.0
    if (student1.getGPA() < 2) {
      cout << "\nWARNING! " << student1.getStudentName() << "'s grades below 2.0" << endl;
    }
    else if (student2.getGPA() < 2) {
      cout << "\nWARNING! " << student2.getStudentName() << "'s grades below 2.0" << endl;
    }
    //ask user if he/she wants to do anything else
    cout << "Do you want to change anything else?" << endl << "1. Increase Stage of a student.\n"
    << "2. Change GPA.\n" << "3. Exit program.\n";
    cin >> choice;
  }
}
