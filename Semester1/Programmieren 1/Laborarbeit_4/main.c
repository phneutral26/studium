#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void handle_error(linked_list_error_t error, const char* message, int terminate) {
  if (error != LINKED_LIST_SUCCESS) {
    fprintf(stderr, "%s: Error code %d\n", message, error);
    if (terminate) {
      exit(EXIT_FAILURE);
    }
  }
}

int main(void) {
  linked_list_t* list = linked_list_create();
  if (!list) {
    handle_error(LINKED_LIST_ERR_ALLOCATION, "Failed to create linked list", EXIT_FAILURE);
  }

  handle_error(linked_list_append(list, 10), "Failed to append 10", 1);
  handle_error(linked_list_append(list, 20), "Failed to append 20", 1);
  handle_error(linked_list_prepend(list, 5), "Failed to prepend 5", 1);

  printf("List size: %zu\n", linked_list_size(list));
  for (size_t i = 0; i < linked_list_size(list); i++) {
    int value;
    handle_error(linked_list_get(list, i, &value), "Failed to get element", 0);
    printf("Element %zu: %d\n", i, value);
  }

  int removed;
  handle_error(linked_list_remove_at(list, 1, &removed), "Failed to remove element at index 1", 0);
  printf("Removed: %d\n", removed);

  for (size_t i = 0; i < linked_list_size(list); i++) {
    int value;
    handle_error(linked_list_get(list, i, &value), "Failed to get element", 0);
    printf("Element %zu: %d\n", i, value);
  }

  linked_list_print(list);
  linked_list_destroy(list);

  return EXIT_SUCCESS;
}
