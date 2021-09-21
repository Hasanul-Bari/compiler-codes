#include<bits/stdc++.h>

using namespace std;

int main()
{
    FILE *f1, *f2;

    f1=fopen("text.txt","r");
    f2=fopen("output.txt","w");


    if(f1==NULL)
    {
        cout<<"Failed to open file 'input.txt'"<<endl;
        return -1;
    }


    int tabs=0,space=0,newlines=0;


    char c=fgetc(f1);

    while(c!=EOF)
    {
        if(c=='\t')
        {
            tabs++;
        }
        else if(c=='\n')
        {
            newlines++;
        }
        else
        {
            //cout<<c;
            fputc(c,f2);
        }


        c=fgetc(f1);

    }

    fclose(f1);
    fclose(f2);

    //cout<<tabs<<" "<<newlines<<endl;

    cout<<"Read from 'input.txt' : success"<<endl;
    cout<<"Delete existing tabs and newline : success"<<endl;
    cout<<"write the output to 'output.txt' : success"<<endl<<endl;

    cout<<"number of deletion : "<<tabs+newlines<<endl;

    return 0;


}






