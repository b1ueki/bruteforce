#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define PASS_LENGTH 4

void bruteImpl(char*, int, int);
void bruteSequential(int);

static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "0123456789";
static const int alphabetSize = sizeof(alphabet) - 1;
char pass[];

int main(void)
{
  printf("please input password(up to 4 characters) >");
  scanf("%s",pass);
  bruteSequential(PASS_LENGTH);
  return 0;
}

void bruteImpl(char* str, int index, int maxDepth)
{
  for (int i = 0; i < alphabetSize; ++i)
  {
    str[index] = alphabet[i];

    if (index == maxDepth - 1){
      printf("%s\n", str);
      if(!strcmp(str, pass)){
        printf("password is [%s]\n",str);
        exit(1);
      }
    }
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

