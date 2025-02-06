/*
 * main.c
 *
 *  	Uploaded 2/5/2025
 *
 *      Author: Devan Meyer
 */
#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

/**
 * Driver function for heap.c, takes user input to create an array of preset size customizable above via MAX_EMPLOYEES.
 * Assumes that user will input non-decimal numbers.
 */
int main()
{
	Employee employees[MAX_EMPLOYEES];
	int cmdLine = 1; // value to # cmdlines

	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		printf("%d Name: ", cmdLine);
		cmdLine++;
		scanf("%49s", employees[i].name); //	Scan for input string and prevent buffer overflow
		printf("%d Salary: ", cmdLine++);
		scanf("%d", &employees[i].salary); // Scan for user int input for salary
		printf("%d\n", cmdLine++);
	}
	printf("%d ", cmdLine++);

	heapSort(employees, MAX_EMPLOYEES); // Sort input array

	printf("\n%d ", cmdLine++);

	printList(employees, MAX_EMPLOYEES); // Print out sorted array

	return 0;
}
