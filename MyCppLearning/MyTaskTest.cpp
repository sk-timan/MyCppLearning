#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <ppl.h>
#include <agents.h>
#include <stdio.h>
#include <concrtrm.h>
#include <vector>

CRITICAL_SECTION cs;

using namespace ::std;
//using namespace ::std::tr1;

using namespace Concurrency;
task_group task4;
task_group task3;
task_group task2;

volatile long aa = 0; //volatile关键字可以用来提醒编译器它后面所定义的变量随时有可能改变，
volatile long bb = 0; //因此编译后的程序每次需要存储或读取这个变量的时候，都会直接从变量地址中读取数据
volatile long cc = 0;
static bool waitFor1 = true;
static bool waitFor5 = true;

#pragma optimize("", off)		//关闭所有优化
void Spin()
{
	for (int i = 0; i < 50 * 50000; ++i);
}
#pragma optimize("", on)


template<class Func>
class RunFunc						//仿函数模板，将参数包装成成员变量，类名+()用作函数(RunFunc<a,b> Func())
{									//标志：重载operator()
	Func& m_Func;
	int m_o;
public:
	RunFunc(Func& func, int o) : m_Func(func), m_o(o) {};
	
	void operator()()const
	{
		m_Func(m_o);					//执行 A 函数
		//cout << "opertator() \n";
	};
};

void T(int o)
{
	cout << "Scheduled run \n";
};

void R(int o)
{
	if (o == 2)
	{
		while (waitFor5) { ; }
		Spin();

		//use up all processors but 4 by scheduling 4 non-terminating tasks.
		int numProcsToBurn = GetProcessorCount() - 4;
		int i;
		vector<call<int>*> tasks;					//call类，在接收消息时调用指定函数
													//如果 call 对象在收到消息时正在执行工作，则会将该消息添加到队列中
													//每个 call 对象都按接收排队消息的顺序处理它们
													//调用call会发起另一个线程
		for (i = 0; i < numProcsToBurn; i++)
		{
			single_assignment<int> result;
			tasks.push_back(new call<int>([o](int i) {cout << i << "\n"; while (true)Spin();}));
			asend<int>(tasks[i], i);				//将数据异步传送到目标块
			asend<int>(result, i);
			cout << "Started task	" << tasks[i] << "\n";
			cout << "Started task	" << receive<int>(result) << "\n";
		}

		task_handle<RunFunc<decltype(T)>> t6(RunFunc<decltype(T)>(T, i + 1 + 5));
		task_handle<RunFunc<decltype(T)>> t7(RunFunc<decltype(T)>(T, i + 2 + 5));
		task_handle<RunFunc<decltype(T)>> t8(RunFunc<decltype(T)>(T, i + 3 + 5));
		task_handle<RunFunc<decltype(T)>> t9(RunFunc<decltype(T)>(T, i + 4 + 5));
		task_handle<RunFunc<decltype(T)>> t10(RunFunc<decltype(T)>(T, i + 5 + 5));
		task2.run(t6);
		task2.run(t7);
		task2.run(t8);
		task2.run(t9);
		task2.run(t10);

		//BP4 - 1 in M, 2 in R, 3 in J, 4 in R, 5 died
		DebugBreak();
	}
	else
	{
		if (o != 4)
			throw;

		task3.wait();
	}
};

void Q()
{
	//break here at the same time as N and M
	InterlockedIncrement(&cc);
	while (cc < 4) { ; }
	//task 5 dies here freeing task 4 (its parent)
	cout << "t5 dies\n";
	waitFor5 = false;
};

void P()
{
	cout << "t5 runs\n";
	Q();
};

void O(int o)
{
	task_group t5;
	t5.run(&P);
	t5.wait();
	R(o);
};

void N(int o)
{
	//breaks here at the same time as M and Q
	InterlockedIncrement(&cc);
	while (cc < 4) { ; }
	R(o);
};

void M(int o)
{
	// breaks here at the same time as N and Q
	InterlockedIncrement(&cc);
	while (cc < 3) { ; }

	//BP3 - 1 in M, 2 in N, 3 still in J, 4 in O, 5 in Q
	DebugBreak();
	InterlockedIncrement(&cc);
	while (true)
		Sleep(500); // for ever
};

void L(int oo)
{
	int temp3 = oo;

	switch (temp3)
	{
	case 1:
		M(oo);
		break;
	case 2:
		N(oo);
		break;
	case 4:
		O(oo);
		break;
	default:
		throw; //fool3
		break;
	}
}

void K(int o)
{
	//break here at the same time as E and H
	InterlockedIncrement(&bb);
	EnterCriticalSection(&cs);	//进入临界区，让每个线程按顺序访问变量.
	/**
	*	对于每个访问下面变量的操作都需要加上EnterCriticalSection(&cs),否则其他程序还是可以访问修改
	*	简单地说，对于同一个 CRITICAL_SECTION，当一个线程执行了EnterCriticalSection而
	*	没有执行LeaveCriticalSection的时候，其它任何一个线程都无法完全执行EnterCriticalSection而不得不处于等待状态
	**/
	
	while (bb < 3) { ; }

	LeaveCriticalSection(&cs);
	Spin();

	//after
	L(o);
}

void J(int o)
{
	int temp2 = o;

	switch (temp2)
	{
	case 3 :
		task4.wait();
		break;
	case 4:
		K(o);
		break;
	default:
		throw; //fool2
		break;
	}
}

static void I(int o)
{
	J(o);
}

static void H(int o)
{
	//break here at the same time as E and K
	InterlockedIncrement(&bb);
	EnterCriticalSection(&cs);				//第一次进入临界区
	while (bb < 3)
	{
		;
	}
	LeaveCriticalSection(&cs);
	Spin();

	//after
	L(o);
}

static void G(int o)
{
	H(o);
}
static void F(int o)
{
	G(o);
}

static void E(int o)
{
	// break here at the same time as H and K
	while (bb < 2)
	{
		;
	}
	//BP2 - 1 in E, 2 in H, 3 in J, 4 in K   
	Spin(); // for native case only
	DebugBreak();
	InterlockedIncrement(&bb);

	//after
	L(o);

}

static void D(int o)
{
	E(o);
}

static void C(int o)
{
	int temp = o;

	InterlockedIncrement(&aa);	//实现数的原子性加减,当前线程锁定该数，其他线程调用需等待
	while (aa < 4) { ; }

	if (temp == 1)
	{
		// BP1 - all tasks in C
 		DebugBreak();
		waitFor1 = false;
	}
	else
	{
		while (waitFor1) { ; }
	}
	switch (temp)
	{
	case 1:
		D(o);
		break;
	case 2:
		F(o);
		break;
	case 3:
	case 4:
		I(o);
		break;
	default:
		throw; //fool
		break;
	}
}

static void B(int o)
{
	C(o);
}

void A(int o)
{
	B(o);
}

void MyTaskTest()
{
	InitializeCriticalSection(&cs);

	task_group tasks;					//如果要将并行工作分解成较小的部分，
										//然后等待这些较小的部分完成，请使用任务组
										//该类表示可以等待或取消的并行工作的集合

	task_handle<RunFunc<decltype(A)>> t1(RunFunc<decltype(A)>(A, 1));	//task_handle 类表示单个并行工作项。
																		//它封装执行一项工作所需的指令和数据。

	tasks.run(t1);
	task_handle<RunFunc<decltype(A)>> t2(RunFunc<decltype(A)>(A, 2));
	task2.run(t2);
	task_handle<RunFunc<decltype(A)>> t3(RunFunc<decltype(A)>(A, 3));
	task3.run(t3);
	task_handle<RunFunc<decltype(A)>> t4(RunFunc<decltype(A)>(A, 4));
	task4.run(t4);

	getchar();	//从标准输入 stdin 获取一个字符，该函数以无符号 char 强制转换为 int 的形式返回读取的字符，
				//如果到达文件末尾或发生读错误，则返回 EOF。
}