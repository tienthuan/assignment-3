#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ordered_list.h"
#define MAX_INPUT 80
int main(){
  char str[MAX_INPUT];
  List * list = construct();
  const char delim[4] = " .,!?";
  printf("enter your inputs\n");
  while(NULL != fgets(str,MAX_INPUT,stdin)){
    char * token;
    token = strtok(str,delim);
    while(token != NULL){
        if(0 == find(list,token))
        insert(list,token);
        
        token = strtok(str,delim);
    }
  }

  print(list);
  size(list);
  traversals(list);
  destroy(list);
}