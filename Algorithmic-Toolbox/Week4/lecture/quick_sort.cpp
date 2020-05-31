#include <iostream>
#define MAX 10

using namespace std;
void print(int *pArray, size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << pArray[i] << " ";
  }
}
void swap(int *p_a, int *p_b) {
  int temp;
  temp = *p_a;
  *p_a = *p_b;
  *p_b = temp;
}
int partition(int *p_array, int start, int end) {
  int j = start;
  int pivot = p_array[start];
  for (int i = start + 1; i <= end; i++) {
    if (p_array[i] <= pivot) {
      j++;
      swap(&(p_array[i]), &(p_array[j]));
    }
  }
  swap(&(p_array[start]), &(p_array[j]));
  return j;
}
void quick_sort(int *p_array, int start, int end) {
  if (start >= end)
    return;

  int p = partition(p_array, start, end);
  quick_sort(p_array, start, p - 1);
  quick_sort(p_array, p + 1, end);
}

int main(void) {
  int array[MAX];
  for (int i = 0; i < MAX; i++) {
    cin >> array[i];
  }
  quick_sort(array, 0, MAX - 1);
  print(array, MAX);
  return 0;
}
