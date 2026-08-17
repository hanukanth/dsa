#ifndef _H__COMMON
#define _H__COMMON

typedef struct node
{
    uint16_t data;
    struct node *next_node;
}node_t; 

 node_t *head;
 node_t *tail;

void print_linked_list(void);

#endif
