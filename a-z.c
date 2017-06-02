#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bruteImpl(char*, int, int);
void bruteSequential(int);

static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
static const int alphabetSize = sizeof(alphabet) - 1;
char pass[];

int main()
{
  int pass_length;

  printf("please input pass_length >");
  scanf("%d", &pass_length);
  printf("please input password(up to %d characters) >", pass_length);
  scanf("%s",pass);
  bruteSequential(pass_length);
  return 0;
}

void bruteImpl(char* str, int index, int maxDepth)
{
  static int j = 0;
  for (int i = 0; i < alphabetSize; ++i)
  {
    str[index] = alphabet[i];

    if (index == maxDepth - 1){
      printf("%s  ", str);
      if(j++ % 30 == 0)
        printf("\n");
      if(!strcmp(str, pass)){
        printf("\n----------------\n");
        printf("pass is [%s]\n",str);
        printf("----------------\n");
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

