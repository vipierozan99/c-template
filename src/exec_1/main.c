#include <exec_1.h>
#include <lib_1.h>
#include <stdio.h>

int exec_1_main(int argc, char *argv[]) {
  printf("exec_1: %d", foo(1));
  return 0;
};