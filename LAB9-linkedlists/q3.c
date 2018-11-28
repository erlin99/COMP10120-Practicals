/*LAB 9 QUESTION 3    Written by Er Lin using code provided on Moodle
Program that implements queue using linked list.*/
#include <stdio.h>
#include <stdlib.h>

//self referential structure
struct queueNode {
  char data;
  struct queueNode *next;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

//function prototypes
void insert(QueueNodePtr *headPtr, QueueNodePtr *endPtr, char value);
void delete(QueueNodePtr *sPtr);
void printQueue(QueueNodePtr currentPtr);
void instructions(void);

int main(void)
{
  QueueNodePtr head = NULL;
  QueueNodePtr end = NULL;

  int choice;//user's choice of action
  char letter;//char entered by user

  printf("\nWelcome to a program that shows Queue implementation\n");

  instructions();//display the menu
  printf("? ");
  scanf("%d", &choice);

  //loop while user doesn't exit
  while (choice != 3)
  {
    //depending on user's choice:
    switch (choice)
    {
      case 1: //insert element
        printf("\nEnter a character: ");
        scanf("\n%c", &letter);
        printf("\n");

        insert(&head, &end, letter);
        printQueue(head);
        break;

      case 2: //delete element(first element in)
        if (head == NULL)//if stack is empty
        {
          printf("\nQueue is empty.\n");
        }
        else
        {
          delete(&head);
          printQueue(head);
        }
        break;

      default:
        printf("\nINVALID CHOICE!\n");
        break;
    }

    printf("\n? ");
    scanf("%d", &choice);
  }

  printf("\nEnd of run.\n");
  return 0; //indicates succesful termination
}

//display program instructions to the user
void instructions(void)
{
  printf("\n************ MENU ************\n"
  "1. INSERT element into queue.\n"
  "2. DELETE element from queue.\n"
  "3. EXIT.\n"
  "Enter your choice ");
}

//insert new value into queue
void insert(QueueNodePtr *headPtr, QueueNodePtr *endPtr, char value)
{
  QueueNodePtr newPtr = malloc(sizeof(QueueNode)); //create node

  if (newPtr != NULL)//if space is availabel
  {
    newPtr->data = value;
    newPtr->next = NULL;

    if (*headPtr == NULL) //if first element
    {
      *headPtr = *endPtr = newPtr;
    }
    else
    {
      (*endPtr)->next = newPtr;
      *endPtr = newPtr;
    }

  }
  else { //if memory is not created
    printf("\nInsertion Failed! Memory not available!\n");
  }
}

//print queue
void printQueue(QueueNodePtr currentPtr)
{
  if (currentPtr == NULL) //if queue is empty
  {
    printf("\nQueue is empty.\n");
  }
  else
  {
    printf("The queue is:\n");

    //while not end of queue
    while (currentPtr != NULL)
    {
      printf("%c --> ", currentPtr->data);
      currentPtr = currentPtr->next;
    }
    printf("NULL\n");
  }
}

//delete first in the queue
void delete(QueueNodePtr *sPtr)
{
  QueueNodePtr temp = *sPtr;

  //inform of deleted element
  printf("%c deleted from queue.\n", temp->data);

  *sPtr = temp->next;//de-threaded node
  free(temp); //free de-threaded node
}
