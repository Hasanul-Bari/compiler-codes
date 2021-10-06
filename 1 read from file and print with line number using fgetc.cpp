#include<iostream>

using namespace std;

int main()
{
    char fileName [200];
    cout<<"Enter the name of the file(with extension) to be read : ";
    cin>>fileName;
    FILE *f1;

    f1=fopen(fileName,"r");

    if(f1==NULL)
    {
        cout<<"Failed to open "<<fileName<<" file"<<endl;
        return -1;
    }
    else
    {
        cout<<fileName<<" file opened successfully"<<endl;
    }


    int Linecount=1;
    bool isNewline=true;
    char c=fgetc(f1);

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
