/*
Problem: Write a C/C++ program that reads text from a file, then count and prints the number of character exist in the inputted text file.
*/

#include<bits/stdc++.h>
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
        cout<<"Failed to open file "<<fileName<<endl;
        return -1;
    }
    else
    {
        cout<<fileName<<" file opened successfully"<<endl;
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

    cout<<"number of characters in "<<fileName<<" file is (without whitespace) : "<<characters<<endl;
    cout<<"number of characters in "<<fileName<<" file is (with whitespace) : "<<characters+whitespace<<endl;


    return 0;


}

