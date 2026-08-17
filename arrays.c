#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "arrays.h"
#include "limits.h"


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

/* matrix ops */
/* matrix addition */
#define ROW 3
#define COL 3

void matrix_add(void)
{
    uint8_t A[ROW][COL] = {{1,1,1},{1,1,1},{1,1,1,}};
    uint8_t B[ROW][COL] = {{1,1,1},{1,1,1},{1,1,255,}};
    uint8_t C[ROW][COL] = {0};
    for(uint8_t i = 0;i<ROW;i++) {
        for(uint8_t j = 0;j<COL;j++) {
            if(A[i][j] > CHAR_MAX-B[i][j]) {
                printf("overflow detected at [%d][%d]\n",i,j);
            } else {
                C[i][j] = (A[i][j]+B[i][j]);
            }
            
        }
    }
    for(uint8_t i = 0;i<ROW;i++) {
        for(uint8_t j = 0;j<COL;j++) {
            printf(" %d ",C[i][j]);
        }
        printf("\n");
    }
}
#define TROW 4
#define TCOL 4
void matrix_transpose(void)
{
    uint8_t A[TROW][TCOL] = {{1,2,3,4},{4,5,6,7},{7,8,9,10},{10,11,12,13}};
    for(uint8_t i = 0;i<TROW;i++) {
        for(uint8_t j = 0;j<TCOL;j++) {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(uint8_t i = 0;i<TROW;i++) {
        for(uint8_t j = i+1;j<TCOL;j++) {
            uint8_t temp = 0;
            //if(i != j) {
                temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            //}
        }
    }
    for(uint8_t i = 0;i<TROW;i++) {
        for(uint8_t j = 0;j<TCOL;j++) {
            printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
}
void matrix_mul(void)
{
    uint8_t A[ROW][COL] = {{1,2,3},{4,5,6},{7,8,9}};
    uint8_t B[ROW][COL] = {{1,2,3},{4,5,6},{7,8,9}};
    uint8_t C[ROW][COL] = {0};
    for(uint8_t i = 0;i<ROW;i++) {
        for(uint8_t j = 0;j<COL;j++) {
            for(uint8_t k = 0;k<COL;k++) {
                C[i][j] += (A[i][k]*B[k][j]);
            }
        }
    }
    for(uint8_t i = 0;i<ROW;i++) {
        for(uint8_t j = 0;j<COL;j++) {
            printf(" %d ",C[i][j]);
        }
        printf("\n");
    }
}