#include <iostream>
#include "class_a.h"
#include <cstdlib>
#include <time.h>
#include <math.h>


int main(int argc, const char *argv[])
{
  srand(time(NULL));
  for (int i = 0; i < 1000; ++i) 
  {
    std::cout << pow(-1, rand() % 2) * (rand() % 6) << ", ";
  }
  ClassA class_a;
  std::cout << class_a.ReturnOne();
  return 0;
}
