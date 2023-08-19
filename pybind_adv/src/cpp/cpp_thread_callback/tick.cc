#include "tick.h"
#include <iostream>

#include <utility>

TaskRunner::TaskRunner() {
   Start();
}

TaskRunner::~TaskRunner() {
  Stop();
}


void TaskRunner::Start() {
  if (is_running_) Stop();
  is_running_ = true;
  thread_ = std::thread(&TaskRunner::Run, this);
}

void TaskRunner::Stop() {
  if (!is_running_) return;

   {
      std::unique_lock<std::mutex> lk(mutex_);

      is_running_ = false;
   }
  condition_.notify_one();
  if (thread_.joinable()) {
    std::cout << "Stop: waiting\n";
    thread_.join();
  }
}

bool TaskRunner::RunTask() {

   std::cout << "RunTask waiting for signal\n";
   // Wait until main() sends data
   std::unique_lock<std::mutex> lk(mutex_);

   while (true) {
      if (queue_.empty()) {
         if (!is_running_) return false;
      }
      else {
         break;
      }
      condition_.wait(lk);
   }

   Task task = queue_.front();
   queue_.pop();

   std::cout << "RunTask calling callback\n";
   // call the callback in the Task
   task.tc_();

   return true;
}

void TaskRunner::PushTask(Task& task) {
   std::cout << "PushTask called\n";
   {
      std::unique_lock<std::mutex> lk(mutex_);

      queue_.push(task);
   }

   condition_.notify_one();
}

void TaskRunner::Run() {

  while (is_running_) {

     RunTask();

  }

}
