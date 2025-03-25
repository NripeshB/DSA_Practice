#include <stdio.h>

int main(){

   int n; 


   printf("Enter the number n:  ");
   scanf("%d", &n );

   int ans = 0;
   int count = 0;

   while(count<=n){
      ans+=count;
      count++;
   }
   printf("The answer is :%d", ans);
    
   //  int a;
   //  int b;
   //  int c;
   //  printf("Enter the height of the rec: ");
   //  printf("Enter the height of the rec: ");
   //  scanf("%d %d %d", &a, &b ,&c);
   //  if(a>b && a>b){
   //      printf("%d is the greatest number.", a);
   //  }
   //  else if(b>a && b>c){
   //      printf("%d is the greatest number.", b);
   //  }
   //  if(c>b && c>a){
   //      printf("%d is the greatest number.", c);
   //  }
    

   //  int num;

   //  printf("Enter a number: ");
   //  scanf("%d", &num);

    // //for singular sentences we can choose to not put braces.
    // if(num%2== 0)
    //     printf("%d is an even number", num );
    
    // else
    //     printf("%d is an odd number", num );


    // int a;
    // int b;
    // int c;
    // printf("enter three numbers: ");
    // scanf("%d %d %d", &a, &b, &c);

    // if(a>b){
    //     if(a>c){
    //         printf("The gratest number is : %d", a);
    //     }
    //     else {
    //         printf("The gratest number is : %d", c);
    //     }


    // }

    // else{
    //     if( b>c){
    //         printf("The gratest number is : %d", b);

    //     }
    //     else{
    //         printf("The gratest number is : %d", c);

    //     }
    // }



    // program to print electricity bill

    /**
 * C program to calculate total electricity bill
 */



    // int unit;
    // float amt, total_amt, sur_charge;

    // /* Input unit consumed from user */
    // printf("Enter total units consumed: ");
    // scanf("%d", &unit);


    // /* Calculate electricity bill according to given conditions */
    // if(unit <= 50)
    // {
    //     amt = unit * 0.50;
    // }
    // else if(unit <= 150)
    // {
    //     amt = 25 + ((unit-50) * 0.75);
    // }
    // else if(unit <= 250)
    // {
    //     amt = 100 + ((unit-150) * 1.20);
    // }
    // else
    // {
    //     amt = 220 + ((unit-250) * 1.50);
    // }

    /*
    //  * Calculate total electricity bill
    //  * after adding surcharge
    //  */
    // sur_charge = amt * 0.20;
    // total_amt  = amt + sur_charge;

    // printf("Electricity Bill = Rs. %.2f", total_amt);

    // return 0;


 //75<  a
 //60 - 75 b
 //45 - 60  c
//  40 - 45 d
//>40 f

// int grade ;
// printf("Enter your marks from 0 to 100: ");
// scanf("%d", &grade);

// if (grade>=75){
// printf("Your grade is : A" );
// }

// else if (grade>=60 ){
// printf("Your grade is : B" );
// }

// else if (grade >= 45){
// printf("Your grade is : C" );
// }

// else if (grade>= 40){
// printf("Your grade is : D" );
// }

// else  if (grade<40){
// printf("Your grade is : F" );
// }


// for(int i =0; i<10; i++){
//     printf("Hello\nNamaste\n\");
// }


return 0;

}