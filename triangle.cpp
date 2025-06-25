    //       *
    //      * *
    //     * * *
    //    * * * *

    #include<iostream>
    using namespace std;

    int main(){
        int i,j,r;
        cout<<"enter number of rows :";
        cin>>r;
        for(i=0;i<r;i++){
            for(j=0;j<=i;j++){
                for(int k=i;k<2*i-1;k++){
                    if(k>r-i+1 && k<r+i-1){
                        cout<<" ";
                
                    }
                    else{
                        cout<<"*";
                    }
                }
                 cout<<endl;
            }
        }
    }