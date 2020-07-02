#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

void bin2dec (char *pm, char *pn);
void bin2hex (char *pm, char *pn);
void dec2bin (char *pm, char *pn);
void dec2hex (char *pm, char *pn);
void hex2bin (char *pm, char *pn);
void hex2dec (char *pm, char *pn);

int main(void) {
  int quantidade,i,j;
  char number[32];
  char type[3];
  char n[32];
  char *pointerBin, *pointerDec, *pointerHex;
  
  scanf("%d",&quantidade);
  
  char matrizBin[quantidade][32];
  char matrizDec[quantidade][32];
  char matrizHex[quantidade][32];
  char matrizInput[quantidade][4];

  for(i=0;i<quantidade;i++){    
    scanf("%s",&number[0]);
    strcpy(n,number);    
    scanf("%s",type);        
    strcpy(matrizInput[i],type);
    if(strcmp(type,"bin")==0){
      strcpy(matrizBin[i],n);
      pointerDec = &matrizDec[i][0];
      pointerHex = &matrizHex[i][0];
      bin2dec(pointerDec,n);
      bin2hex(pointerHex,n);   
    }else{
      if(strcmp(type,"dec")==0){  
        strcpy(matrizDec[i],n);
        pointerBin = &matrizBin[i][0];
        dec2bin(pointerBin,n);
        pointerHex = &matrizHex[i][0];
        dec2hex(pointerHex,n);
      }else{
        if(strcmp(type,"hex")==0){          
          strcpy(matrizHex[i],n);
          pointerBin = &matrizBin[i][0];
          pointerDec = &matrizDec[i][0];
          hex2bin(pointerBin,n);
          hex2dec(pointerDec,n);
        }
      }
    }    
  }

  for(i=0;i<quantidade;i++){
    printf("Case %d:\n",i+1);
    if(strcmp(matrizInput[i],"bin") == 0){
      printf("%s dec\n",matrizDec[i]);
      printf("%s hex\n",matrizHex[i]);
    }

    if(strcmp(matrizInput[i],"dec") == 0){
      printf("%s hex\n",matrizHex[i]);
      printf("%s bin\n",matrizBin[i]);
    }

    if(strcmp(matrizInput[i],"hex") == 0){
      printf("%s dec\n",matrizDec[i]);
      printf("%s bin\n",matrizBin[i]);
    }
    printf("\n");    
  }
  return 0;
}

void bin2dec (char *pm, char *pn){
  int tamanho = strlen(pn);
  int x,digito, decimal=0;
  char bit;
  for (x=0;x<tamanho;x++){
    bit = pn[x];
    digito = (int)(bit) - 48;
    decimal = decimal + digito*pow(2,tamanho - (x+1));
  }
  sprintf(pm, "%d", decimal);
}

void bin2hex (char *pm, char *pn){
  int tamanho = strlen(pn);
  int x,digito, decimal=0, resto, i=0, dividendo;
  char bit, hexadecimal[32]="", hexadecimalInvert[32],d[1];
  for (x=0;x<tamanho;x++){
    bit = pn[x];
    digito = (int)(bit) - 48;
    decimal = decimal + digito*pow(2,tamanho - (x+1));
  }
  resto = decimal;
  dividendo= decimal;
  if(dividendo<16){
    if(resto<10){
      sprintf(d,"%d",resto);
      strcat(hexadecimal, d);
    }
    if(resto==10){
      strcat(hexadecimal, "A");
    }
    if(resto==11){
      strcat(hexadecimal, "B");
    }
    if(resto==12){
      strcat(hexadecimal, "C");
    }
    if(resto==13){
      strcat(hexadecimal, "D");
    }
    if(resto==14){
      strcat(hexadecimal, "E");
    }
    if(resto==15){
      strcat(hexadecimal, "F");
    }
  }else{
    while(dividendo>=16){
      resto = dividendo%16;
      dividendo=dividendo/16;
      if(resto<10){
        sprintf(d,"%d",resto);
        strcat(hexadecimal, d);
      }
      if(resto==10){
        strcat(hexadecimal, "A");
      }
      if(resto==11){
        strcat(hexadecimal, "B");
      }
      if(resto==12){
        strcat(hexadecimal, "C");
      }
      if(resto==13){
        strcat(hexadecimal, "D");
      }
      if(resto==14){
        strcat(hexadecimal, "E");
      }
      if(resto==15){
        strcat(hexadecimal, "F");
      }
    }
    sprintf(d,"%d",dividendo);
    strcat(hexadecimal, d);
  }
  tamanho = strlen(hexadecimal);
  for(x=0;x<tamanho;x++){
    hexadecimalInvert[x]=hexadecimal[tamanho-(x+1)];
  }
  hexadecimalInvert[tamanho]='\0';
  strcpy(pm, hexadecimalInvert);
}

void dec2bin (char *pm, char *pn){
  int dividendo,resto,numero=0,i;
  int tamanho = strlen(pn);
  char binario[32]="",binarioInvert[32],d[1];
  for (i=0;i<tamanho;i++){
    numero=numero+((int)(pn[i])-48)*pow(10,tamanho-(i+1));
  }
  dividendo = numero;
  if(dividendo<2){
    sprintf(binario,"%d",dividendo);
  }else{
    while(dividendo>1){
      resto=dividendo%2;
      dividendo=dividendo/2;
      sprintf(d,"%d",resto);
      strcat(binario, d);
    }
    resto=dividendo%2;
    sprintf(d,"%d",resto);
    strcat(binario, d);
  }
  tamanho = strlen(binario);
  for(i=0;i<tamanho;i++){
    binarioInvert[i]=binario[tamanho-(i+1)];
  }
  binarioInvert[tamanho]='\0';
  strcpy(pm, binarioInvert);
}

void dec2hex (char *pm, char *pn){
  int dividendo,resto,numero=0,i;
  int tamanho = strlen(pn);
  char hexadecimal[32]="",hexadecimalInvert[32],d[1];
  for (i=0;i<tamanho;i++){
    numero=numero+((int)(pn[i])-48)*pow(10,tamanho-(i+1));
  }
  resto = numero;
  dividendo= numero;
  if(dividendo<16){
    if(resto<10){
      sprintf(d,"%d",resto);
      strcat(hexadecimal, d);
    }
    if(resto==10){
      strcat(hexadecimal, "A");
    }
    if(resto==11){
      strcat(hexadecimal, "B");
    }
    if(resto==12){
      strcat(hexadecimal, "C");
    }
    if(resto==13){
      strcat(hexadecimal, "D");
    }
    if(resto==14){
      strcat(hexadecimal, "E");
    }
    if(resto==15){
      strcat(hexadecimal, "F");
    }
  }else{
    while(dividendo>=16){
      resto = dividendo%16;
      dividendo=dividendo/16;
      if(resto<10){
        sprintf(d,"%d",resto);
        strcat(hexadecimal, d);
      }
      if(resto==10){
        strcat(hexadecimal, "A");
      }
      if(resto==11){
        strcat(hexadecimal, "B");
      }
      if(resto==12){
        strcat(hexadecimal, "C");
      }
      if(resto==13){
        strcat(hexadecimal, "D");
      }
      if(resto==14){
        strcat(hexadecimal, "E");
      }
      if(resto==15){
        strcat(hexadecimal, "F");
      }
    }
    sprintf(d,"%d",dividendo);
    strcat(hexadecimal, d);
  }
  tamanho = strlen(hexadecimal);
  for(i=0;i<tamanho;i++){
    hexadecimalInvert[i]=hexadecimal[tamanho-(i+1)];
  }
  hexadecimalInvert[tamanho]='\0';
  strcpy(pm, hexadecimalInvert);
}

void hex2bin (char *pm, char *pn){
  int tamanho = strlen(pn);
  int x,digito, decimal=0;
  int dividendo,resto,i;
  char binario[32]="",binarioInvert[32],d[1];
  char bit;
  for (x=0;x<tamanho;x++){
    bit = pn[x];
    if(bit=='A'||bit=='a'){
     digito=10; 
    }
    if(bit=='B'||bit=='b'){
     digito=11; 
    }
    if(bit=='C'||bit=='c'){
     digito=12; 
    }
    if(bit=='D'||bit=='d'){
     digito=13; 
    }
    if(bit=='E'||bit=='e'){
     digito=14; 
    }
    if(bit=='F'||bit=='f'){
     digito=15; 
    }
    if(bit=='0' || bit=='1' || bit=='2' || bit=='3' || bit=='4' || bit=='5' || bit=='6' || bit=='7' || bit=='8' || bit=='9'){
      digito = (int)(bit) - 48;
    }
    decimal = decimal + digito*pow(16,tamanho - (x+1));
  }
  
  dividendo = decimal;
  if(dividendo<2){
    sprintf(binario,"%d",dividendo);
  }else{
    while(dividendo>1){
      resto=dividendo%2;
      dividendo=dividendo/2;
      sprintf(d,"%d",resto);
      strcat(binario, d);
    }
    resto=dividendo%2;
    sprintf(d,"%d",resto);
    strcat(binario, d);
  }
  tamanho = strlen(binario);
  for(i=0;i<tamanho;i++){
    binarioInvert[i]=binario[tamanho-(i+1)];
  }
  binarioInvert[tamanho]='\0';
  strcpy(pm, binarioInvert);
}

void hex2dec (char *pm, char *pn){
  int tamanho = strlen(pn);
  int x,digito, decimal=0;
  char bit;
  for (x=0;x<tamanho;x++){
    bit = pn[x];
    if(bit=='A'||bit=='a'){
     digito=10; 
    }
    if(bit=='B'||bit=='b'){
     digito=11; 
    }
    if(bit=='C'||bit=='c'){
     digito=12; 
    }
    if(bit=='D'||bit=='d'){
     digito=13; 
    }
    if(bit=='E'||bit=='e'){
     digito=14; 
    }
    if(bit=='F'||bit=='f'){
     digito=15; 
    }
    if(bit=='0' || bit=='1' || bit=='2' || bit=='3' || bit=='4' || bit=='5' || bit=='6' || bit=='7' || bit=='8' || bit=='9'){
      digito = (int)(bit) - 48;
    }
    decimal = decimal + digito*pow(16,tamanho - (x+1));
  }
  sprintf(pm, "%d", decimal);
}