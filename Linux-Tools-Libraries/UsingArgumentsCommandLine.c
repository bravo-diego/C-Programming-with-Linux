// Activity - Pass numbers to a program from the command line.

// You are selling plants and are working on creating invoices for customer orders. You are testing a program that should receive, as arguments passed in from the command line, a number of plants to be purchased (an integer) and the price per plant (a decimal number). Your job is to create an invoice for the customer (see examples) that prints out the total price of the order (which can be found by multiplying the price per plant by the number of plants purchased). 

// If your program is called with an incorrect number of arguments the user should receive the message "Invalid input" (see Example 3).

// Be sure to print prices with two decimal places, and to print the invoice exactly as presented in the examples below.


# include<stdio.h>
# include<stdlib.h>

int main(int argc, char **argv){ // argc is the number of arguments from the command line (including the ./program); argv is an array containing pointers to an array of characters
    int plants;
    double price;
    double total;
    
    if(argc != 3){
        printf("Invalid input");
    }
    else{
        plants = atoi(argv[1]); // ASCII to integer
        price = atof(argv[2]); // ASCII to float
        total = plants*price;
        
        printf("%d plants for %.2lf dollars each cost %.2lf dollars.", plants, price, total);
    }

    return 0;
}