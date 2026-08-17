#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"


void reverse_linked_list_recursive(node_t **head_ref)
{
    node_t *first;
    node_t *rest;

    if (*head_ref == NULL) {
        return;
    }
    first = *head_ref;
    rest = first->next_node;

    if (rest == NULL) {
        return;
    }
    reverse_linked_list_recursive(&rest);
    first->next_node->next_node = first;
    first->next_node = NULL;
    *head_ref = rest;
}
