/**
 * COMP2160
 *
 * COMP 2160 SECTION A02
 * INSTRUCTOR    Mehdi Niknam
 * ASSIGNMENT    Assignment 3, question 1
 * AUTHOR        Nguyen Tien Thuan, 7900457
 * DATE          6/11/2021
 *
 * PURPOSE: Testing ordered_list.c
 */
//gcc main.c ordered_list.c -o main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ordered_list.h"
#define MAX_INPUT
static int testFailed = 0; 
static int totalTest = 0; 
//check the number of number of traversals is as expected
int testNodeAt(List * list, int index, char * expected){
    totalTest++;
    char * content;
    contentAt(list,index,content);
    if(strcmp(content,expected) != 0){
        printf("test number #%d has failed\n", totalTest);
        testFailed++;
        return 0;
    }
    return 1;
}
int testSize(List * list , int expected){
    totalTest++;
    int numNode = size(list);
    if(numNode != expected){
        printf("nsize of list expected for test #%d is: %d", totalTest,expected);
        printf("size of list is: %d", numNode);
        testFailed++;
        return 0;
    }
    return 1;

}
int testTraversals(List * list, int expected, char * array[], int arraySize){
    totalTest++;
    int beforeTraverse = traversals();
    for(int i = 0; i< arraySize; i++){
        insert(list,array[i]);
    }
    int afterTraverse = traversals();
    if(afterTraverse - beforeTraverse != expected){
        printf("test number #%d has failed\n", totalTest); 
        printf("traversals is for #%d is :%d\n",totalTest,afterTraverse - beforeTraverse);
        testFailed++;
        return 0;
    }
    return 1;
}
//Give a list of strings, insert each one into the list and check for its existence in the list
//also test the size
int testInsertion(List * list ,int inputLength, char * input[MAX_INPUT]){
    totalTest++;
    int i = 0;
    for(i = 0; i < inputLength; i ++){
        insert(list, input[i]);
    }
    for(i = 0 ; i < inputLength; i++){
        if(find(list,input[i]) == 0 ){
            printf("test number #%d has failed\n", totalTest);
            printf("failed to find %s\n", input[i]);
            return 0;
        }
    }
    testSize(list,inputLength);
    return 1;
}

int main()
{
  //test insertions and size (2 test in 1);    
  List * test1 = construct();
  List * test2 = construct();
  List * test3 = construct();
  List * test4 = construct();
  int initialTraversal1 = 0, initialTraversal2 = 0,initialTraversal3 = 0,initialTraversal4 = 0;
  char * arr1[MAX_INPUT] = {"apple", "belmont", "zorryun"};
  char * arr2[MAX_INPUT] = {"zorryun", "belmont", "apple"};
  char * arr3[MAX_INPUT] = {" ", "", " "};
  char * arr4[MAX_INPUT] = {",",".","/","`","~","-","_","+","*","{","}","[","]"};
  testInsertion(test1,3,arr1);
  testInsertion(test2,3,arr2);
  testInsertion(test3,3,arr3);
  testInsertion(test4,13,arr4);
  //test traversals
  List * test9 = construct();
  char * arr5[MAX_INPUT] = {"apple", "ace", "axe", "bearro"};
  testTraversals(test9,5,arr5,4);
  //inserting at the top takes no traversals so apple and ace takes 0
  //axe have to move through 2 elem so 2 traversals and since bearro is the first elem of new index(that is not top insertion) we start from the top 
  //so in total 5 traversals

  List * test10 = construct();
  char * arr6[MAX_INPUT] = {"E","D","C","B","A"};
  testTraversals(test10,0,arr6,5);
  //inserting at top takes 0 elem;

  List * test11 = construct();
  char * arr7[MAX_INPUT] = {"X","X","X","X","X"};
  testTraversals(test11,0,arr7,5);
  //same thing;
  
  List * test12 = construct();
  char* arr8[MAX_INPUT] = {"I", "am", "watching", "you", "sleep"};
  testTraversals(test12,8,arr8,5);
  //I = 0; am = 1; watching = 2; you = 3; sleep = 2;


  printf("total tests are:%d ; test failed is:%d\n", totalTest, testFailed);
  if(0 == testFailed){
      printf("yay the test that you designed and tested yourself didn't fail \n");
  }
  destroy(test1);
  destroy(test2);
  destroy(test3);
  destroy(test4);
  destroy(test9);
  destroy(test10);
  destroy(test11);
  destroy(test12);
}
