// Activity - Read numbers from a file

// You are teaching a class on C-programming! You would like to find out whether your teaching has been effective, and so you need to compute the average grade your students have received on the most recent assignment. These grades (integers) are stored in the file studentGrades.txt.

// Your job is to calculate and print out the average of the grades stored in the file. Please print the average grade with two decimal places.

# include <stdio.h>

int main(){
    int total_grades;
    int individual_grade;
    
    double avg;
    double sum = 0;
    
    // Steps for open and reading a file
    
    FILE *ptrfile; // FILE data type; ifile is a pointer to keep track of our file 
    ptrfile = fopen("studentGrades.txt", "r"); // Open file; r stands for reading (1)
    
    fscanf(ptrfile, "%d", &total_grades); // just like scanf(), the only differences is the file pointer that is passed in as well (2)

    for(int i = 0; i < total_grades; i++){
        fscanf(ptrfile, "%d", &individual_grade);
        sum += individual_grade;
    }
    
    avg = sum/total_grades;
    printf("%.2lf", avg);

    fclose(ptrfile); // close file (3)
    
    return 0;
}