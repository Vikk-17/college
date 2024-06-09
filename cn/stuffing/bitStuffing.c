#include<stdio.h>
#define MAX 10

int main(){

  int data[MAX], stuffed_data[2*MAX];
  int count = 0, j = 0;

  printf("Enter the data: ");
  for(int i = 0; i<MAX; i++) scanf("%d", &data[i]);
  
  for(int i = 0; i<MAX; i++){
    stuffed_data[j++] = data[i];
    if(data[i] == 1) count ++;
    else count = 0;

    if(count == 5){
      stuffed_data[j++] = 0;
      count = 0;
    }
  }
  printf("Stuffed data is: ");
  for(int i = 0; i<j; i++) printf("%d", stuffed_data[i]);
  printf("\n\n");
  return 0;
}
