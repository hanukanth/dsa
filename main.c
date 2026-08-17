#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"


int main(void)
{
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

}