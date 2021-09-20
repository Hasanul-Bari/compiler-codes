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
    int lineNumber=1;

    while(fgets(s,200,f1)!=NULL)
    {
        cout<<lineNumber<<"   "<<s;
        lineNumber++;
    }

    fclose(f1);




    return 0;


}

