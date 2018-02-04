#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Swap(int *Mas, int i)
{
int temp;
temp=Mas[i];
Mas[i]=Mas[i-1];
Mas[i-1]=temp;
}

void ShakerSort(int *Mas, int Start, int N)
{
int Left, Right, i;
Left=Start;
Right=N-1;
while (Left<=Right)
{
for (i=Right; i>=Left; i--)
if (Mas[i-1]>Mas[i]) Swap(Mas, i);
Left++;
for (i=Left; i<=Right; i++)
if (Mas[i-1]>Mas[i]) Swap(Mas, i);
Right--;
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
    setlocale(LC_ALL, "RUS");
    cout << "Введите n" << endl;
    cin >> n;
    int *mas = new int [n]; randmas (mas, n);
    cout << "Массив до сортировки" << endl;
    mas[0] = 10000;
    outmas(mas,n);

    time_t start, end;

      time(&start);

      ShakerSort(mas,1,n);
      time(&end);
      double seconds = difftime(end, start);


    cout << "Массив после сортировки" << endl;
    outmas(mas,n);
      printf("The time: %f sec\n", seconds);
    return 0;
}
