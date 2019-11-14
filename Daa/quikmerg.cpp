#include <iostream>
#include <ctime>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int u)
{
    int pivot, i, j, temp;
    pivot = a[u];
    i = l - 1;

    for (j = l; j < u; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[u]);
    return (i + 1);
}

void quick_sort(int a[], int l, int u)
{

    int j;
    if (l < u)
    {
        j = partition(a, l, u);
    quick_sort(a, l, j - 1);
    quick_sort(a, j + 1, u);
}}

void merge(int a[], int l, int m, int u)
{
    int i, j, k;
    int p = m - l + 1;
    int q = u - m;

    int L[p], R[q];

    for (i = 0; i < p; i++)
        L[i] = a[l + i];
    for (j = 0; j < q; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < p && j < q)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }  
    while (i < p)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < q)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int l, int u)
{

    if (l < u)
    {

        int m;
        m = (l + u) / 2;
        merge_sort(a, l, m);

        merge_sort(a, m + 1, u);
        merge(a, l, m, u);
    }
}

int main()
{
    int a[50], n, i, choice;
    cout << "How many elements you want to enter ?" << endl;
    cin >> n;
    cout << "\nEnter array elements : " << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1. Quick Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;

    clock_t time_req;
    time_req = clock();

    if (choice == 1)
        quick_sort(a, 0, n - 1);
    else if (choice == 2)
        merge_sort(a, 0, n - 1);
    time_req = clock() - time_req;
    cout << "\nArray after sorting:";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nIt took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
