#include <stdio.h>




int main() {
    int num ;
    int choice = 1;
    while (choice == 1)
    {
        printf("Enter a number between 1-7: ");
    scanf("%d", &num );

    switch (num)
    {
    case 1:
        printf("Monday \n");
        break;
    
    case 2:
        printf("Tuesday\n");
        break;
    
    case 3:
        printf("Wednersday\n");
        break;
    
    case 4:
        printf("Thursday\n");
        break;
    
    case 5:
        printf("Friday\n");
        break;
    
    case 6:
        printf("Saturday\n");
        break;
    
    case 7:
        printf("Sunday\n");
        break;
    
    default:
    printf("Enter a valid number\n");
        break;
    }
    
    printf("Do you want to do it again? enter 0 for no and 1 for true : ");
    scanf("%d", &choice);

    
    } 
    
    return 0;
}