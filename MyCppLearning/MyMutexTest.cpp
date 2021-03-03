#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "pch.h"


std::mutex g_mutex;         //mutex 是进程级别的互斥锁，开销较大，critical_section是线程级别的，开销较小
int g_count = 0;

void Counter()
{
    g_mutex.lock();

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

    // 前面代码如有异常，unlock 就调不到了。
    g_mutex.unlock();

}

void Counter2()
{
    // lock_guard 在构造函数里加锁，在析构函数里解锁。
    std::lock_guard<std::mutex> lock(g_mutex);

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

}

void Counter3()
{
    std::unique_lock<std::mutex> lock(g_mutex); //注意：mutex::scoped_lock 其实就是 unique_lock<mutex> 的 typedef.

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

}

int MutexTest()
{
    const std::size_t SIZE = 4;

    // 创建一组线程。
    std::vector <std::thread> v;
    v.reserve(SIZE);

    for (std::size_t i = 0; i < SIZE; ++i) 
        v.emplace_back(&Counter3);

    // 等待所有线程结束。
    for (std::thread& t: v)
        t.join();

    return 0;
}
