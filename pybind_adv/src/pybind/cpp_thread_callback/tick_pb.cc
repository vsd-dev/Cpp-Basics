#include <pybind11/pybind11.h>
#include <pybind11/chrono.h>
#include <pybind11/functional.h>
#include <pybind11/stl_bind.h>

#include <memory>

#include "cpp/cpp_thread_callback/tick.h"

namespace py = pybind11;
using namespace pybind11::literals;  // NOLINT

PYBIND11_MODULE(tick_pb, m) {
  m.doc() = "tick_pb bindings";

  py::class_<Task>(m, "Task")
    .def(py::init<const TaskCallback &>());

  py::class_<TaskRunner, std::shared_ptr<TaskRunner>>(m, "TaskRunner")
    .def(py::init<>())
    .def("push_task", [](TaskRunner &self, Task &task) {
      self.PushTask(task);
    });
}
