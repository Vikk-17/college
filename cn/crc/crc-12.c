#include<stdio.h>
#include<string.h>
#define POLY 0x80F // 2063

int main(){
  char data[100] = "101011010110"; // '\0'
  unsigned short crc = 0;
  int n = strlen(data); // 12
  // printf("Enter the data: ");
  // scanf("%s", data);

  // handle each bit of input stream by iterating over each bit of each input byte
  for(int i = 0; i<n; i++){
    crc = crc ^ ((unsigned short) data[i] << 4);
    // crc ^= (unsigned short) data[i] << 4;
    for(int j = 0; j<8; j++){
      // Check for MSB
      // IF MSB is 1: left shift of crc by 1 and xor operation of crc and poly
      if(crc & 0x800){
       // crc = (crc<<1) ^ POLY;
       crc = crc << 1;
       crc = crc ^ POLY;
      }
      // if MSB = 0 then left shift crc by 1
      else crc = crc << 1;
    }
  }

  // 9070 => 0x236E = > 10001101101110 & 0xFFF => 00111111111111
 
  printf("CRC-12 code: %05X\n", crc&0xFFF); // 0036E
  return 0;
}

// int = %d
// float  = %f
// hex = %x(a-f) or %X(A-F)
