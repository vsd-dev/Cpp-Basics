#pragma once

#include <atomic>
#include <chrono>
#include <queue>
#include <functional>
#include <limits>
#include <thread>
#include <mutex>
#include <condition_variable>


using TaskCallback = std::function<void(void)>;
class Task {
   public:
      Task(TaskCallback &&task_cb) {
        tc_ = std::move(task_cb);
      }

      Task(const TaskCallback &task_cb) {
         tc_ = task_cb;
      }
      TaskCallback tc_;
};

class TaskRunner {
 public:

  TaskRunner();
  virtual ~TaskRunner();

  void PushTask(Task& t);

 protected:

  void Start();
  void Stop();
  bool RunTask();

  void Run();

  std::atomic_bool is_running_;
  std::thread thread_;
  std::mutex mutex_;
  std::condition_variable condition_;
  std::queue<Task> queue_;
  bool ready_;
  bool processed_;

};
