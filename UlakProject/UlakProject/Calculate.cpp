#include <iostream>
#include <vector> 
#define vertex 5 
#define INF INT_MAX 
using namespace std;

class BaseCalculate
{
public:
	virtual vector<int> dijkstra(int graph[vertex][vertex], int source) = 0;
	virtual vector<int> bellmanFord(int graph[][3], int lineCount, int source) = 0;
	virtual int calculateDistance(int distance[], bool shortPathSet[]) = 0;
};

//Summary:
//This method calculate short path and working with dijkstra and bellmanford algoirthm
class Calculate :public BaseCalculate
{
	//This method calculate short path with Dijskstra Alogirthm
public:
	vector<int> dijkstra(int graph[vertex][vertex], int source)
	{
		int distance[vertex];
		bool shortPathSet[vertex];
		vector<int> result;

		for (int i = 0; i < vertex; i++)
		{
			distance[i] = INT_MAX; // set inital infinity value for all node
			shortPathSet[i] = false;
		}

		distance[source] = 0;

		for (int counter = 0; counter < vertex; counter++)
		{
			int minimumIndex = calculateDistance(distance, shortPathSet);
			shortPathSet[minimumIndex] = true;

			for (int destionationIndex = 0; destionationIndex < vertex; destionationIndex++)
			{
				if (!shortPathSet[destionationIndex] && graph[minimumIndex][destionationIndex] && distance[minimumIndex] != INT_MAX && (distance[minimumIndex] + graph[minimumIndex][destionationIndex] < distance[destionationIndex]))
				{
					distance[destionationIndex] = distance[minimumIndex] + graph[minimumIndex][destionationIndex];
				}
			}
		}

		for (int i = 0; i < vertex; i++)
		{
			result.push_back(distance[i]);
		}

		return result;
	}

	//This method calculate short path with bellmanFord Alogirthm
public:
	vector<int> bellmanFord(int graph[][3], int lineCount, int source)
	{
		int distance[vertex];
		vector<int> result;

		for (int i = 0; i < vertex; i++)
		{
			distance[i] = INT_MAX;
		}

		distance[source] = 0;

		for (int i = 0; i < vertex - 1; i++) {

			for (int j = 0; j < lineCount; j++) {
				if (distance[graph[j][0]] + graph[j][2] < distance[graph[j][1]]) {
					distance[graph[j][1]] = distance[graph[j][0]] + graph[j][2];
				}

			}
		}

		for (int i = 0; i < vertex; i++)
		{
			result.push_back(distance[i]);
		}

		return result;
	}

	int calculateDistance(int distance[], bool shortPathSet[]) {
		int min = INT_MAX;
		int index;

		for (int v = 0; v < vertex; v++)
		{
			if (shortPathSet[v] == false && distance[v] <= min)
			{
				min = distance[v];
				index = v;
			}
		}
		return index;
	}
};