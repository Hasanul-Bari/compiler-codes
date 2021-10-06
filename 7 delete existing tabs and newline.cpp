/*
Problem: Write a C/C++ program that reads text from a file, then delete the existing tabs (spaces)
and new line and save the output text file. Also count and print the number of deletion.
*/



#include<bits/stdc++.h>

using namespace std;

int main()
{
    char fileName [100];
    cout<<"Enter the name of the file(with extension) to be read : ";
    cin>>fileName;

    FILE *f1, *f2;

    f1=fopen(fileName,"r");
    f2=fopen("output.txt","w");


    if(f1==NULL)
    {
        cout<<"Failed to open file "<<fileName<<endl;
        return -1;
    }
    else
    {
        cout<<fileName<<" file opened successfully"<<endl;
    }


    int tabs=0,newlines=0;


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

    cout<<"Delete existing tabs and newline : success"<<endl;
    cout<<"write the output to 'output.txt' : success"<<endl<<endl;

    cout<<"number of deletion : "<<tabs+newlines<<endl;

    return 0;


}






