#include <exec_2.h>
#include <lib_1.h>
#include <stdio.h>

int exec_2_main(int argc, char *argv[]) {
  printf("exec_2: %d", foo(2));
  return 0;
};