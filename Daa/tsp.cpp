#include <iostream>
using namespace std;

class TSP
{

public:
    int num, a[10][10], tour[10], cost;
    void getdata();
    int tsp(int a[10][10], int tour[10], int start, int num);
};

int TSP ::tsp(int a[10][10], int tour[10], int start, int num)
{
    int mintour[10], temp[10], mincost = 999, ccost, i, j, k;
    if (start == num - 1)
    {
        return (a[tour[num - 1]][tour[num]] + a[tour[num]][1]);
    }
    for (i = start + 1; i <= num; i++)
    {
        for (j = 1; j <= num; j++)
        {
            temp[j] = tour[j];
        }
        temp[start + 1] = tour[i];
        temp[i] = tour[start + 1];
        if ((a[tour[start]][tour[i]] + (ccost = tsp(a, temp, start + 1, num))) < mincost)
        {
            mincost = a[tour[start]][tour[i]] + ccost;
            for (k = 1; k <= num; k++)
                mintour[k] = temp[k];
        }
    }
    for (i = 1; i <= num; i++)
    {
        tour[i] = mintour[i];
    }
    return mincost;
}

void TSP ::getdata()
{
    cout << "Enter Number Of Cities" << endl;
    cin >> num;
    if (num == 1)
    {
        cout << "Path Is Not Possible" << endl;
    }
    else
    {

        cout << "Enter the cost matrix" << endl;
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j <= num; j++)
            {

                cin >> a[i][j];
            }
        }
    }
    cout << "The Travelling SalesMan Problem" << endl;
    cout << "The Cost Matrix is " << endl;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            cout << "\t" << a[i][j];
        }
        cout << endl;
    }
    for (int i = 1; i <= num; i++)
    {
        tour[i] = i;
    }
    cost = tsp(a, tour, 1, num);
    cout << "The Optimal Tour is " << endl;
    for (int i = 1; i <= num; i++)
    {
        cout << tour[i] << " -> ";
    }
    cout << "1" << endl;
    cout << "The Minimum Cost is " << cost << endl;
}

int main()
{
    TSP obj;
    obj.getdata();
    return 0;
}
