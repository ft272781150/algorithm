/*
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>

using namespace std;

#define random(x) (rand()%x)

mutex mut;
condition_variable empty, full;
queue<int> Q;
int sum = 10;
int threadCount = 5;

void conduct()
{
	while (true)
	{
		unique_lock<mutex> lock(mut);

		int val = random(10);
		Q.push(val);
		cout << "conduct:" << val << endl;
		lock.unlock();
		full.notify_all();

		chrono::seconds ss(1);
		this_thread::sleep_for(ss);
	}
}

void consume(int id)
{
	while (true)
	{
		unique_lock<mutex> lock(mut);
		full.wait(lock);
		if (!Q.empty())
		{
			int i = Q.front();
			Q.pop();
			cout << "thread:" << id << "take:" << i << endl;
		}
		lock.unlock();
		chrono::seconds ss(1);
		this_thread::sleep_for(ss);
	}
}

int main()
{

	vector<thread> threads;
	thread t_conduct(conduct);

	for (int i = 0; i < threadCount; i++)
	{
		threads.push_back(thread(consume, i));
	}
	t_conduct.join();
	for (auto &t : threads)
	{
		t.join();
	}
}



