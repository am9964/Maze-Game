#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;
struct Edge{
    int source, dest, cost;
};

void printPath(vector<int> const &parent, int vertex){
    if (vertex < 0){
        return;
    }
    printPath(parent, parent[vertex]);
    cout << vertex << " ";
}

void bellmanFord(vector<Edge> const &edges, int source, int N, int dest){
    vector<int> distance (N, INT_MAX);
    distance[source] = 0;
    vector<int> parent (N, -1);
    int u, v, w, k = N;
    while (--k){
        for (Edge edge: edges){
            u = edge.source;
            v = edge.dest;
            w = edge.cost;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }
    for (Edge edge: edges){
        u = edge.source;
        v = edge.dest;
        w = edge.cost;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]){
            cout << "Negative-weight cycle is found!!";
            return;
        }
    }
    cout << "The distance of vertex " << dest << " from the source is "<< distance[dest] << ". Its path is [ ";
    printPath(parent, dest);
    cout << "]" << endl;
}

int main(int argc, char **argv){
    int side;
    int num_vertices=-1;
    cout<<"Enter size of side for maze: ";
    cin>>side;
    int maze[side][side],cost[side][side];
    cout<<"Enter maze elements: \n";
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++){
            cin>>maze[i][j];
            if(maze[i][j]==0){
                num_vertices++;
                maze[i][j]=num_vertices;
            }
        }
    }
    cout<<"\nEnter cost matrix elements: \n";
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++)
            cin>>cost[i][j];
    }
    cout<<"\nDisplaying maze with marked vertices: \n";
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++)
            cout<< maze[i][j]<<" ";
        cout<<endl;
    }
    vector<Edge> edges;
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++){
            if(maze[i][j]!=-1){
                if(maze[i+1][j]!=-1 && i+1<side)
                    edges.push_back({maze[i][j],maze[i+1][j],cost[i+1][j]});
                if(maze[i][j+1]!=-1 && j+1<side)
                    edges.push_back({maze[i][j],maze[i][j+1],cost[i][j+1]});
            }
        }
    }
    int source=0;
    int destination=num_vertices;
    bellmanFord(edges, source, num_vertices,destination);
    return 0;
}