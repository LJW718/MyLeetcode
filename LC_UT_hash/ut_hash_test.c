//
// Created by Administrator on 2022/2/20.
//

#include "ut_hash_test.h"

typedef struct tagHASH_NODE
{
    int key;
    int value;
    UT_hash_handle hh;      // hash handle, must exist
} HASH_NODE_S;    // 节点

typedef struct tagHASH_TEST
{
    int capacity;    // 表容量
    int curCnt;      // 当前元素个数
} HASH_TEST;

HASH_NODE_S *g_hash_head = NULL;    // 哈希表头

// HASH_FIND_INT(g_hash_head, &key, temp);
// HASH_ADD_INT(g_hash_head, key, temp);
// HASH_ITER(hh, g_hash_head, s, temp);   // 遍历, hh为固定值
// HASH_DEL(g_hash_head, del);            // 删除

HASH_TEST *HashTableCreate(int capacity)
{
    HASH_TEST *obj = (HASH_TEST *)malloc(sizeof(HASH_TEST));
    if (obj != NULL)
    {
        memset(obj, 0, sizeof(HASH_TEST));
        obj->capacity = capacity;
        obj->curCnt = 0;
        LOG_INFO("Hash table capacity = %d", capacity);
        return obj;
    }
    else
    {
        return NULL;
    }
}

void HashAddNode(HASH_TEST *obj, int key, int value)
{
    if (obj == NULL)
    {
        return;
    }
    if (obj->curCnt < obj->capacity)
    {
        HASH_NODE_S *temp = NULL;
        HASH_FIND_INT(g_hash_head, &key, temp);
        if (temp != NULL)
        {
            HASH_DEL(g_hash_head, temp);
        }
        HASH_NODE_S *add = (HASH_NODE_S *)malloc(sizeof(HASH_NODE_S));
        if (add != NULL)
        {
            add->key = key;
            add->value = value;
        }
        HASH_ADD_INT(g_hash_head, key, add);
        obj->curCnt++;
        LOG_DEBUG("add node, key = %d, value = %d", key, value);
    }
    else
    {
        LOG_INFO("curCnt = %d, Capacity %d is overload", obj->curCnt, obj->capacity);
    }
}

int HashFindNode(HASH_TEST *obj, int key)
{
    if (obj == NULL)
    {
        return -1;
    }
    HASH_NODE_S *temp = NULL;
    HASH_FIND_INT(g_hash_head, &key, temp);
    if (temp == NULL)
    {
        return -1;
    }
    LOG_INFO("find node, key = %d, value = %d", temp->key, temp->value);
    return temp->value;
}

int HashDelNode(HASH_TEST *obj, int key)
{
    if (obj == NULL)
    {
        return -1;
    }
    HASH_NODE_S *del = NULL;
    HASH_FIND_INT(g_hash_head, &key, del);
    if (del == NULL)
    {
        return -1;
    }
    LOG_INFO("delete node, key = %d, value = %d", del->key, del->value);
    HASH_DEL(g_hash_head, del);
    obj->curCnt--;
    return 0;
}

void HashIterNode()
{
    HASH_NODE_S *node, *temp = NULL;
    HASH_ITER(hh, g_hash_head, node, temp)
    {
        if (node != NULL)
        {
            LOG_DEBUG("key = %d, value = %d", node->key, node->value);
        }
    }
}

int HashTestIntKey()
{
    // 整型 key
    HASH_TEST *obj = HashTableCreate(20);
    int start = 100;
    for (int i = 1; i <= 101; i++)
    {
        HashAddNode(obj, i, start);
        start += i;
    }

    HashDelNode(obj, 20);
    HashDelNode(obj, 30);
    HashDelNode(obj, 40);
    HashDelNode(obj, 50);

    HashFindNode(obj, 12);
    HashFindNode(obj, 15);
    HashAddNode(obj, 12, 1111);
    HashAddNode(obj, 15, 2222);

    HashIterNode();
    return 0;
}

void LC_UT_Hash_Demo(void)
{
    FUNC_ENTRY();
    LOG_INFO("LC_UTHASH_DEBUG = %d", LC_UTHASH_DEBUG);
    if (!LC_UTHASH_DEBUG)
    {
        FUNC_EXIT();
        return;
    }

    HashTestIntKey();
    FUNC_EXIT();
}