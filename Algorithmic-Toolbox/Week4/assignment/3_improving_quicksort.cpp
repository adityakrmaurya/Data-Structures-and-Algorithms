#include <iostream>
#include <time.h>

using namespace std;

void print(int *p_array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << p_array[i] << " ";
  }
}
void swap(int *p_a, int *p_b) {
  int temp;
  temp = *p_a;
  *p_a = *p_b;
  *p_b = temp;
}
void partition(int *p_array, int start, int end, int *j) {
  j[0] = j[1] = start;
  int pivot = p_array[start];

  for (int i = start + 1; i <= end; i++) {
    if (p_array[i] == pivot) {
      j[1]++;
      swap(&(p_array[i]), &(p_array[j[1]]));
    } else if (p_array[i] < pivot) {
      j[1]++;
      swap(&(p_array[i]), &(p_array[j[1]]));
      swap(&(p_array[j[0]]), &(p_array[j[1]]));
      j[0]++;
    }
  }
}
void random_quick_sort(int *p_array, int start, int end) {
  if (start >= end)
    return;
  int k = (rand() % (end - start + 1)) + start;
  swap(&(p_array[k]), &(p_array[start]));

  int j[2];
  partition(p_array, start, end, j);
  random_quick_sort(p_array, start, j[0] - 1);
  random_quick_sort(p_array, j[1] + 1, end);
}

int main(void) {
  int max;
  cin >> max;
  int array[max];
  for (int i = 0; i < max; i++) {
    cin >> array[i];
  }
  srand(time(0));
  random_quick_sort(array, 0, max - 1);
  print(array, max);
  return 0;
}
