#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> v(5);
vector<int> v1(5);
vector<int> v2(5);
void reverse(){
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    cout<<"reverse vector is :";
    for(int i=0;i<5;i++){
        v1[i]=v[4-i];
        cout<<v1[i]<<" ";
    }
    cout<<"\n";

}

void mean(){
    int sum=0;
    for(int i=0;i<5;i++){
        sum=sum+v[i];
    }
    cout<<"medium is :";
    int mean=sum/5;
    cout<<mean;
    cout<<"\n";
}

double mediun(){
    sort(v.begin(),v.end());
    cout<<"mediun is :";
    if(v.size()%2==0){
        return (v[v.size()/2]+v[v.size()/2-1])/(double)2;
    }
    return v[v.size()/2];
    
}


int main(){
    
    reverse();
    mean();
   cout<< mediun();
    
    return 0;
}