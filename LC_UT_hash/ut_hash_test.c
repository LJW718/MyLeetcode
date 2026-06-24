//
// Created by Administrator on 2022/2/20.
//

#include "ut_hash_test.h"

/***************************************HASH INT KEY***********************************/
typedef struct
{
    int key;
    int value;
    UT_hash_handle hh; // hash handle, must exist
} HASH_INT_NODE;         // 节点

HASH_INT_NODE *g_int_hash_head = NULL; // 哈希表头

typedef struct
{
    int capacity; // 表容量
    int curCnt;   // 当前元素个数
} HASH_TEST;

// HASH_FIND_INT(g_int_hash_head, &key, temp);
// HASH_ADD_INT(g_int_hash_head, key, temp);
// HASH_ITER(hh, g_int_hash_head, s, temp);   // 遍历, hh为固定值
// HASH_DEL(g_int_hash_head, del);            // 删除

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
        HASH_INT_NODE *temp = NULL;
        HASH_FIND_INT(g_int_hash_head, &key, temp);
        if (temp != NULL)
        {
            HASH_DEL(g_int_hash_head, temp);
        }
        HASH_INT_NODE *add = (HASH_INT_NODE *)malloc(sizeof(HASH_INT_NODE));
        if (add != NULL)
        {
            add->key = key;
            add->value = value;
        }
        HASH_ADD_INT(g_int_hash_head, key, add);
        obj->curCnt++;
        LOG_DEBUG("add intkey = %d, value = %d", key, value);
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
    HASH_INT_NODE *temp = NULL;
    HASH_FIND_INT(g_int_hash_head, &key, temp);
    if (temp == NULL)
    {
        return -1;
    }
    LOG_INFO("find intkey = %d, value = %d", temp->key, temp->value);
    return temp->value;
}

int HashDelNode(HASH_TEST *obj, int key)
{
    if (obj == NULL)
    {
        return -1;
    }
    HASH_INT_NODE *del = NULL;
    HASH_FIND_INT(g_int_hash_head, &key, del);
    if (del == NULL)
    {
        return -1;
    }
    LOG_INFO("del intkey = %d, value = %d", del->key, del->value);
    HASH_DEL(g_int_hash_head, del);
    obj->curCnt--;
    return 0;
}

void HashIterNode()
{
    HASH_INT_NODE *node, *temp = NULL;
    HASH_ITER(hh, g_int_hash_head, node, temp)
    {
        if (node != NULL)
        {
            LOG_DEBUG("iter intkey = %d, value = %d", node->key, node->value);
        }
    }
}

int HashIntKeyTest()
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
    HASH_INT_NODE *cur, *tmp;
    HASH_ITER(hh, g_int_hash_head, cur, tmp)
    {
        HASH_DEL(g_int_hash_head, cur);
        free(cur);
    }
    g_int_hash_head = NULL;

    return 0;
}

/***************************************HASH STR KEY***********************************/

typedef struct
{
    char birthday[11];     // 1991-08-23
    char phone_number[12]; // 137xxxxxxxx
} PERSENAL_INFO;

typedef struct
{
    char name[20];      // key
    PERSENAL_INFO info; // value
    UT_hash_handle hh;  // hash handle, must exist
} HASH_STR_NODE;        // 节点

HASH_STR_NODE *g_str_hash_head = NULL; // 哈希表头

void HashStrNodeAdd(char *name, char *birthday, char *phone)
{
    if ((name == NULL) || (birthday == NULL) || (phone == NULL))
    {
        return;
    }
    HASH_STR_NODE *add = (HASH_STR_NODE *)malloc(sizeof(HASH_STR_NODE));
    if (add != NULL)
    {
        memset(add, 0, sizeof(HASH_STR_NODE));
        strcpy(add->name, name);
        strcpy(add->info.birthday, birthday);
        strcpy(add->info.phone_number, phone);
        HASH_ADD_STR(g_str_hash_head, name, add);
        LOG_INFO("add strkey:%s, birthday:%s, phone:%s", add->name, add->info.birthday, add->info.phone_number);
    }
}

void HashStrNodeDel(char *name)
{
    if (name == NULL)
    {
        return;
    }
    HASH_STR_NODE *del = NULL;
    HASH_FIND_STR(g_str_hash_head, name, del);
    if (del)
    {
        LOG_WARN("find strkey:%s, birthday:%s, phone:%s", del->name, del->info.birthday, del->info.phone_number);
        HASH_DEL(g_str_hash_head, del);
        LOG_WARN("del strkey:%s, birthday:%s, phone:%s", del->name, del->info.birthday, del->info.phone_number);
        free(del);
        del = NULL;
    }
}

void HashStrNodeIter(void)
{
    HASH_STR_NODE *node = NULL;
    HASH_STR_NODE *tmp_node = NULL;
    HASH_ITER(hh, g_str_hash_head, node, tmp_node)
    {
        if (node)
        {
            LOG_INFO("iter strkey:%s, birthday:%s, phone:%s", node->name, node->info.birthday, node->info.phone_number);
        }
    }
}

void HashStrKeyTest(void)
{
    HashStrNodeAdd("zhangsan", "1991-08-23", "137xxxxxxxx");
    HashStrNodeAdd("lisi", "1991-08-23", "137xxxxxxxx");
    HashStrNodeAdd("wangwu", "1991-08-23", "137xxxxxxxx");
    HashStrNodeAdd("duanyu", "1991-08-23", "137xxxxxxxx");
    HashStrNodeAdd("xuzhu", "1991-08-23", "137xxxxxxxx");
    HashStrNodeAdd("qiaofeng", "1991-08-23", "137xxxxxxxx");
    HashStrNodeDel("lisi");
    HashStrNodeIter();
    HashStrNodeAdd("zhangsan", "1991-08-23", "18702956581");
    HashStrNodeIter();

    HASH_STR_NODE *cur, *tmp;
    HASH_ITER(hh, g_str_hash_head, cur, tmp)
    {
        HASH_DEL(g_str_hash_head, cur);
        free(cur);
    }
    g_str_hash_head = NULL;
}

/***************************************HASH STR KEY***********************************/
typedef struct HASH_PTR_NODE_S
{
    void *ptrkey;       // key
    PERSENAL_INFO info; // value
    UT_hash_handle hh;  // hash handle, must exist
} HASH_PTR_NODE;        // 节点

HASH_PTR_NODE *g_ptr_hash_head = NULL; // 哈希表头

// ---------- 功能函数 ----------

/**
 * 添加节点（如果键已存在，则覆盖旧节点）
 * 返回 0 成功，-1 失败（内存分配失败）
 */
int HashPtrNodeAdd(void *key, const PERSENAL_INFO *info)
{
    if (key == NULL)
    {
        LOG_ERROR("key is NULL");
        return -1;
    }

    // 先尝试查找是否已存在，若存在则删除旧节点（可替换策略）
    HASH_PTR_NODE *existing = NULL;
    HASH_FIND_PTR(g_ptr_hash_head, &key, existing); // 注意第二个参数是 &key
    if (existing)
    {
        HASH_DEL(g_ptr_hash_head, existing);
        free(existing);
    }

    // 分配新节点
    HASH_PTR_NODE *new_node = (HASH_PTR_NODE *)malloc(sizeof(HASH_PTR_NODE));
    if (!new_node)
    {
        LOG_ERROR("malloc failed");
        return -1;
    }

    new_node->ptrkey = key;
    new_node->info = *info; // 结构体赋值

    // 添加到哈希表
    HASH_ADD_PTR(g_ptr_hash_head, ptrkey, new_node);
    LOG_INFO("add key:%p", key);
    return 0;
}

/**
 * 删除指定键的节点
 * 返回 0 成功，-1 未找到
 */
int HashPtrNodeDel(void *key)
{
    if (key == NULL)
    {
        return -1;
    }

    HASH_PTR_NODE *found = NULL;
    HASH_FIND_PTR(g_ptr_hash_head, &key, found);
    if (found)
    {
        // 从哈希表中移除
        HASH_DEL(g_ptr_hash_head, found);
        free(found);
        LOG_INFO("del key:%p", key);
        return 0;
    }
    LOG_ERROR("key:%p not found", key);
    return -1;
}

/**
 * 查找指定键的节点，返回指向其 info 的指针，若未找到返回 NULL
 */
PERSENAL_INFO *HashPtrNodeFind(void *key)
{
    if (key == NULL)
    {
        return NULL;
    }

    HASH_PTR_NODE *found = NULL;
    HASH_FIND_PTR(g_ptr_hash_head, &key, found);
    if (found)
    {
        LOG_INFO("find key:%p", key);
        return &found->info;
    }
    return NULL;
}

/**
 * 遍历所有节点，打印信息
 * 迭代器回调函数类型：参数为 (void *key, PERSENAL_INFO *info, void *userdata)
 */
typedef void (*iter_callback_t)(void *key, PERSENAL_INFO *info, void *userdata);

void HashPtrNodeIter(iter_callback_t callback, void *userdata)
{
    LOG_INFO("iter hash ptr node");
    HASH_PTR_NODE *cur, *tmp;
    HASH_ITER(hh, g_ptr_hash_head, cur, tmp)
    {
        callback(cur->ptrkey, &cur->info, userdata);
    }
}

// ---------- 示例回调（打印信息） ----------
void PrintHashNode(void *key, PERSENAL_INFO *info, void *userdata)
{
    UNUSED(userdata); // 未使用
    LOG_DEBUG("key: %p, birthday: %s, phone: %s", key, info->birthday, info->phone_number);
}

void HashPtrKeyTest(void)
{
    // 示例数据
    PERSENAL_INFO info1 = {"1991-08-23", "13712345678"};
    PERSENAL_INFO info2 = {"1995-12-01", "13898765432"};
    PERSENAL_INFO info3 = {"2000-05-15", "15911112222"};

    // 用不同变量的地址作为键
    int a = 10, b = 20, c = 30;

    // 添加三个节点
    HashPtrNodeAdd(&a, &info1);
    HashPtrNodeAdd(&b, &info2);
    HashPtrNodeAdd(&c, &info3);

    HashPtrNodeIter(PrintHashNode, NULL);

    // 查找键 &b
    LOG_INFO("find key &b:%p", (void *)&b);
    PERSENAL_INFO *found = HashPtrNodeFind(&b);
    if (found)
    {
        LOG_INFO("found: birthday=%s, phone=%s", found->birthday, found->phone_number);
    }
    else
    {
        LOG_ERROR("not found");
    }

    // 删除键 &a
    LOG_INFO("del key &a:%p", (void *)&a);
    HashPtrNodeDel(&a);

    HashPtrNodeIter(PrintHashNode, NULL);

    // 测试覆盖：用新信息替换键 &c
    PERSENAL_INFO new_info_c = {"1988-07-20", "13666668888"};
    LOG_INFO("replace key &c:%p", (void *)&c);
    HashPtrNodeAdd(&c, &new_info_c);

    HashPtrNodeIter(PrintHashNode, NULL);

    // 清理所有节点（防止内存泄漏）
    HASH_PTR_NODE *cur, *tmp;
    HASH_ITER(hh, g_ptr_hash_head, cur, tmp)
    {
        HASH_DEL(g_ptr_hash_head, cur);
        free(cur);
    }
    g_ptr_hash_head = NULL;

    return;
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

    HashIntKeyTest();

    HashStrKeyTest();

    HashPtrKeyTest();

    FUNC_EXIT();
}