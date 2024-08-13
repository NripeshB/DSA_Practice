

#include<iostream>
using namespace std;

long long int floorSqrt(int n)
{
    int start = 0;
    int end = n ;
    long long int Mid = start + ((end - start)/2);
    long long int ans;

    while (start <= end) {

      if (((Mid) * (Mid)) > n ) {
        end = Mid -1;
      }

      else if(((Mid) * (Mid)) <= n){  
        ans = Mid;
        start = Mid + 1 ; }

    Mid = start + ((end - start)/2);
    }
    return ans ;
    }

double morePrecision(int prescision, int tempsol, int n ) {
    double factor = 1 ;
    double ans= tempsol;
    

    for (int i = 0; i < prescision; i++)
    {
        factor = factor / 10;
        for (double j = ans ; j*j < n; j = j+factor)
        {
            ans = j ;
        }
        
    }
    return ans;
}  

int main() {
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    int tempSol = floorSqrt(n);
    cout <<" Answer is " << morePrecision(4, tempSol, n) << endl;

    return 0;
}