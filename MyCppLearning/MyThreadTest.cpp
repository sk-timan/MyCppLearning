#include "pch.h"
#include <thread>
#include <iostream>
#include <vector>
#include <string>


int Threadcount = 0;

void DoSomeWork() 
{
	std::cout << "The DoSomeWork function is running on another thread."
		<< std::endl;
	int data = Threadcount++;

	//Pause for a moment to provide a delay to make threads more apparent.
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::string str = std::to_string(data);
	std::cout << "The function called by the worker thread has ended." + str
		<< std::endl;

}

void Func_ThreadTest()
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i)
	{
		threads.push_back(std::thread(DoSomeWork));
		std::cout << "The Main() thread calls this after staring the new thread"
			<< std::endl;
	}

	for (auto& thread : threads)
		thread.join();
}