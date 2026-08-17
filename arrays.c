#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "arrays.h"


void reverse_array(int *arr, int start, int end)
{
    int temp;

    if (start >= end) {
        return;
    }
    /* print array before reversal */
    for (int i = 0; i < end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reverse_array(arr,start+1,end-1);
    temp = arr[start];
    arr[start] = arr[end-1];
    arr[end-1] = temp;
    /* print array post reversal */
    for (int i = 0; i < end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* problem: verify longest connected ones in array left,right,top,bottom*/

int count_connected_ones(int arr[ROWS][COLS], int row, int col, int current_row, int current_col)
{
    int count = 0;
    if(arr == NULL || current_row < 0 || current_row >= row || current_col < 0 || current_col >= col) {
        return 0;
    }
    if(arr[current_row][current_col] == 0) {
        return 0;
    }

    if(arr[current_row][current_col] == 1) {
        arr[current_row][current_col] = 0; // mark as visited
        count = 1;
        // Found a connected one, explore all 4 directions
        count = count + count_connected_ones(arr, row, col, current_row-1, current_col); // up
        count = count + count_connected_ones(arr, row, col, current_row+1, current_col); // down
        count = count + count_connected_ones(arr, row, col, current_row, current_col-1); // left
        count = count + count_connected_ones(arr, row, col, current_row, current_col+1); // right
    }
    return count;
}
