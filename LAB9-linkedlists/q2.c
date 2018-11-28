/*LAB 9 QUESTION 2    Written by Er Lin using code provided on Moodle
Program that implements a stack using linked list.*/
#include <stdio.h>
#include <stdlib.h>

//self referential structure
struct stackNode {
  char data; //each node contains a character
  struct stackNode *next; //pointer to next node
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

//function prototypes
void insert(StackNodePtr *sPtr, char value);
void delete(StackNodePtr *sPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void)//main function
{
  StackNodePtr startPtr = NULL; //no nodes at start
  int choice; //user' choice of action
  char letter; //char entered by user

  //prompt message introducing program
  printf("\nWelcome to a program that shows Stack implementation.\n");

  instructions();//display the menu
  printf("? ");
  scanf("%d", &choice);

  //loop while user doesn't exit
  while (choice != 3)
  {
    //depending on user's choice
    switch (choice)
    {
      //push element
      case 1:
        printf("\nEnter a character: ");
        scanf("\n%c", &letter);
        printf("\n");

        insert(&startPtr, letter);//push element to stack
        printStack(startPtr);
        break;

      //pop element
      case 2:
        if (startPtr == NULL)//if stack is empty
        {
          printf("\nStack is empty.\n");
        }
        else
        {
          delete(&startPtr); //pop element from stack
          printStack(startPtr);
        }
        break;

      default:
        printf("\nINVALID CHOICE!\n");
        break;
    }

    printf("\n? ");
    scanf("%d", &choice);
  }

  printf("\nEnd of Run.\n");
  return 0; //indicates succesful termination
}

//display program instructions to the user
void instructions(void)
{
  printf("\n************ MENU ************\n"
  "1. PUSH element into the stack.\n"
  "2. POP element from the stack.\n"
  "3. EXIT.\n"
  "Enter your choice ");
}

//push a new value into the stack
void insert(StackNodePtr *sPtr, char value)
{
  StackNodePtr newPtr = malloc(sizeof(StackNode));//create node

  if (newPtr != NULL)//if space is available
  {
    newPtr->data = value;//place value in node

    if (*sPtr == NULL) //if first element
    {
      newPtr->next = NULL;//node doesn't link to anything
    }
    else
    {
      newPtr->next = *sPtr;
    }
    *sPtr = newPtr; //point startPtr to last element entered
  }
  else {
    printf("\nPush Failed! Memory not available!\n");
  }
}

//Print stack
void printStack(StackNodePtr currentPtr)
{
  //if stack is empty
  if (currentPtr == NULL)
  {
    printf("\nStack is empty.\n");
  }
  else
  {
    printf("The stack is:\n");

    //while not the end of the stack
    while (currentPtr != NULL)
    {
      printf("%c --> ", currentPtr->data);
      currentPtr = currentPtr->next;
    }
    printf("NULL\n");
  }
}

//pop element from the stack
void delete(StackNodePtr *sPtr)
{
  StackNodePtr temp = *sPtr;

  //inform of deleted element
  printf("\n%c popped from the stack.\n", temp->data);

  *sPtr = temp->next;//de-threaded node
  free(temp);//free de-threaded node
}
