#include <bits/stdc++.h>
using namespace std;

struct edge{
    int start;
    int end;
    int weight;
    edge(){
        this->start=-1;
        this->end=-1;
        this->weight=-1;
    }
};

bool compareWeight(edge e1,edge e2){
    return (e1.weight < e2.weight);
}

int getparent(int v,int * arr){
    if(v==arr[v])return v;
    int ans = getparent(arr[v],arr);
    return ans;
}

// MINIMUM SPANNING TREE ==> KRUSKAL
void kruskal(int n, edge graph[],int e){
    int parent[n+1];
    for(int i=0; i<n; i++)parent[i]=i;
    int count=0;
    sort(graph,graph+e,compareWeight);
    int ptr=0;
    while(count<(n-1) && ptr < e){
        int sParent = getparent(graph[ptr].start,parent);
        int eParent = getparent(graph[ptr].end,parent);
        if(sParent != eParent){
            cout<<graph[ptr].start<<" "<<graph[ptr].end<<" "<<graph[ptr].weight<<endl;
            parent[eParent]=sParent;
            count++;
        }
        ptr++; 
    }
}


int main()
{
    clock_t tstart  = clock();
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
    edge graph[e];
    for(int i=0; i<e; i++){
        cin>>graph[i].start>>graph[i].end>>graph[i].weight;
    }

    kruskal(n,graph,e);

    cerr<< double(clock()) - tstart;
    return 0;
}
