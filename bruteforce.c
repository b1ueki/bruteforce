#include<stdio.h>
#include<stdlib.h>

int main(){
  int mode;

  printf("password cracking for bruteforce!\n");
  printf("please select bruteforce mode\n");
  printf("1:all  2:a-z  3:0-9 >");
  scanf("%d", &mode);

  if(mode == 1)
    system("./all");
  else if(mode == 2)
    system("./a-z");
  else if(mode == 3)
    system("./0-9");

    return 0;
}
