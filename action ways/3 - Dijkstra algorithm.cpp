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