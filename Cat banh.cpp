#include <bits/stdc++.h>

using namespace std;

void themvaomang(vector <int> &a, int n, int m){
    a.push_back(m);
    for (int i = a.size()-1; i > n; i--){
        swap(a[i],a[i-1]);
    }
}
void reversearr(vector <int> &a){
    int j = 0, p = a.size();
    if (p%2 != 0){
        for (int i = p-1; i > p/2; i--){
            swap(a[i], a[j]);
            j++;
        }
    }
    else{
        for (int i = p-1; i >= p/2; i--){
            swap(a[i],a[j]);
            j++;
        }
    }
}
int main(){
    int n,tong;
    cin >> n;
    vector <int> a;
    vector <int> kq;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        a.push_back(m);
    }
    kq.push_back(a[0]);
    kq.push_back(360 - a[0]);
    for (int i = 1; i < n; i++){
        tong = 0;
        for (int j = 1; j < kq.size(); j++){
            tong  = tong + kq[j];
            if (a[i] < tong){
                int tam = kq[i];
                kq.erase(kq.begin() + j);
                reversearr(kq);
                themvaomang(kq,0,tam - tong + a[i]);
                themvaomang(kq,1,tong - a[i]);
                break;
            }
        }
        for (int i = 0; i < kq.size(); i++){
            cout << kq[i] <<" ";
        }
        cout <<endl;
    }
    int dapan = kq[0];
    for (int i = 1; i < kq.size(); i++){
        if (kq[i] > dapan) dapan = kq[i];
    }
    cout << dapan;
    return 0;
}
