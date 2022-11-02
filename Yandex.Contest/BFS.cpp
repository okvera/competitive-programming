#include <iostream>
#include <vector>
#include <queue>

int BFS()
{
  // input parameters
	int n{};      //number of cities (vertexes)
	int k{};      //max allowable road (rib) length
	int from{};
  int to{};

	std::cin >> n;
	if (n < 2)
	{
		std::cout << -1;
		return 0;
	}

  // get coordinates
	std::vector<std::pair<int, int>> coords(n);
	int x{};
	int y{};
	for(int i = 0; i < n; ++i)
	{		
		std::cin >> x >> y;
		coords[i] = (std::make_pair(x, y));
	}
  
	std::cin >> k;
	std::cin >> from >> to;
	--from;
	--to;
	
	// graph formation (array of ribs)
	std::vector<std::vector<int>> distance(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
	    distance[i][i] = 0;
	    for (int j = 0; j < i; ++j)
	    {
	        int d = abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second);
	        distance[i][j] = distance[j][i] = (d > k) ? 0  : d;
	    }
	}
	
	std::queue<int> q{};
	std::vector<bool> seen(n, false);
	std::vector<int> pathLen(n, 0);
	
	int resultLen = -1;

	q.push(from);
	seen[from] = true;

	do
	{
	    int v = q.front();
	    q.pop();
	    if (distance[v][to] > 0)
	    {
	        resultLen = pathLen[v] + 1;
	        break;
	    }
	    
	    for (int i = 0; i < n; ++i)
	    {
	        if ((distance[v][i] > 0) && !seen[i])
	        {
	            seen[i] = true;
	            pathLen[i] = pathLen[v] + 1;
	            q.push(i);
	        }
	    }
	} while (!q.empty());
  
	std::cout << resultLen;
  
	return 0;
}
