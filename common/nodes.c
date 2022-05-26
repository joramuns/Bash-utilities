//
//  nodes.c
//  s21_grep
//
//  Created by Joramun Sasin on 5/26/22.
//

#include "nodes.h"

node *init_node(void) {
    node *head = (node *)malloc(sizeof(node));
    if (head) {
        head->type = 0;
        head->array = NULL;
        head->next = NULL;
    }

    return head;
}

node *push(node *head) {
    node *next = NULL;
    if (head) {
        next = malloc(sizeof(node));
        if (next) {
            next->type = 0;
            next->array = NULL;
            next->next = NULL;
            node *last = find_last(head);
            if (last)
                last->next = next;
        } else {
            next = head;
        }
    }

    return next;
}

node *pop(node *head) {
    node *last = NULL;
    if (head && head->next) {
        last = find_last(head);
        node *temp = head;
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(last);
        last = find_last(head);
    }

    return last;
}

void *clean(node *head) {
    if (head) {
        while (head->next) {
            node *next = head->next;
            free(head);
            head = next;
        }
        free(head);
    }

    return NULL;
}

node *find_last(node *head) {
    node *last = NULL;
    if (head) {
        last = head;
        while (last->next) {
            last = last->next;
        }
    }

    return last;
}