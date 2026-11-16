#include <iostream>
#include <map>
const int kMaxNodes = 6;
struct Grafo
{
    int matrix[kMaxNodes][kMaxNodes];
    int size;
};
void inicializarGrafo(Grafo &graph, int size)
{
    graph.size = size;
    // 0-> o(1)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i < size; j++)
        {
            graph.matrix[i][j] = 0;
        }
    }
}
void addEger(Grafo &graph, int from, int to)
{
    graph.matrix[from][to] = 1;
    graph.matrix[to][from] = 1;
}
bool HasEdge(Grafo &graph, int from, int to)
{
    if (graph.matrix[from][to] = 1)
    {
        return true;
    }
}
int Degree(const Grafo &graph, int node)
{
    int count = 0;
    for (int j = 0; j < graph.size; j++)
    {
        if (graph.matrix[node][j] == 1)
        {
            count++;
        }
    }
}

void RemoveEger(Grafo &graph, int from, int to)
{
    graph.matrix[from][to] = 0;
    graph.matrix[to][from] = 0;
}
using namespace std;

int main()
{
    Grafo graph1;
    inicializarGrafo(graph1, 6);
    addEger(graph1, 0, 1);
    addEger(graph1, 0, 2);
    addEger(graph1, 1, 3);
    addEger(graph1, 2, 3);
    addEger(graph1, 3, 4);
    addEger(graph1, 4, 5);
    cout << "CONEXION ENTRE 3 Y 4 " << endl;
    cout << HasEdge(graph1, 3 4) << endl;
    return 0;
}
/*
QUE FALTA 
VER CUALES CUALES CONEXIONES TIENE EL NODE 3 ( BUSCAR EN CADA ELEMENTOS TIENE 1 )
CUALES (QUIENES ESTA CONEXTADO 3 )

*/