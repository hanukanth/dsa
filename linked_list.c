#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"



void add(int data)
{
    node_t *temp = NULL;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    //printf("address of new_node=%p\n",new_node);
    if(!new_node)
    {
        printf("new node memory allocation failed....");
        return ;
    }
    new_node->data = data;
    new_node->next_node = NULL;
    if(!head) {
        head = new_node;
        //tail = new_node;
        return ;
    }
    for(temp = head;temp != NULL;temp = temp->next_node) {
        if(temp->next_node == NULL) {
            temp->next_node = new_node;
            return;
        }
    }
    printf("address of temp=%p\n",temp);
    //tail->next_node = new_node;
    //tail = new_node;

}


void add_start(int data)
{
    node_t *temp = NULL;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    //printf("address of new_node=%p\n",new_node);
    if(!new_node)
    {
        printf("new node memory allocation failed....");
        return ;
    }
    new_node->data = data;

    if(!head) {
        head = new_node;
        //tail = new_node;
        return ;
    }
    temp = head;
    head = new_node;
    new_node->next_node = temp;
    
    printf("address of temp=%p\n",temp);
    //tail->next_node = new_node;
    //tail = new_node;

}

void add_after(int reference,int data)
{
    node_t *temp = NULL;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    //printf("address of new_node=%p\n",new_node);
    if(!new_node)
    {
        printf("new node memory allocation failed....");
        return ;
    }
    new_node->data = data;

    if(!head) {
        printf("Linked list is empty, adding the new node as head...");
        head = new_node;
        //tail = new_node;
        return ;
    }
    for(temp = head;temp != NULL;temp = temp->next_node) {
        if(temp->data == reference) {
            new_node->next_node = temp->next_node;
            temp->next_node = new_node;
            return;
        }
    }
    printf("Node with data %d not found, adding the new node at the end...", reference);
    for(temp = head;temp != NULL;temp = temp->next_node) {
        if(temp->next_node == NULL) {
            temp->next_node = new_node;
            return;
        }
    }
    //printf("address of temp=%p\n",temp);
    //tail->next_node = new_node;
    //tail = new_node;

}

void delete(int data)
{
    node_t *temp = head;
    node_t *prev = NULL;
    if(!head) {
        printf("Linked list is empty, nothing to delete...");
        return ;
    }
    if(head->data == data) {
        head = head->next_node;
        free(temp);
        return;

    }
    for(temp = head;temp != NULL; temp = temp->next_node) {
        
        if(temp->next_node->data == data) {
            prev = temp;
            node_t *to_delete = temp->next_node;
            prev->next_node = to_delete->next_node;
            free(to_delete);
            return;
            

        }
    }
}
    /*
    for(temp = head;temp != NULL;temp = temp->next_node) {
        if(temp->data == data) {
            if(prev == NULL) {
                head = temp->next_node;
            }else {
                prev->next_node = temp->next_node;
            }
            free(temp);
            return;
        }
        prev = temp;
    }
    printf("Node with data %d not found, nothing to delete...", data);
}
*/
void print_linked_list(void)
{
    if(!head) {
        printf("Linked list is empty...");
    }else {
        for(node_t *temp = head; temp != NULL;temp = temp->next_node)
        {
            //printf("address of temp=%p\n",temp);
            printf("%d-->",temp->data);
        }
        printf("{null}\n");
    }
}

void reverse_linked_list(void)
{
    node_t *p = NULL;
    node_t *c = head;
    node_t *n = NULL;
    if(!head) {
        printf("Linked list is empty, nothing to reverse...");
        return ;
    }
    while(c != NULL) {
        n = c->next_node;
        c->next_node = p;
        p = c;
        c = n;
    }
    head = p;
}