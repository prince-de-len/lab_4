/*************************************
* Автор: Тимофеев Гордей Евгеньевич. ПИ-231
* Версия 2
* Название: Использование процедур и функций (Вариант 13)
* Ссылка: https://onlinegdb.com/SATb3482G
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
    int sum;
    
    sum = 0;
    
    for (int m = 0; m < size_array; ++m) {
        if (array[m] != 0) {
            ++sum;
        }
        
    }
    
    cout << sum;
    
}

int main() {
    
    int n, m;
          
    cout << "Количество элементов массива F: ";
    cin  >> n;
            
    cout << "Количество элементов массива G: ";
    cin  >> m;
    cout << endl;
      
    double F[n], G[m];
      
    cout << "Заполните массив F: " << endl;
    fill_array(F, n);
    cout << endl;

    cout << "Заполните массив G: " << endl;
    fill_array(G, m);
    cout << endl;

    cout << "Количество ненулевых элементов массива F: ";
    count_nonzero(F, n);
    cout << endl;
        
    cout << "Количество ненулевых элементов массива G: ";
    count_nonzero(G, m);
    cout << endl;
    
    return 0;

}
