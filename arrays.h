#ifndef _H__ARRAYS
#define _H__ARRAYS

#define REVERSE_RECURSION 0
#define ROWS 5
#define COLS 4

void reverse_array(int *arr, int start, int end);
int count_connected_ones(int arr[ROWS][COLS], int row, int col, int current_row, int current_col);
void matrix_add(void);
void matrix_transpose(void);
void matrix_mul(void);

#endif
