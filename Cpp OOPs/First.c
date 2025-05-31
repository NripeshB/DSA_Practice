#include <stdio.h>



int main() {

    int basic;
    int level;
    printf("Enter your basic pay and Job level: ");
    scanf("%d %d", &basic, &level);
    float gross;
    if(level == 1) gross = basic + (basic*25)/100 + 1000 + 500  ;
    else if(level == 2) gross = basic + (basic*25)/100 + 750 + 200  ;
    else if(level == 3) gross = basic + (basic*25)/100 + 500 + 100  ;
    else if(level == 4) gross = basic + (basic*25)/100 + 250 + 0  ;

    float net = 0;
    if(gross <= 2000) net = gross;
    else if(gross> 2000 && gross<= 4000) net = gross - (gross*3)/100;
    else if(gross> 4000 && gross<= 5000) net = gross - (gross*5)/100;
    else if(gross > 5000) net = gross- (gross*8)/100;

    printf("Your net salary is : %f", net);
    
    return 0;
}