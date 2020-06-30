#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main(void) {
  int quantidade,i,j;
  char number[32];
  char type[3];
  char *pointer;
  scanf("%d",&quantidade);
  
  //col(0): binary, col(1): decimal, col(2): hexadecimal, col(3): origin number
  char *matrizBin[quantidade][32];
  char *matrizDec[quantidade][32];
  char *matrizHex[quantidade][32];
  char *matrizInput[quantidade][3];

  for(i=0;i<quantidade;i++){    
    scanf("%s",number);
    scanf("%s",type);
    matrizInput[i][0]=type;
    if(strcmp(type,"bin")==0){         
      matrizBin[i][0]=number;
      //Bin2Dec(i, number);
      //Bin2Hex(i, number); 
    }               
    if(strcmp(type,"dec")==0){  
      matrizDec[i][0]=number;
      //Dec2Bin(i, number);
      //Dec2Hex(i, number); 
    }       
    if(strcmp(type,"hex")==0){
      matrizHex[i][0]=number;
      //Hex2Bin(i, number);
      //Hex2Dec(i, number);
    }    
  }
  for(i=0;i<quantidade;i++){
    printf("\nBin %d:\n",i);
    printf("%s \n",matrizBin[i][0]);
    printf("Input %d:\n",i);
    printf("%s \n",matrizInput[i][0]);    
  }  

  return 0;
}