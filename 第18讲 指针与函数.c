#include <stdio.h>

// 知识点1：指针变量作为函数的参数
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("Values after swap: x = %d, y = %d\n", *x, *y);
}

// 训练代码1：通过函数交换两个整数的值
void exerciseSwap() {
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
}

// 知识点2：用数组名做函数参数
void reverseArray(int arr[], int n) {
    int temp, i, j;
    j = n - 1;
    for (i = 0; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 训练代码2：将数组中n个整数按相反顺序存放
void exerciseReverseArray() {
    int a[] = {3, 7, 9, 11, 0, 6, 7, 5, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    reverseArray(a, n);
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

// 函数声明：计算总平均分数
void calculateAverage(float *p, int n);

// 函数声明：找出并输出第n个学生的成绩
void printStudentScores(float (*p)[4], int studentNumber);

// 训练代码3: 有一个班，3个学生，各学4门课，计算总平均分数以及第n个学生的成绩。
void processStudentScores() {
    float score[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};
    calculateAverage(*score, 12); // 计算总平均成绩
    printStudentScores(score, 2);  // 输出第2个学生的成绩
}

// 函数定义：计算总平均分数
void calculateAverage(float *p, int n) {
    float sum = 0, aver;
    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }
    aver = sum / n;
    printf("average = %5.2f\n", aver);
}

// 知识点3：数组指针作为函数参数
void printStudentScores(float (*p)[4], int studentNumber) {
    int i;
    printf("The score of No.%d student are:\n", studentNumber);
    for (i = 0; i < 4; i++) {
        printf("%5.2f ", *(*(p + studentNumber - 1) + i));
    }
    printf("\n");
}


// 知识点4：指针作为函数返回值
int *max1(int *i, int *j) {
    return (*i > *j) ? i : j;
}

// 训练代码4：定义一个函数，求出两个数中的最大值，并返回其地址
void exerciseMax() {
    int a = 5, b = 10;
    int *maxValue = max1(&a, &b);
    printf("The maximum value is: %d\n", *maxValue);
}

// 知识点5：指向函数的指针
int max(int x, int y) {
    return (x > y) ? x : y;
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

// 训练代码5：输入两个整数，然后让用户选择1或2，选1时调用max函数，输出二者中的大数，选2时调用min函数，输出二者中的小数
void exerciseFunctionPointer() {
    int a = 5, b = 10, choice = 2;
    printf("Enter two integers: ");
    // scanf("%d %d", &a, &b);
    printf("Enter choice (1 for max, 2 for min): ");
    // scanf("%d", &choice);
    int (*func)(int, int) = (choice == 1) ? max : min;
    printf("Result: %d\n", func(a, b));
}

int main() {
    // 训练代码1：通过函数交换两个整数的值
    // exerciseSwap();

    // 训练代码2：将数组中n个整数按相反顺序存放
    //exerciseReverseArray();

    // 训练代码3: 有一个班，3个学生，各学4门课，计算总平均分数以及第n个学生的成绩
    // processStudentScores();

    // 训练代码4：定义一个函数，求出两个数中的最大值，并返回其地址
    // exerciseMax();

    // 训练代码5：输入两个整数，然后让用户选择1或2，选1时调用max函数，输出二者中的大数，选2时调用min函数，输出二者中的小数
    exerciseFunctionPointer();
    return 0;
}