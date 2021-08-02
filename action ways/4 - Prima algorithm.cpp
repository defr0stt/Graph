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