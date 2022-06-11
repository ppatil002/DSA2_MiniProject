#include <stdio.h>
#include <string.h>
#include "stmr.h"
#include "demo.h"

int main(int argc, char **argv)
{
  char *word = argv[1];

  int end = stem(word, 0, strlen(word) - 1);

  word[end + 1] = 0;

  printf("%s\n", word);
  // pratik();
  // abc();
  return 0;
}
