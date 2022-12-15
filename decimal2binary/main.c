#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,i,index;
    int binary[8];
    printf("Inserisci il numero da convertire in binario (max 255):");
    scanf("%d",&num);
    if (num > 255)
    {
        printf("Errore: il numero è troppo grande\n");
        return 0;
    }
    //inizializzo l'array di output
    for(i=0;i<8;i++){
        binary[i] = 0;
    }
 
    index = 7;
    while(num>0){
        binary[index] = num % 2;
        num = num / 2;
        index-=1;
    }
    printf("Binario:");
    for(i=0;i<8;i++){
        printf("%d",binary[i]);
    }
   

}