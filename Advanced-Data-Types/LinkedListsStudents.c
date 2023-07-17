// Activity - Using linked lists to store studend data.

/* You would like to store student data (for each student, their name and age) in a linked list of students. You are given the following structure to store each student's information. Please do not modify this structure:

struct student {
      char name[50];
      int age;
      struct student *next;
}; */

/* The first task is to write a function createStudent() that takes as inputs a string (namely a student's name) and an integer (their age) and that returns a pointer to a struct student which stores this information. Your function should dynamically allocate the memory required for this struct student and then write the student's name and age into this newly allocated memory. */

/* The second task is to write a function append() which takes as input two pointers: the first pointer holds the address of the current end of the linked list of students, the second pointer points to a newly created student. Your function should append this new student to the linked list and return the address (a struct student *) of the new end of the list. */

/* The third task is to write a function printStudents() which takes as input a pointer that holds the address of the start of a linked list of students. Your function should then print this list of students to the screen as specified in the example below. Your function should not return anything. */

/* Finally you need to write a function freeStudents() which takes as input a pointer that holds the address of the start of a linked list of students. Your function should then free the space allocated for each student in this list of students. Your function should not return anything. */

#include <stdio.h>
#include <stdlib.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[50], int studentAge);
struct student * append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void freeStudents(struct student *start);

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;

    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);

    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    
    freeStudents(start);

    return 0;
}

struct student *createStudent(char studentName[], int studentAge){
    int i = 0;
    struct student *add;
    add = (struct student *) malloc(sizeof(struct student));
    while(studentName[i] != '\0'){
        (*add).name[i] = studentName[i];
        i += 1;
    }
    (*add).age = studentAge; 
    (*add).next = NULL;
    return add;
}

struct student *append(struct student * end, struct student * newStudptr){
    struct student *add;
    (*end).next = newStudptr;
    end = newStudptr;
    add = end;
    return add;
}

void printStudents(struct student *start){
    struct student *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("%s is %d years old.\n", (*ptr).name, (*ptr).age);
        ptr = (*ptr).next;
    }
}

void freeStudents(struct student *start){
    struct student *ptr;
    struct student *temp;
    
    ptr = start;
    
    while(ptr != NULL){
        temp = (*ptr).next;
        free(ptr);
        ptr = temp;
    }
}