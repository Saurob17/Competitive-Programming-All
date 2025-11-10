#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,w,h,d;
    while(1){
        if(!(cin>>l>>w>>h>>d)) break;
        int boxVol=l*w*h;
          double rad = d * M_PI / 180.0;
        double lossVol=(double)0.5*l*l*tan(rad);
        cout<<fixed<<setprecision(3);
        cout<<boxVol-(double)lossVol*w<<" mL"<<endl;

    }
}