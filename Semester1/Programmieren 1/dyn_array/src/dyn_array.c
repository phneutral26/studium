#include "dyn_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dyn_array {
  int* data;        // Pointer auf die gespeicherten Elemente
  size_t size;      // Anzahl an gespeicherten Elemente
  size_t capacity;  // Kapazität des Arrays
};

static dyn_array_error_t last_error = DYN_ARRAY_SUCCESS;

static dyn_array_error_t set_last_error(dyn_array_error_t error) { return last_error = error; }

dyn_array_error_t dyn_array_get_last_error(void) { return last_error; }

dyn_array* create_array(size_t initial_capacity) {
  if (initial_capacity == 0) {
    set_last_error(DYN_ARRAY_ERR_ALLOCATION);
    return NULL;
  }

  dyn_array* arr = malloc(sizeof(dyn_array));
  if (!arr) {
    set_last_error(DYN_ARRAY_ERR_ALLOCATION);
    return NULL;
  }

  arr->data = malloc(initial_capacity * sizeof(int));
  if (!arr->data) {
    free(arr);
    set_last_error(DYN_ARRAY_ERR_ALLOCATION);
    return NULL;
  }

  arr->size = 0;
  arr->capacity = initial_capacity;
  set_last_error(DYN_ARRAY_SUCCESS);
  return arr;
}

void destroy_array(dyn_array* arr) {
  if (arr) {
    free(arr->data);
    free(arr);
  }
  set_last_error(DYN_ARRAY_SUCCESS);
}

dyn_array_error_t append(dyn_array* arr, int value) {
  if (!arr) {
    set_last_error(DYN_ARRAY_ERR_NULL_POINTER);
    return DYN_ARRAY_ERR_NULL_POINTER;
  }
  if (arr->size >= arr->capacity) {
    size_t new_capacity = arr->capacity * 2;
    int* new_data = realloc(arr->data, new_capacity * sizeof(int));
    if (!new_data) { return set_last_error(DYN_ARRAY_ERR_ALLOCATION); }

    arr->data = new_data;
    arr->capacity = new_capacity;
  }
  arr->data[arr->size++] = value;

  return set_last_error(DYN_ARRAY_SUCCESS);
}

dyn_array_error_t get(const dyn_array* arr, size_t index, int* value) {
  if (!arr || !value) { return set_last_error(DYN_ARRAY_ERR_NULL_POINTER); }
  if (index >= arr->size) { return set_last_error(DYN_ARRAY_ERR_OUT_OF_BOUNDS); }

  *value = arr->data[index];
  return set_last_error(DYN_ARRAY_SUCCESS);
}

dyn_array_error_t set(dyn_array* arr, size_t index, int value) {
  if (!arr) { return set_last_error(DYN_ARRAY_ERR_NULL_POINTER); }
  if (index >= arr->size) { return set_last_error(DYN_ARRAY_ERR_OUT_OF_BOUNDS); }

  arr->data[index] = value;
  return set_last_error(DYN_ARRAY_SUCCESS);
}

dyn_array_error_t remove_at(dyn_array* arr, size_t index) {
  if (!arr) { return set_last_error(DYN_ARRAY_ERR_NULL_POINTER); }
  if (index >= arr->size) { return set_last_error(DYN_ARRAY_ERR_OUT_OF_BOUNDS); }

  /* Shifte alle Elemente nach dem Index eine Position nach links */
  memmove(&arr->data[index], &arr->data[index + 1], (arr->size - index - 1) * sizeof(int));

  arr->size--;
  return set_last_error(DYN_ARRAY_SUCCESS);
}

size_t size(const dyn_array* arr) { return arr ? arr->size : 0; }

size_t capacity(const dyn_array* arr) { return arr ? arr->capacity : 0; }

dyn_array_error_t print_array(const dyn_array* arr) {
  if (!arr) { return set_last_error(DYN_ARRAY_ERR_NULL_POINTER); }

  printf("Array: [ ");
  for (size_t i = 0; i < arr->size; i++) { printf("%d ", arr->data[i]); } 
  printf("]\n");

  return set_last_error(DYN_ARRAY_SUCCESS);
}
