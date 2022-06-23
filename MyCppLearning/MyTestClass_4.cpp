#include "pch.h"
#include "MyTestClass_4.h"
#include <utility>

void AdjustDown(HeapType* a, int n, int i)
{
	// ������ѭ�����Խ�С��Ϊ����
	// �Ӹ�����㿪ʼ������ø����Ⱥ��ӽ������С�Ĵ���ô�ͽ�����������㣬���������ߣ���������ѭ��
	// ѭ��һֱ�����һ����Ҷ�ӽڵ�
	while (i <= (n - 2) / 2)
	{
		int cur = 0;
		// ����� if ���ж�����ߵ����һ����Ҷ�ӽڵ㣬��ô������������Ǿ��Ǹø����Ķ��� 1 ���� 2
		if (2 * i + 2 < n)
			// ������Һ��ӣ���ô���ҳ����Һ�������С�ģ�����Ƚ�
			cur = (a[2 * i + 1] < a[2 * i + 2] ? 2 * i + 1 : 2 * i + 2);
		else
			// ���û���Һ��ӣ���ô��ֻ�����ӱȽ�
			cur = 2 * i + 1;

		// �жϸ����ͱȺ��ӽ���С��ϵ
		if (a[i] > a[cur])
		{
			// std::swap(a, a[cur]);		//ע������
			// �������ں��ӽ�㣬�ͽ���
			swap(&a[i], &a[cur]);
			// ���½ڵ�λ��
			i = cur;
		}
		else
			return;
	}
}

void AdjustUp(HeapType* a, int n, int i)
{
	//����ѭ�����Դ����õ�С�����������ϵ�����
	while (i) 
	{
		//�Ƚϵ�ǰλ��Ԫ�غ͸����Ԫ�ش�С
		if (a[i] < a[(i - 1) / 2]) 
		{
			//����������ڵ�ǰ��㣬�Ǿͽ���
			swap(a[i], a[(i - 1) / 2]);
			//�����´��Ƚ�λ��
			i = (i - 1) / 2;
		}

		//��������С�ڵ�ǰ�ڵ��ֱ�ӽ���
		else
			return;

	}
}

void swap(HeapType* x, HeapType* y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

void HeapInit(Heap* hp)
{
	//�����Ϸ��Լ���
	if (hp == NULL)
		return;

	hp->_data = nullptr;
	hp->_capacity = hp->_size = 0;
}

void HeapCreate(Heap* hp, HeapType* a, int n)
{
	// �����Ϸ��Լ���
	if (hp == NULL)
		return;

	// ��̬���������С�ռ�
	hp->_data = (HeapType*)malloc(sizeof(HeapType) * n);

	// ѭ�������ݷ������
	for (int i = 0; i < n; i++)
		hp->_data[i] = a[i];

	hp->_capacity = hp->_size = n;

	// ѭ�����µ���,ʹ�ѱ��С��
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(hp->_data, n, i);

}

void HeapDestory(Heap* hp)
{
	//�����Ϸ��Լ���
	if (hp == NULL)
		return;

	//�ͷſռ�
	free(hp->_data);

	//�������NULL,��ֹ��ΪҰָ��
	hp->_data == NULL;
}

void CheckCapacity(Heap* hp)
{
	//��ЧԪ�ص�����������˵�����ˣ���Ҫ����
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;

		//ʹ�� realloc �������пռ�����
		hp->_data = (HeapType*)realloc(hp->_data, sizeof(HeapType) * hp->_capacity);
	}
	
}

void HeapPush(Heap* hp, HeapType x)
{
	//�����Ϸ��Լ���
	if (hp == NULL)
		return;
	
	//�������
	CheckCapacity(hp);

	//β��
	hp->_data[hp->_size] = x;
	hp->_size++;

	//���ϵ���
	AdjustUp(hp->_data, hp->_size, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	//�����Ϸ��Լ��飬���Ϊ�նѣ���ôֱ�ӷ���
	if (hp == NULL || hp->_size == 0)
		return;

	//�Ѷ���βԪ�ػ���
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);

	//βɾ
	hp->_size--;

	//�Ѷ����µ���
	AdjustDown(hp->_data, hp->_size, 0);

}

HeapType HeapTop(Heap* hp)
{
	return hp->_data[0];
}

int HeapSize(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 0;

	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	if (hp == NULL || hp->_size == 0)
		return 1;

	return 0;
}

void HeapPrint(Heap* hp)
{
	//�����Ϸ��Լ���
	if (hp == NULL)
		return;
	
	//ѭ����ӡ
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_data[i]);
	}

	printf("\n");
}

void HeapSort(HeapType* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(a, n, i);
	int cur = n;

	while (--cur)
	{
		auto b = *a;
		auto c = a[cur];
		auto d = &a[cur];
		auto e = a[0];
		auto f = &a[0];
		auto g = *d;
		int& h = a[0];
		auto i = &h;

		swap(a, &a[cur]);
		swap(*a, a[cur]);
		Mymove(*a, a[cur]);
		AdjustDown(a, cur, 0);
	}
}

void PrintTopK(int* a, int n, int k)
{
	Heap hp;
	HeapInit(&hp);

	//�����ݲ������
	for (int i = 0; i < n; i++)
		HeapPush(&hp, a[i]);

	//�öѶ�Ԫ�أ�Ȼ��ɾ���Ѷ�Ԫ��
	for (int i = 0; i < k; i++) 
	{
		printf("%d\n", HeapTop(&hp));
		HeapPop(&hp);
	}
}

void Mymove(HeapType& A, HeapType& B)
{
	HeapType _Tmp = _STD move(A);
	A = _STD move(B);
	//auto a = &A;
	//auto t = _STD move(A);
	//A = B;
	A = _STD move(_Tmp);
}

void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));

	//�������10000�����������飬��֤Ԫ�ض�С��1000000
	for (size_t i = 0; i < n; ++i)
		a[i] = rand() % 1000000 + 11;

	//ȷ��10��������
	a[5] = 1;
	a[1231] = 2;
	a[531] = 3;
	a[5121] = 4;
	a[115] = 5;
	a[2335] = 6;
	a[9999] = 7;
	a[76] = 7;
	a[423] = 9;
	a[3144] = 10;



	//HeapSort(a, 5);
	PrintTopK(a, n, 12);
	//HeapSort(a, 5);
}
