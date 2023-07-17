// Activity - Branch inside a loop, how many big cities?

/* You want to determine the number of cities in a given region that have a population strictly greater than 10,000. To do this, you write a program that first reads the number of cities in a region as an integer, and then the populations for each city one by one (also integers). */

#include<stdio.h>

int main(){
    
    int cities;
    int pop;
    int total = 0;
    
    scanf("%d", &cities);
    
    for(int i = 0; i < cities; i++){
        scanf("%d", &pop);
        if(pop > 10000){
            total = total + 1;
        }
    }
    
    printf("%d", total);
    
    return 0;
}