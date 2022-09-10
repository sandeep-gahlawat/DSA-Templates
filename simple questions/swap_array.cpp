
#include <bits/stdc++.h>
using namespace std;


int main()
{
    cout<<"enter the size of array"<<endl;
    int n;
    cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    cout<<"enter the first "<<n<<" elements of array 1"<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
        cout<<"enter the first "<<n<<" elements of array 2"<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    cout<<endl<<"array's before swapping"<<endl;
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << ", ";

    cout << "\narr2[] = ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << ", ";
    for (int i = 0; i < n; i++)
    {
        swap(arr1[i], arr2[i]);
    }
   cout<<endl<<"array's after swapping"<<endl;
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++)
        cout << arr1[i] << ", ";

    cout << "\narr2[] = ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << ", ";

    return 0;
}
