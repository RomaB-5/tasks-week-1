#include <stdlib.h>
#include <string.h>

#include "string-list.h"


int StringListInit(char** &list){
    if (list != NULL) return -1;

    list = (char**)malloc(sizeof(char*));

    if (list == NULL) return -1;

    else list[0] = NULL;

    return 0;
}


int StringListDestroy(char** &list){
    if (list == NULL) return -1;
    for(int i = 0; list[i] != NULL; i++){
        free(list[i]);
    }
    free(list);
    list = NULL;
    return 0;
}


int StringListAdd(char** &list, const char* str){
    if (list == NULL || str == NULL) return -1;
    char* temp_str = (char*)malloc(strlen(str) + 1);
    if (temp_str == NULL) return -1;

    int size = StringListSize(list);
    char** temp = (char**)realloc(list, (size + 2) * sizeof(char*));
    if (temp == NULL) 
    {
        free(temp_str);
        return -1;
    }
    list = temp;
    list[size] = temp_str;
    strcpy(list[size], str);
    list[size + 1] = NULL;

    return 0;
}


int StringListRemove(char** &list, const char* str){
    if (list == NULL || str == NULL) return -1;
    int i = 0, j = 0;
    while(list[i] != NULL){
        if (strcmp(list[i], str) == 0) {
            free(list[i]);
        } else {
            list[j] = list[i];
            j++;
        }
        i++;
    }
    list[j] = NULL;
    char** temp = (char**)realloc(list, sizeof(char*) * (j + 1));
    if (temp == NULL) return -1;

    return 0;
}

int StringListSize(char** &list){
    if (list == NULL) return -1;
    int size = 0;
    for(int i = 0; list[i] != NULL; i++){
        size++;
    }
    return size;
}


int StringListIndexOf(char** &list, const char* str){
    if (list == NULL || str == NULL) return -1;
    for(int i = 0; list[i] != NULL; i++){
        if(strcmp(list[i], str) == 0){
            return i;
        }
    }
    return -1;
}


int StringListRemoveDuplicates(char** &list){
    if (list == NULL) return -1;
    int size = StringListSize(list);
    
    for (int i = 0; i < size; i++){
        int j = i + 1, k = i + 1;
        while (list[j] != NULL){
            if (strcmp(list[i], list[j]) == 0){
                free(list[j]);
                size--;
            } else {
                list[k] = list[j];
                k++;
            }
            j++;
        }
        list[size] = NULL;
    }



    char** temp = (char**) realloc(list, (size + 1) * sizeof(char*));
    if (temp == NULL) return -1;
    list = temp;
    list[size] = NULL;

    return 0;
}


int StringListReplaceInStrings(char** &list, const char* before, const char* after){
    if (list == NULL || before == NULL || after == NULL) return -1;
    for(int i = 0; list[i] != NULL; i++){
        char* ptr = list[i];
        while((ptr = strstr(ptr, before)) != NULL){
            int pos = ptr - list[i];
            int before_len = strlen(before);
            int after_len = strlen(after);
            int tail_len = strlen(ptr + before_len);
            char* tail = (char*)malloc(tail_len + 1);
            if (tail == NULL) return -1;
            strcpy(tail, ptr + before_len);
            char* temp = (char*)realloc(list[i], strlen(list[i]) - before_len + after_len + 1);
            if (temp == NULL)
            {
                free(tail);
                return -1;
            }
            list[i] = temp;
            ptr = list[i] + pos;
            strcpy(ptr, after);
            strcpy(ptr + after_len, tail);
            free(tail);
            ptr += after_len;
        }
    }

    return 0;
}

int cmp(const void* s1, const void* s2)
{
    const char** a = (const char**) s1;
    const char** b = (const char**) s2;
    return strcmp(*a, *b);
}

void StringListSort(char** &list){
    qsort(list, StringListSize(list), sizeof(char*), cmp);
}
