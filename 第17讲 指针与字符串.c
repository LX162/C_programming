#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 知识点1：字符串的指针表示法
void stringPointerRepresentation() {
    // 例1：定义一个字符数组，存放字符串“I love China!”并输出该字符串和第8个字符。
    char string[] = "I love China!";
    printf("%s\n", string);
    printf("%c\n", string[7]);
    
    // 例2：通过字符指针变量输出一个字符串。
    char *stringPtr = "I love China!";
    printf("%s\n", stringPtr);
    
    // 修改指针指向的字符串
    stringPtr = "I am a student.";
    printf("%s\n", stringPtr);
}

// 知识点2：将字符串a复制为字符串b，然后输出字符串b。
void copyString() {
    char a[] = "I am a student.", b[20];
    int i;
    for (i = 0; *(a + i) != '\0'; i++) {
        *(b + i) = *(a + i);
    }
    *(b + i) = '\0';
    printf("string a is: %s\n", a);
    printf("string b is: ");
    for (i = 0; b[i] != '\0'; i++) {
        printf("%c", b[i]);
    }
    printf("\n");
}

// 知识点3：用指针变量来处理字符串复制问题。
void copyStringWithPointer() {
    char a[] = "I am a student.", b[20];
    char *p1 = a, *p2 = b;
    while (*p1 != '\0') {
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';
    printf("string a is: %s\n", a);
    printf("string b is: %s\n", b);
}

// 知识点4：字符串数组
void stringArray() {
    char str_arr[5][20] = {"hello", "nice to meet you", "good morning", "ambition", "stranger"};
    int i;
    printf("char str_arr[5][20]:\n");
    for (i = 0; i < 5; i++) {
        printf("%d is: %s\n", i + 1, str_arr[i]);
    }
}

// 训练代码2：使用字符数组指针解决输出5个字符串的问题
void exerciseCharArrayPointer() {
    char (*p)[20], str_arr[5][20] = {"hello", "nice to meet you", "good morning", "ambition", "stranger"};
    p = str_arr;
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d is: %s\n", i + 1, p[i]);
    }
}

// 训练代码3：使用字符指针数组解决输出5个字符串的问题
void exerciseCharPointerArray() {
    char *ptr_arr[5], str_arr[5][20] = {"hello", "nice to meet you", "good morning", "ambition", "stranger"};
    int i;
    for (i = 0; i < 5; i++) {
        ptr_arr[i] = str_arr[i];
    }
    for (i = 0; i < 5; i++) {
        printf("%d is: %s\n", i + 1, ptr_arr[i]);
    }
}

// 训练代码4：用12个月的英文名称初始化一个字符指针数组
void exerciseMonthNames() {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int n = 5;
    printf("输入月份：");
    // scanf("%d", &n);
    if (n <= 12 && n > 0) {
        printf("%d月的英文名称是%s\n", n, months[n - 1]);
    } else {
        printf("输入的月份无效！\n");
    }
}

// 训练代码5：显示命令行上的参数
void exerciseCommandArgs(int argc, char *argv[]) {
    int i;
    printf("The program receives %d parameters:\n", argc);
    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
}

// 训练代码6：判断用户输入的是否是素数
void exerciseIsPrime(int argc, char *argv[]) {
	int isPrime(int n);
    if (argc <= 1) {
        printf("Error: no input integer!\n");
        exit(EXIT_SUCCESS);
    }
    int i, n, result;
    for (i = 1; i < argc; i++) {
        n = atoi(argv[i]);
        result = isPrime(n);
        if (result < 0) {
            printf("%3d is error.\n", n);
        } else if (result) {
            printf("%3d is prime number.\n", n);
        } else {
            printf("%3d is not prime number.\n", n);
        }
    }
}

// 判断一个数是否是素数
int isPrime(int n) {
    if (n <= 1) return -1; // 参数错误
    if (n == 2) return 1;  // 2是特例，单独处理
    if (n % 2 == 0) return 0; // 偶数不是素数
    int j = (int)sqrt(n);
    for (int i = 3; i <= j; i += 2) {
        if (n % i == 0) return 0; // 找到因子，不是素数
    }
    return 1; // 是素数
}

int main() {
	// 1. 字符串的指针表示法
	// 2. 字符串数组
	// 3. main()函数，接收控制台数据


    // 知识点1：字符串的指针表示法
    // stringPointerRepresentation();

    // 知识点2：将字符串a复制为字符串b，然后输出字符串b。
    // copyString();

    // 知识点3：用指针变量来处理字符串复制问题。
    // copyStringWithPointer();
    
    // 知识点4：字符串数组
    // stringArray();


	// 训练代码1：使用字符数组指针解决输出5个字符串的问题
    // exerciseCharArrayPointer();

    // 训练代码2：使用字符指针数组解决输出5个字符串的问题
    // exerciseCharPointerArray();

	// 训练代码3：用12个月的英文名称初始化一个字符指针数组
    // exerciseMonthNames();
    
    // 训练代码4：显示命令行上的参数
    // exerciseCommandArgs(5, (char *[5]){"show", "Java", "C++", "C#", "Kimi"});
    
    // 训练代码5：判断用户输入的是否是素数
    // exerciseIsPrime(5, (char *[5]){"show", "0", "1", "2", "3"});
    return 0;
}
