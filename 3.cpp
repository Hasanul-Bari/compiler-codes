#include<bits/stdc++.h>
using namespace std;

bool isIdentifierValid(string identifier)
{
    int IDLength=identifier.length();

    if(IDLength==0)
    {
        return false;
    }

    //if the first character is neither an alphabet nor an underscore then invalid
    if( !(isalpha(identifier[0]) || identifier[0]=='_') )
    {
        return false;
    }

    for(int i=1; i<IDLength; i++)
    {

        //if the character is not an alphabet or a digit or an underscore then invalid
        if( !(isalpha(identifier[0]) || isdigit(identifier[0]) || identifier[0]=='_') )
        {
            return false;
        }
    }

    return true;


}



int main()
{
    string id;
    cout<<"Enter an identifier : ";

    getline(cin,id);

    //cout<<isIdentifierValid(id)<<endl;


    if(isIdentifierValid(id))
    {
        cout<<"Given identifier is valid"<<endl;
    }
    else
    {
        cout<<"Given identifier is not valid"<<endl;
    }


    return 0;
}
