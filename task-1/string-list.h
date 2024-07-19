/* dynamically sized list of c-strings */

/*
    [ String* ] [ String* ] ... [ String* ] [ NULL ]
*/

typedef char* String;

/**
 *  void StringListInit(char*** list)
 *  Initializes the list to an empty list.
 *  First element* is set to NULL.
 */
int StringListInit(char** &list);

/**
 * void StringListDestroy(char*** list)
 * Frees all the memory allocated for the list.
 */
int StringListDestroy(char** &list);

/**
 * void StringListAdd(char** list, String str)
 * Adds a copy of the string to the list.
 */
int StringListAdd(char** &list, const char* str);

/**
 * void StringListRemove(char** list, String str)
 * Removes all occurances of str in the list
 */
int StringListRemove(char** &list, const char* str);

/**
 * int StringListSize(char** list)
 * Returns the number of strings in the list.
 */
int StringListSize(char** &list);

/**
 * int StringListIndexOf(char** list, char* str)
 * Returns the index of the first occurrence of the string in the list.
 * Returns -1 if the string is not found.
 */
int StringListIndexOf(char** &list, const char* str);

/**
 * void StringListRemoveDuplicates(char** list)
 * Removes all duplicate strings from the list.
 */
int StringListRemoveDuplicates(char** &list);

/**
 * void StringListReplaceInStrings(char** list, char* before, char* after)
 * Replaces all occurrences of the string before with the string after in all strings in the list.
 */
int StringListReplaceInStrings(char** &list, const char* before, const char* after);

/**
 * void StringListSort(char** list)
 * Sorts the list in ascending order.
 */
void StringListSort(char** &list);