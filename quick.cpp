#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quicksort(int *mas, int first, int last)
{
int mid, count;
int f=first, l=last;
mid=mas[(f+l) / 2]; //вычисление опорного элемента
do
{
while (mas[f]<mid) f++;
while (mas[l]>mid) l--;
if (f<=l) //перестановка элементов
{
count=mas[f];
mas[f]=mas[l];
mas[l]=count;
f++;
l--;
}
} while (f<l);
if (first<l) quicksort(mas, first, l);
if (f<last) quicksort(mas, f, last);
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

      quicksort(mas,0,n-1);
      time(&end);
      double seconds = difftime(end, start);


    cout << "Массив после сортировки" << endl;
    outmas(mas,n);
      printf("The time: %f sec\n", seconds);
    return 0;
}
