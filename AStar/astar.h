typedef pair<int, int> Node;
typedef pair<double, int> doubleNode;
typedef vector<vector<Node>> Graph;
typedef priority_queue<doubleNode, vector<doubleNode>, greater<doubleNode>> DijkstraQueue;
typedef long long ll;

const ll INF = 1e15 + 10;



class AStar {
private:
	int n, m, s, t;
	Graph G;
	vector<Point<int>> P;
	vector<ll> dist;
	DijkstraQueue pq;
	void read() {
		cout << "Enter number of nodes: ";
		cin >> n;
		cout << "Enter number of edges: ";
		cin >> m;
		cout<<"Enter x and y coordinates of each node (starting from 1):\n";
		G.assign(n + 1, vector<Node>());
		P.assign(n + 1, Point<int>());
		for (int i = 1; i <= n; ++i)
			cin >> P[i].x >> P[i].y;
		int u, v, w;
		cout<<"Enter edges in the form \"from to weight\":\n";
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> w;
			G[u].push_back(make_pair(v, w));
		}
	}
	int AS() {
		dist[s] = 0;
		pq.push(make_pair(P[s].dist(P[t]), s));
		Node front;
		while (!pq.empty()) {
			front = pq.top();
			pq.pop();
			RelaxNodeEdges(front);
			if (front.second == t)
				return dist[front.second];
		}
		return -1;
	}
	void RelaxNodeEdges(Node currNode) {
		int u = currNode.second, v, w;
		for (int i = 0; i < (int) G[u].size(); ++i) {
			v = G[u][i].first, w = G[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v] + P[v].dist(P[t]), v));
			}
		}
	}
public:
	AStar() {
		read();
	}
	int Query(int _s, int _t) {
		s = _s, t = _t;
		while (!pq.empty())
			pq.pop();
		dist.assign(n + 1, INF);
		return AS();
	}

};
