#include <bits/stdc++.h>
using namespace std;

 
int NO_PARENT = -1;


/* This part taken from GeeksForGeeks with slight modification*/
/* source : https://www.geeksforgeeks.org/different-ways-to-print-elements-of-vector/ */
template <typename S>
ostream& operator<<(ostream& os,
                    const vector<S>& vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector) {
        os << "->" << element << endl;
    }
    return os;
}

/*This part taken from GeeksForGeeks with slight modification*/
/* source : https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/ */
// A Java program for Dijkstra's
// single source shortest path
// algorithm. The program is for
// adjacency matrix representation
// of the graph.

// Function to print shortest path
// from source to currentVertex
// using parents array
void printPath(int currentVertex, vector<int> parents, vector<string> nodename)
{
 
    // Base case : Source node has
    // been processed
    if (currentVertex == NO_PARENT) {
        return;
    }
    printPath(parents[currentVertex], parents, nodename);
    cout << "->"  << nodename[currentVertex];
}
 
// A utility function to print
// the constructed distances
// array and shortest paths
void printSolution(int startVertex, vector<double> distances,
                   vector<int> parents, vector<string> nodename)
{
    int nVertices = distances.size();
    cout << "Ruang\t\t\t Distance\t\tPath";
 
    for (int vertexIndex = 20; vertexIndex < 26;
         vertexIndex++) {
        if (vertexIndex != startVertex) {
            cout << "\n" << nodename[startVertex] << " -> ";
            cout << nodename[vertexIndex] << "\t   ";
            cout << distances[vertexIndex] << "m\t\t";
            printPath(vertexIndex, parents, nodename);
        }
    }
}
 
// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix
// representation
 
void dijkstra(vector<vector<double> > adjacencyMatrix, 
              vector<string> nodename,
              int startVertex)
{
    int nVertices = adjacencyMatrix[0].size();
 
    // shortestDistances[i] will hold the
    // shortest distance from src to i
    vector<double> shortestDistances(nVertices);
 
    // added[i] will true if vertex i is
    // included / in shortest path tree
    // or shortest distance from src to
    // i is finalized
    vector<bool> added(nVertices);
 
    // Initialize all distances as
    // INFINITE and added[] as false
    for (int vertexIndex = 0; vertexIndex < nVertices;
         vertexIndex++) {
        shortestDistances[vertexIndex] = 999999.0;
        added[vertexIndex] = false;
    }
 
    // Distance of source vertex from
    // itself is always 0
    shortestDistances[startVertex] = 0.0;
 
    // Parent array to store shortest
    // path tree
    vector<int> parents(nVertices);
 
    // The starting vertex does not
    // have a parent
    parents[startVertex] = NO_PARENT;
 
    // Find shortest path for all
    // vertices
    for (int i = 1; i < nVertices; i++) {
 
        // Pick the minimum distance vertex
        // from the set of vertices not yet
        // processed. nearestVertex is
        // always equal to startNode in
        // first iteration.
        double nearestVertex = -1.0;
        double shortestDistance = 999999.0;
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            if (!added[vertexIndex]
                && shortestDistances[vertexIndex]
                       < shortestDistance) {
                nearestVertex = vertexIndex;
                shortestDistance
                    = shortestDistances[vertexIndex];
            }
        }
 
        // Mark the picked vertex as
        // processed
        added[nearestVertex] = true;
 
        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int vertexIndex = 0; vertexIndex < nVertices;
             vertexIndex++) {
            double edgeDistance
                = adjacencyMatrix[nearestVertex]
                                 [vertexIndex];
 
            if (edgeDistance > 0
                && ((shortestDistance + edgeDistance)
                    < shortestDistances[vertexIndex])) {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex]
                    = shortestDistance + edgeDistance;
            }
        }
    }
 
    printSolution(startVertex, shortestDistances, parents, nodename);
}

/*How to get position of a certain element in strings vector, to use it as an index in ints vector?*/
/* Answer by Hoen */
/*https://stackoverflow.com/questions/15099707/how-to-get-position-of-a-certain-element-in-strings-vector-to-use-it-as-an-inde*/
int getVecPos(vector<string> vec, string element){
    int i;
    for(i = 0; i < vec.size(); i++){
        if(vec[i] == element){
            break;
        }
    }
    if(i == vec.size()){
        cout<<"Ruangan "<<element<<" tidak ditemukan. Masukkan nama ruangan kembali : ";
        cin>>element;
        i = getVecPos(vec, element);
    }
        
    return i;
}
 
