// E 
// DE 
// CDE 
// BCDE 
// ABCDE

#include<iostream>
using namespace std;

int main() {
    int i, j, r;
    char a = 'A', d;
    cout << "enter number of rows :";
    cin >> r;

    for (i=1;i<=r;i++) {
        d=a+r-i;  
        for (j=1;j<=i;j++) {
            cout<<d;
            d++;
        }
        cout<<endl;
    }

    return 0;
}
