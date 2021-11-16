#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ordered_list.h"
#define MAX_INPUT 80
int main(){
  char str[MAX_INPUT];
  char * ptr;
  char * token;
  List * list = construct();
  const char delim[] = " \n.,!?";
  printf("enter your inputs\n");
  while(fgets(str,MAX_INPUT,stdin) != NULL){
    ptr = str;
    while((token = strtok(ptr,delim)) != NULL){
      if(0 == find(list,token)){
        insert(list,token);
      }
      ptr = NULL;
    }
  } 

  print(list);
  printf("%d\n",size(list));
  printf("%d\n",traversals(list));
  destroy(list);
}