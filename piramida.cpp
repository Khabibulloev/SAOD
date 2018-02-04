#include <iostream>
#include <ctime>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size)
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size);
  // Просеиваем через пирамиду остальные элементы
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
    cout << "Введите n" << endl;
    cin >> n;
    int *mas = new int [n]; randmas (mas, n);
    cout << "Массив до сортировки" << endl;
    outmas(mas,n);

    time_t start, end;

      time(&start);

      heapSort(mas,n);
      time(&end);
      double seconds = difftime(end, start);

    cout << "Массив после сортировки" << endl;
    outmas(mas,n);
      printf("The time: %f sec\n", seconds);
    return 0;
}
