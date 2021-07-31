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

    Queue.push(0);                                      // 1-st vertice goes in a queue
    cout << "\n\n\t   Start vertice -> " << Queue.front() + 1 << "\n\n    ";

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