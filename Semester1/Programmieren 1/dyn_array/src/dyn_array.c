#include "dyn_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dyn_array {
    int *data;           // Pointer auf die gespeicherten Elemente
    size_t size;         // Anzahl an gespeicherten Elemente
    size_t capacity;     // Kapazität des Arrays
};

static dyn_array_error_t last_error = DYN_ARRAY_SUCCESS;

// Helper function to set the last error
static void set_last_error(dyn_array_error_t error) {
    last_error = error;
}

dyn_array_error_t dyn_array_get_last_error(void) {
    return last_error;
}

dyn_array* create_array(size_t initial_capacity) {
    // Prüfen, ob die Initialkapazität gültig ist
    // Wenn die Initialkapazität 0 ist, setzen wir Fehler auf DYN_ARRAY_ERR_ALLOCATION und geben NULL zurück
    // Verhindert Memory-Leaks durch free()
    if (initial_capacity == 0) {
        set_last_error(DYN_ARRAY_ERR_ALLOCATION);
        return NULL;
    }

    dyn_array *arr = malloc(sizeof(dyn_array)); // Dynamisches Array anlegen
    if (!arr) {
        set_last_error(DYN_ARRAY_ERR_ALLOCATION);
        return NULL;
    }

    arr->data = malloc(initial_capacity * sizeof(int)); // Speicherplatzreservierung mit Pointer für Daten im Array (_data_)
    /* Überprüft ob der Pointer auf Data null ist, d.h Speicherzuweisung fehlgeschlagen ist */
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

/**
 * Fügt einen neuen Integerwert am Ende des Arrays hinzu.
 *
 * Diese Funktion fügt am Ende des Arrays den übergebenen Wert hinzu.
 * Wenn das Array voll ist, wird die Größe verdoppelt und der neue Wert wird eingefügt.
 *
 * @param arr Pointe auf dynamisches Array.
 * @param value Der Integerwert, der hinzugefügt werden soll.
 * @return:
 *         DYN_ARRAY_SUCCESS bei erfolgreichem Einfügen,
 *         DYN_ARRAY_ERR_NULL_POINTER wenn arr NULL ist, oder
 *         DYN_ARRAY_ERR_ALLOCATION wenn der Speicher nicht reserviert werden konnte.
 */
dyn_array_error_t append(dyn_array* arr, int value) {
    if(!arr) {
        set_last_error(DYN_ARRAY_ERR_NULL_POINTER);
        return DYN_ARRAY_ERR_NULL_POINTER;
    }
    if (arr->size >= arr->capacity) {
        size_t new_capacity = arr->capacity * 2;
        int *new_data = realloc(arr->data, new_capacity * sizeof(int));
        if (!new_data) {
            set_last_error(DYN_ARRAY_ERR_ALLOCATION);
            return DYN_ARRAY_ERR_ALLOCATION;
        }
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    arr->data[arr->size++] = value;
    set_last_error(DYN_ARRAY_SUCCESS);
    return DYN_ARRAY_SUCCESS;
}


dyn_array_error_t get(const dyn_array* arr, size_t index, int* value) {
    if (!arr || !value) {
        set_last_error(DYN_ARRAY_ERR_NULL_POINTER);
        return DYN_ARRAY_ERR_NULL_POINTER;
    }
    if (index >= arr->size) {
        set_last_error(DYN_ARRAY_ERR_OUT_OF_BOUNDS);
        return DYN_ARRAY_ERR_OUT_OF_BOUNDS;
    }

    *value = arr->data[index];
    set_last_error(DYN_ARRAY_SUCCESS);
    return DYN_ARRAY_SUCCESS;
}

dyn_array_error_t set(dyn_array* arr, size_t index, int value) {
    if (!arr) {
        set_last_error(DYN_ARRAY_ERR_NULL_POINTER);
        return DYN_ARRAY_ERR_NULL_POINTER;
    }
    if (index >= arr->size) {
        set_last_error(DYN_ARRAY_ERR_OUT_OF_BOUNDS);
        return DYN_ARRAY_ERR_OUT_OF_BOUNDS;
    }

    arr->data[index] = value;
    set_last_error(DYN_ARRAY_SUCCESS);
    return DYN_ARRAY_SUCCESS;

}

dyn_array_error_t remove_at(dyn_array* arr, size_t index) {
    /* Wenn Pointer auf Array Null ist (Array nicht existiert) DYN_ARRAY_ERR_NULL_POINTER ausgeben */
    if (!arr) {
        set_last_error(DYN_ARRAY_ERR_NULL_POINTER);
        return DYN_ARRAY_ERR_NULL_POINTER;
    }
    /* Gib OOB Error wenn Index außerhalb des Arrays */
    if (index >= arr->size) {
        set_last_error(DYN_ARRAY_ERR_OUT_OF_BOUNDS);
        return DYN_ARRAY_ERR_OUT_OF_BOUNDS;
    }

    /* Shifte alle Elemente nach dem Index eine Position nach links */
    memmove(&arr->data[index], &arr->data[index + 1], (arr->size - index - 1) * sizeof(int));

    arr->size--; // Reduziert die Anzahl der Elemente um eins

    /* Erfolgreich - DYN_ARRAY_SUCCESS ausgeben */
    set_last_error(DYN_ARRAY_SUCCESS);
    return DYN_ARRAY_SUCCESS;

}

size_t size(const dyn_array* arr) {
    return arr ? arr->size : 0;
}

size_t capacity(const dyn_array* arr) {
    return arr ? arr->capacity : 0;
}

dyn_array_error_t print_array(const dyn_array* arr) {
    if (!arr) {
        set_last_error(DYN_ARRAY_ERR_NULL_POINTER);
        return DYN_ARRAY_ERR_NULL_POINTER;
    }

    printf("Array: [ ");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("]\n");

    set_last_error(DYN_ARRAY_SUCCESS);
    return DYN_ARRAY_SUCCESS;

}
