#include<bits/stdc++.h>

using namespace std;

int main()
{
    FILE *f1;

    f1=fopen("text.txt","r");

    if(f1==NULL)
    {
        cout<<"Failed to open file 'input.txt'"<<endl;
        return -1;
    }


    int tabs=0,space=0,newlines=0;


    char c=fgetc(f1);

    while(c!=EOF)
    {
        /*if(c=='\t')
        {
            cout<<"tab";
        }*/

        if(c==' ')
        {
            space++;
        }
        else
        {
            if(space>0 && space<4)
            {
                while(space--)
                {
                    cout<<' ';
                }
            }

            if(c=='\n')
            {
                newlines++;
            }
            else
            {
                cout<<c;
            }

            space=0;
        }

        if(space==4)
        {
            tabs++;
            space=0;
        }


        c=fgetc(f1);

    }

    cout<<"number of deletion : "<<tabs+newlines<<endl;

    return 0;


}





