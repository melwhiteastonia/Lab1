
#include <stdio.h>
#include <stdlib.h>
#include "list.h"



// list/list.c
//
// Implementation for linked list.
//
// Melanie White 

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */



list_t *list_alloc() {
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}


void list_print(list_t* l){

  node_t* curr = l ->head;
  if (curr == NULL){

  printf("The list is empty.\n");
  }
  else {
    printf("Here's the list:");
    while (curr!= NULL){
      printf("%d ", curr->value);
      curr = curr -> next;
    }
    printf("\n");
  }
}
//collaboration with Mary Nwosu 
node_t *node_alloc(elem val) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->next = NULL;
  node->value = val; 
  return node;
}

void list_add_to_front(list_t *l, elem value){

  node_t* newNode = node_alloc(value);
  newNode->next = l->head; 
  l->head = newNode;


}

elem list_remove_from_back(list_t *l){

  node_t* curr = l->head;
  if (curr == NULL){
    return -1;
  }
  while (curr -> next->next != NULL) { curr = curr->next;}

  free(curr->next);
  curr->next = NULL;

  return 0; 
}






void list_add_to_back(list_t *l, elem v){
  node_t* curr = l->head;
  node_t* newNode = (node_t*) malloc(sizeof(node_t));
  node_t* temp = (node_t*) malloc(sizeof(node_t));

  

  if (curr == NULL){
    list_add_to_front(l,v);
  }
  while (curr->next != NULL){
    curr = curr->next;
  }

  curr->next = newNode;
  newNode->next = NULL;
  newNode->value = v; 


}

//geeks for geeks 
void list_add_at_index(list_t *l, elem value, int index){

node_t* curr = l->head;
node_t* newNode = (node_t*)malloc(sizeof(node_t));
node_t* temp = (node_t*) malloc(sizeof(node_t));
int count = 0;

if (curr == NULL) {
  list_add_to_front(l,value);
}

while (count < index-1){
  curr = curr->next;
  count ++;
}


if (count == index-1){
  temp = curr->next;
  curr->next = newNode; 
  newNode->next = temp;
  newNode->value = value;
}
}

void list_add_to_front(list_t *l, elem v) {
  node_t* temp = l->head;
  node_t* newNode = (node_t*) malloc(sizeof(node_t));
  l->head = newNode;
  newNode->next = temp;
  newNode->value = v;
}


bool list_is_in(list_t *l, elem v) {
  int x;
  node_t* curr = l->head;
  int count = list_length(l);

  for(x=0; x < count; x++ ){
    if(curr->value == v) {
      printf("Is %d in the list? Yes it is! :) \n", v);
      return true;
    }
    curr = curr->next;
  }
  printf("Is %d in the list? No, it isn't. :/ \n", v);
  return false;
}


elem list_get_elem_at(list_t *l, int index) {
  int x = 0;
  node_t* curr = l->head;
  int count = index;

  while (x < count){
    curr = curr->next;
    x++;
  }
  printf("The element at index %d is %d.\n", index, curr->value);
  return curr->value;
}


elem list_remove_at_index(list_t *l, int index) {
  node_t* curr = l->head;
  node_t* temp = (node_t*) malloc(sizeof(node_t));
  int count = 0;

  if (curr == NULL) { return 0; }

  while (count < index-1) {
    curr = curr->next;
    count++;
    }

  temp = curr->next;
  curr->next = curr->next->next;
  free(temp);
  return 0;
}

elem list_remove_from_front(list_t *l) {
  node_t* temp = (node_t*) malloc(sizeof(node_t));

  temp = l->head;
  l->head = l->head->next;
  free(temp);
  return 0;
}

int list_length(list_t *l) {
  int count = 0;
  node_t* curr = l->head;
  while (curr != NULL) {
    count++;
    curr = curr->next;
  }
  // printf("The list has %d node(s).\n", count);
  return count; }



