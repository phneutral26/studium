#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h> // For size_t

/**
 * @brief Error codes for linked list operations.
 */
typedef enum {
    LINKED_LIST_SUCCESS = 0,       /**< Operation succeeded */
    LINKED_LIST_ERR_OUT_OF_BOUNDS, /**< Index out of bounds */
    LINKED_LIST_ERR_ALLOCATION,    /**< Memory allocation failed */
    LINKED_LIST_ERR_NULL_POINTER   /**< Null pointer passed */
} linked_list_error_t;

/**
 * @brief Opaque type for a linked list.
 */
typedef struct linked_list linked_list_t;

/**
 * @brief Creates a new linked list.
 * @return Pointer to the created list, or NULL if allocation fails.
 */
linked_list_t* linked_list_create(void);

/**
 * @brief Frees all resources associated with the linked list.
 * @param list Pointer to the list. Safe to pass NULL.
 */
void linked_list_destroy(linked_list_t* list);

/**
 * @brief Appends a value to the end of the list.
 * @param list Pointer to the linked list.
 * @param value Value to append.
 * @return LINKED_LIST_SUCCESS on success, or an error code.
 */
linked_list_error_t linked_list_append(linked_list_t* list, int value);

/**
 * @brief Prepends a value to the beginning of the list.
 * @param list Pointer to the linked list.
 * @param value Value to prepend.
 * @return LINKED_LIST_SUCCESS on success, or an error code.
 */
linked_list_error_t linked_list_prepend(linked_list_t* list, int value);

/**
 * @brief Removes the element at a given index and stores its value.
 * @param list Pointer to the linked list.
 * @param index Index of the element to remove.
 * @param value Pointer to store the removed value.
 * @return LINKED_LIST_SUCCESS on success, or an error code.
 */
linked_list_error_t linked_list_remove_at(linked_list_t* list, size_t index, int* value);

/**
 * @brief Retrieves the value at a given index.
 * @param list Pointer to the linked list.
 * @param index Index of the element to retrieve.
 * @param value Pointer to store the retrieved value.
 * @return LINKED_LIST_SUCCESS on success, or an error code.
 */
linked_list_error_t linked_list_get(const linked_list_t* list, size_t index, int* value);

/**
 * @brief Sets the value at a given index.
 * @param list Pointer to the linked list.
 * @param index Index of the element to update.
 * @param value New value to set.
 * @return LINKED_LIST_SUCCESS on success, or an error code.
 */
linked_list_error_t linked_list_set(linked_list_t* list, size_t index, int value);

/**
 * @brief Returns the number of elements in the list.
 * @param list Pointer to the linked list.
 * @return The number of elements, or 0 on error.
 */
size_t linked_list_size(const linked_list_t* list);

/**
 * @brief Prints all elements in the linked list to the console.
 * @param list Pointer to the linked list.
 * @return LINKED_LIST_SUCCESS on success, or an error code.
 */
linked_list_error_t linked_list_print(const linked_list_t* list);

#endif // LINKED_LIST_H
