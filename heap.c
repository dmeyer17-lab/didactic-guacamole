/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013, 2/5/2025
 *
 *      Author: Devan Meyer
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// BuildHeap on the heap
	buildHeap(A, n);
	// while n > 0:
	for (int i = n - 1; i > 0; i--)
	{
		swap(&A[0], &A[i]); // swap A[n-1] with A[0], since A[0] is the smallest number.
		heapify(A, 0, i);	// Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// heapify() every element from A[n/2] down-to A[0]
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	//	get index of left child of element i
	int left_child = 2 * (i + 1) - 1;

	//	get index of right child of element i

	int right_child = 2 * (i + 1);

	//	determine which child has a smaller salary. We'll call the index of this
	//	element: "smaller"

	int smaller = i;

	printf("heapifying: i=%d, left_child=%d, right_child=%d, n=%d\n", i, left_child, right_child, n); // show heapify values for error checking

	if (left_child < n && A[left_child].salary < A[smaller].salary)
	{
		smaller = left_child;
	}

	if (right_child < n && A[right_child].salary < A[smaller].salary)
	{
		smaller = right_child;
	}

	//	recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//	Then recursively heapify A[smaller].

	if (A[i].salary > A[smaller].salary && smaller != i)
	{
		if (smaller >= n || i >= n)
		{
			printf("Error: Attempting to swap out-of-bounds index! i=%d, smaller=%d, n=%d\n", i, smaller, n);
			return; // Prevents seg fault
		}

		printf("Swapping index %d (%d) with index %d (%d)\n", i, A[i].salary, smaller, A[smaller].salary); // show swap values for error checking

		swap(&A[i], &A[smaller]);
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	if (!e1 || !e2)
		return;			 // Prevent null pointer errors
	Employee temp = *e1; //	Create temp to save index of e1 after first swap
	*e1 = *e2;			 //	e1 gets e2's index
	*e2 = temp;			 //	e2 gets e1's index
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	printf("[");
	for (int i = 0; i < n; i++)
	{
		printf("id: %s, sal: %d", A[i].name, A[i].salary);

		if (i < n - 1)
		{
			printf("], [");
		}
	}
	printf("]\n");
}
