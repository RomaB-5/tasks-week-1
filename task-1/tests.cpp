#include "string-list.h"
#include "gtest/gtest.h"

TEST(StringListInit, Test1) {
    char** list = NULL;
    StringListInit(list);
    ASSERT_EQ(list[0], (char*) NULL);

    StringListDestroy(list);

}

TEST(StringListAdd, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple"); 
    StringListAdd(list,  "apple");

    ASSERT_STREQ(list[0],  "apple");
    ASSERT_STREQ(list[1],  "plum");
    ASSERT_STREQ(list[2],  "apple");
    ASSERT_STREQ(list[3],  "apple");
    ASSERT_EQ(list[4],  (char*) NULL);

    StringListDestroy(list);

}

TEST(StringListRemove, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");

    StringListRemove(list, "apple");

    ASSERT_STREQ(list[0],  "plum");
    ASSERT_EQ(list[1], (char*) NULL);

    StringListRemove(list, "plum");
    ASSERT_EQ(list[0], (char*) NULL);

    StringListDestroy(list);
}

TEST(StringListRemove, Test2) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");
    StringListAdd(list,  "banana");
    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");

    StringListRemove(list, "plum");

    ASSERT_STREQ(list[0],  "apple");
    ASSERT_STREQ(list[1],  "apple");
    ASSERT_STREQ(list[2],  "banana");
    ASSERT_STREQ(list[3],  "apple");
    ASSERT_EQ(list[4], (char*) NULL);

    StringListRemove(list, "apple");

    ASSERT_STREQ(list[0],  "banana");
    ASSERT_EQ(list[1], (char*) NULL);

    StringListRemove(list, "banana");
    ASSERT_EQ(list[0], (char*) NULL);

    StringListDestroy(list);
}

TEST(StringListDestroy, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");

    StringListDestroy(list);

    ASSERT_EQ(list, (char**) NULL);
}

TEST(StringListSize, Test1) {
    char** list = NULL;
    StringListInit(list);

    ASSERT_EQ(StringListSize(list), 0);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");

    ASSERT_EQ(StringListSize(list), 3);

    StringListDestroy(list);
}


TEST(StringListIndexOf, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");

    ASSERT_EQ(StringListIndexOf(list, "apple"), 0);
    ASSERT_EQ(StringListIndexOf(list, "plum"), 1);
    ASSERT_EQ(StringListIndexOf(list, "banana"), -1);

    StringListDestroy(list);
}

TEST(StringListRemoveDuplicates, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");
    StringListAdd(list,  "banana");
    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");

    StringListRemoveDuplicates(list);

    ASSERT_STREQ(list[0], "apple");
    ASSERT_STREQ(list[1], "plum");
    ASSERT_STREQ(list[2], "banana");
    ASSERT_EQ(list[3], (char*) NULL);

    StringListDestroy(list);
}

TEST(StringListReplaceInStrings, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "apple");

    StringListReplaceInStrings(list, "apple", "banana");

    ASSERT_STREQ(list[0], "banana");
    ASSERT_STREQ(list[1], "plum");
    ASSERT_STREQ(list[2], "banana");
    ASSERT_EQ(list[3], (char*) NULL);

    // recursive case
    StringListReplaceInStrings(list, "banana", "banana");
    ASSERT_STREQ(list[0], "banana");
    ASSERT_STREQ(list[1], "plum");
    ASSERT_STREQ(list[2], "banana");
    ASSERT_EQ(list[3], (char*) NULL);

    StringListDestroy(list);
}

TEST(StringListReplaceInStrings, Test2) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apple banana apple");
    StringListAdd(list,  "plum apple banana");
    StringListAdd(list,  "apple apple apple");

    StringListReplaceInStrings(list, "apple", "banana");

    ASSERT_STREQ(list[0], "banana banana banana");
    ASSERT_STREQ(list[1], "plum banana banana");
    ASSERT_STREQ(list[2], "banana banana banana");

    StringListReplaceInStrings(list, "banana", "apple");

    ASSERT_STREQ(list[0], "apple apple apple");
    ASSERT_STREQ(list[1], "plum apple apple");
    ASSERT_STREQ(list[2], "apple apple apple");

    StringListReplaceInStrings(list, "apple", "apple cake");

    ASSERT_STREQ(list[0], "apple cake apple cake apple cake");
    ASSERT_STREQ(list[1], "plum apple cake apple cake");
    ASSERT_STREQ(list[2], "apple cake apple cake apple cake");

    StringListDestroy(list);
}

TEST(StringListSort, Test1) {
    char** list = NULL;
    StringListInit(list);

    StringListAdd(list,  "apricot");
    StringListAdd(list,  "apple");
    StringListAdd(list,  "plum");
    StringListAdd(list,  "banana");

    StringListSort(list);

    ASSERT_STREQ(list[0], "apple");
    ASSERT_STREQ(list[1], "apricot");
    ASSERT_STREQ(list[2], "banana");
    ASSERT_STREQ(list[3], "plum");
    ASSERT_EQ(list[4], (char*) NULL);

    StringListDestroy(list);
}

TEST(StressTest, Test1) {
    char** list = NULL;
    StringListInit(list);

    for(int i = 0; i < 10000; i++){
        StringListAdd(list, "apple");
    }

    ASSERT_EQ(StringListSize(list), 10000);

    for(int i = 0; i < 10000; i++){
        StringListRemove(list, "apple");
    }

    ASSERT_EQ(list[0], (char*) NULL);

    StringListDestroy(list);
}

