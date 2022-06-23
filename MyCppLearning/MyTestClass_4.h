#pragma once

typedef uint16 UINT16, * PUINT16;

class MyTestClass_4
{
public:

	UINT16 MyTestUint = 4;
	UINT16 MyTestUint_2 = MyTestUint;
	const UINT16 MyTestUint_3 = MyTestUint;

	PUINT16 MyTestUintPointer = &MyTestUint;
	PUINT16 MyTestUintPointer_2 = MyTestUintPointer;
	UINT16 MyTestUintPointerValue = *MyTestUintPointer;
	PUINT16* MyTestUintPP = &MyTestUintPointer;
	
	UINT16& MyTestUintRef = MyTestUint;
	UINT16 MyTestUintPointerAddress = (UINT16)*MyTestUintPP;
};



typedef int HeapType;

typedef struct Heap
{
	HeapType* _data;

	//堆的有效元素个数
	int _size;

	//堆的容量
	int _capacity;

} Heap;

// 向下调整
void AdjustDown(HeapType* a, int n, int root);

// 向上调整
void AdjustUp(HeapType* a, int n, int root);

//交换函数
void swap(HeapType* x, HeapType* y);

//堆的初始化
void HeapInit(Heap* hp);

// 堆的构建
void HeapCreate(Heap* hp, HeapType* a, int n);

// 堆的销毁
void HeapDestory(Heap* hp);

//检查容量
void CheckCapacity(Heap* hp);

// 堆的插入
void HeapPush(Heap* hp, HeapType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HeapType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
int HeapEmpty(Heap* hp);

//打印函数
void HeapPrint(Heap* hp);

// 对数组进行堆排序
void HeapSort(HeapType* a, int n);

//打印n个数中，前k个最小的数
void PrintTopK(int* a, int n, int k);

void Mymove(HeapType& A, HeapType& B);

void TestTopk();