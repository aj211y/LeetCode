//No. 804 - AC
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution{
	public:
		int uniqueMorseRepresentations(vector<string>& words) {
        	string Morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
        	"--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        	set <string> ret;
        	int id;

        	string trans="";
        	for(int i=0; i<words.size(); i++)
        	{
        		trans="";
        		for(int j=0; j<words[i].length(); j++)
        		{
        			id = words[i][j]-'a';
        			trans+=Morse[id];
        		}
        		ret.insert(trans);
        	}
        	return ret.size();
    	}
};

int main()
{
	string str;
	vector<string> words;
	Solution sol;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		cin >> str;
		words.push_back(str);
	}
	cout << sol.uniqueMorseRepresentations(words);


	return 0;
}

/*
a: .-
b: -...
c: -.-.
d: -..
e: .
f: ..-.
g: --.
h: ....
i: ..
j: .---
k: -.-
l: .-..
m: --
n: -.
o: ---
p: .--.
q: --.- 
r: .-.
s: ...
t: -
u: ..-
v: ...-
w: .--
x: -..-
y: -.--
z: --..
*/