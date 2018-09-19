//No.537 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string ret="";
        int intA=0, intB=0, virA=0, virB=0, intRet=0, virRet=0;
        bool isNeg, isVir;

	    isVir = false;
	    isNeg = false;
        for(int i=0; i<a.length()-1; i++)
        {
        	if(a[i]=='-')
        	{
        		isNeg = true;
        	}
        	else if(a[i]=='+')
        	{
        		isVir = true;
        		if(isNeg)
        			intA = 0-intA;
        		isNeg = false;
        	}
        	else if(!isVir)
        	{
        		intA = intA*10 + (a[i]-'0');
        	}
        	else
        	{
        		virA = virA*10 + (a[i]-'0');
        	}
        }
        if(isNeg)
        	virA = 0-virA;

        isVir = false;
	    isNeg = false;
        for(int i=0; i<b.length()-1; i++)
        {
        	if(b[i]=='-')
        	{
        		isNeg = true;
        	}
        	else if(b[i]=='+')
        	{
        		isVir = true;
        		if(isNeg)
        			intB = 0-intB;
        		isNeg = false;
        	}
        	else if(!isVir)
        	{
        		intB = intB*10 + (b[i]-'0');
        	}
        	else
        	{
        		virB = virB*10 + (b[i]-'0');
        	}
        }
        if(isNeg)
        	virB = 0-virB;

        intRet = intA*intB - virA*virB;
        virRet = intA*virB + intB*virA;

        ret = to_string(intRet) + "+" + to_string(virRet) + "i";

        return ret;
    }
};
int main()
{
	string a, b;
	Solution sol;

	cin >> a >> b;

	cout << sol.complexNumberMultiply(a,b) << endl;
	return 0;
}