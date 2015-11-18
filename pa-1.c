#pragma once
#define _CRT_SECURE_NO_WARNINGS –
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pa-1.h"
#include <math.h>

/*
This function takes an integer n as a parameter.
The purpose of this function is to determine if n is an
"Armstrong Number".
*/
bool f_armstrong(int n)
{
	//Declaring variables
	bool testResult = false;
	int remainder;
	int holder = n;
	int total = 0;
	int counter = 0;

	//Getting the amount of digits
	while (holder > 0)
	{
		holder = holder / 10;
		counter = counter + 1;
	}

	

	//Resetting our holder variable
	holder = n;

	//Getting each digit and their sum
	while (holder > 0)
	{
		remainder = holder % 10;
		holder = holder / 10;
		total = total + pow(remainder, counter);
	}

	//Checking to see if the input equates to the sum of its digits
	if (n == total)
	{
		testResult = true;
	}

	return testResult;
}



/*
THe user enters a string phrase into the function.
The function will then go through the string and count the
number of open and closed brackets. If the sizes match it
returns true, if not it returns false.
*/
bool f_brackets(char *e)
{
	//Declaring variables
	int brackLen;
	int counter = 0;
	int openCount = 0;
	int closeCount = 0;
	char curChar, brackets;
	bool results = true;

	brackLen = strlen(e);

	while (counter < brackLen && results == true)
	{

		if (e[counter] == '[')
		{
			openCount = openCount + 1;
		}
		else
		{
			closeCount = closeCount + 1;
		}

		if (closeCount > openCount)
		{
			results = false;
		}

		counter = counter + 1;
	}

	if (closeCount != openCount)
	{
		results = false;
	}

	return results;
}

/*
The user will enter a number theu want to test.
The function will then add up the sum of the divisors.
If the sum and number match it returns true, if not it
returns true.
*/
bool f_perfect(int x)
{
	int userNum = x;					//Variable to hold the parameter value
	int sum = 1;						//Holds the final sum of perfect numbers

	//Divided by the user's number
	//Starts at 2 since all numbers are divisable by 1
	int divisor = 2;

	//While the user's number is greater then the divisor
	while (divisor < userNum)
	{
		//Int to hold the value
		int test = userNum % divisor;

		//If test is 0, then userNum is divisable
		if (test == 0)
		{
			//Add the divisable to the overall sum
			sum += divisor;
		}

		//Incrememnt 
		divisor++;
	}

	//If the sum of divisors is equal to the user's number
	if (userNum == sum)
	{
		return true;
	}

	//If the sum of divisors is not equal to the user's number
	else
	{
		return false;
	}
}


/*
The purpose of this function is for the user to enter a number,
and then they enter another number which the function uses to rotate
the values of their first number.
*/
int f_rotate(int n, int r)
{
	//Declaring variables
	int remainder;
	int counter = 0;
	int holder = n;

	//Checking the amount of digits
	while (holder > 0)
	{
		holder = holder / 10;
		counter = counter + 1;
	}

	//Rotating the number
	while (r > 0)
	{
		//Getting the last digit of number
		remainder = n % 10;
		//Adjusting the other numbers
		n = n / 10;
		//Putting the last number in the front
		n = n + (remainder * pow(10, counter-1));
		//Adjusting the amount of rotations needed
		r = r - 1;
	}

	return n;
}


/*
The user enters a pattern that they would like to search for.
The user also enters a text that they want to check for patterns.
The function will return the amount of times it finds the pattern
in the test.
*/
int f_str_search(char *pattern, char *text)
{
	int patSize = strlen(pattern);			
	int textSize = strlen(text);			
	int occurence = 0;						
	int patElement = 0;						
	int textElem = 0;						
	int match = 0;						

	//While there's still chars left to test in the text string
	while (textElem < textSize)
	{
		//If the values in the element match
		if (*(pattern + patElement) == *(text + textElem))
		{
			//Increment match and the pattern element
			match++;
			patElement++;
		}

		//If the values in the element do not match
		else
		{
			match = 0;
			patElement = 0;
		}

		//If matches equal size of pattern, pattern is found
		if (match == patSize)
		{
			match = 0;
			patElement = 0;

	
			occurence = occurence + 1;

			
			textElem--;
		}

		printf("TEST\n");
		textElem++;
	}

	return occurence;
}


/*
The user enters a natural number.
The program will use the "The Collatz Conjecture" and return
the amount of iterations it took to get the user's number to
equal 1.
*/
int f_collatz_count(int n)
{
	//Declaring variables
	int remainder;
	int counter = 0;

	//Performing the Collartz conjucture
	while (n > 1)
	{
		//Checking to see if odd or even
		remainder = n % 2;

		if (remainder == 0)
		{
			//Halving the number
			n = n / 2;
		}
		else
		{
			//Multiplying by 3
			n = n * 3 + 1;
		}
		counter = counter + 1;
	}

	return counter;
}


/*
User enters a number.
The function will add however many random numbers the user entered.
It will then multiply all the random numbers by 2, and will return the
average of the first 5 numbers divisable by 3.
*/
int f_array(int n)
{

	//Creating variables
	int remainder, average;
	int counter = 0;
	int avgCount = 0;
	int total = 0;
	bool results = false;

	//Creating arrayAn
	int* A;
	A = malloc(n * sizeof(A));

	//Initializing random seed
	srand(time(NULL));

	//Populating array with random numbers
	while (counter < n)
	{
		A[counter] = rand() % 99 + 1;

		counter = counter + 1;
	}
	//Resetting counter
	counter = 0;

	//Multiplying array by 2
	while (counter < n)
	{
		A[counter] = A[counter] * 2;

		counter = counter + 1;
	}

	//Restting counter
	counter = 0;

	//Getting the average of first 5 numbers divisible by 3
	while (counter < n && results == false)
	{
		//Checking if divisible by 3
		remainder = A[counter] % 3;

		if (remainder == 0)
		{
			total = total + A[counter];
			avgCount = avgCount + 1;
		}

		if (avgCount == 5)
		{
			results = true;
		}

		counter = counter + 1;

	}

	free(A);
	
	// To prevent dividing by zero if no numbers are divisable by 0
	if (avgCount == 0)
	{
		return 0;
	}

	average = total / avgCount;

	return average;

}



/*
The user enters two different strings.
The function will test to see which one is larger and then return a
combined string with the shorter string, the longer string, and the
shorter string again.
*/
void f_strings(char *s1, char *s2, char *s3)
{
	//Comparing the string lengths
	//int	firstCount = strlen(s1);
	//int secCount = strlen(s2);


	if ((int)strlen(s1) > (int)strlen(s2))
	{
		strcpy(s3,s1);
		strcat(s3,s2);
		strcat(s3,s1);
	}
	else
	{
		strcpy(s3,s2);
		strcat(s3,s1);
		strcat(s3,s2);
	}

	return;
}


/*
The user enters 3 numbers.
The function then sorts those numbers and lists them in ascending
order.
*/
void f_sort(int x, int y, int z, int *list)
{

	//Declaring variables
	int xCount = 2;
	int yCount = 2;
	int zCount = 2;

	if (x >= y)
	{
		yCount = yCount - 1;
	}
	else
	{
		xCount = xCount - 1;
	}

	if (y >= z)
	{
		zCount = zCount - 1;
	}
	else
	{
		yCount = yCount - 1;
	}

	if (z >= x)
	{
		xCount = xCount - 1;
	}
	else
	{
		zCount = zCount - 1;
	}

	//Putting the numbers in the array in ascending order
	list[xCount] = x;
	list[yCount] = y;
	list[zCount] = z;

	return;
}

/*
The user enters a number.
The function will test if the cubed sum of 2 numbers is equal
to the number they entered.
*/
int *f_cubed_sum(int n)
{
	int aCount, a, b, sum;
	int bCount = 1;

	while (bCount < n)
	{
		aCount = 1;
		while (aCount < n)
		{
			a = pow(aCount, 3);
			b = pow(bCount, 3);
			sum = a + b;

			if (sum == n)
			{
				int *res = malloc(2 * sizeof(*res));

				res[0] = aCount;
				res[1] = bCount;

				return res;
			}
			else
			{
				aCount = aCount + 1;
			}
		}
		bCount = bCount + 1;
	}
	
	//If no solution found
	return NULL;
}
