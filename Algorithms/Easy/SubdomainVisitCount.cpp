//No.811 - AC
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;

//Without using strcpy, the runtime is faster.
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
    	int len = cpdomains.size();
    	int cnt;
    	bool beforeDot,beforeSpace;
    	string cnt_str, name, ret_item, tmpName;
    	char cpd[105];
    	vector<string> ret;
    	map<string, int> domains;
    	
        for(int i=0; i<len; i++)
        {
        	// strcpy(cpd, cpdomains[i].c_str());
        	// cnt_str = strtok(cpd," ");
        	// name = strtok(NULL, " ");
        	
        	// cnt = 0;
        	// for(int j=0; j<cnt_str.length(); j++)
        	// {
        	// 	cnt = cnt*10 + (cnt_str[j]-'0');
        	// }
        	beforeSpace = true;
        	cnt = 0;
        	name = "";
        	for(int j=0; j<cpdomains[i].length(); j++)
        	{
        		if(cpdomains[i][j] == ' ')
        		{
        			beforeSpace = false;
        		}
        		else if(beforeSpace)
        		{
        			cnt = cnt*10 + cpdomains[i][j] - '0';
        		}
        		else//After Space
        		{
        			name += cpdomains[i][j];
        		}
        	}
        	while(name!="")
        	{
	        	if(domains.find(name) == domains.end())
	        	{
	        		domains[name] = cnt;
	        	}
	        	else
	        	{
	        		domains[name] += cnt;
	        	}
	        	beforeDot = true;
	        	tmpName = "";
	        	for(int j=0; j<name.length(); j++)
	        	{
	        		if(beforeDot)
	        		{
	        			if(name[j] == '.')
	        				beforeDot = false;
	        		}
	        		else
	        		{
	        			tmpName += name[j];
	        		}
	        	}
	        	name = tmpName;
        	}
        }
        // for(map<string, int>::iterator it = domains.begin(); it!=domains.end(); it++)
        //for(auto it = domains.begin(); it!=domains.end(); it++) // only in g++11
        for(auto elem: domains) // only in g++11
        {
        	// name = it->first;
        	// cnt = it->second;
        	name = elem.first;
        	cnt = elem.second;

        	ret_item = to_string(cnt) + " " + name;
        	// cout << ret_item << endl;
        	ret.push_back(ret_item);
        }        

        return ret;
    }
};

int main()
{
	vector<string> cpdomains, Ans;
	string s;
	int n;
	Solution sol;

	scanf("%d", &n);
	getchar();
	for(int i=0; i<n; i++)
	{
		getline(cin, s);
		cpdomains.push_back(s);
	}
	Ans = sol.subdomainVisits(cpdomains);

	for(int i=0; i<Ans.size(); i++)
	{
		cout << Ans[i] << endl;
	}
	return 0;
}