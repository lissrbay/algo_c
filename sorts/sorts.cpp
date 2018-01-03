#include <iostream>
#include "sorts.h"

using namespace std;

void bubble_sort(int *arr, int length) {
    for (int i = 0 ; i < length ; i++)
        for (int j = i + 1 ; j < length ; j++)
            if (arr[j] < arr[i])
            {
                swap(arr[i], arr[j]);
            }
}

int partition_sort(int *arr, int left_pointer, int right_pointer) {
    int middle_element = arr[left_pointer], i = left_pointer - 1, j = right_pointer + 1;
    while (true)
    {
        while(arr[j] < middle_element)
            j--;
        while(arr[i] > middle_element)
            i++;
        if (i < j)
            swap(arr[i], arr[j]);
        else
            return j;
    }
}

void quick_sort(int *arr, int left_pointer, int right_pointer) {
    if (left_pointer < right_pointer)
    {
        int middle_element = partition_sort(arr, left_pointer, right_pointer);
        quick_sort(arr, left_pointer, middle_element - 1);
        quick_sort(arr, middle_element + 1, right_pointer);
    }
}

void selection_sort(int *arr, int length) {
    for(int i = length - 1; i >= 0; i--)
    {
        int max_position = 0;
        for(int j = 1; j <= i; j++)
        {
            if(arr[j] > arr[max_position])
                max_position = j;
        }
        swap(arr[i], arr[max_position]);
    }
}

void insertion_sort(int *arr, int length) {
    for(int i = 0; i < length; i++)
    {
        int current_position = arr[i];
        int position = i;
        while((position > 0) && (current_position < arr[position - 1]))
        {
            arr[position] = arr[position - 1];
            position--;
        }
        arr[position] = current_position;
    }
}

void merge(int *arr, int left_pointer, int middle_element, int right_pointer) {
    int it1 = 0, it2 = 0;
    int *result = new int[right_pointer - left_pointer];

    while (left_pointer + it1 < middle_element && (middle_element + it2 < right_pointer))
    {
        if (arr[left_pointer + it1] < arr[middle_element + it2])
        {
            result[it1 + it2] = arr[left_pointer + it1];
            it1++;
        }
        else
        {
            result[it1 + it2] = arr[middle_element + it2];
            it2++;
        }
    }
    while (left_pointer + it1 < middle_element)
    {
        result[it1 + it2] = arr[left_pointer + it1];
        it1++;
    }
    while(middle_element + it2 < right_pointer)
    {
        result[it1 + it2] = arr[middle_element + it2];
        it2++;
    }

    for (int i = 0; i < it1 + it2; i++)
        arr[left_pointer + i] = result[i];
    delete[] result;
}

void merge_sort(int *arr, int left_pointer, int right_pointer) {
    if(left_pointer - right_pointer < -1)
    {
        int middle_element = (left_pointer + right_pointer) / 2;
        merge_sort(arr, left_pointer, middle_element);
        merge_sort(arr, middle_element, right_pointer);
        merge(arr, left_pointer, middle_element, right_pointer);
    }
}


