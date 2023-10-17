#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "Stack.h"
#include <string.h>
#include "Queue.h"

void PrintArray(int* a, int n);

void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void BubbleSort(int* a, int n);
void HeapSort(int* a, int n);
void SelectSort(int* a, int n);
void QuickSort1(int* a, int left, int right);
void QuickSort2(int* a, int left, int right);
void QuickSort3(int* a, int left, int right);
void QuickSortNorR(int* a, int left, int right);
void MergeSort(int* a, int n);
void MergeSortNorR(int* a, int n);
void CountSort(int* a, int n);
void RadixSort(int* a, int n);
