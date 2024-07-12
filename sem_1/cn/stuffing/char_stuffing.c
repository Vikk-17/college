#include<stdio.h>
#include<string.h>

int main(){
  char del = '!', esc = '\\';
  char input_string[100], stuffed_string[100];
  int j = 0;
  printf("Enter input_string: ");
  scanf("%s", input_string);
  stuffed_string[j++] = del;
  for(int i = 0; i<strlen(input_string); i++){
    if(input_string[i] == del || input_string[i] == esc) stuffed_string[j++] = esc;
    stuffed_string[j++] = input_string[i];
  }
  stuffed_string[j++] = del;
  stuffed_string[j] = '\0';

  printf("Stuffed_string is %s\n", stuffed_string);
  return 0;
}
