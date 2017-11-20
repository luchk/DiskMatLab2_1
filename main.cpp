#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int q, int f)
{
    int s = a[q];
    a[q] = a[f];
    a[f] = s;
}

long int fack(int x)
{
    if (x>=1)
        return x*fack(x-1);
    else
        return 1;
}

void newLine(void)
{
    cout << " " << endl;
}
int main() {
    int n;

    cout << "введіть кількість елементів у масиві для перебору ";
    cin >> n;

    int mass[n];

    int size = sizeof(mass)/sizeof(mass[0]);

    long int numberOfSwaps = fack(size);
    long int numberOfSwapsCounter = 0;

    for (int j = 0; j < n ; ++j)
    {
        cout << "введіть " << j << " значення масиву" << endl;
        cin >> mass[j];
    }

//    for (int i = 0; i < n; ++i) {
//        cout << mass[i] << endl;
//    }

//    sort(mass, mass+size);

    for (int i = 0; i < n ; ++i) { // вивід масиву
        cout << mass[i] << " ";
    }
    newLine();

    while(numberOfSwapsCounter < numberOfSwaps)
    {
//        for (int i = 0; i < n; ++i)
//        {
//            cout << mass[i] << endl;
//        }

        for(int k = n-1; k >0; k--)
        {


            if(mass[k-1]<mass[k])
            {
//              cout << mass[k-1] << mass[k]<< endl;
                swap(mass,k-1, k);
//              cout << numberOfSwapsCounter << "; ";
                for (int i = 0; i < n ; ++i) { // вивід масиву
                    cout << mass[i] << " ";
                }
                newLine();
                break;
            }
            sort(mass+k+1, mass+size);
        }
        numberOfSwapsCounter++;

    }
    cout << size << endl;
    cout << n << endl;

    return 0;
}