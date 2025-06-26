// 1      1
// 12    21
// 123  321
// 12344321

#include<iostream>
using namespace std;

int main(){
    int i,j,r,start;
    cout<<"enter number of rows :";
    cin>>r;
    for(i=1;i<=r;i++){
            for(int j=1;j<=i;j++){
                cout<<j;
            }
            for(int j=1;j<=2*(r-i);j++){
                cout<<" ";
            }
            for(int j=i;j>=1;j--){
                 cout<<j;
            }
            cout<<endl;
        }
       
    }
