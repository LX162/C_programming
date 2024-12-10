#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
typedef struct student {
    char num[6];
    char name[8];
    int score[3];
    float avr;
} Student;

// 函数声明：生成datafile.dat文件并写入字符串
void createDatafile6() {
    FILE *fp;
    const char *data = "abcdefghijk";

    // 打开文件用于写入
    if ((fp = fopen("datafile.dat", "w")) == NULL) {
        printf("File cannot be opened\n");
        exit(1);
    }

    // 写入字符串到文件
    fputs(data, fp);

    // 关闭文件
    fclose(fp);
    printf("File datafile.dat created with data '%s'\n", data);
}

// 知识点1：文件的随机读写
void randomReadWrite() {
    printf("Reading specific string from file\n");
    FILE *fp;
    char buf[20];
    // 打开文件用于读取
    if ((fp = fopen("datafile.dat", "rb")) == NULL) {
        printf("File cannot be opened\n");
        exit(1);
    }
    // 使用fseek定位并读取字符串
    fseek(fp, 5L, SEEK_SET);
    fgets(buf, 20, fp);
    printf("%s", buf);
    fclose(fp);
}

// 知识点2：文件的错误检测
void fileErrorDetection() {
    FILE *fp;
    int ch;
    int errorFlag;

    fp = fopen("datafile.dat", "r");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    // 读取文件内容
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    putchar(10);

    // 检查是否有错误发生
    errorFlag = ferror(fp);
    if (errorFlag) {
        printf("Error occurred during file read.\n");
    } else {
        printf("File read successfully.\n");
    }

    // 清除错误标志
    clearerr(fp);

    // 关闭文件
    fclose(fp);
}


// 例题1：读取和保存学生信息
void example1() {
    FILE *fp;
    Student boy;
    Student boys[3] = {
        {"123", "John", {96, 95, 94}, 95.0},
        {"456", "Tom", {86, 85, 84}, 85.0},
        {"789", "Jack", {76, 75, 74}, 75.0}
    };
    int i;
    // 打开文件用于写入
    if ((fp = fopen("demo.txt", "wb+")) == NULL) {
        printf("Cannot open file, press any key to exit!\n");
        exit(1);
    }
    // 从键盘输入学生信息
    // printf("Input data:\n");
    // for (i = 0; i < 3; i++) {
    //     scanf("%s %d %d %f", boys[i].num, &boys[i].score[0], &boys[i].score[1], &boys[i].score[2]);
    // }
    // 写入学生信息到文件
    fwrite(boys, sizeof(Student), 3, fp);
    // 移动文件指针到第二个学生信息的位置
    fseek(fp, sizeof(Student), SEEK_SET);
    // 读取第二个学生信息
    fread(&boy, sizeof(Student), 1, fp);
    printf("%s %s %d %d %d %f\n", boy.num, boy.name, boy.score[0], 
                                  boy.score[1], boy.score[2], boy.avr);
    fclose(fp);
}

// 例题2：循环读写文本文件
void example2() {
    FILE *fp;
    char choice;
    char buffer[64];

    // 打开文件用于读写
    if ((fp = fopen("datefile.txt", "a+")) == NULL) {
        printf("文件打开失败！");
        return;
    }

    do {
        printf("选择读取r，写入W，退出q：\n");
        choice = getchar();
        getchar(); // 用来消化最后输入的回车符

        if (choice == 'R' || choice == 'r') {
            rewind(fp);
            while (fgets(buffer, 64, fp) != NULL) {
                printf("%s", buffer);
            }
        } else if (choice == 'W' || choice == 'w') {
            fseek(fp, 0, SEEK_END);
            printf("请输入要存储的字符串(以#字符结束输入)：\n");
            while (fgets(buffer, 64, stdin) && strcmp(buffer, "#\n") != 0) {
                fputs(buffer, fp);
            }
        }
    } while (choice != 'Q' && choice != 'q');

    fclose(fp);
}

// 例题3：计算班级学生的平均成绩并保存到文件
void example3() {
    FILE *fp;
    Student stu[3] = {
        {"123", "John", {96, 95, 94}, 95.0},
        {"456", "Tom", {86, 85, 84}, 85.0},
        {"789", "Jack", {76, 75, 74}, 75.0}
    };
    int i, j, sum;
    fp = fopen("stud", "wb");
    for (i = 0; i < 3; i++) {
        if (fwrite(&stu[i], sizeof(Student), 1, fp) != 1) {
            printf("file write error\n");
        }
    }
    fclose(fp);
}

// 例题4：读取文件中的学生数据并显示
void example4() {
    FILE *fp;
    Student stu[3];
    int i;

    fp = fopen("stud", "rb");
    printf("\n%-6s%-8s%-8s%-8s%-8s%-8s\n", "num", "name", "score1", "score2", "score3", "avr");
    for (i = 0; i < 3; i++) {
        fread(&stu[i], sizeof(Student), 1, fp);
        printf("%-6s%-8s%-8d%-8d%-8d%-8.0f\n", stu[i].num, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].avr);
    }
    fclose(fp);
}

int main() {
    // 1. 文件的随机操作
    // 2. 文件的错误检测
    // 3. 文件应用

    // 创建 datafile.dat
    // createDatafile6();
    
    // 知识点1：文件的随机读写
    // randomReadWrite();

    // 知识点2：文件的错误检测
    // fileErrorDetection();

    // 例题1：读取和保存学生信息
    // example1();

    // 例题2：循环读写文本文件
    // example2();

    // 例题3：计算班级学生的平均成绩并保存到文件
    // example3();

    // 例题4：读取文件中的学生数据并显示
    example4();
    return 0;
}





