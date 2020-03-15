#include "traitementvideo.hpp"
#include <stdio.h>
#include <iostream>

int main(){
  MultiTraitement t;
  t.threadAll();
  int d;
  printf("entrer un nombre pour arreter\n");
  scanf("%d",&d);
  t.stopAll();
  t.waitAll();
  exit(0);
}
