#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergesort(vector<int> &v, int l, int r) 
{
    if (l < r) 
    {
        int mid = (l + r) / 2;

        mergesort(v, l, mid);
        mergesort(v, mid + 1, r);

        vector<int> left_Sort(mid - l + 1);
        vector<int> right_Sort(r - mid);

        for (int i = 0; i < (mid - l + 1); ++i)
            left_Sort[i] = v[l + i];

        for (int i = 0; i < (r - mid); ++i)
            right_Sort[i] = v[mid + i + 1];

        int m = 0;
        int n = 0;
        int k = l;

        while (m < (mid - l + 1) && n < (r - mid)) 
        {
            if (left_Sort[m] <= right_Sort[n]) 
            {
                v[k] = left_Sort[m];
                m++;

            } 
            else 
            {
                v[k] = right_Sort[n];
                n++;
            }
            k++;
        }

        while (m < (mid - l + 1)) 
        {
            v[k] = left_Sort[m];
            m++;
            k++;
        }

        while (n < (r - mid)) 
        {
            v[k] = right_Sort[n];
            n++;
            k++;
        }


    }
}

void merge(vector<int> &v, int l, int r) 
{
    if (l < r) 
    {
        int mid = (l + r) / 2;

        merge(v, l, mid);
        merge(v, mid + 1, r);
        mergesort(v, l, r);
    }

}

int main(int argc, char const *argv[]) 
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    merge(v, 0, n - 1);

    return 0;
}
