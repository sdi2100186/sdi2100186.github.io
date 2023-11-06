#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000
#define MIN -100000000


int collatz(long int num) {
    int length = 1; //initialize length
    if (num<0){ //if num is negative number end the program
       printf("0\n");
       exit(-1);
       
    }
    while (num != 1) {  //once we reach 1, the loop stops
        if (num % 2 == 0) { //if num is even
            num /= 2;   //re-assign loop with a new value
        } else { //(num is odd)
            num = 3 * num + 1; //re-assign loop with a new value
        }
        length++;
    }
    return length;
}



int main(int argc, char *argv[]) {
    if (argc != 3) { ///check the correct number of arguments has been entered
        printf("Error: Incorrect number of arguments!\n");
        return 1;
    } else {
        int num1 = atoi(argv[1]); //convert from char to int
        int num2 = atoi(argv[2]);
        if (MAX < num1 < MIN || MAX < num2 < MIN) { //validate that input values are between MIN and MAX
            printf("0\n");
            return 1;
        } else {
            int max_length = 0; //initialize max_length
            for (int i = num1; i <= num2; i++) { //loop from num1 to num2
                int length = collatz(i);
                if (length > max_length) { //get the max length
                    max_length = length;
                }
            }
            printf("Maximum length of the Collatz Conjecture between %d and %d is: %d \n", num1, num2, max_length);
        }
    }
    return 0; //Return 0 once program completes
}
