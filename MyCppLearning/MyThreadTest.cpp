#include <thread>
#include <iostream>
#include <vector>
#include <string>

int Treadcount = 0;

{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::string str = std::to_string(data);
}

{
	std::vector<std::thread> threads;

	for (int i = 0; i < 10; ++i)
	{
	}

	for (auto& thread : threads)
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