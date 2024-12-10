#include <stdio.h>
#include <stdlib.h>

// 知识点1：文件的基本知识
void basic() {
    printf("文件的基本知识：\n");
    printf("1. 文件是存储在外部介质上数据的集合。\n");
    printf("2. C语言把文件看作是一个字符（或字节）的序列。\n");
    printf("3. 标准I/O提供了四种文件存取方法：\n");
    printf("   - 每次读写一个字符\n");
    printf("   - 每次读写一个字符串\n");
    printf("   - 格式化读写\n");
    printf("   - 成块读写\n");
}

// 知识点2：打开文件
void openFile() {
    printf("打开文件演示：\n");
    FILE *fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("无法打开文件\n");
        exit(0);
    }
    fprintf(fp, "Hello, World!\n");
    fclose(fp);
}

// 知识点3：关闭文件
void closeFile() {
    printf("关闭文件演示：\n");
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("无法打开文件\n");
        exit(0);
    }
    fclose(fp);
}

// 知识点4：文件的字符读写操作
void fileCharReadWrite() {
    printf("文件的字符读写操作演示：\n");
    FILE *fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("无法打开文件\n");
        exit(0);
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

// 例题1：从键盘输入一些字符，逐个把它们送到磁盘上去，直到用户输入一个“#”为止。
void example1() {
    printf("例题1演示：\n");
    FILE *fp;
    char ch, filename[10];
    printf("请输入文件名：");
    scanf("%s", filename);
    if ((fp = fopen(filename, "w")) == NULL) {
        printf("无法打开此文件\n");
        exit(0);
    }
    printf("请输入一个字符串(以#结束)：");
    while ((ch = getchar()) != '#') {
        fputc(ch, fp);
        putchar(ch);
    }
    putchar('#');
    fclose(fp);
}

// 例题2：将一个磁盘文件中的信息复制到另一个磁盘文件中。
void example2() {
    printf("例题2演示：\n");
    FILE *in, *out;
    char ch, infile[20] = {"example.txt"}, outfile[20] = {"exa.txt"};

    printf("输入读入文件的名字：");
    printf("%s", infile);
    // scanf("%s", infile);
    printf("输入输出文件的名字：");
    printf("%s", outfile);
    // scanf("%s", outfile);
    if ((in = fopen(infile, "r")) == NULL) {
        printf("无法打开此文件\n");
        exit(0);
    }
    if ((out = fopen(outfile, "w")) == NULL) {
        printf("无法打开此文件\n");
        exit(0);
    }
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
        putchar(ch);
    }
    fclose(in);
    fclose(out);
}

int main() {
    // 1. 文件的基本知识
    // 2. 打开和关闭文件
    // 3. 文件的字符读写操作

    // 知识点1：文件的基本知识
    // basic();

    // 知识点2：打开文件
    // openFile();

    // 知识点3：关闭文件
    // closeFile();

    // 知识点4：文件的字符读写操作
    // fileCharReadWrite();

    // 例题1：从键盘输入一些字符，逐个把它们送到磁盘上去，直到用户输入一个“#”为止。
    // example1();

    // 例题2：将一个磁盘文件中的信息复制到另一个磁盘文件中。
    example2();
    return 0;
}

