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

    char c;
    int count=1;
    bool f=true;

    while(true)
    {
        c=fgetc(f1);
        if(c==EOF)
        {
            break;
        }

        if(f==true)
        {
            cout<<count<<"  ";
            f=false;
        }

        cout<<c;

        if(c=='\n')
        {
            f=true;
            count++;
        }

    }


    return 0;


}
