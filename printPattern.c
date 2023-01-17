#include <stdio.h>

int main(){
    int line = 5,i,j;
    
    printf("1\n");
    for(i=1;i<=line;i++){
        for(j=line; j>=1; j--){
            if(j>=line-(i-1)){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    printf("2\n");
    for(i=1;i<=line;i++){
        for(j=1; j<=line; j++){
            if(j>=line-(i-1)){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    printf("3\n");
    for(i=line;i>=1;i--){
        for(j=1; j<=line; j++){
            if(j>=line-(i-1)){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    printf("4\n");
    for(i=line;i>=1;i--){
        for(j=line; j>=1; j--){
            if(j>=line-(i-1)){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    printf("5\n");
    for(i=1; i<=line; i++){
        for(j=1; j<=2*line-1; j++){
            if(j>=line-(i-1) && j<=line+(i-1)){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    printf("6\n");
    for(i=line; i>=1; i--){
        for(j=1; j<=2*line-1; j++){
            if(j>=line-(i-1) && j<=line+(i-1)){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    return 0;
}