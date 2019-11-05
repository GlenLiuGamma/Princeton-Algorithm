#include <iostream>
using namespace std;
int main(){
   int key;
   int a[10]={ 100, 5, 34, 567, 4, 2, 5 ,78, 90, 3};
   for(int j=1; j<10; j++){
   	key = a[j];
      for(int i=j-1; i>=0 && a[i]>key; i--){
	 a[i+1] = a[i];
	}
       a[j-1]=key;
   }
   for (int i=0; i<10; i++){
   	cout << a[i]<<endl;
   }

return 0;
}
