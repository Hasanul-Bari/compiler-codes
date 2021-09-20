#include<bits/stdc++.h>

using namespace std;

int main()
{
    FILE *f1;

    f1=fopen("input.txt","r");

    if(f1==NULL)
    {
        cout<<"Failed to open file 'input.txt'"<<endl;
        return -1;
    }

    char s[200];

    int count=fread(s,strlen(s)+1, 10, f1);

    cout<<s<<endl;
    cout<<" ** "<<count<<endl;





    return 0;


}

