#include <iostream>
#include <thread>
using namespace std;
void func(int value)
{
    cout<<"ThreadID:"<<std::this_thread::get_id()<<" Threading is implementing:"<<value<<endl;
}
int main()
{
    std::thread t1(func,1);
    std::thread t2(func,2);
    std::thread t3(func,3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}


/*
Output :
ThreadID:ThreadID:ThreadID:2 Threading is implementing:1
43 Threading is implementing:2
 Threading is implementing:3


 // Explaination , here multiple Threads are running at the same time in the different core of cpu and they are doing context switching of thread also.
*/