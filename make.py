#!/usr/bin/env python3

# I was too lazy to make a Makefile

import os
import sys
import shutil
import subprocess

CC = 'cc'
BUILD = 'build'
TEST = 'test'
SRC = 'src'
BUILD_TEST = os.path.join(BUILD, TEST)

def make_tests():
  if not os.path.exists(BUILD):
    os.mkdir(BUILD)

  if not os.path.exists(BUILD_TEST):
    os.mkdir(BUILD_TEST)

  for c_file in [os.path.join(TEST, f) for f in os.listdir(TEST) if f.endswith('.c')]:
    subprocess.call(
      [
        CC,
        '-I{}'.format(SRC),
        '-I{}'.format(TEST),
        '-Wall',
        '-Wextra',
        '-Wpedantic',
        '-Werror',
        '-std=c11',
        '-lcriterion',
        'src/argparser.c',
        c_file,
        '-o', os.path.join(BUILD_TEST, os.path.basename(c_file).split('.')[0])
      ]
    )

def run_tests():
  for test in [os.path.join(BUILD_TEST, f) for f in os.listdir(BUILD_TEST)]:
    subprocess.call([test])

def clean():
  if os.path.exists(BUILD):
    shutil.rmtree(BUILD)


if __name__ == '__main__':
  if len(sys.argv) > 1:
    if sys.argv[1] == 'clean':
      clean()
    elif sys.argv[1] == 'test':
      clean()
      make_tests()
      run_tests()

  else:
    clean()
    make_tests()
    run_tests()

