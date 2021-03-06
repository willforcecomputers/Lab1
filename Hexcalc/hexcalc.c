/*
 * hexcalc.c
 *
 * CSCI 247, Fall 2016, Lab Exercise 1
 *
 * William Metzger
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void outahere();

// function numval() returns the integer number represented by the parameter word
// returns -1 if the string word cannot be converted into an integer number
int numval(char *word){
	int i = strlen(word);
	int q;
	int numerical = 0;
	int value = 0;

    for(q = 0; q < i; q++){ //For loop for iterating through *word char
      value = word[q];

      numerical = numerical * 16;
      if(value <= 57 && value >= 48) { //if given char is 0-9, subtract 48 to get value

    	  numerical = numerical + (value - 48);
      }
      else if(value <= 70 && value >= 65) { //if else given char is capital A-F, subtract 65 to get hex value

          	  numerical = numerical + (value - 55);
            }

      else if(value <= 102 && value >= 97) { //if else given char is lower case A-F, subtract 87 to get hex value

          	  numerical = numerical + (value - 87);
            }

      else {

    	  numerical = -1; //if not 0-9, A-F or a-f, set returned variable to -1 to prompt outahere
      }
    }

    return numerical;
}
// function docalc() returns the result of applying the operator to two numbers
// operator may be +, -, * or /
// abort the program with the usage message for invalid operator
int docalc(int first, int second, char operator) {
	int i;

	if(operator == 43) { //if operator is "+" add numbers

		i = first + second;
	}

	if(operator == 45) { //if operator is "-" subtract numbers

		i = first - second;
	}

	if(operator == 42) { //if operator is "*" multiply numbers, * must be escaped to process correctly

		i = first * second;
	}

	if(operator == 47) { //if operator is "/" divide numbers

		i = first / second;
	}

	return i; //return result of operation.
}

void outahere() {
    puts("Usage: ./hexcalc number op number, where op is +, -, * or /\n");
    exit(0);
}

int main(int argcount, char *arg[]) {

    if (argcount < 4) outahere();

    // get the first number
    int num1 = numval(arg[1]);
    if (num1 < 0) outahere();

    // get the second number
    int num2 = numval(arg[3]);
    if (num2 < 0) outahere();

    // apply the operator
    int result = docalc(num1, num2, arg[2][0]);

    // display the result
    printf("%s %s %s = %X\n", arg[1], arg[2], arg[3], result);

    return 1;

}
