#define _CRT_SECURE_NO_WARNINGS 1
//数组指针（指针）
#include <stdio.h>
//
//int main()
//{
//	int* p = NULL;	//p是整形指针 - 指向整形的指针 - 可以存放整形的地址
//	char* pc = NULL;	//pc是字符指针 - 指向字符的指针 - 可以存放字符的地址
//
//	//数组指针 - 指向数组的指针 - 可以存放数组的地址
//	
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };	//整型数组
//	//arr - 首元素地址
//	//&arr[0] - 首元素的地址
//	//&arr - 数组的地址
//
//	//*p指向数组；有十个元素；每个元素为int类型
//
//	int(*p)[10] = &arr;	//数组的地址要存起来
//	//上面的p就是数组的指针
//	return 0;
//}

//int main()
//{
//	char* arr[5];
//	char*(*pa)[5] = &arr;	//
//
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;	//
//	return 0;
//}

//3.2 &数组名VS数组名
// arr是数组名，数组名表示数组首元素的地址
// &arr 表示的是数组的地址，而不是数组首元素的地址
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);	//000000EEBB6FF728
//	printf("%p\n", &arr);	//000000EEBB6FF728
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);	//arr = 0000000BDAAFFAD8
//	printf("&arr= %p\n", &arr);	//&arr = 0000000BDAAFFAD8
//	printf("arr+1 = %p\n", arr + 1);	//arr+1 = 0000000BDAAFFADC----+4
//	printf("&arr+1= %p\n", &arr + 1);	//&arr+1= 0000000BDAAFFB00----+40
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", (*pa)[i]);	//1 2 3 4 5 6 7 8 9 10
//
//	//}
//
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(*pa + i));	//1 2 3 4 5 6 7 8 9 10
//	//}
//
//	//不用数组指针还简单些
//	int* p = &arr;
//	int j = 0;
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", *(p + j));	//1 2 3 4 5 6 7 8 9 10
//	}
//	return 0;
//}

//数组指针用于二维数组以上方便一些
//参数是数组的形式
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			
			printf("%d ", *(p[i] + j));//printf("%d ", *(*(p + i) + j));
			//printf("%d ", p[i][j]);
			//printf("%d ", (*(p + i))[j]);	//p+i找到那一行---*（p+i）得到那一行的数组---通过一维数组下标进行打印
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print1(arr, 3, 5);	//arr - 数组名 - 首元素地址
	/*1 2 3 4 5
	  2 3 4 5 6
	  3 4 5 6 7*/
	print2(arr, 3, 5);
	/*1 2 3 4 5
	  2 3 4 5 6
	  3 4 5 6 7*/

	//int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int i = 0;
	//int* p = &arr1;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d ", (*(p + i)));	//1 2 3 4 5 6 7 8 9 10
	//	printf("%d ", p[i]);		//1 2 3 4 5 6 7 8 9 10
	//	printf("%d ", *(arr1 + i));	//1 2 3 4 5 6 7 8 9 10
	//	printf("%d ", arr1[i]);//arr[i] == *(arr+i) == *(p+i) == p[i]
	//								//1 2 3 4 5 6 7 8 9 10
	//}
	
	return 0;
}

//
/*
int arr[5];			//arr是一个5个元素的整型数组
int *parr1[10];		//parr1是指针数组，该数组有10个元素，每个元素的类型为int*
int (*parr2)[10];	//parr2是数组指针，该指针指向了一个数组，数组有10个元素，每个元素的类型为int
int (*parr3[10])[5];//parr3是一个数组，数组有10个元素，每个元素是一个数组指针，
					  该数组指针指向的数组有5个元素，元素类型为int */
