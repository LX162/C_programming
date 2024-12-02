#include <stdio.h>
#include <stdlib.h>

// 动态内存分配函数声明
void demonstrateDynamicMemoryAllocation();
// 建立简单的静态链表函数声明
void createStaticLinkedList();
// 建立动态链表函数声明
struct Student *createDynamicLinkedList();
// 链表的遍历函数声明
void printLinkedList(struct Student *head);
// 释放链表空间函数声明
void freeLinkedList(struct Student *head);


// 定义结构体类型 Student
struct Student {
    long num;
    float score;
    struct Student *next;
};

// 动态内存分配
void demonstrateDynamicMemoryAllocation() {
    printf("Demonstrating dynamic memory allocation:\n");
    int *p = (int *)malloc(sizeof(int) * 5);
    if (p == NULL) {
        printf("Memory allocation failed.\n");
    } else {
        for (int i = 0; i < 5; i++) {
            p[i] = i;
        }
        for (int i = 0; i < 5; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
        free(p);
    }
}

// 建立简单的静态链表
void createStaticLinkedList() {
    printf("Creating a static linked list:\n");
    struct Student a, b, c;
    a.num = 10101; a.score = 89.5;
    b.num = 10103; b.score = 90;
    c.num = 10107; c.score = 85;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    
    struct Student *p = &a;
    while (p != NULL) {
        printf("%ld %5.1f\n", p->num, p->score);
        p = p->next;
    }
}

// 建立动态链表
struct Student *createDynamicLinkedList() {
    struct Student *head = NULL, *p1, *p2;
    p1 = p2 = (struct Student *)malloc(sizeof(struct Student));
    if (p1 == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    p1->num = 1;
    p1->score = 95;

    while (p1->num != 5) {
        if (head == NULL) {
            head = p1;
        } else {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct Student *)malloc(sizeof(struct Student));
        if (p1 == NULL) {
            printf("Memory allocation failed.\n");
            return head; // Return the partially created list
        }
        p1->num = p2->num + 1;
        p1->score = p2->score - 1;

    }
    p2->next = NULL;
    return head;
}

// 链表的遍历
void printLinkedList(struct Student *head) {
    struct Student *p = head;
    printf("Printing linked list:\n");
    while (p != NULL) {
        printf("%ld %5.1f\n", p->num, p->score);
        p = p->next;
    }
}


// 释放链表空间
void freeLinkedList(struct Student *head) {
    struct Student *p = head;
    while (p != NULL) {
        struct Student *temp = p->next;
        free(p);
        p = temp;
    }
}

int main() {
    // 1. 动态内存分配
    // 2. 链表及其操作

    // 知识点1：动态内存分配
    // demonstrateDynamicMemoryAllocation();

    // 知识点2.1. 创建静态链表
    // createStaticLinkedList();

    // // 知识点2.2. 创建动态链表
    struct Student *dynamicList = createDynamicLinkedList();

    // 知识点2.3. 打印链表
    if (dynamicList != NULL) {
        printLinkedList(dynamicList);
    }

    // // 知识点2.4. 释放动态链表
    freeLinkedList(dynamicList);

    
    return 0;
}