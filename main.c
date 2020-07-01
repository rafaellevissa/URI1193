#include <stdio.h>
#include<stdlib.h>
#include <string.h>

char * bin2dec (char *pm, int i, char *pn);
char * bin2hex (char *pm, int i, char *pn);
char * dec2bin (char *pm, int i, char *pn);
char * dec2hex (char *pm, int i, char *pn);
char * hex2bin (char *pm, int i, char *pn);
char * hex2dec (char *pm, int i, char *pn);

int main(void) {
  int quantidade,i,j;
  char number[32];
  char n[34];
  char type[3];
  char *pointer, *pointerBin, *pointerDec, *pointerHex, *pointerNumber;
  scanf("%d",&quantidade);
  
  char matrizBin[quantidade][32];
  char matrizDec[quantidade][32];
  char matrizHex[quantidade][32];
  char matrizInput[quantidade][3];

  for(i=0;i<quantidade;i++){    
    scanf("%s",number);
    scanf("%s",type);
    pointerNumber = number;
    if(strcmp(type,"bin")==0){         
      pointer = &matrizBin[i][0];
      strcpy(pointer,number);
      pointer = &matrizInput[i][0];
      strcpy(pointer,type); 
      pointerDec = &matrizDec[i][0];
      pointerHex = &matrizHex[i][0];
      bin2dec(pointerDec,i,pointerNumber);
      bin2hex(pointerHex,i,pointerNumber);   
    }else{
      if(strcmp(type,"dec")==0){  
        pointer = &matrizDec[i][0];
        strcpy(pointer,number);
        pointer = &matrizInput[i][0];
        strcpy(pointer,type);
        pointerBin = &matrizBin[i][0];
        pointerHex = &matrizHex[i][0];
        dec2bin(pointerBin,i,pointerNumber);
        dec2hex(pointerHex,i,pointerNumber);
      }else{
        if(strcmp(type,"hex")==0){
          pointer = &matrizHex[i][0];
          strcpy(pointer,number);
          pointer = &matrizInput[i][0];
          strcpy(pointer, type);
          pointerBin = &matrizBin[i][0];
          pointerDec = &matrizDec[i][0];
          hex2bin(pointerBin,i,pointerNumber);
          hex2dec(pointerDec,i,pointerNumber);
        }
      }
    }
  }

  printf("Matriz:\n");


  return 0;
}

char * bin2dec ( char *pm, int i, char *pn){
  printf("função bin2dec\n");
  char c = 'g';
  char *p = &c;
  return p;
}

char * bin2hex (char *pm, int i, char *pn){
  printf("função bin2hex\n");
  char c = 'g';
  char *p = &c;
  return p;
}

char * dec2bin (char *pm, int i, char *pn){
  printf("função dec2bin\n");
  char c = 'g';
  char *p = &c;
  return p;
}

char * dec2hex (char *pm, int i, char *pn){
  printf("função dec2hex\n");
  char c = 'g';
  char *p = &c;
  return p;
}

char * hex2bin (char *pm, int i, char *pn){
  printf("função hex2bin\n");
  char c = 'g';
  char *p = &c;
  return p;
}

char * hex2dec (char *pm, int i, char *pn){
  printf("função hex2dec\n");
  char c = 'g';
  char *p = &c;
  return p;
}