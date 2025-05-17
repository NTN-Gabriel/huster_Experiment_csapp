#include<stdio.h>
void printid();
void(*myprint)(void) = printid;
void printid(){
    printf("U202315653\n");
}