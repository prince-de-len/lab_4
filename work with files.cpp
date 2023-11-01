/*************************************
* Автор: Тимофеев Гордей Евгеньевич. ПИ-231
* Версия 1
* Название: Работа с файлами (Вариант 13)
* Ссылка: https://onlinegdb.com/wlPKcrpyR
************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string firm, word, data, i, lightest_phone, name, common_data, name_min_phone, name_max_phone;
    string path = "/Users/princedelen/Documents/Xcode/Xstudy/phones.txt";
    stringstream str;
    int count, average, price, number_of_models, all_prices, weight, min_weight, common_price,
        max_price, min_price;
    
    count = 0;
    number_of_models = 0;
    all_prices = 0;
    min_weight = 1000000000;
    max_price = 0;
    min_price = 1000000000;
    
    cout << "Введите фирму (Apple, Samsung_Galaxy, Xiaomi):";
    cin >> firm;

    ifstream fin;
    fin.open(path);
    
    if (!fin.is_open()) {
        cout << "Ошибка" << endl;
    }
    else {
        while (!fin.eof()) {
            
            word = "";
            fin >> word;
            
            if (word == firm) {
                
                data = "";
                getline(fin, data);
                data.erase(0, 1);
                
                cout << data << endl;
                
                str << data;
                while (getline(str, data, ' ')) {
                    ++count;
                    
                    if (count == 1) {
                        name = data;
                    }
                    
                    if (count == 3) {
                        weight = stoi(data.substr(0, data.size() - 1));
                        if (min_weight > weight) {
                            min_weight = weight;
                            lightest_phone = name;
                        }
                        
                    }
                    
                    if (count == 4) {
                        ++number_of_models;
                        
                        price = stoi(data.substr(0, data.size() - 7));
                        all_prices += price;
                        
                        if (min_price > price) {
                            min_price = price;
                            name_min_phone = word + " " +  name;
                        }
                        
                        else if (max_price < price) {
                            max_price = price;
                            name_max_phone = word + " " + name;
                        }
                    }
                }
                str.clear();
                count = 0;
            }
            
            else {
                
                common_data = "";
                getline(fin, common_data);
                common_data.erase(0, 1);
                str << common_data;
                
                while (getline(str, common_data, ' ')) {
                    ++count;
                    
                    if (count == 1) {
                        name = common_data;
                    }
                    
                    if (count == 4) {
                        common_price = stoi(common_data.substr(0, common_data.size() - 7));
                        
                        if (min_price > common_price) {
                            min_price = common_price;
                            name_min_phone = word + " " +  name;
                        }
                        
                        else if (max_price < common_price) {
                            max_price = common_price;
                            name_max_phone = word + " " + name;
                        }
                    }
                }
                str.clear();
                count = 0;
            }
        }
        average = all_prices / number_of_models;
        
        cout << "Средняя стоимость всех моделей: " << average << "_руб " << endl;
        cout << "Самый легкий телефон этой фирмы: " << lightest_phone << endl;
        cout << endl;
        cout << "Самый дешевый телефон из всех: " << name_min_phone << " стоимостью "
             << min_price << "_руб"<<  endl;
        cout << "Самый дорогой телефон из всех: " << name_max_phone << " стоимостью "
        << max_price << "_руб" <<  endl;
    }
    
    fin.close();
    
    return 0;
}
