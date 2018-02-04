#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void InsertSort(int *mas, int n) //сортировка вставками
{
for (int i=0; i<n-1; i++)
{
int key=i+1;
int temp=mas[key];
for (int j=i+1; j>0; j--)
{
if (temp<mas[j-1])
{
mas[j]=mas[j-1];
key=j-1;
}
}
mas[key]=temp;
}
}

void outmas(int *a, int size)
{
    for (int i=0;i<size;i=i+1)
    {cout<<i<< "  "<< a[i]<<endl;
    }
}

int randmas (int *a, int size)
{
    for (int i=0; i<size;i++)
    {a[i]= rand();
    }
    return(*a);
}
int main()
{
    int n,k;
    setlocale(LC_ALL, "RUS"); srand(time(NULL));
    cout << "Введите n" << endl;
    cin >> n;
    int *mas = new int [n]; randmas (mas, n);
    cout << "Массив до сортировки" << endl;
    outmas(mas,n);

    time_t start, end;

      time(&start);

      InsertSort(mas,n);
      time(&end);
      double seconds = difftime(end, start);


    cout << "Массив после сортировки" << endl;
    outmas(mas,n);
      printf("The time: %f sec\n", seconds);
    return 0;
}
