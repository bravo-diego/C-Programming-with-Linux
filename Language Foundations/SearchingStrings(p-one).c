// Activity - Is there a 't' in this word?

/* You are conducting a linguistic study and are interested in finding words that contain the letter 't' or 'T' in the first half of the word (including the middle letter if there is one). Specifically, if the first half of the word does contain a 't' or a 'T', your program should output a 1. If the first half does not contain the letter 't' or 'T', but the second half does, then your program should output a 2. Otherwise, if there is no 't' or 'T' in the word at all, your program's output should be -1. You may assume that the word entered does not have more than 50 letters. */

#include<stdio.h>

int main(){
    
    char word[51];
    int i = 0;
    int j = 0;
    int lenght = 0;
    int value = 0;
    int check = 0;
    //int nvalue = -1;
    
    scanf("%s", word);

    while(word[i] != '\0'){
        i++;
    }
    
    lenght = i;
    
    while(j < lenght && !check){
        if(word[j] == 't' || word[j] == 'T'){
            if(j <= (lenght/2)){
                value = value + 1;
                check = check + 1;
            }
            else{
                value = value + 2;
                check = check + 1;
            }
        }
        else{
            j++;
        }
    }
    
    if(value != 0){
        printf("%d", value);
    }
    else{
        value = value - 1;
        printf("%d", value);
    }
    
    return 0;
}