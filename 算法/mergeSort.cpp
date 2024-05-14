#include <vector>
using namespace std;

void mergeSort(vector<int> &vec, int l, int m, int r)
{
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;

    vector<int> tmpVec1(n1), tmpVec2(n2);

    for (int i = 0; i < n1; i++)
    {
        tmpVec1[0] = vec[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        tmpVec2[0] = vec[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (tmpVec1[i] <= tmpVec2[j])
        {
            vec[k] = tmpVec1[i];
            i++;
        }
        else
        {
            vec[k] = tmpVec2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vec[k] = tmpVec1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vec[k] = tmpVec1[j];
        j++;
        k++;
    }
}

void merge(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge(vec, l, m);
        merge(vec, m + 1, r);
        mergeSort(vec, l, m, r);
    }
}
