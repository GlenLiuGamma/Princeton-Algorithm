#include<iostream>
using namespace std;
void powerset(int amount, string* arr, string current_str="", int cnt=-1){
    string append;
    if(cnt==amount){
        return;
    }
    else{
        cout<<"{"<<current_str<<"}"<<endl;
        for(int i=cnt+1; i<amount; i++){
            //when cnt is at the first element, we don't have to print the space in front of it 
            append=(cnt==-1?arr[i]:" "+arr[i]);
            current_str=current_str+append;
            //with the base of current string, move on to deeper powerset with combination of base string
            powerset(amount, arr, current_str, i);
            current_str.erase(current_str.size()-append.size());
            //delete the current combination move on to next combination
    }
  }
}
int main(){
    int amount;
    string *arr;
    while(!cin.eof()){
    cout<<"Please enter the amount of element in the set"<<endl;
    cin >> amount;
    cout<<"Please input elements:"<<endl;
    arr = new string[amount];
    for (int i=0;i<amount;i++){
        cin>>arr[i];
    }
    powerset(amount, arr);
    delete [] arr;
    }
}

