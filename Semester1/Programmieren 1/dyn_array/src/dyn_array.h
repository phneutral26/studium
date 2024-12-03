#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <stddef.h> // Für size_t

// Vorwärtsdeklaration des opaken Typs
typedef struct dyn_array dyn_array;

/**
 * @brief Mögliche Fehlercodes, die von der API verwendet werden können.
 */
typedef enum {
    DYN_ARRAY_SUCCESS = 0,       // Keine Fehler
    DYN_ARRAY_ERR_OUT_OF_BOUNDS, // Index außerhalb des gültigen Bereichs
    DYN_ARRAY_ERR_ALLOCATION,    // Speicherzuweisung fehlgeschlagen
    DYN_ARRAY_ERR_NULL_POINTER   // Ungültiger Zeiger
} dyn_array_error_t;

/**
 * @brief Gibt den letzten Fehlerstatus zurück.
 * @return Der letzte Fehlerstatus (siehe dyn_array_error_t).
 */
dyn_array_error_t dyn_array_get_last_error(void);

/**
 * @brief Erstellt ein neues dynamisches Array mit einer initialen Kapazität.
 * @param initial_capacity Die anfängliche Kapazität des Arrays.
 * @return Ein Zeiger auf das erstellte dynamische Array oder NULL bei Fehler.
 */
dyn_array* create_array(size_t initial_capacity);

/**
 * @brief Gibt den gesamten Speicher des dynamischen Arrays frei.
 * @param arr Ein Zeiger auf das dynamische Array.
 */
void destroy_array(dyn_array* arr);

/**
 * @brief Fügt ein Element am Ende des dynamischen Arrays hinzu.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @param value Der hinzuzufügende Wert.
 * @return DYN_ARRAY_SUCCESS bei Erfolg, ansonsten ein Fehlercode.
 */
dyn_array_error_t append(dyn_array* arr, int value);

/**
 * @brief Gibt das Element an der angegebenen Position zurück.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @param index Der Index des Elements.
 * @param value Pointer, um das gefundene Element zurückzugeben.
 * @return DYN_ARRAY_SUCCESS bei Erfolg, ansonsten ein Fehlercode.
 */
dyn_array_error_t get(const dyn_array* arr, size_t index, int* value);

/**
 * @brief Setzt das Element an der angegebenen Position auf einen neuen Wert.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @param index Der Index des zu setzenden Elements.
 * @param value Der neue Wert.
 * @return DYN_ARRAY_SUCCESS bei Erfolg, ansonsten ein Fehlercode.
 */
dyn_array_error_t set(dyn_array* arr, size_t index, int value);

/**
 * @brief Löscht das Element an der angegebenen Position und verschiebt
 * die nachfolgenden Elemente entsprechend.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @param index Der Index des zu löschenden Elements.
 * @return DYN_ARRAY_SUCCESS bei Erfolg, ansonsten ein Fehlercode.
 */
dyn_array_error_t remove_at(dyn_array* arr, size_t index);

/**
 * @brief Gibt die Anzahl der aktuell gespeicherten Elemente im Array zurück.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @return Die Anzahl der gespeicherten Elemente oder 0 bei Fehler.
 */
size_t size(const dyn_array* arr);

/**
 * @brief Gibt die aktuelle Kapazität des Arrays zurück.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @return Die aktuelle Kapazität des Arrays oder 0 bei Fehler.
 */
size_t capacity(const dyn_array* arr);

/**
 * @brief Gibt alle Elemente des Arrays in lesbarer Form auf der Konsole aus.
 * @param arr Ein Zeiger auf das dynamische Array.
 * @return DYN_ARRAY_SUCCESS bei Erfolg, ansonsten ein Fehlercode.
 */
dyn_array_error_t print_array(const dyn_array* arr);

#endif // DYN_ARRAY_H

