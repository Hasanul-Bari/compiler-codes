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

    char c=fgetc(f1);
    int Linecount=1;
    bool isNewline=true;

    while(c!=EOF)
    {
        if(isNewline==true)
        {
            cout<<Linecount<<"  ";
            isNewline=false;
        }

        cout<<c;

        if(c=='\n')
        {
            isNewline=true;
            Linecount++;
        }

        c=fgetc(f1);

    }


    return 0;
}
