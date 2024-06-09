#include<stdio.h>

int main(){
  int sent = 0, ack, window_size;
  printf("Enter the window size: ");
  scanf("%d", &window_size);
  
  while(1){
    for(int i = 0; i<window_size; i++){
      if(sent == window_size) break;
      printf("Frame %d has been sent.\n", sent);
      sent++;
    }
    printf("Enter the last acknowledment recieved: ");
    scanf("%d", &ack);
    if(ack == window_size) break;
    else sent = ack;
  }
  return 0;
}
