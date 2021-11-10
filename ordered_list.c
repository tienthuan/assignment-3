#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ordered_list.h"

// Linked list node definition
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};

typedef struct LIST List;

struct LIST
{
  Node *top;
  Node *index[256];
  int nodeCount;
};

static int total_num_traversals = 0;

// construct a linked list
List *construct()
{
  List *list;

  list = malloc(sizeof(List));
  list->top = NULL;
  for (int i = 0; i < 256; i++)
  {
    list->index[i] = NULL;
  }
  list->nodeCount = 0;
  return list;
}

// perform an ordered insertion of an item into a list
boolean insert(List *list, char *new_string)
{
  assert(new_string != NULL);
  boolean rc = true;
  Node *newNode = NULL;
  Node *curr;
  Node *prev;
  int asciiOfFirstChar = (int)new_string[0];
  newNode = malloc(sizeof(Node));
  newNode->string = new_string;

  if(NULL == list->index[asciiOfFirstChar]){
  curr = list->top;
  list->index[asciiOfFirstChar] = newNode;
  }
  else if(strcmp(new_string,list->index[asciiOfFirstChar]->string) < 0){
  curr = list->index[asciiOfFirstChar];
  list->index[asciiOfFirstChar] = newNode;
  }
  else
  curr = list->index[asciiOfFirstChar];

  prev = NULL;
  while (NULL != curr && strcmp(curr->string, new_string) < 0)
  {
    prev = curr;
    total_num_traversals++;
    curr = curr->next;  
  }
  if (prev == NULL)
  { // insert at top
    newNode->next = list->top;
    list->top = newNode;
  }
  else
  { //every other pos
    newNode->next = curr;
    prev->next = newNode;
  } //TODO: add condition where we insert at the end, change the endOfIndex pointer to the new insert

  // note that we need to have space for the string as well!

  newNode->string = malloc(strlen(new_string) + 1);
  strcpy(newNode->string, new_string);
  list->nodeCount++;
  return rc;
}

// tells us whether or not the given string is in the list
boolean find(List *list, char *target)
{
  assert(target != NULL);
  boolean found = false;
  int compare;
  int asciiOfFirstChar = (int)target[0];
  Node *curr = list->index[asciiOfFirstChar];
  while (NULL != curr && !found)
  {
    compare = strcmp(target, curr->string);
    if (compare == 0)
    {
      found = true;
    }
    else if (compare < 0)
    {
      // gone too far
      curr = NULL;
    }
    else
    {
      total_num_traversals++;
      curr = curr->next;
    }
  }
  return found;
}

// calculates the number of nodes in a list
int node_count(List *list)
{
  return list->nodeCount;
}

// calculates the size of a list
int size(List *list)
{
  return node_count(list);
}

// print the contents of a list, one item per line
void print(List *list)
{
  Node *ptr = list->top;
  printf("ASCII . CHARACTER . CONTENT\n");
   while(NULL != ptr)
  {
    int index = (int) ptr->string[0];
    char character[2];
    strncpy(character,ptr->string, 1);
    printf("[%d]  |[%s]        |  [%s]\n",index,character,ptr->string);
    ptr = ptr->next;
  }  
}

// returns the total number of items traversed in the list
int traversals()
{
  return total_num_traversals;
}

// destroy the nodes in a list
void destroy(List *list)

{
  Node *curr = list->top;
  Node *next;

  while (NULL != curr)
  {
    next = curr->next;
    free(curr->string);
    free(curr);
    curr = next;
  }
  list->nodeCount = 0;
  total_num_traversals = 0;
  free(list);
}

void contentAt(List * list, int index,char * output){
  Node * curr = list -> top;
  for(int i = 0; i < index; i++){
    if(NULL == curr){
      return;
    }
    curr = curr -> next;
  }
  memcpy(&output,curr->string,strlen(curr->string));
}

char * getStr(Node * node){

  return node->string;
}

Node * getNext(Node * node){

  return node->next;
}

Node * getTop(List * list){
  return list->top;
}

Node * getIndex(List * list, int ind){

  return list->index[ind];
}

/*  int main(){
  List * list = construct();
  insert(list,"");
  //insert(list,"am");
  //insert(list,"watching");
  //insert(list,"you");
  //insert(list,"sleep");
  printf("%d\n", traversals());
  //printf("%s\n",list->index[98]->string);
  print(list);
}*/