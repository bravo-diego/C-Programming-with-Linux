// Activity - Print a square of stars using nested loops.

/* Create a program that displays on the screen a square of n x n stars, with the integer n given as an input. */

#include<stdio.h>

int main(){
    
    int number;

    scanf("%d", &number);
    
    int row;
    int column;
    
    for(row = 0; row < number; row++){
        for(column = 0; column < number; column++){
            printf("*");
        }
        printf("\n");
    }
        
    return 0;
}