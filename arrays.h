#ifndef _H__ARRAYS
#define _H__ARRAYS

#define ROWS 5
#define COLS 4

void reverse_array(int *arr, int start, int end);
int count_connected_ones(int arr[ROWS][COLS], int row, int col, int current_row, int current_col);

#endif
