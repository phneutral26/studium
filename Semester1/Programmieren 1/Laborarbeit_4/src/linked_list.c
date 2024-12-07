#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct node {
    int value;
    struct node* next;
} node_t;

struct linked_list {
    node_t* head;
    size_t size;
};

linked_list_t* linked_list_create(void) {
    linked_list_t* list = malloc(sizeof(linked_list_t));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void linked_list_destroy(linked_list_t* list) {
    if (!list) return;
    node_t* current = list->head;
    while (current) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

linked_list_error_t linked_list_append(linked_list_t* list, int value) {
    if (!list) return LINKED_LIST_ERR_NULL_POINTER;

    node_t* new_node = malloc(sizeof(node_t));
    if (!new_node) return LINKED_LIST_ERR_ALLOCATION;

    new_node->value = value;
    new_node->next = NULL;

    if (!list->head) {
        list->head = new_node;
    } else {
        node_t* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
    return LINKED_LIST_SUCCESS;
}

linked_list_error_t linked_list_prepend(linked_list_t* list, int value) {
    if (!list) return LINKED_LIST_ERR_NULL_POINTER;

    node_t* new_node = malloc(sizeof(node_t));
    if (!new_node) return LINKED_LIST_ERR_ALLOCATION;

    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return LINKED_LIST_SUCCESS;
}

linked_list_error_t linked_list_remove_at(linked_list_t* list, size_t index, int* value) {
    if (!list || !value) return LINKED_LIST_ERR_NULL_POINTER;
    if (index >= list->size) return LINKED_LIST_ERR_OUT_OF_BOUNDS;

    node_t* current = list->head;
    node_t* previous = NULL;

    for (size_t i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }

    *value = current->value;

    if (previous) {
        previous->next = current->next;
    } else {
        list->head = current->next;
    }

    free(current);
    list->size--;
    return LINKED_LIST_SUCCESS;
}

linked_list_error_t linked_list_get(const linked_list_t* list, size_t index, int* value) {
    if (!list || !value) return LINKED_LIST_ERR_NULL_POINTER;
    if (index >= list->size) return LINKED_LIST_ERR_OUT_OF_BOUNDS;

    node_t* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    *value = current->value;
    return LINKED_LIST_SUCCESS;
}

linked_list_error_t linked_list_set(linked_list_t* list, size_t index, int value) {
    if (!list) return LINKED_LIST_ERR_NULL_POINTER;
    if (index >= list->size) return LINKED_LIST_ERR_OUT_OF_BOUNDS;

    node_t* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    current->value = value;
    return LINKED_LIST_SUCCESS;
}

size_t linked_list_size(const linked_list_t* list) {
    if (!list) return 0;
    return list->size;
}

linked_list_error_t linked_list_print(const linked_list_t* list) {
    if (!list) return LINKED_LIST_ERR_NULL_POINTER;

    node_t* current = list->head;
    printf("Linked List: ");
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
    return LINKED_LIST_SUCCESS;
}

