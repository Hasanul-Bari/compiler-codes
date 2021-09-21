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


    int characters=0,whitespace=0;


    char c=fgetc(f1);

    while(c!=EOF)
    {
        if(isspace(c))
        {
            whitespace++;
        }
        else
        {
            characters++;
            //cout<<characters<<" "<<c<<endl;
        }

        c=fgetc(f1);

    }
    fclose(f1);

    //cout<<characters<<" "<<others<<endl;

    cout<<"number of characters in 'input.txt' file is (without whitespace) : "<<characters<<endl;
    cout<<"number of characters in 'input.txt' file is (with whitespace) : "<<characters+whitespace<<endl;


    return 0;


}

