// Activity - Use recursion to compute the sum of digits.

/* Please write a C-program that uses a recursive function called "sumOfDigits()" to compute the sum of the digits of a number. To do so, your main function should first read an integer number as input and then call sumOfDigits(), which should in turn call itself until there are no digits left to sum, at which point the final sum should display to the user.

Here is the main idea of how the recursion in sumOfDigits() should work:

sumOfDigits(6452) = 2 + sumOfDigits(645)

sumOfDigits(645) = 5 + sumOfDigits(64)

...

sumOfDigits(6) = 6 */

#include <stdio.h>

int sumofDigits(int number);

int main(){
    
    int value;
    
    scanf("%d", &value);
    
    printf("%d", sumofDigits(value));
    
    return 0; 
}

int sumofDigits(int number){
    int result = 0;
    int digit;
    
    if(number > 10000){
        digit = number/10000;
        result = digit + sumofDigits(number%10000);
    }
    else if(number > 1000 && number < 10000){
        digit = number/1000;
        result = digit + sumofDigits(number%1000);
    }
    else if(number > 100 && number < 1000){
        digit = number/100;
        result = digit + sumofDigits(number%100);
    }
    else if(number > 10 && number < 100){
        digit = number/10;
        result = digit + sumofDigits(number%10);
    }
    else if(number < 10){
        digit = number;
        result = digit;
    }
    
    return result;
}
