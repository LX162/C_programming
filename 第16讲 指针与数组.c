#include <stdio.h>

// 知识点1：指针操作二维数组
void _2dArrayOps() {
	int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };	//按行赋值	
	printf("%p,%p,%p\n", a, a + 1, a + 2);
    // a是数组的首地址，每次加1，移动3个元素。也就说每次移动1行
	// 二维数组名是指向首行的，每次加1，移动1行
	printf("%p,%p,%p\n", *a, *(a + 1), *(a + 2));
	// a表示首行的地址，*a表示0行0列的地址
	printf("%p,%p,%p\n", a[0], a[1], a[2]);
	// a[i]和*(a+i)完全等价，表示i行0列的地址
	printf("%p,%p,%p\n", a[1], a[1]+1, a[1]+2);
	// a[i]+j表示i行j列的地址，等价于&(a[i][j])
	printf("%d,%d,%d\n", *(a[1] + 2), *(*(a + 1) + 2),a[1][2]);
  	// 获取二维数组元素的值
}

// 训练代码1：证明二维数组在内存中是按行存储的。
void verify2DArrayRowStorage() {
	int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };		//按行赋值	
	int *p;
	 int i;
	p = &a[0][0];	
	for (i = 0; i < 9; i++)
		printf("%d\n", *(p + i));
}

// 知识点2：数组指针的使用
void arrayPointer() {
	int a[2][3] = { { 1, 2, 3 }, { 4,  5, 6 } };
	int (*p)[3];		//声明一个数组指针，它是指向数据类型为int [3]的指针。
	p = a;
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			//printf("a[%d][%d]=%d\n", i, j, a[i][j]);
			printf("a[%d][%d]=%d\n", i, j, *(*(p+i)+j));	//两种写法等价
}

void pointerArray() {
	int *p[3];
	//定义一个指针数组，这个数组有3个元素，每一个元素的数据类型都是int *.
	int a = 1, b = 2, c = 3;
	p[0] = &a;		p[1] = &b;		p[2] = &c;
	printf("%d,%d,%d\n", *(p[0]), *(p[1]), *(p[2]));
	printf("%d,%d,%d\n", a, b, c);
	*(p[0]) = 100;	*(p[1]) = 200;	*(p[2]) = 300;
	printf("%d,%d,%d\n", a, b, c);
}

void _2LevelPointer() {
	int i = 10;	int *p1;		int **p2;		int ***p3;
	p1 = &i;		p2 = &p1;	p3 = &p2;
	printf("*p1=%d\n", *p1);
	printf("**p2=%d\n", **p2);
	//**p2 = 100;
	printf("***p3=%d\n", ***p3);
	printf("i=%d\n", i);
}

int main()
{	
	// 1 指针操作二维数组
	// 2 数组指针
	// 3 指针数组
	// 4 二级指针

	// 知识点1：指针操作二维数组
	// _2dArrayOps();

	// 训练代码1：证明二维数组在内存中是按行存储的。
	// verify2DArrayRowStorage();

	// 知识点2：数组指针
	// arrayPointer();

	// 知识点3：指针数组
	// pointerArray();

	// 知识点4：二级指针
	_2LevelPointer();
	return 0;
}





