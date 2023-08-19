#include <iostream>
#include <chrono>
#include <thread>

#include "tick.h"

int main(int argc, char const *argv[]) {
  (void)argc;
  (void)argv;

  {
     TaskRunner tr;

     Task t1([]() {
           std::cout << "one" << std::endl;
           });
     Task t2([]() {
           std::cout << "two" << std::endl;
           });

     tr.PushTask(t1);
     tr.PushTask(t2);


     using namespace std::chrono_literals;
     std::this_thread::sleep_for(4s);
     std::cout << "done\n";
  }

  return 0;
}
