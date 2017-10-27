#include <stdio.h>
#include <fcntl.h>
int main(){
  int x = open("/dev/random", O_RDONLY);
  int arr[10];
  int i;
  for (i = 0; i < 10; i++){
    int y;
    read(x,&y,4); 
    arr[i] = y;
    printf("%d\n", arr[i]);
  }
}
