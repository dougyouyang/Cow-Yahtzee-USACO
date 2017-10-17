//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string>

using namespace std;
string com[25];
int n, s, e;
int result[25], sum=0;

int check(int a, int b)
{
    int i, cnt=0;
    for(i=0;i<n;i++)
        if(result[i]==b)
            cnt++;
    if(cnt<a)
        return 0;
    return 1;
}

void comp()
{
    int i, j;
    for(i=0;i<e;i++){
        int first=0, second=0;
        bool s=false, che=true;
        for(j=0;j<com[i].length();j++){
            if(com[i][j]=='x'){
                s=true;
                continue;
            }
            if(com[i][j]=='+'){
                if(!check(first, second))
                    che=false;
                first=0, second=0, s=false;
                continue;
            }
            if(!s)
                first*=10, first+=com[i][j]-'0';
            else{
                second*=10, second+=com[i][j]-'0';
            }
        }
        if(check(first, second) && che){
            sum++;
            return;
        }
    }
}

void gen(int level)
{
    if(level==n){
        comp();
        return;
    }
    int i;
    for(i=0;i<s;i++){
        result[level]=i+1;
        gen(level+1);
    }
}

int main()
{
    int i;
    
    cin >> n >> s >> e;
    for(i=0;i<e;i++){
        cin >> com[i];
    }
    
    gen(0);
    
    cout << sum << endl;
    
    return 0;
}
