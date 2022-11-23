#include <stdio.h>
#include <stdlib.h>

int main(){
    char numero[10]; 
    int i,num=0,base=1,conv=0;

    printf("Inserisci il numero da convertire:");
    scanf("%s",numero);
    base = 1;
    for(i=strlen(numero)-1;i>=0;i--){
        conv = 0;
        if(numero[i]>='A' && numero[i]<='F')
        {
            conv = (numero[i] - 'A') + 10;
        }
        else{
            conv = numero[i] - '0'; 
        }
        num+= conv*base;
        base*=16; 
    }
    printf("Numero in decimale %d",num);
}