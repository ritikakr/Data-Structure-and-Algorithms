#include <bits/stdc++.h>
using namespace std;

void Dijkstra(int n, int ** graph, int s, int e){
    bool * visited = new bool[n];
    for(int i=0; i<n; i++)visited[i] = false;
    int * distance = new int[n];
    for(int i=0; i<n; i++)distance[i] = INT_MAX;
    distance[s] = 0;
    int count =0;
    while(count < n){
        int minD = INT_MAX, minI;
        for(int i=0; i<n; i++){
            if(!visited[i] && minD > distance[i]){
                minD = distance[i];
                minI = i;
            }            
        }
        visited[minI] = true;
        for(int i=0; i<n; i++){
            if(!visited[i] && graph[minI][i] > 0){
                int dist = distance[minI] + graph[minI][i];
                if(dist < distance[i]) distance[i] = dist;

            }
        }
        count++;
    }

    // print distance
    cout<<distance[e]<<endl;
}

// Use adjency list and priority queue for optimized approach
// O(E + Elog(N))

int main()
{
    ios_base::sync_with_stdio( false ) ;  
    cin.tie(NULL) ; 
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen( "input.txt" , "r", stdin);
        freopen( "output.txt" , "w", stdout);
        freopen( "Error.txt" , "w", stderr);
    #endif

    int n,e;
    cin>>n>>e;
    int ** graph = new int * [n];
    for(int i=0 ; i<n ; i++){
      graph[i] = new int [n];
      for(int j=0;j<n;j++)graph[i][j]=-1;
    }
    for(int i=0;i<e;i++){
      int n1,n2,w;
      cin>>n1>>n2>>w;
      graph[n1][n2]=w;
      graph[n2][n1]=w;
    }

    cout<<"Distance b/w 1 & 6 is: ";
    Dijkstra(n,graph,1,6);

    return 0;
}
