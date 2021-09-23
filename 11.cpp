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

    char s[1000];
    int lineNumber=1;
    bool isNewline=true;

    while(fgets(s,1000,f1)!=NULL)
    {
        for(int i=0; s[i]!='\0'; i++)
        {

            if(isNewline)
            {
                cout<<lineNumber<<"   ";
                isNewline=false;
            }

            cout<<s[i];

            if(s[i]=='\n')
            {
                isNewline=true;
                lineNumber++;
            }
        }

    }

    fclose(f1);




    return 0;


}

