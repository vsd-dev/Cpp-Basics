#!/usr/bin/env python
# -*- coding: utf-8 -*-
# pylint: disable=missing-docstring, import-error
import functools
import time

import tick_pb as tick


def _main():
  t = tick.TaskRunner()

  time.sleep(1)
  def tick_event1():
      print("one")
  def tick_event2():
      print("two")

  print("pushing one")
  t.push_task(tick.Task(lambda:print("one")))
  print("pushing two")
  t.push_task(tick.Task(lambda:print("two")))

  print("sleeping")
  time.sleep(4)


if __name__ == "__main__":
  _main()
