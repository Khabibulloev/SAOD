#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// ������� "�����������" ����� ���� - ������������ ����
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // ������ ������������� �������
  int done = 0; // ���� ����, ��� ���� ������������
  // ���� �� ����� �� ���������� ����
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)    // ���� �� � ��������� ����,
      maxChild = root * 2;    // ���������� ����� �������
    // ����� ���������� ������� ������� �� ����
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // ���� ������� ������� ������ ������������� �������
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root]; // ������ �� �������
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // �����
      done = 1; // �������� ������������
  }
}
// ������� ���������� �� ����
void heapSort(int *numbers, int array_size)
{
  // ��������� ������ ��� ��������
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size);
  // ���������� ����� �������� ��������� ��������
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
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
    cout << "������� n" << endl;
    cin >> n;
    int *mas = new int [n]; randmas (mas, n);
    cout << "������ �� ����������" << endl;
    outmas(mas,n);

    time_t start, end;

      time(&start);

      heapSort(mas,n);
      time(&end);
      double seconds = difftime(end, start);

    cout << "������ ����� ����������" << endl;
    outmas(mas,n);
      printf("The time: %f sec\n", seconds);
    return 0;
}
