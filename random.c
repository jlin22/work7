#include <stdio.h>
#include <fcntl.h>
int main(){
  int x = open("/dev/random", O_RDONLY);
  int arr1[10];
  int arr2[10];
  int i, z;
  for (i = 0; i < 10; i++){
    int y;
    read(x,&y,4); 
    arr1[i] = y;
    printf("Generating numbers: %d\n", arr1[i]);
  }
  int y = open("NewFile", O_CREAT | O_WRONLY, 0777);
  write(y, arr1, 40);
  close(y);

  y = open("NewFile", O_RDONLY);
  read(y, arr2, 40);
  close(y);
  printf("To compare the values:\n");
  for(z = 0; z < 10; z++){
    printf("Original Array: %d\n", arr1[z]);
    printf("Second Array: %d\n", arr2[z]);
  }
}
