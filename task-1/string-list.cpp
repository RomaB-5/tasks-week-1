#include <stdlib.h>
#include <string.h>

#include "string-list.h"


void StringListInit(char** &list){
    list = (char**)malloc(sizeof(char*));
    list[0] = NULL;
}


void StringListDestroy(char** &list){
    for(int i = 0; list[i] != NULL; i++){
        free(list[i]);
    }
    free(list);
    list = NULL;
}


void StringListAdd(char** &list, const char* str){
    int size = StringListSize(list);
    list = (char**)realloc(list, (size + 2) * sizeof(char*));
    list[size] = (char*)malloc(strlen(str) + 1);
    strcpy(list[size], str);
    list[size + 1] = NULL;
}


void StringListRemove(char** &list, const char* str){
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
    list = (char**)realloc(list, sizeof(char*) * (j + 1));
}

int StringListSize(char** &list){
    int size = 0;
    for(int i = 0; list[i] != NULL; i++){
        size++;
    }
    return size;
}


int StringListIndexOf(char** &list, const char* str){
    for(int i = 0; list[i] != NULL; i++){
        if(strcmp(list[i], str) == 0){
            return i;
        }
    }
    return -1;
}


void StringListRemoveDuplicates(char** &list){
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



    list = (char**) realloc(list, (size + 1) * sizeof(char*));
    list[size] = NULL;
}


void StringListReplaceInStrings(char** &list, const char* before, const char* after){
    for(int i = 0; list[i] != NULL; i++){
        char* ptr = list[i];
        while((ptr = strstr(ptr, before)) != NULL){
            int pos = ptr - list[i];
            int before_len = strlen(before);
            int after_len = strlen(after);
            int tail_len = strlen(ptr + before_len);
            char* tail = (char*)malloc(tail_len + 1);
            strcpy(tail, ptr + before_len);
            list[i] = (char*)realloc(list[i], strlen(list[i]) - before_len + after_len + 1);
            ptr = list[i] + pos;
            strcpy(ptr, after);
            strcpy(ptr + after_len, tail);
            free(tail);
            ptr += after_len;
        }
    }
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
