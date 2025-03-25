#include <stdio.h>



int main() {
    int marks[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the subject marks out of hundred for:%d ", i);
        scanf("%d", &marks[i]);
    }

    int net = 0;

    for (int i = 0; i < 5; i++)
    {
        net += marks[i];
    }
    
    printf("The sum of the marks is: %d", net);
    
    return 0;
}