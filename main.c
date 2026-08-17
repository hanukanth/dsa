#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"
#include "arrays.h"


int main(void)
{
#if LINKED_LIST
    add_start(100);
    add_start(200);
    add_start(400);
    add_start(500);
    add_after(200, 300);
    add_after(500, 600);
    print_linked_list();
    delete(100);
    print_linked_list();
    delete(500);
    print_linked_list();
    reverse_linked_list();
    print_linked_list();
    add_after(200, 300);
    add_after(500, 600);
    print_linked_list();
    return 20;
#endif

#if REVERSE_RECURSION
int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    reverse_array(my_array, 0, size);

    int my_2d_array[ROWS][COLS] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0}
    };
    /* count the number of connected ones */
    int count = 0;
    int largest = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int current_count = count_connected_ones(my_2d_array, ROWS, COLS, i, j);
            count += current_count;
            if (current_count > largest) {
                largest = current_count;
            }
        }
    }
    printf("Count of connected ones: %d\n", count);
    printf("Largest connected ones: %d\n", largest);
    return 0;
#endif

//matrix_add();
//matrix_transpose();
 matrix_mul();
return 0;

}