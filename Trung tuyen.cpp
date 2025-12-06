#include <iostream>

using namespace std;

int main(){
    int n,m,k,a[100000],tong = 0,tien = 0;
    cin >> n >> m >> k;
    for (int i = 0;i < n*(m+1); i++){
        cin >> a[i];
    }
    for (int i = 0;i < n*(m+1); i++){
        cout << a[i];
    }
    for (int i = 1; i < m+1; i++){
        tong = a[i];
        for (int j = i + m+1; j < n*(m+1); j = j+m+1){
            tong = tong + a[j];
        }
        if (tong < k){
            cout << -1;
            return;
        }
    }

    return 0;
}
