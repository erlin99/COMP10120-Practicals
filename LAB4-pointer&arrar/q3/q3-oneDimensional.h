#define SIZE 2
//one dimensional array elements address definition
void oneDimensional(int *a, float *b, double *c, char *d)
{
  //display adresses of elements from integer array using for loop
  printf("Integer Array:\n");
  int j = 1;
  for (int i = 0; i < SIZE; i++)
  {
    printf("Element %d address is: %p\n", j, a+i);
    j++;
  }
  //display adresses of elements from float type array using for loop
  printf("Float Type Array:\n");
  j = 1;
  for (int i = 0; i < SIZE; i++)
  {
    printf("Element %d address is: %p\n", j, b+i);
    j++;
  }
  //display adresses of elements from double type array using for loop
  printf("Double Type Array:\n");
  j = 1;
  for (int i = 0; i < SIZE; i++)
  {
    printf("Element %d address is: %p\n", j, c+i);
    j++;
  }
  //display adresses of elements from char type array using for loop
  printf("Char Type Array:\n");
  j = 1;
  for (int i = 0; i < SIZE; i++)
  {
    printf("Element %d address is: %p\n", j, d+i);
    j++;
  }
}
