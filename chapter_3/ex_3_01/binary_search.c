/** @file binary_search.c
 *  @brief Implementation for Exercise 3-1.
 * 
 *  Our binary search makes two tests inside the loop,
 *  when one would suffice (at the price of more tests outside.)
 *  Write a version with only one test inside the loop and
 *  measure the difference in run-time. 
 * 
 *  @author Youssef Samir
 *  @bug No Known Bugs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defines the size of the array to be tested. 
#define ARR_SIZE 10000000UL

//Defines the number of trials of the search function to compute the average time. 
#define N_RUNS 100UL

/** @brief A function that searches for integers in a sorted array in a O(log N) time. (Uses multiple tests inside the loop.)
 *  @param value The number to search for.
 *  @param arr The sorted array to be searched.
 *  @param n The size of the sorted array.
 *  @return The index of the number, otherwise, a -1.
*/
long int binary_search_v1(int value, int *arr, size_t n){
    long int min, mid, max;
    min = 0;
    max = (long int)n - 1;
    while(max >= min){
        mid = (max + min) / 2;
        if(value < arr[mid]){
            max = mid - 1;
        }else if(value > arr[mid]){
            min = mid + 1;
        }else{
            return mid;
        }
    }

    return arr[mid] == value ? mid : -1;
}

/** @brief A function that searches for integers in a sorted array in a O(log N) time. (Uses a single test inside the loop.)
 *  @param value The number to search for.
 *  @param arr The sorted array to be searched.
 *  @param n The size of the sorted array.
 *  @return The index of the number, otherwise, a -1.
*/
long int binary_search_v2(int value, int *arr, size_t n){
    long int min, mid, max;
    min = 0;
    max = (long int)n - 1;
    while(max >= min && arr[mid] != value){
        mid = (max + min) / 2;
        if(value < arr[mid]){
            max = mid - 1;
        }else{
            min = mid + 1;
        }
    }

    return arr[mid] == value ? mid : -1;
}

/** @brief A function to test and time a searching algorithm on a sorted array.
 *  @param arr The array to be tested.
 *  @param n The size of the array.
 *  @param fcn A pointer to the searching function to be used.
 *  @return The elapsed time in seconds the test took to complete.
*/
double test_function(int *arr, size_t n, long int (*fcn)(int, int *, size_t)){
    clock_t start, end;
    start = clock();
    for(size_t i = 0; i < n; i++){
        fcn(i, arr, n);
    }
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/** @brief A function that runs the test function for a certain searching function
 *         multiple number of times to compute the average elapsed time.
 *  @param runs The number of times to run the searching function.
 *  @param arr The array to be tested.
 *  @param n The size of the array.
 *  @param fcn A pointer to the searching function to be used.
 *  @return The average elapsed time in seconds the test took to complete.
*/
double compute_average(size_t runs, int *arr, size_t n, long int (*fcn)(int, int *, size_t)){
    double sum = 0.0;
    for(size_t i; i < runs; i++){
        sum += test_function(arr, n, fcn);
    }
    return (sum / runs);
}

//If you get Segmentation Fault when you try to run this
//you can decrease ARR_SIZE, increase stack size or enable -fsplit-stack compiler option.
int main(){
    int arr[ARR_SIZE];
    for(size_t i = 0; i < ARR_SIZE; i++){
        arr[i] = i;
    }
    size_t n = sizeof(arr) / sizeof(*arr);

    printf("%lu runs of the first Binary Search function (K&R Implementation) took an average of %lf seconds.\n", N_RUNS, compute_average(N_RUNS, arr, n, binary_search_v1));
    printf("%lu runs of the second Binary Search function (My Implementation) took an average of %lf seconds.\n", N_RUNS, compute_average(N_RUNS, arr, n, binary_search_v2));
    return 0;
}