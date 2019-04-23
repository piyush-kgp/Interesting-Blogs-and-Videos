/*
Inspiration: https://www.youtube.com/watch?v=7ENFeb-J75k
Compile and run
g++ multithreading.cpp -lpthread && ./a.out
*/

#include <iostream>
#include <thread>
#include <mutex>

volatile long int a = 0;
std::mutex mtx;

void sumOne(){
  std::lock_guard<std::mutex> lock(mtx);
  for (long int i=0; i<500000; i++){
    a+=i;
  }
}

void sumTwo(){
  std::lock_guard<std::mutex> lock(mtx);
  for (long int i=500000; i<=1000000; i++){
    a+=i;
  }
}

int main(){
  std::thread t1(sumOne);
  std::thread t2(sumTwo);
  t1.join();
  t2.join();
  // for (long int i=0; i<=1000000; i++) a+=i;
  std::cout << a << std::endl;
  return 0;
}
