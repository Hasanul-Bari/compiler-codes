#include<bits/stdc++.h>
using namespace std;

bool isValidNumber(string num)
{
    int length=num.length();

    if(length==1 && !isdigit(num[0]))
    {
        return false;
    }

    if( !(isdigit(num[0]) || num[0]=='+' || num[0]=='-' || num[0]=='.') )
    {
        return false;
    }

    bool dot=false,exp=false;

    if(num[0]=='.')
    {
        if(length>1 && isdigit(num[1]))
        {
            dot=true;
        }
        else
        {
            return false;
        }
    }

    for(int i=1; i<length; i++)
    {
        if(isdigit(num[i]))
            continue;
        else if(num[i]=='.')
        {
            if(dot==true || exp==true)
                return false;
            if(i+1==length)
                return false;
            if(!isdigit(num[i+1]))
                return false;

            dot=true;
        }
        else if(num[i]=='e')
        {
            if(exp==true)
                return false;
            if(i+1==length)
                return false;
            if( !(isdigit(num[i+1]) || num[i+1]=='+' || num[i+1]=='-') )
                return false;

            dot=true;
            exp=true;
        }
        else if(num[i]=='+' || num[i]=='-')
        {
            if(num[i-1]!='e')
                return false;
            if(i+1==length)
                return false;
            if(!isdigit(num[i+1]))
                return false;
        }
    }




    return true;
}

int main()
{

    double x=0.1e-1;
    cout<<x<<endl;
    string num;
    cin>>num;

    cout<<isValidNumber(num)<<endl;
}
