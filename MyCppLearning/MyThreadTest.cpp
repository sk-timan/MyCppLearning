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