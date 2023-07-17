// Activity - Arrays and functions.

/* Within this program, we will pass an array with 6 integers to a function, have the function swap the first and last integer, the second and the second to last integer, the third and the third to last integer.

The function is called reverseArray and doesn't return anything (void). It should take one parameter, representing the array of integers. 

The main function first reads 6 integers from the input, and assigns them to the array. The main function then calls reverseArray, passing the array as an argument.

The main function then prints the reversed array. */

#include <stdio.h>

void reverseArray(int []);

int main(){
    
    int array[7];
    int i;
    int value;
    
    for(i = 0; i < 6; i++){
        scanf("%d", &value);
        array[i] = value;
    }
    
    reverseArray(array);
    
    for(i = 0; i < 6; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}

void reverseArray(int array[]){
    int j;
    int l = 5;
    
    int temp;
    
    for(j = 0; j < 3; j++){
        temp = array[j];
        array[j] = array[l];
        array[l] = temp;
        l = l - 1;
    }
}


