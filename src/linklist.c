/*
 * @Author: RedRouge 15253476176@163.com
 * @Date: 2023-11-30 19:10:28
 * @LastEditors: RedRouge 15253476176@163.com
 * @LastEditTime: 2023-12-02 13:58:03
 * @FilePath: /03/src/linklist.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "linklist.h"

int dlist_init(DLink *node, int val)
{
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return 0;
}


DLink *dlist_create(int val)
{
    DLink *node = (DLink *)malloc(sizeof(DLink));
    dlist_init(node, val);
    return node;
}

int dlist_free(DLink *head)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        free(head);
        return 0;
    }
    else if (head->next->next == NULL)
    {
        free(head->next);
        free(head);
        return 0;
    }
    DLink *cur = head->next->next, *next;
    while (cur != head->next)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(head->next);
    free(head);
    return 0;
}
int dlist_scanf(DLink *head)
{
    int data;
    printf("请输入：");
    while (scanf("%d", &data) == 1)
    {
        while (getchar() != '\n');
        dlist_add_head(head, dlist_create(data));
        printf("请输入：");
    }
    return 0;
}


int dlist_printf(DLink *head)
{
    if (head == NULL || head->next == NULL)
    {
        return -1;
    }
    else if (head->next->next == NULL)
    {

        printf("%d\n", head->next->val);
        return 0;
    }
    DLink *cur = head->next;
    do
    {
        printf("%d ", cur->val);
        cur = cur->next;
    } while (cur != head->next);
    printf("\n");
    return 0;
}


int dlist_add_head(DLink *head, DLink *node)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        head->next = node;
        node->prev = NULL;
        node->next = NULL;
        return 0;
    }
    else if (head->next->next == NULL)
    {
        head->next->next = node;
        head->next->prev = node;
        node->next = head->next;
        node->prev = head->next;
        return 0;
    }
    node->next = head->next;
    node->prev = head->next->prev;
    head->next->prev->next = node;
    head->next->prev = node;
    return 0;
}

int dlist_add_tail(DLink *head, DLink *node)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        head->next = node;
        node->prev = NULL;
        node->next = NULL;
        return 0;
    }
    else if (head->next->next == NULL)
    {
        head->next->next = node;
        head->next->prev = node;
        node->next = head->next;
        node->prev = head->next;
        head->next = node;
        return 0;
    }
    node->next = head->next;
    node->prev = head->next->prev;
    head->next->prev->next = node;
    head->next->prev = node;
    head->next = node;
    return 0;
}


int dlist_add_pos(DLink *head, DLink *node, int pos)
{
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        head->next = node;
        node->prev = NULL;
        node->next = NULL;
        return 0;
    }
    else if (head->next->next == NULL)
    {
        head->next->next = node;
        head->next->prev = node;
        node->next = head->next;
        node->prev = head->next;
        head->next = node;
    }
    DLink *cur = head->next;
    int i = 0;
    while (i < pos)
    {
        cur = cur->next;
        i++;
        if (i != 1 && cur == head->next->next)
        {
            pos -= i;
            cur = head->next;
            i = 0;
        }
    }
    // 再cur的前边插入
    node->next = cur;
    node->prev = cur->prev;
    cur->prev->next = node;
    cur->prev = node;
    if (pos == 0)
        head->next = node;
    return 0;
}


DLink *dlist_find_val(DLink *head, int val)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    else if (head->next->next == NULL)
    {
        if (head->next->val == val)
            return head->next;
        else
            return NULL;
    }
    if (head->next->val == val)
        return head->next;
    DLink *cur = head->next->next;
    while (cur != head->next)
    {
        if (cur->val == val)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
DLink *dlist_find_pos(DLink *head, int pos)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    else if (head->next->next == NULL && pos == 0)
    {
        return head->next;
    }
    if (pos == 0)
        return head->next;
    DLink *cur = head->next->next;
    int i = 1;
    while (i < pos)
    {
        cur = cur->next;
        i++;
    }
    return cur;
}

int dlist_change_pos(DLink *head, int pos, int new_val)
{
    if (head == NULL || head->next == NULL)
    {
        return -1;
    }
    DLink *cur = dlist_find_pos(head, pos);
    if (cur == NULL)
        return -1;
    cur->val = new_val;
    return 0;
}

int dlist_change_val(DLink *head, int val, int new_val)
{
    if (head == NULL || head->next == NULL)
    {
        return -1;
    }
    DLink *cur = dlist_find_val(head, val);
    if (cur == NULL)
        return -1;
    cur->val = new_val;
    return 0;
}

int dlist_del_val(DLink *head, int val)
{
    if (head == NULL || head->next == NULL)
    {
        return -1;
    }
    else if (head->next->next == NULL)
    {
        if (head->next->val == val)
        {
            free(head->next);
            head->next = NULL;
            return 0;
        }
        else
            return -1;
    }
    else if (head->next->next->val == val && head->next->next == head->next->prev && head->next->next != NULL)
    {
        free(head->next->next);
        head->next->next = NULL;
        head->next->prev = NULL;
        return 0;
    }
    DLink *cur = dlist_find_val(head, val);
    if (cur == NULL)
    {
        return -1;
    }
    else if (cur == head->next)
    {
        head->next = cur->next;
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        free(cur);
    }
    else
    {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        free(cur);
    }
    if (head->next->next == head->next)
    {
        head->next->next = NULL;
        head->next->prev = NULL;
    }
    return 0;
}
//按位置删除，找到了返回0，没找到返回-1
int dlist_del_pos(DLink *head, int pos)
{
    if (head == NULL || head->next == NULL)
    {
        return -1;
    }
    else if (head->next->next == NULL && pos == 0)
    {
        free(head->next);
        head->next = NULL;
        return 0;
    }
    else if (pos == 1 && head->next->next == head->next->prev && head->next->next != NULL)
    {
        free(head->next->next);
        head->next->next = NULL;
        head->next->prev = NULL;
        return 0;
    }
    DLink *cur = dlist_find_pos(head, pos);
    if (cur == NULL)
    {
        return -1;
    }
    else if (cur == head->next)
    {
        head->next = cur->next;
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        free(cur);
    }
    else
    {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        free(cur);
    }
    if (head->next->next == head->next)
    {
        head->next->next = NULL;
        head->next->prev = NULL;
    }
    return 0;
}


int dlist_sort(DLink *head, int mode)
{
    if (head == NULL || head->next == NULL || mode < 0 || mode > 2 || head->next->next == NULL)
    {
        return -1;
    }
    if (mode == 2)
    {
        list_random(head); //对这个双向链表随机排序
        return 0;
    }
    DLink *cur = head->next;
    do
    {
        DLink *next = cur->next;
        while (next != head->next)
        {
            if (mode == 0 ? (cur->val > next->val) : (cur->val < next->val))
                dlist_swap(cur, next);
            next = next->next;
        }
        cur = cur->next;
    } while (cur != head->next);
    return 0;
}

int dlist_swap(DLink *node1, DLink *node2)
{
    if (node1 == NULL || node2 == NULL)
    {
        return -1;
    }
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
    return 0;
}

int list_random(DLink *head)
{
    int len = 0;
    DLink *cur = head->next;
    do
    {
        len++;
        cur = cur->next;
    } while (cur != head->next);
    if (len == 0)
        return -1;
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++)
    {
        int rand_num = rand() % len;
        cur = head->next;
        for (int j = 0; j < rand_num; j++)
        {
            cur = cur->next;
        }
        dlist_swap(head->next, cur);
    }
    return 0;
}





