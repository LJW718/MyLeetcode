//
// Created by Administrator on 2022/2/20.
//

#include "uthash.h"
#include <stdlib.h>   /* malloc */
#include <stdio.h>    /* printf */

// HASH_FIND_INT(g_hash, &key, temp);
// HASH_ADD_INT(g_hash, key, temp);
// HASH_ITER(hh, g_hash, s, temp);   // 遍历
// HASH_DEL(g_hash, del);      // 删除

typedef struct tagHASH_NODE {
    int key;
    int value;
    UT_hash_handle hh;
}HASH_NODE_S;

typedef struct tagHASH_TEST {
    int capacity;
    int curCnt;
}HAST_TEST;

HASH_NODE_S *g_hash = NULL;

HAST_TEST * Create(int capacity) {
    HAST_TEST *obj = (HAST_TEST *)malloc(sizeof(HAST_TEST));
    if (obj != NULL) {
        memset(obj, 0, sizeof(HAST_TEST));
        obj->capacity = capacity;
        obj->curCnt = 0;
    }
    return obj;
}

void  AddNode(HAST_TEST *obj, int key, int value) {
    if (obj == NULL) {
            return;
    }
    if (obj->curCnt < obj->capacity) {
        HASH_NODE_S *temp = NULL;
        HASH_FIND_INT(g_hash, &key, temp);
        if (temp != NULL) {
            HASH_DEL(g_hash, temp);
        }
        HASH_NODE_S *add = (HASH_NODE_S *)malloc(sizeof(HASH_NODE_S));
        if (add != NULL) {
            add->key = key;
            add->value = value;
        }
        HASH_ADD_INT(g_hash, key, add);
        obj->curCnt++;
    } else {
        printf("curCnt = %d, Capacity %d is overload \n", obj->curCnt, obj->capacity);
    }
    return;
}

int  GetNode(HAST_TEST *obj, int key) {
    if (obj == NULL) {
        return -1;
    }
    HASH_NODE_S *temp = NULL;
    HASH_FIND_INT(g_hash, &key, temp);
    if (temp == NULL) {
        return -1;
    }
    return temp->value;
}

int DelNode(HAST_TEST *obj, int key) {
    if (obj == NULL) {
        return -1;
    }
    HASH_NODE_S *del = NULL;
    HASH_FIND_INT(g_hash, &key, del);
    if (del == NULL) {
        return -1;
    }
    HASH_DEL(g_hash, del);
    obj->curCnt--;
    return 0;
}

void BianliNode() {
    HASH_NODE_S *node, *temp = NULL;
    HASH_ITER(hh, g_hash, node, temp) {
        if (node != NULL) {
           printf("key = %d, value = %d\n", node->key, node->value);
        }
    }
    return;
}

int HashTest1() {
    HAST_TEST *obj = Create(99);
    int start = 100;
    for (int i = 1; i <= 100; i++) {
        AddNode(obj, i, start);
        start += 100;
    }

    DelNode(obj, 20);
    BianliNode();
    int key = 12;
    int value = GetNode(obj, key);
    printf("key = %d, value = %d\n", key, value);
    AddNode(obj, key, 55);

    value = GetNode(obj, key);
    printf("key = %d, value = %d\n", key, value);

}


