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

	//�ѵ���ЧԪ�ظ���
	int _size;

	//�ѵ�����
	int _capacity;

} Heap;

// ���µ���
void AdjustDown(HeapType* a, int n, int root);

// ���ϵ���
void AdjustUp(HeapType* a, int n, int root);

//��������
void swap(HeapType* x, HeapType* y);

//�ѵĳ�ʼ��
void HeapInit(Heap* hp);

// �ѵĹ���
void HeapCreate(Heap* hp, HeapType* a, int n);

// �ѵ�����
void HeapDestory(Heap* hp);

//�������
void CheckCapacity(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HeapType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HeapType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);

//��ӡ����
void HeapPrint(Heap* hp);

// ��������ж�����
void HeapSort(HeapType* a, int n);

//��ӡn�����У�ǰk����С����
void PrintTopK(int* a, int n, int k);

void Mymove(HeapType& A, HeapType& B);

void TestTopk();