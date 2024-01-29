#include <stdio.h>
#include <stdbool.h>

bool obladi() {
  int i, j, k;
  int a = 0;

  for (i = 0; i < 10; i++)
          for (j = 0; j < 10; j++)
                  for (k = 0; k < 10; k++)
                          a += i + j + k;
}

char oohlalaaa(int f) {
  return 'c';
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("The program expects one argument\n");
    return 1;
  }
  
  if (argv[1][0] == 'A')
    printf("A\n");
  else 
    if (argv[1][0] == 'B')
      printf("B\n");
    else printf("C\n");
  
  return 0;
}
