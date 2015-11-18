#define _CRT_SECURE_NO_WARNINGS –
#pragma once
#include "pa-1.h"
#include <stdio.h>
// "pa-1.c"
int main()
{
	//Declaring an array
	int list[3];
	//Declaring variables
	int n = 0;
	int x = 0;
	int r = 0;
	int y = 0;
	int z = 0;
	int rotateNum = 0;
	int searchRecur = 0;
	int collatzNum = 0;
	int average = 0;
	bool results;
	char brackets[1000];
	char lookFor[1000];
	char paragraph[1000];
	char fString[1000];
	char sString[1000];
	char *e[1000];
	char *pattern[1000];
	char *text[1000];
	char *s1[1000];
	char *s2[1000];
	char *s3[1000];

	//Function 1
	//Will see if input is an armstrong number
	printf("Enter a number to check if it's an armstrong number: ");
	scanf("%d", &n);


	results = f_armstrong(n);

	if (results == true)
	{
		printf("%d is an armstrong number", n);
	}
	else
	{
		printf("%d is not an armstrong number", n);
	}
	//Function 2
	//Will see if brackets are balanced
	printf("\n\nEnter brackets and the program will check to see if they are in order: ");
	scanf("%s", &brackets);

	results = f_brackets(brackets);

	if (results == true)
	{
	printf("Your brackets are in order");
	}
	else
	{
	printf("Your brackets are not in order");
	}

	//Function 3
	//Will see if input is a perfect number
	printf("\n\nEnter a number and the program will check to see if it's a perfect number: ");
	scanf("%d", &x);

	results = f_perfect(x);

	if (results == true)
	{
	printf("%d is a perfect number", x);
	}
	else
	{
	printf("%d is not a perfect number", x);
	}

	//Function 4
	//Will rotate input by a number that is also given
	printf("\n\nEnter a number that you want to rotate its digits: ");
	scanf("%d", &n);
	printf("Enter a number that you want to rotate by: ");
	scanf("%d", &r);

	rotateNum = f_rotate(n, r);

	printf("\nThe new number is: %d", rotateNum);

	//Funtction 5
	//Will search for a pattern in a text
	printf("\n\nEnter a pattern you want to search for: ");
	scanf("%s", &lookFor);
	printf("Enter a text you want to search through: ");
	scanf("%s", &paragraph);

	searchRecur = f_str_search(lookFor, paragraph);

	printf("%s can be found in your text %d times", lookFor, searchRecur);

	//Funtction 6
	//Will perform the Collatz conjucture on input
	printf("\n\nEnter a number for the program to perform the Collatz conjucture to: ");
	scanf("%d", &n);

	collatzNum = f_collatz_count(n);

	printf("It took %d iterations", collatzNum);

	//Funtction 7
	//This function will take a number and create an array with the amount and perform other operation
	printf("\n\nEnter a number to determine how many random numbers are generated: ");
	scanf("%d", &n);

	average = f_array(n);

	printf("The numbers were randomly generated between 1-99 and multiplied by 2. The following number is the average of the (up to 5) numbers divisible by 3: %d", average);

	//Funtction 8
	//This function will take two strings and put them into one, in shorter/larger/shorter order
	printf("\n\nEnter the first text you want to forge with: ");
	scanf("%s", &fString);
	printf("\nEnter the second text you want to forge with: ");
	scanf("%s", &sString);

	f_strings(fString, sString, s3);

	printf("Your new string is: %s", s3);

	//Function 9
	//This will take three numbers and sort them in order
	printf("\n\nThe program will now take three numbers and sort them in assending order. Enter the first number: ");
	scanf("%d", &x);
	printf("Enter the second number: ");
	scanf("%d", &y);
	printf("Enter the third number: ");
	scanf("%d", &z);

	f_sort(x, y, z, list);

	printf("The numbers in order are: %d %d %d", list[0], list[1], list[2]);

	//Funtction 10
	//This will look for a set of numbers that equate to the input, when cubed
	printf("\n\nEnter a number and the program will see if a set of numbers cubed will equate to it: ");
	scanf("%d", &n);

	int *twoValues = f_cubed_sum(n);

	if (twoValues)
	{
	printf("The two values are: %d and %d", twoValues[0], twoValues[1]);
	}
	else
	{
	printf("There is no pair of integers that satasfy the formula");
	}

	free(twoValues);

	return 0;
}
