
#include <iostream>
#include <vector>
#include <queue>

using namespace std ;

int minimumSpanningTree(vector<vector<int> >& edges, int n)
{


  vector<vector<pair<int,int> > > adj(n) ; 
  for(auto e : edges){
      int u = e[0] ;
      int v = e[1] ;
      int w = e[2] ;

      adj[u].push_back(make_pair(v,w)) ;
      adj[v].push_back(make_pair(u,w)) ;
  }

  vector<bool> visited(n,false);
  priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > pq ;
  pq.push(make_pair(0,0));
  visited[0] = true ;
  int sum = 0 ;
  while(!pq.empty()){
    pair<int,int> c = pq.top() ; 
    pq.pop() ; 
    if(visited[c.second]){
      continue ;
    }

    visited[c.second] ;
    sum += c.first ;

    for(auto e: adj[c.second]){
      if(!visited[e.first]){
        pq.push(make_pair(e.second,e.first));
      }
    }
   }
   return sum ;

}
int main() {
    // Example usage
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 3}, {1, 2, 1}, {1, 3, 2}, {2, 3, 5}};
    int n = 4; // Number of nodes

    int minSpanningTreeWeight = minimumSpanningTree(edges, n);
    cout << "Weight of the minimum spanning tree: " << minSpanningTreeWeight << endl;

    return 0;
}