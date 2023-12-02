/*
 * @Author: RedRouge 15253476176@163.com
 * @Date: 2023-12-01 15:51:05
 * @LastEditors: RedRouge 15253476176@163.com
 * @LastEditTime: 2023-12-01 18:18:51
 * @FilePath: /03/inc/newlinklist.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __LINKLIST__H
#define __LINKLIST__H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 // 双循环链表
typedef struct DLinkNode
{
    int val;
    struct DLinkNode *prev;
    struct DLinkNode *next;
} DLink; //双向循环的

//节点初始化
int dlist_init(DLink *node, int val);
//创建节点
DLink *dlist_create(int val);
//销毁链表
int dlist_free(DLink *head);
//键盘输入
int dlist_scanf(DLink *head);
//打印输出
int dlist_printf(DLink *head);
//头插
int dlist_add_head(DLink *head, DLink *node);
//尾插
int dlist_add_tail(DLink *head, DLink *node);
//任意位置
int dlist_add_pos(DLink *head, DLink *node, int pos);
//按值寻找，找到了返回那个节点，没找到返回空
DLink *dlist_find_val(DLink *head, int val);
//按位置寻找，找到了返回那个节点，没找到返回空
DLink *dlist_find_pos(DLink *head, int pos);
//按值改变，找到了返回0，没找到返回-1
int dlist_change_pos(DLink *head, int pos, int new_val);
//按位置改变，找到了返回0，没找到返回-1
int dlist_change_val(DLink *head, int val, int new_val);
//按值删除，找到了返回0，没找到返回-1
int dlist_del_val(DLink *head, int val);
//按位置删除，找到了返回0，没找到返回-1
int dlist_del_pos(DLink *head, int pos);
//排序，0是正序，1是倒叙，3打乱排序
int dlist_sort(DLink *head, int mode);
//数值交换，为排序服务的
int dlist_swap(DLink *node1, DLink *node2);
//随机排序的函数主体
int list_random(DLink *head);



#endif



