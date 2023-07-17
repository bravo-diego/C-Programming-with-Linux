// Activity - Find repeat letters in a word.

/* You are still conducting linguistic research! This time, you'd like to write a program to find out how many letters occur multiple times in a given word. Your program should read a word from the input and then sort the letters of the word alphabetically (by their ASCII codes). Next, your program should iterate through the letters of the word and compare each letter with the one following it. If these equal each other, you increase a counter by 1, making sure to then skip ahead far enough so that letters that occur more than twice are not counted again. You may assume that the word you read from the input has no more than 50 letters, and that the word is all lowercase. */

#include<stdio.h>

int main(){
    
    char word[51];
    int lenght = 0;
    int i, j;
    char letter;
    int value = 0;
    
    scanf("%s", word);
    
    while(word[lenght] != '\0'){
        lenght = lenght + 1;
    }
    
    for(j = 0; j < lenght; j++){
        for(i = 0; i < lenght; i++){
            if(word[i] > word[i + 1]){
                letter = word[i];
                word[i] = word[i + 1];
                word[i + 1] = letter;
            }
        }
    }
    
    for(i = 0; i < lenght; i++){
        if(word[i] == word[i + 1]){
            value = value + 1;
            if(word[i + 1] == word[i + 2]){
                i = i + 1;
                if(word[i + 1] == word[i + 2]){
                    i = i + 1;    
                }
            }
        }
    }
    
    printf("%d", value);
    
    return 0;
}