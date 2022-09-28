#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");

  list_t* myList = list_alloc();

  list_print(myList);
  list_add_to_front(myList, 10);
  list_print(myList);
  list_add_to_front(myList, 200);
  list_add_to_front(myList, 13);
  list_add_to_front(myList, 20);
  list_add_to_front(myList, 11);
  list_add_to_front(myList, 15);
  list_print(myList);
  list_add_at_index(myList, 3,2);
  list_print(myList);
  list_remove_from_back(myList);
  list_print(myList);
  list_add_to_back(myList, 300);
  list_print(myList);
}
