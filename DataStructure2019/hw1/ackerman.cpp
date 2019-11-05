#include<iostream>
using namespace std;
int Ackerman(int m, int n);
int main(){ 
    int a,b;
    while(!cin.eof()) {
    cout<<"Please enter two inputs"<<endl;
    cin >> a>>b;
    cout<<Ackerman(a,b)<<endl;}
}
int Ackerman(int m, int n){
    if(m==0){
        return n+1;
    }else if(n==0){
        return Ackerman(m-1,1);
    }else{
        return Ackerman(m-1, Ackerman(m,n-1));
    }
}