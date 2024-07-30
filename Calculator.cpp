#include <iostream>
#include <cmath>
using namespace std;
const double pi = std::acos(-1);
//adding a comment

class SimpleOp{
    protected:
    float a1, b1;
    public:
    void assign1(){
        cout<<"Enter the First number:"<<endl;
        cin>> a1;
        cout<<"Enter the Second number:"<<endl;
        cin>> b1;
    }
    float operations1(){
        string s;
        cout<<"type +, -, *, /, for respective operations"<< endl;
        cin>>s;
        if (s == "+"){
        cout<<"The answer is: "<< endl;
        cout<<float(a1+b1)<<endl;
        }
        else if (s == "-"){
        cout<<"The answer is: "<< endl;
        cout<<float(a1-b1)<<endl;
        }
        else if (s == "*"){
        cout<<"The answer is: "<< endl;
        cout<<float(a1*b1)<<endl;
        }
        else if (s == "/"){
        cout<<"The answer is: "<< endl;
        cout<<(float(a1/b1))<<endl;
        }
        else{
            cout<<"Invalid operation. "<< endl;
        }
        

    }
    
};


class TrigoCalc{
    protected:
    double a2;
    public:
    void assign2(){
        string check;
        cout<< "If you want to enter radians type Ri, and if in the form of pi/x, type Pi: "<<endl;
        cin>> check;
        if (check =="Ri"){
        cin>> a2;}
        else if (check == "Pi"){
            float num;
            cout<< "Enter the x in pi/x: "<<endl;
            cin>>num;
            a2 = pi/num;
        }
        else{
            cout<<"Invalid option:"<<endl;
        }
        }


    void operations2(){
        string si;
        cout<<"To calculate trigonometric operations type: sin, cos, tan, cosc, sec, cot:  "<<endl ;
        cin >> si;
        if (si== "sin"){
            if( double(sin(a2)) > 1.0e+016){
                cout<<"It is not defined."<<endl;
            }
            else if (double(sin(a2)) < 7.0e-017){
                cout<<"The value is 0 "<<endl;}

            else{
            cout<<"The answer is: "<<endl;
            cout<< double(sin(a2))<<endl;}
        }
        else if (si == "cos"){
            if( double(cos(a2)) > 1.0e+016){
                cout<<"It is not defined."<<endl;
            }
            else if (double(cos(a2)) < 7.0e-017){
                cout<<"The value is 0 "<<endl;
            }
            else{
            cout<<"The answer is: "<<endl;
            cout<<double(cos(a2))<<endl;}
        }
        else if (si == "tan"){
            if( double(tan(a2)) > 1.0e+016){
                cout<<"It is not defined."<<endl;
            }
            else if (double(tan(a2)) < 7.0e-017){
                cout<<"The value is 0 "<<endl;
            }
            else{
            cout<<"The answer is: "<<endl;
            cout<<double(tan(a2))<<endl;}
        }
        else if (si == "cosc"){
            if( double(1/(sin(a2))) > 1.0e+016){
                cout<<"It is not defined."<<endl;
            }
            else if (double(1/(sin(a2))) < 7.0e-017){
                cout<<"The value is 0 "<<endl;
            }
            else{
            cout<<"The answer is: "<<endl;
            cout<<double(1/(sin(a2)))<<endl;}
        }
        else if (si == "sec"){
            if( double(1/(cos(a2))) > 1.0e+016){
                cout<<"It is not defined."<<endl;
            }
            else if (double(1/(cos(a2))) < 7.0e-017){
                cout<<"The value is 0 "<<endl;
            }
            else{
            cout<<"The answer is: "<<endl;
            cout<<double(1/(cos(a2)))<<endl;}
        }
        else if (si == "cot"){
            if( double(1/(tan(a2))) > 1.0e+016){
                cout<<"It is not defined."<<endl;
            }
            else if (double(1/(tan(a2))) < 7.0e-017){
                cout<<"The value is 0 "<<endl;
            }
            else{
            cout<<"The answer is: "<<endl;
            cout<<double (1/(tan(a2)))<<endl;}
        }
        else{
            cout<<"Invalid operation."<< endl;
        }  
        }

};

int Factorial(int);

class CompleteCalc : public TrigoCalc, public SimpleOp{
    protected:
    
    public:
    void operations3(){
        string ask;
        cout<<"This function can calculate factorials, exponents, logarithms and powers."<<endl
        << "For Factorials --> Fac \n For Exponents --> Exp \n For Logarithms --> Log \n For Powers --> Pow"<<endl;
        cin>>ask;


        if (ask == "Fac"){
            int Fac;
            int ans;
            cout<<"Enter the number you want to find the factorial of. "<< endl;
            cin>>Fac;
            ans = Factorial(Fac);
            cout<<"The Factorial of "<< Fac<< " is "<< ans<< endl;
               
        }
        else if (ask == "Exp"){
            double Exp;
            cout<<"Enter the x in e^x :"<< endl;
            cin>> Exp;
            cout <<"The eponentiation of "<< Exp << " is "<< double(exp(Exp))<< endl;
        }
        else if (ask == "Log"){
            double Log;
            cout<<"Enter the x in lnx :"<< endl;
            cin>> Log;
            cout <<"The natural Log of "<< Log << " is "<< double(log(Log))<< endl;
        }   
        else if (ask == "Pow"){
            int x;
            float y;
            cout<<"Enter the number you want to raise to a certain power."<<endl;
            cin>>y;
            cout<<"Enter the power you want to raise "<<y <<" by "<<endl;
            cin>>x;
            cout << y <<" raised to the power of "<< x<< " is "<< pow(y,x) <<endl;
        }
        else{
            cout<<"Invalid operation. "<<endl;
        }


    }
    

};   

int Factorial(int a){
    
    if(a <= 1){
        return 1;
    }
    return a*Factorial(a-1);
    
}




int main(){
    CompleteCalc Opp;

    Opp.assign1();
    Opp.operations1();
    Opp.operations1();
    Opp.operations1();
    Opp.operations1();
    Opp.operations1();
    Opp.operations1();
    Opp.operations1();

    
    Opp.assign2();
    Opp.operations2();
    Opp.operations2();
    Opp.operations2();
    Opp.operations2();

    Opp.operations3();
    Opp.operations3();
    Opp.operations3();
    Opp.operations3();
    Opp.operations3();
}