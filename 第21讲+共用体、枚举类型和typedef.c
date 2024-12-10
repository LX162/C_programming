#include <stdio.h>
#include <string.h>

// 定义共用体类型
union Category {
    int clas;
    char position[10];
};

// 定义结构体类型
typedef struct {
    int num;
    char name[10];
    char sex;
    char job;
    union Category category;
} Person;

// 定义枚举类型
typedef enum {
    Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun
} Weekday;

// 使用typedef为类型起别名
typedef int INTEGER;
typedef char ARRAY20[20];
typedef struct {
    int month;
    int day;
    int year;
} Date;
typedef int (*PTR_TO_ARR)[4];
typedef int (*PTR_TO_FUNC)(int, int);

// 知识点1：共用体类型定义和使用
void demonstrateUnion() {
    union Category cat;
    cat.clas = 101;
    printf("Class: %d\n", cat.clas);
    strcpy(cat.position, "Professor");
    printf("Position: %s\n", cat.position);
}

// 知识点2：枚举类型定义和使用
void demonstrateEnum() {
    Weekday day;
    printf("Input week: ");
    // scanf("%d", &day);
    day = 2;
    switch (day) {
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Invalid day");
    }
}

int max(int a, int b) {
        return a > b ? a : b;
}

// 知识点3：typedef的使用
void demonstrateTypedef() {
    INTEGER a = 1;
    INTEGER b = 2;
    printf("INTEGER a = %d, b = %d\n", a, b);

    ARRAY20 arr = "Hello, world!";
    printf("ARRAY20 arr = %s\n", arr);

    Date birthday = {1, 1, 2022};
    printf("Date birthday = {%d, %d, %d}\n", birthday.month, birthday.day, birthday.year);

    int arr2[4] = {1, 2, 3, 4};
    PTR_TO_ARR pArr = &arr2;
    printf("PTR_TO_ARR pArr = {%d, %d, %d, %d}\n", (*pArr)[0], (*pArr)[1], (*pArr)[2], (*pArr)[3]);

    PTR_TO_FUNC pFunc = max;
    printf("PTR_TO_FUNC pFunc result = %d\n", pFunc(3, 5));
}

// 例题1：使用共用体处理不同类别的数据
void processPersonData() {
    Person person[2] = {
        {101, "Li", 'M', 's', {501}},
        {102, "Wang", 'F', 't', {.position="Changsha"}}
    };
    for (int i = 0; i < 2; i++) {
        if (person[i].job == 's') {
            printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name,
                   person[i].sex, person[i].job, person[i].category.clas);
        } else {
            printf("%-6d%-10s%-4c%-4c%-10s\n", person[i].num, person[i].name,
                   person[i].sex, person[i].job, person[i].category.position);
        }
    }
}

int main() {
    // 1. 共用体
    // 2. 枚举类型
    // 3. typedef

    // 知识点1：共用体类型定义和使用
    // demonstrateUnion();

    // 知识点2：枚举类型定义和使用
    // demonstrateEnum();

    // 知识点3：typedef的使用
    // demonstrateTypedef();

    // 例题1：使用共用体处理不同类别的数据
    // processPersonData();
    return 0;
}