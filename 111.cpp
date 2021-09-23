#include<bits/stdc++.h>

using namespace std;

int main()
{
    FILE *f1;

    f1=fopen("input.txt","r");

    char s[1000];



    //int count=fread(s,sizeof(char), 1000, f1);
   // printf("%s",s);
    //cout<<s<<" ";

    while(fread(s,1, 100, f1)==100)
    {
        cout<<s;
    }


    //cout<<" ** "<<count<<endl;





    return 0;


}

