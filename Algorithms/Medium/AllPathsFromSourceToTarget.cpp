//No.797 - AC
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> findRoute(int start, int end, vector<vector<int> >& graph)
	{
		vector<string> ret, possibleRoute;
		string route;

		if(start == end)
		{
			route = to_string(start);
			ret.push_back(route);
			return ret;
		}
		else
		{
			for(int i=0; i<graph[start].size(); i++)
			{
				possibleRoute = findRoute(graph[start][i], end, graph);
				for(int j=0; j<possibleRoute.size(); j++)
				{
					route = to_string(start) + " " + possibleRoute[j];
					ret.push_back(route);
				}
			}
			return ret;
		}
	}
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
        vector<vector<int> > ret;
        vector<int> route;
        vector<string> Ans;
        int num;

        Ans = findRoute(0,graph.size()-1, graph);

        for(int i=0; i<Ans.size(); i++)
        {
        	route.clear();
        	num = 0;
        	for(int j=0; j<Ans[i].length(); j++)
        	{
        		if(Ans[i][j] == ' ')
        		{
        			route.push_back(num);
        			num = 0;
        		}
        		else
        		{
        			num = num*10 + (Ans[i][j] - '0');
        		}
        	}
        	route.push_back(num);

        	ret.push_back(route);
        }
        return ret;
    }
};
int main()
{
	vector<int> edge;
	vector<vector<int> > graph, Ans;
	Solution sol;

	edge.push_back(1);
	edge.push_back(2);
	graph.push_back(edge);
	edge.clear();

	edge.push_back(3);
	graph.push_back(edge);
	graph.push_back(edge);

	edge.clear();
	graph.push_back(edge);

	Ans = sol.allPathsSourceTarget(graph);
	for(int i=0; i<Ans.size(); i++)
	{
		for(int j=0; j< Ans[i].size(); j++)
		{
			cout << Ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}