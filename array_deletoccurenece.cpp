#include<iostream>
using namespace std;
void Delete_All_Ocuurence(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            for(int j=i;j<size-1;j++){
                arr[j]=arr[j+1];
            }
            size--;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[10]={2,5,1,3,4,5,1,2,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=5;
    Delete_All_Ocuurence(arr,size,key);
    return 0;
}