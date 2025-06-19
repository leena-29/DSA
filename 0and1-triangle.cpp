// 1
// 01
// 101
// 0101
// 10101

#include<iostream>
using namespace std;
int main(){
    int i,j,num=1,n;
    cout<<"enter number of rows :";
    cin>>n;
    for(i=1;i<=n;i++){
        int num = (i % 2 == 1) ? 1 : 0;
        for(j=1;j<=i;j++){
            cout << num;
            num = 1 - num;
        }
        cout<<endl;
    }
}