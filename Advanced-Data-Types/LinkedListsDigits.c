// Activity - Using linked lists to store digits.

/* In this task you will work with the linked list of digits we have created in the lessons up to this point. As before you are provided with some code that you should not modify:

A structure definition for the storage of each digit's information.
A main() function to test your code. 
The functions createDigit(), append(), printNumber(), freeNumber() and readNumber() which we have written in the lectures. */

/* Your new task is to write a new function divisibleByThree() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should then check whether the number stored in this linked list of digits is divisible by three. The function should return the value 1 if indeed the number is divisible by three and it should return the value 0 otherwise. */

/* Then you need to write a function changeThrees() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should change all of those digits in this linked list that equal 3 to the digit 9, and count how many replacements were made. The function should return this number of replacements. */

/* Finally you need to write a function countRedun() which takes as input a pointer that holds the address of the start of a linked list of digits. Your function should count how many redundancies can be observed in the number stored in this list and return this count of redundancies. A redundancy is a digit which has previously already occurred in the number. For example, in the number 39534, the second '3' is a redundancy. */

#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);

int countRedun(struct digit * start); 


int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}

int countRedun(struct digit * start){
    struct digit * ptr;
    struct digit * nptr;
    
    int c = 0;
    
    ptr = start;
    nptr = (*ptr).next;
    
    while(nptr != NULL){
        if((*ptr).num != (*nptr).num){
            nptr = (*nptr).next;
        }
        else{
            c = c + 1;
            ptr = nptr;
            nptr = (*nptr).next;
        }
    }
    
    return c;
}