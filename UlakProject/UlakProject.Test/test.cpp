#include "pch.h"
#include "pch.h";
#include "../UlakProject/Calculate.cpp"
TEST(DijkstraCase, dijkstra) {

	int graph[5][5] = { { 0, 3, 0, 7, 8 },
								{ 0, 0, 1, 4, 0 },
								{ 0, 0, 0, 0, 0 },
								{ 0, 0, 2, 0, 0 },
								{ 0, 0, 0, 3, 0 },
	};
	Calculate calculate;
	vector<int> testResult = calculate.dijkstra(graph, 0);
	ASSERT_EQ(4, testResult[2]);
}

TEST(BellmanFordCase, bellmanFord) {

	int graphBell[][3] = { { 0, 1, 3 },
						   { 0, 3, 7 },
						   { 0, 4, 8 },
						   { 1, 2, 1 },
						   { 1, 3, 4 },
						   { 3, 2, 2 },
						   { 4, 3,3 } };
	Calculate calculate;
	vector<int> testResult = calculate.bellmanFord(graphBell, 7, 0);
	ASSERT_EQ(4, testResult[2]);
}