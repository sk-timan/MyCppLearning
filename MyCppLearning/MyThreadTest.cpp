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

        threads.push_back(std::thread(doSomeWork));     //每个线程必须有一个初始函数
        std::cout << "The Main() thread calls this after starting the new thread" << std::endl;
    }

    for (auto& thread : threads)
        thread.join();      //主线程阻塞，等待子线程的结束
        
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
            do_something(i);           // 1. 潜在访问隐患：悬空引用
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    //my_thread.join();
    //my_thread.detach();          // 2. 不等待线程结束   分离线程无法找到引用对象(oops退出堆栈)
}                              // 3. 新线程可能还在运行

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) :
        t(t_)
    {}
    ~thread_guard()                     //使用 void quick_exit (int status) 函数，直接退出，不调用析构函数
    {
        if (t.joinable()) // 1
        {
            t.join();      // 2
        }
    }
    thread_guard(thread_guard const&) = delete;   // 3   拷贝构造函数和拷贝赋值操作被标记为=delete，是为了不让编译器自动生成它们
    thread_guard& operator=(thread_guard const&) = delete;    //直接对一个对象进行拷贝或赋值是危险的，因为这可能会弄丢已经加入的线程
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    do_something(2);
}    // 4          局部对象逆序销毁(栈顶)