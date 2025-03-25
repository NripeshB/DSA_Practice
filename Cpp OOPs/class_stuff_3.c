#include <stdio.h>
#include <math.h>

int main(){
    int a;
    int check = 0;
    printf("Enter the number you want to check. ");

    scanf("%d", &a);

    for( int i = 2 ; i<a; i++){
        if( a%i == 0){
            check = 1;
            break;
        }
        
}

    if( check == 1){
        printf("%d is not a prime number. ", a);
    }

    else{
        printf("%d is a prime number. ", a);
    }



}
