#include<stdio.h>
#include<string.h>
#define POLY 0x80F

int main(){
  char data[100];
  unsigned short crc = 0;
  
  printf("Enter the data: ");
  scanf("%s", data);

  for(int i = 0; i<strlen(data); i++){
    crc ^= (unsigned short) data[i] << 4;
    for(int j = 0; j<8; j++){
      if(crc&0x800) crc = (crc<<1) ^ POLY;
      else crc <<= 1;
    }
  }
  printf("CRC-12: %03X\n", crc&0xFFF);
  return 0;
}
