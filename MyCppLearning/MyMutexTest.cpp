#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "pch.h"


std::mutex g_mutex;         //mutex �ǽ��̼���Ļ������������ϴ�critical_section���̼߳���ģ�������С
int g_count = 0;

void Counter()
{
    g_mutex.lock();

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

    // ǰ����������쳣��unlock �͵������ˡ�
    g_mutex.unlock();

}

void Counter2()
{
    // lock_guard �ڹ��캯��������������������������
    std::lock_guard<std::mutex> lock(g_mutex);

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

}

void Counter3()
{
    std::unique_lock<std::mutex> lock(g_mutex); //ע�⣺mutex::scoped_lock ��ʵ���� unique_lock<mutex> �� typedef.

    int i = ++g_count;
    std::cout << "count: " << i << std::endl;

}

int MutexTest()
{
    const std::size_t SIZE = 4;

    // ����һ���̡߳�
    std::vector <std::thread> v;
    v.reserve(SIZE);

    for (std::size_t i = 0; i < SIZE; ++i) 
        v.emplace_back(&Counter3);

    // �ȴ������߳̽�����
    for (std::thread& t: v)
        t.join();

    return 0;
}
