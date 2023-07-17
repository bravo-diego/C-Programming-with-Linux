// Activity - Find the longest word in a text.

/* Your job is to find the length of the longest word in a text with no punctuation or special characters of any kind - only contains words. To do so, please write a C-program that takes as a input first the number of words in a text, followed by all of the words in the text. The output of your program should be the length of the longest word in the text.

To simplify your program, you can assume that the longest word will not exceed 100 characters. */

#include<stdio.h>

int main(){
    
    int nwords;
    int fc; // first counter
    char words[101];
    int p = 0; // word position
    int sc = 0; // second counter
    int lenght = 0;
    
    scanf("%d", &nwords);
    
    for(fc = 0; fc < nwords; fc++){
        scanf("%s", words);
        while(words[p] != '\0'){
            sc++;
            p++;
        }
        if(sc > lenght){
            lenght = sc;
        }
        p = 0;
        sc = 0;
    }
    
    printf("%d", lenght);
    
    return 0;
}