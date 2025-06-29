// 12345
// 1234
// 123
// 12
// 1

#include<iostream>
using namespace std;

int main(){
    int i,j,n;
    cout<<"enter number of rows";
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--){
            cout<<n-j+1;
        }
        cout<<endl;
    }
}