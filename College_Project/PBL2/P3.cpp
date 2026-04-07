#include <bits/stdc++.h>
using namespace std;

/* ================= SEARCHING ================= */

int linearSearch(vector<pair<int,bool>>& centers, int key) {
    for (int i = 0; i < centers.size(); i++) {
        if (centers[i].first == key) {
            if (centers[i].second == true)
                return i;   // found & available
            else
                return -2;  // found but NOT available
        }
    }
    return -1; // not found
}

int binarySearch(vector<pair<int,bool>>& centers, int key) {
    int l = 0, r = centers.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (centers[mid].first == key) {
            if (centers[mid].second == true)
                return mid;
            else
                return -2;
        }
        else if (centers[mid].first < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

/* ================= SORTING ================= */

void merge(vector<pair<string,int>>& arr, int l, int m, int r) {
    vector<pair<string,int>> temp;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (arr[i].second < arr[j].second)
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);

    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];
}

void mergeSort(vector<pair<string,int>>& arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int partition(vector<pair<string,int>>& arr, int low, int high) {
    int pivot = arr[high].second;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].second < pivot) {
            swap(arr[++i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<pair<string,int>>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ===== HEAP SORT ===== */

void heapify(vector<pair<string,int>>& arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l].second > arr[largest].second)
        largest = l;

    if (r < n && arr[r].second > arr[largest].second)
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<pair<string,int>>& arr) {
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/* ================= GRAPH ================= */

void BFS(int V, vector<vector<int>>& adj, int start) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void DFSUtil(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!visited[v]) DFSUtil(v, adj, visited);
}

void DFS(int V, vector<vector<int>>& adj, int start) {
    vector<bool> visited(V, false);
    DFSUtil(start, adj, visited);
}

/* ===== DIJKSTRA ===== */

void dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();

        for (auto &edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances:\n";
    for (int i = 0; i < V; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}

/* ===== PRIMS ===== */

int prims(int V, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> inMST(V, false);

    pq.push({0, 0});
    int cost = 0;

    while (!pq.empty()) {
        pair<int,int> p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if (inMST[u]) continue;

        inMST[u] = true;
        cost += wt;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!inMST[v]) {
                pq.push({w, v});
            }
        }
    }

    return cost;
}

/* ===== KRUSKAL ===== */

struct Edge { int u, v, w; };

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u], parent);
}

void unite(int u, int v, vector<int>& parent) {
    parent[find(u, parent)] = find(v, parent);
}

int kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int cost = 0;
    for (auto e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            cost += e.w;
            unite(e.u, e.v, parent);
        }
    }
    return cost;
}

/* ===== KNAPSACK ===== */

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    // Backtrack to find selected items
    int w = W;
    vector<int> selected, notSelected;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected.push_back(i);   // store 1-based index // item included
            w -= wt[i-1];
        } else {
            notSelected.push_back(i);   // store 1-based index // item not included
        }
    }

    // Output
    cout << "\nSelected Items: ";
    for (int i : selected)
        cout << i << " ";
    
    cout << "\nNot Selected Items: ";
    for (int i : notSelected)
        cout << i << " ";

    cout << endl;

    return dp[n][W];
}

/* ================= MAIN ================= */

int main() {
    cout << "===== Wind Turbine Supply Chain Optimizer =====\n";

    int blades, centers;
    cout << "Enter number of blades: ";
    cin >> blades;

    cout << "Enter number of locations: ";
    cin >> centers;

    vector<vector<pair<int,int>>> adj(centers);

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < centers; i++) {
        for (int j = 0; j < centers; j++) {
            int w; cin >> w;
            if (i != j && w != 0)
                adj[i].push_back({j, w});
        }
    }

    int cost, time;
    cout << "Enter cost constraint: "; cin >> cost;
    cout << "Enter time constraint: "; cin >> time;

    cout << "\nRecommended Algorithm: Dijkstra\n";
    cout << "Reason: Minimizes transport distance\n";
    cout << "Complexity: O(E log V)\n";

    int src;
    cout << "Enter source: ";
    cin >> src;

    dijkstra(centers, adj, src);

    /* MENU */
    int ch;

while (true) {
    cout << "\nDo you want to try other algorithms?\n";
    cout << "1.Prims 2.Kruskal 3.BFS/DFS 4.Knapsack 5.Sorting 6.Searching 0.Exit\n";
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 0) {
        cout << "Exiting program...\n";
        break;
    }

    if (ch == 1)
        cout << "Prim Cost: " << prims(centers, adj) << endl;

    else if (ch == 2) {
        vector<Edge> edges;
        for (int i = 0; i < centers; i++)
            for (auto &p : adj[i])
                edges.push_back({i, p.first, p.second});

        cout << "Kruskal Cost: " << kruskal(centers, edges) << endl;
    }

    else if (ch == 3) {
        vector<vector<int>> simple(centers);
        for (int i = 0; i < centers; i++)
            for (auto &p : adj[i])
                simple[i].push_back(p.first);

        cout << "BFS: "; BFS(centers, simple, src);
        cout << "\nDFS: "; DFS(centers, simple, src);
        cout << endl;
    }

    else if (ch == 4) {
    int n, W;
    cout << "Enter items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    int maxVal = knapsack(W, wt, val, n);

    cout << "Maximum Value: " << maxVal << endl;
   }

    else if (ch == 5) {

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<pair<string,int>> processes(n);

    cout << "Enter process name and efficiency:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].first >> processes[i].second;
    }

    int sortChoice;
    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Merge Sort\n2. Quick Sort\n3. Heap Sort\n";
    cin >> sortChoice;

    if (sortChoice == 1)
        mergeSort(processes, 0, n - 1);

    else if (sortChoice == 2)
        quickSort(processes, 0, n - 1);

    else if (sortChoice == 3)
        heapSort(processes);

    cout << "\nProcesses sorted by efficiency (highest first):\n";

    for (int i = n-1; i >= 0; i--) {
        cout << processes[i].first << " -> Efficiency: "
             << processes[i].second << endl;
    }
   }

    else if (ch == 6) {

    int n;
    cout << "Enter number of centers: ";
    cin >> n;

    vector<pair<int,bool>> centers(n);

    cout << "Enter center ID and availability (1=Yes, 0=No):\n";
    for (int i = 0; i < n; i++) {
        cin >> centers[i].first >> centers[i].second;
    }

    int key;
    cout << "Enter center ID to search: ";
    cin >> key;

    // Sort for binary search
    sort(centers.begin(), centers.end());

    int res1 = linearSearch(centers, key);
    int res2 = binarySearch(centers, key);

    cout << "\nLinear Search Result:\n";
    if (res1 >= 0) cout << "Center Available\n";
    else if (res1 == -2) cout << "Center Found but NOT Available\n";
    else cout << "Center Not Found\n";

    cout << "\nBinary Search Result:\n";
    if (res2 >= 0) cout << "Center Available\n";
    else if (res2 == -2) cout << "Center Found but NOT Available\n";
    else cout << "Center Not Found\n";
}

    else {
        cout << "Invalid choice! Try again.\n";
    }
}

    return 0;
}
