#include <iostream>
#include <queue>
using namespace std;

void Adjacency_matrix();                            // adjacency matrix (breadth-first graph search)
void Own_adjacency_matrix();                        // your own adjacency matrix (breadth-first graph search)
void Dijkstra_algorithm();                          // realization of the shortest way
void Prima_algorithm();                             // the minimum skeletal tree of the graph

int main()
{
    int a; 

    cout << "\n\t--------------------------------------\n\t|      Action ways with graphs       |\n\t--------------------------------------\n\t|\t\t\t\t     |";
    cout<<"\n\t|  Adjacency matrix (prepared) - 1   |\n\t|  Adjacency matrix (your own) - 2   |\n\t|  Dijkstra algorithm - 3\t     |";
    cout << "\n\t|  Prima algorithm - 4\t\t     | ";
    cout<<"\n\t|\t\t\t\t     |\n\t--------------------------------------\n\n\t  Enter type of action : ";
    cin >> a;
    cout << "\n_____________________________________________________";
    
    switch (a) 
    {
        case 1:Adjacency_matrix();
            break;
        case 2:Own_adjacency_matrix();
            break;
        case 3:Dijkstra_algorithm();
            break;
        case 4:Prima_algorithm();
            break;
        default:
            break;
    }
    
    return 0;
}



void Adjacency_matrix()
{
    queue<int> Queue;
    int mas[7][7] = {
    { 0, 1, 1, 0, 0, 0, 1 },                            // adjacency matrix
    { 1, 0, 1, 1, 0, 0, 0 },                            //
    { 1, 1, 0, 0, 0, 0, 0 },                            //          state of graphs
    { 0, 1, 0, 0, 1, 0, 0 },                            //      -----------------------
    { 0, 0, 0, 1, 0, 1, 0 },                            //      0 - not visited
    { 0, 0, 0, 0, 1, 0, 1 },                            //      1 - marked , but not visited
    { 1, 0, 0, 0, 0, 1, 0 } };                          //      2 - visited 

    int count = 1;

    cout << "\n\n\t\t   Matrix"<<"\n\n    ";

    for (int i = 0; i < 7; i++)
    {       
        cout <<"\t  " << count << " -> ";
        for (int j = 0; j < 7; j++)
        {                                     
            if (mas[i][j] == 1)
                cout << j+1<<" ";
        }
        count++;
        cout << "\n    ";
    }

    int nodes[7];                                       // graph vertices
    for (int i = 0; i < 7; i++)
        nodes[i] = 0;                                   // for start all vertices = 0

    int b;
    cout << "\n\n\t   Start vertice -> ";
    cin >> b;
    cout << "\n\n    ";

    Queue.push(b - 1);                                  // 1-st vertice goes in a queue

    while (!Queue.empty())
    {                                                   // while queue isn`t empty
        int node = Queue.front();                       // number of the vertice enter for node
        Queue.pop();
        nodes[node] = 2;                                // note is visited
        for (int j = 0; j < 7; j++)
        {                                               // check all adjacent vertices
            if (mas[node][j] == 1 && nodes[j] == 0)     // if the vertice adjacent and not visited
            {
                Queue.push(j);                          // it goes in a queue
                nodes[j] = 1;                           // note this vertice marked
            }
        }
        cout << node + 1;                       // displaying the number of the vertice what was processed
        if (!Queue.empty())
            cout << "  -->  ";
        else
        {
            cout << "\n";
            break;
        }

    }
}


void Own_adjacency_matrix()         // algorithm the same as in the function: Adjacency_matrix() but you enter this martix
{
    int n;
    cout << "\n\n\t  Enter count of elements : ";
    cin >> n;

    int **a, count=1, ver=1;

    a = new int*[n];                //
    for (int i = 0; i < n; i++)     //dyn. memory for matrix
        a[i] = new int[n];          //

    for (int i = 0; i < n; i++)
    {
        cout << "Vertice #"<< i+1 <<" connected with : ";
        while(1)
        {
            cin >> ver;
            if (ver == 0)
                break;
            a[i][ver-1] = 1;
        }
    }
    cout << "\n";
    cout << "\t\t   Matrix\n\n" ;

    for (int i = 0; i < n; i++)
    {
        cout << "\t  " << i+1 << " -> ";
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 0)
                a[i][j] = 0;
            else
                cout << j + 1 << " ";
        }
        printf("\n");
    }

    int nodes[100];                            // graph vertices
    for (int i = 0; i < 7; i++)
        nodes[i] = 0;                                   // for start all vertices = 0
    queue<int> Queue;

    int b;
    cout << "\n\n\t   Start vertice -> ";
    cin >> b;
    cout << "\n\n    ";

    Queue.push(b-1);                                      // 1-st vertice goes in a queue

    while (!Queue.empty())
    {                                                   // while queue isn`t empty
        int node = Queue.front();                       // number of the vertice enter for node
        Queue.pop();
        nodes[node] = 2;                                // note is visited
        for (int j = 0; j < n; j++)
        {                                               // check all adjacent vertices
            if (a[node][j] == 1 && nodes[j] == 0)     // if the vertice adjacent and not visited
            {
                Queue.push(j);                          // it goes in a queue
                nodes[j] = 1;                           // note this vertice marked
            }
        }
        cout << node + 1;                       // displaying the number of the vertice what was processed
        if (!Queue.empty())
            cout << "  -->  ";
        else
        {
            cout << "\n";
            break;
        }

    }

    for (int i = 0; i < n; i++)         //
        delete[] a[i];                  //clear memory
                                        //
    delete[] a;                         //
}


void Dijkstra_algorithm()
{
    int n, oriented, temp;
    cout << "\n\n\t  Enter count of elements : ";
    cin >> n;
    cout << "\n\t  Is this graph oriented? ( 1-yes, 0-no ) : ";
    cin >> oriented;
    cout << "\n";

    int** a, count = 1, ver = 1, k;

    a = new int* [n];               //
    for (int i = 0; i < n; i++)     //dyn. memory for matrix
        a[i] = new int[n];          //

    int* dist = new int[n];         // min distance
    int* visit = new int[n];        // visited vetices

    if(oriented!=1)
    {
        cout << "   <->    Enter the distance between : \n\n";
        for (int i = 0; i < n; i++)
        {
            a[i][i] = 0;
            for (int j = i + 1; j < n; j++) 
            {
                cout << "\t\t" << i + 1 << " --> " << j + 1 << "  = ";
                cin >> temp;
                a[i][j] = temp;
                a[j][i] = temp;
            }
        }
    }

    else
    {
        cout << "   <->    Enter the distance between : \n\n";
        for (int i = 0; i < n; i++)
        {
            a[i][i] = 0;
            for (int j = 0; j < n; j++) 
            {
                if(i!=j)
                {
                    cout <<"\t\t" << i + 1 << " --> " << j + 1 << "  = ";
                    cin >> temp;
                    a[i][j] = temp;
                }
            }
        }
    }
    cout << "\n\t\t   Matrix\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
            printf("%-5d ", a[i][j]);
        cout<<"\n";
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = 1000;
        visit[i] = 1;
    }
    cout << "\n______________________________________________________\n\n\t  Enter the start : ";
    cin >> k;
    dist[k-1] = 0;

    int limit;
    int min;
    do {
        limit = 1000;
        min = 1000;
        for (int i = 0; i < n; i++)             // if the vertice isn`t visited and dist < min (10000)
        { 
            if ((visit[i] == 1) && (dist[i] < min))
            {                                           //reassign our values
                min = dist[i];
                limit = i;
            }
        }
        
        if (limit != 1000)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[limit][i] > 0)
                {
                    temp = min + a[limit][i];
                    if (temp < dist[i])
                    {
                        dist[i] = temp;
                    }
                }
            }
            visit[limit] = 0;
        }
    } while (limit < 1000);

    cout<<"\nThe shortest ways to another vertices: \n";
    for (int i = 0; i < n; i++)
    {
        if (k != i + 1)
            cout << "\t\t" << k << " --> " << i + 1 << "  = " << dist[i] << endl;
    }

    for (int i = 0; i < n; i++)         //
        delete[] a[i];                  //clear memory
                                        //
    delete[] a;                         //
    delete[] dist;
    delete[] visit;
}


void Prima_algorithm() 
{
        int a, b, u, v, n, i, j, ne = 1;
        int visited[10] = { 0 }, min, mincost = 0, cost[100][100];
        int path[100] = { 0 }; 
        int path_index = 0;

        cout << "\n\n\tEnter the count of vertices :  "; cin >> n;
        cout << "\tEnter the matrix : \n";


        for (int i = 1; i <=n; i++)
        {
            cost[i][i] = 999;
            for (int j = i + 1; j <=n; j++)
            {
                cout << "\t\t" << i << " --> " << j << "  = ";
                cin >> cost[i][j];
                if (cost[i][j] == 0)
                {
                    cost[i][j] = 999;
                    cost[j][i] = 999;
                }
                else
                    cost[j][i] = cost[i][j];
            }
        }
        visited[1] = 1;
        cout << "\n";

        while (ne < n)
        {
            for (i = 1, min = 999; i <=n; i++)
                for (j = 1; j <=n; j++)
                    if (cost[i][j] < min)
                        if (visited[i] != 0)
                        {
                            min = cost[i][j];
                            a = u = i;
                            b = v = j;
                        }
            if (visited[u] == 0 || visited[v] == 0)
            {
                path[path_index] = b;
                path_index++;
                ne++; 
                mincost += min;
                visited[b] = 1;

            }
            cost[a][b] = cost[b][a] = 999;
        }


        cout << "\n";

        cout <<"  " << 1 << " --> ";
        for (int i = 0; i < n - 1; i++)
        {
            cout << path[i];
            if (i < n - 2) cout << " --> ";
        }

        cout << "\n  Min cost = " << mincost << endl;
}