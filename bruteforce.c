#include<stdio.h>

#define PASS_LENGTH 6

void bruteImpl(char*, int, int);
void bruteSequential(int);

static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "0123456789";
static const int alphabetSize = sizeof(alphabet) - 1;

int main(void)
{
  bruteSequential(6);
  return 0;
}

void bruteImpl(char* str, int index, int maxDepth)
{
  for (int i = 0; i < alphabetSize; ++i)
  {
    str[index] = alphabet[i];

    if (index == maxDepth - 1) printf("%s\n", str);
    else bruteImpl(str, index + 1, maxDepth);
  }
}

void bruteSequential(int maxLen)
{
  char* buf = malloc(maxLen + 1);

  for (int i = 1; i <= maxLen; ++i)
  {
    memset(buf, 0, maxLen + 1);
    bruteImpl(buf, 0, i);
  }

  free(buf);
}

