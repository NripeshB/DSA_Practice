#include <stdio.h>
#include <string.h>





int main() {
    char alpha;
    printf("Enter a character:\n ");
    scanf("%c", &alpha);
    

    // char vow[] = "aeiouAEIOU";
    // for (char i = 0; i < ; i++)
    // {
    //     if (alpha == vow[i])
    //     {
            
    //     }
        
    // }
    
   


    switch (alpha)
    {
    case  'a':
    
    
    case  'e' :
        
        
    case  'i' :
      
    
    case  'o' :
      
    
    case  'u' :
       

    case  'A':
       
    
    case  'E' :
    
       
        
    case  'I' :
       
    
    case  'O' :
       
    
    case  'U' :
       printf("It is a vowel.\n");
       break;
        
    
    
    
    default:
    printf("It is a consonant. \n");
        
    }
    return 0;
}