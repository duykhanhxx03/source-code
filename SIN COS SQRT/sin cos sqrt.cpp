#include <iostream>
#include <cmath>
using namespace std;
double factorial(double x){
    if (x==0||x==1) return 1;
    return x*factorial(x-1);
}
double mySin(double x){
    double sum=x; double oldsum=0;
    int i=0;
    while(fabs(sum-oldsum)>0.00001){
        oldsum=sum; i++;
        sum+=(pow(-1,i)*(pow(x,2*i+1))/factorial(2*i+1));
    }
    return sum;
}
double myCos(double x){
    double sum=1; double oldsum=0;
    int i=0;
    while(fabs(sum-oldsum)>0.00001){
        oldsum=sum; i++;
        sum += (pow(-1, i) * pow(x, 2 * i) / factorial(i * 2));
    }
    return sum;
}
#define EPSILON 0.0001f
double mySqrt(double number)
{
    double result = 1.0f;
    while (fabs(result * result - number) / number >= EPSILON)
        result = (number / result  - result) / 2 + result;
    return result;
}
int main(){
    double pi=3.14159265359;
    cout<<myCos(pi);
    return 0;
}