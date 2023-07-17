// Activity - Programming a toaster (memory usage nicely displayed).

/* You are programming a toaster! The toaster does not have a lot of memory, so you need to be careful about the data types you use (remember that different data types use different amounts of memory). To make this easier, you'd like an easy way to track how much memory your variables are going to use.

Your job is to write a program that shows, in human-readable form (see below for specifics), how much memory a set of variables of a certain type will use. Your program should read a character that identifies the data type ('i' for int, 's' for short, 'c' for char, 'd' for double). Next it should read an integer that indicates how many variables of the given type you wish to store.

Your program should then calculate the amount of memory required to store the given variables. Your program needs to be written in such a way that it would also perform correctly on other computers. In other words, rather than hard-coding specific sizes for the different variable types, your program needs to use the "sizeof()" function to determine how much memory an individual variable of a given type needs.

Finally, you need to output the amount of space required by your variables to the screen. You need to make sure you provide this output in a form that is easy to read for humans. */

#include<stdio.h>

int main(){
    
    char type;
    int variables;
    
    int result = 0;
    int mbytes = 0;
    int kbytes = 0;
    int bytes = 0;
    
    int vari;
    short vars;
    char varc;
    double vard;
    
    scanf("%c %d", &type, &variables);
    
    switch(type){
        case 'i':
            result = sizeof(vari)*variables;
            break;
        case 's':
            result = sizeof(vars)*variables;
            break;
        case 'c':
            result = sizeof(varc)*variables;
            break;
        case 'd':
            result = sizeof(vard)*variables;
            break;
    }
    
    if(result > 1000000){
        mbytes = result / 1000000;
        kbytes = ((result % 1000000)/1000); 
        bytes = ((result % 1000000)%1000);
        printf("%d MB and %d KB and %d B", mbytes, kbytes, bytes);
    }
    else if(result > 100000 && result < 1000000){
        kbytes = result / 1000;
        bytes = result % 1000;    
        printf("%d KB and %d B", kbytes, bytes);
    }
    else if(result < 1000){
        bytes = result;  
        printf("%d B", bytes);
    }
    
    return 0;
}