#include "pch.h"
#include "MyTestClass_4.h"
#include <utility>

void AdjustDown(HeapType* a, int n, int i)
{
	// 下面做循环，以建小堆为例；
	// 从给定结点开始，如果该父结点比孩子结点中最小的大，那么就交换这两个结点，接着向下走，否则跳出循环
	// 循环一直到最后一个非叶子节点
	while (i <= (n - 2) / 2)
	{
		int cur = 0;
		// 下面的 if 是判断如果走到最后一个非叶子节点，那么有两种情况，那就是该父结点的度是 1 还是 2
		if (2 * i + 2 < n)
			// 如果有右孩子，那么就找出左右孩子中最小的，与其比较
			cur = (a[2 * i + 1] < a[2 * i + 2] ? 2 * i + 1 : 2 * i + 2);
		else
			// 如果没有右孩子，那么就只和左孩子比较
			cur = 2 * i + 1;

		// 判断父结点和比孩子结点大小关系
		if (a[i] > a[cur])
		{
			// std::swap(a, a[cur]);		//注意区别
			// 父结点大于孩子结点，就交换
			swap(&a[i], &a[cur]);
			// 更新节点位置
			i = cur;
		}
		else
			return;
	}
}

void AdjustUp(HeapType* a, int n, int i)
{
	//下面循环是以创建好的小堆来进行向上调整的
	while (i) 
	{
		//比较当前位置元素和父结点元素大小
		if (a[i] < a[(i - 1) / 2]) 
		{
			//如果父结点大于当前结点，那就交换
			swap(a[i], a[(i - 1) / 2]);
			//并更新待比较位置
			i = (i - 1) / 2;
		}

		//如果父结点小于当前节点就直接结束
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
	//参数合法性检验
	if (hp == NULL)
		return;

	hp->_data = nullptr;
	hp->_capacity = hp->_size = 0;
}

void HeapCreate(Heap* hp, HeapType* a, int n)
{
	// 参数合法性检验
	if (hp == NULL)
		return;

	// 动态开辟数组大小空间
	hp->_data = (HeapType*)malloc(sizeof(HeapType) * n);

	// 循环将数据放入堆中
	for (int i = 0; i < n; i++)
		hp->_data[i] = a[i];

	hp->_capacity = hp->_size = n;

	// 循环向下调整,使堆变成小堆
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(hp->_data, n, i);

}

void HeapDestory(Heap* hp)
{
	//参数合法性检验
	if (hp == NULL)
		return;

	//释放空间
	free(hp->_data);

	//令其等于NULL,防止成为野指针
	hp->_data == NULL;
}

void CheckCapacity(Heap* hp)
{
	//有效元素等于容量，则说明满了，需要增容
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;

		//使用 realloc 函数进行空间增容
		hp->_data = (HeapType*)realloc(hp->_data, sizeof(HeapType) * hp->_capacity);
	}
	
}

void HeapPush(Heap* hp, HeapType x)
{
	//参数合法性检验
	if (hp == NULL)
		return;
	
	//容量检查
	CheckCapacity(hp);

	//尾插
	hp->_data[hp->_size] = x;
	hp->_size++;

	//向上调整
	AdjustUp(hp->_data, hp->_size, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	//参数合法性检验，如果为空堆，那么直接返回
	if (hp == NULL || hp->_size == 0)
		return;

	//堆顶堆尾元素互换
	swap(&hp->_data[0], &hp->_data[hp->_size - 1]);

	//尾删
	hp->_size--;

	//堆顶向下调整
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
	//参数合法性检验
	if (hp == NULL)
		return;
	
	//循环打印
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

	//将数据插入堆中
	for (int i = 0; i < n; i++)
		HeapPush(&hp, a[i]);

	//拿堆顶元素，然后删除堆顶元素
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

	//随机生成10000个数存入数组，保证元素都小于1000000
	for (size_t i = 0; i < n; ++i)
		a[i] = rand() % 1000000 + 11;

	//确定10个最大的数
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
