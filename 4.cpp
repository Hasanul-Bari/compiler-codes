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


    int characters=0,others=0;


    char c=fgetc(f1);

    while(c!=EOF)
    {
        if(c=='\n' || c==' ')
        {
            others++;
        }
        else
        {
            characters++;
        }

        c=fgetc(f1);

    }

    //cout<<characters<<" "<<others<<endl;

    cout<<"number of characters in 'input.txt' file is (without spaces and newline) : "<<characters<<endl;
    cout<<"number of characters in 'input.txt' file is (with spaces and newline) : "<<characters+others<<endl;


    return 0;


}

