#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 知识点1：文件的字符串读写操作
void demonstrateStringReadWrite() {
    printf("Demonstrating file string read/write operations:\n");
    FILE *fp;
    char buffer[64];

    // 打开文件用于读取
    if ((fp = fopen("example.txt", "r")) == NULL) {
        printf("Can't open file\n");
        exit(1);
    }

    // 使用fgets读取文件内容
    while (fgets(buffer, 64, fp) != NULL) {
        printf("%s", buffer);
    }

    // 关闭文件
    fclose(fp);
}

// 知识点2：文件的格式化读写操作
void demonstrateFormattedReadWrite() {
    printf("Demonstrating file formatted read/write operations:\n");
    FILE *fp;
    char name[20];
    int age;
    float sum;

    // 打开文件用于写入
    if ((fp = fopen("datafile.txt", "w")) == NULL) {
        printf("File cannot be opened\n");
        exit(1);
    }

    // 从键盘读取学生信息并写入文件
    // printf("Type name, age, sum: ");
    // scanf("%s %d %f", name, &age, &sum);
    strcpy(name, "John");
    age = 20;
    sum = 5.5;
    fprintf(fp, "%s %d %.2f\n", name, age, sum);
    // while (strlen(name) > 1) {
    //     fprintf(fp, "%s %d %.2f\n", name, age, sum);
    //     printf("Type name, age, sum: ");
    //     scanf("%s %d %f", name, &age, &sum);
    // }

    // 关闭文件
    fclose(fp);
}

// 知识点3：以二进制方式读写文件
void demonstrateBinaryReadWrite() {
    printf("Demonstrating binary read/write operations:\n");
    FILE *fp;
    int a[5] = {1, 2, 3, 4, 5}, b[5];
    int i, size = sizeof(int);

    // 打开文件用于二进制读写
    if ((fp = fopen("demo.txt", "wb+")) == NULL) {
        printf("Cannot open file, press any key to exit!\n");
        exit(1);
    }

    // 从键盘输入数据并保存到数组a
    // for (i = 0; i < 5; i++) {
    //     scanf("%d", &a[i]);demonstrateBinaryReadWrite
    // }

    // 将数组a的内容写入到文件
    fwrite(a, size, 5, fp);

    // 将文件中的位置指针重新定位到文件开头
    rewind(fp);

    // 从文件读取内容并保存到数组b
    fread(b, size, 5, fp);

    // 在屏幕上显示数组b的内容
    for (i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // 关闭文件
    fclose(fp);
}

int main() {
    // 1. 文件的字符串读写操作
    // 2. 文件的格式化读写操作
    // 3. 以二进制方式读写文件

    // 知识点1：文件的字符串读写操作
    // demonstrateStringReadWrite();

    // 知识点2：文件的格式化读写操作
    // demonstrateFormattedReadWrite();

    // 知识点3：以二进制方式读写文件
    demonstrateBinaryReadWrite();
    return 0;
}