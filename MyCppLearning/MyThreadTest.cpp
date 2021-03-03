#include "pch.h" // Use with pre-compiled header
#include <thread>
#include <iostream>
#include <vector>
#include <string>

int Treadcount = 0;

void doSomeWork()
{
    std::cout << "The doSomeWork function is running on another thread." << std::endl;
    int data = Treadcount++;
    // Pause for a moment to provide a delay to make
    // threads more apparent.
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = std::to_string(data);
    std::cout << "The function called by the worker thread has ended. " + str << std::endl;
}

void ThreadTest()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
    {

        threads.push_back(std::thread(doSomeWork));     //ÿ���̱߳�����һ����ʼ����
        std::cout << "The Main() thread calls this after starting the new thread" << std::endl;
    }

    for (auto& thread : threads)
        thread.join();      //���߳��������ȴ����̵߳Ľ���
        
    std::cout << "MainTreadTestPass" << std::endl;
}

void do_something(int i)
{
    cout << "do something, i = " << i << endl;
}

struct func
{
    int& i;
    func(int& i_) : i(i_) {}
    void operator() ()
    {
        for (unsigned j = 0; j < 1000000; ++j)
        {
            do_something(i);           // 1. Ǳ�ڷ�����������������
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    //my_thread.join();
    //my_thread.detach();          // 2. ���ȴ��߳̽���   �����߳��޷��ҵ����ö���(oops�˳���ջ)
}                              // 3. ���߳̿��ܻ�������

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) :
        t(t_)
    {}
    ~thread_guard()                     //ʹ�� void quick_exit (int status) ������ֱ���˳�����������������
    {
        if (t.joinable()) // 1
        {
            t.join();      // 2
        }
    }
    thread_guard(thread_guard const&) = delete;   // 3   �������캯���Ϳ�����ֵ���������Ϊ=delete����Ϊ�˲��ñ������Զ���������
    thread_guard& operator=(thread_guard const&) = delete;    //ֱ�Ӷ�һ��������п�����ֵ��Σ�յģ���Ϊ����ܻ�Ū���Ѿ�������߳�
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    do_something(2);
}    // 4          �ֲ�������������(ջ��)