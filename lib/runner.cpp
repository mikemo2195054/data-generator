#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

#define ll long long

void runcmd(string s){
    cout<<"Running Command: "<<s<<endl;
    system(s.c_str());
}

int main(){
    ll i,j;
    runcmd("g++-11 -o Sol Sol.cpp");
    runcmd("rm -r data");
    runcmd("mkdir data");

    while(true){
        ll l,r;
        cout<<"Please input the first and last ID. use -1 to end\n";
        cin>>l>>r;
        if(l==-1)
            break;
        cout<<"Please input data generator name. Starting with ./\n";
        string s,cmd;
        cin>>s;
        while(s[0]!='.' || s[1]!='/'){
            cout<<"Error, please re-enter.\n";
            cin>>s;
        }
        for(i=l;i<=r;i++){
            cmd="echo > data/data"+to_string(i)+".in";
            runcmd(cmd);
            cmd="echo > data/data"+to_string(i)+".out";
            runcmd(cmd);
            cmd=s+" > data/data"+to_string(i)+".in";
            runcmd(cmd);
            cmd="./Sol < data/data"+to_string(i)+".in > data/data"+to_string(i)+".out";
            runcmd(cmd);
            sleep(1);
        }
    }
    return 0;
}