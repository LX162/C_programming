#include <stdio.h>
#include <string.h>

// 定义结构体类型 Student
struct Student {
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
};

// 知识点1：结构体与结构体变量
void demonstrateStructAndVariables() {
    // 创建结构体变量
    struct Student student1, student2;
    student1.num = 10001;
    strcpy(student1.name, "Zhang Xin");
    student1.sex = 'M';
    student1.age = 19;
    student1.score = 90.5;
    strcpy(student1.addr, "Shanghai");

    student2.num = 10002;
    strcpy(student2.name, "Wang Li");
    student2.sex = 'F';
    student2.age = 20;
    student2.score = 98;
    strcpy(student2.addr, "Beijing");

    // 打印结构体变量信息
    printf("Student 1: %s, %d, %c, %d, %.2f, %s\n", student1.name, student1.num, student1.sex, student1.age, student1.score, student1.addr);
    printf("Student 2: %s, %d, %c, %d, %.2f, %s\n", student2.name, student2.num, student2.sex, student2.age, student2.score, student2.addr);
}

// 知识点2：结构体数组
void demonstrateStructArray() {
    struct Student cls[5] = {
        {5, "Li ping", 'C', 18, 145.0, "Unknown"},
        {4, "Zhang ping", 'A', 19, 130.5, "Unknown"},
        {1, "He fang", 'A', 18, 148.5, "Unknown"},
        {3, "Wang ming", 'B', 18, 139.5, "Unknown"},
        {2, "Zhao li", 'A', 19, 142.5, "Unknown"}
    };

    // 计算全班学生的总成绩、平均成绩以及140分以下的学生人数
    int i, num_140 = 0;
    float sum = 0;
    for (i = 0; i < 5; i++) {
        sum += cls[i].score;
        if (cls[i].score < 140) num_140++;
    }
    printf("Total score: %.2f, Average score: %.2f, Number of students under 140: %d\n", sum, sum / 5, num_140);
}

// 知识点3：结构体指针
void demonstrateStructPointer() {
    struct Student stu1 = {12, "Tom", 'A', 18, 136.5, "Yiyang"};
    struct Student *pstu = &stu1;

    // 打印结构体指针指向的结构体成员信息
    printf("%s's number is %d, age is %d, score is %.1f, addr is %s!\n", pstu->name, pstu->num, pstu->age, pstu->score, pstu->addr);
}

// 例题1：计算全班学生的总成绩、平均成绩以及140分以下的学生人数
void calculateScoresSummary() {
    struct Student cls[5] = {
        {5, "Li ping", 'C', 18, 145.0, "Unknown"},
        {4, "Zhang ping", 'A', 19, 130.5, "Unknown"},
        {1, "He fang", 'A', 18, 148.5, "Unknown"},
        {3, "Wang ming", 'B', 18, 139.5, "Unknown"},
        {2, "Zhao li", 'A', 19, 142.5, "Unknown"}
    };

    int i, num_140 = 0;
    float sum = 0;
    for (i = 0; i < 5; i++) {
        sum += cls[i].score;
        if (cls[i].score < 140) num_140++;
    }
    printf("Total score: %.2f, Average score: %.2f, Number of students under 140: %d\n", sum, sum / 5, num_140);
}

int main() {
    // 1. 结构体与结构体变量
    // 2. 结构体数组
    // 3. 结构体指针

    // 知识点1：结构体与结构体变量
    // demonstrateStructAndVariables();

    // 知识点2：结构体数组
    // demonstrateStructArray();

    // 知识点3：结构体指针
    // demonstrateStructPointer();

    // 训练代码1：计算全班学生的总成绩、平均成绩以及140分以下的学生人数
    calculateScoresSummary();
    return 0;
}