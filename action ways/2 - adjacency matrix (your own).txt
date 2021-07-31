void Own_adjacency_matrix()         // algorithm the same as in the function: Adjacency_matrix() but you enter this martix
{
    int n;
    cout << "\n\n\t  Enter count of elements : ";
    cin >> n;

    int **a, count=1, ver=1,k;

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

    int nodes[7];                                       // graph vertices
    for (int i = 0; i < 7; i++)
        nodes[i] = 0;                                   // for start all vertices = 0
    queue<int> Queue;

    Queue.push(0);                                      // 1-st vertice goes in a queue
    cout << "\n\n\t   Start vertice -> " << Queue.front() + 1 << "\n\n    ";

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