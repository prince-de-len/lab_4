/*************************************
 * Автор: Тимофеев Гордей Евгеньевич. ПИ-231
 * Версия 3
 * Название: Использование процедур и функций (Вариант 13)
 * Ссылка: https://onlinegdb.com/5eAvxExpM
 ************************************/

#include <iostream>

using namespace std;

void fill_array(double array[], int size_array) {
  for (int index = 0; index < size_array; ++index) {
    
    cout << index + 1 << ". ";
    cin  >> array[index];    
  }
}

void count_nonzero(double array[], int size_array) {
  int count_nonzero;
  
  count_nonzero = 0;
  
  for (int m = 0; m < size_array; ++m) {
    if (array[m] != 0) {
      ++count_nonzero;
    }
  }
  
  cout << count_nonzero;
  
}

int main() {
  
  int count_elements_F, count_elements_G;
  
  cout << "Количество элементов массива F: ";
  cin  >> count_elements_F;
  
  cout << "Количество элементов массива G: ";
  cin  >> count_elements_G;
  cout << endl;
  
  double F[count_elements_F], G[count_elements_G];
  
  cout << "Заполните массив F: " << endl;
  fill_array(F, count_elements_F);
  cout << endl;
  
  cout << "Заполните массив G: " << endl;
  fill_array(G, count_elements_G);
  cout << endl;
  
  cout << "Количество ненулевых элементов массива F: ";
  count_nonzero(F, count_elements_F);
  cout << endl;
  
  cout << "Количество ненулевых элементов массива G: ";
  count_nonzero(G, count_elements_G);
  cout << endl;
  
  return 0;
  
}
