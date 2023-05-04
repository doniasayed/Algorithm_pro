#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size of the array \n");
    scanf("%d",&size);
    int x[size] ;
    int y[size];
   int number, postive =0,negative =0 ,i;
    printf("Enter the Elements of the array\n");
    for( i=0;i<size;i++){
    scanf("%d",&number);
        if(number >0)
        y[postive++]=number;
        else
        x[negative++]=number;
    }
    for( i=0;i<postive;i++){
        x[i+negative]=y[i];
    }
    for( i=0;i<size;i++){
        printf("%d ",x[i]);
    }
}
