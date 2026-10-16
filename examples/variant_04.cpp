#include "arraylib.h"
#include <iostream>

int main() {
    // Исходный массив из примера + добавлены отрицательные числа и ноль для проверки
    int data[] = {5, -3, 8, 0, 1, 9, 2};
    
    // Вычисляем размер массива через sizeof (работает только в текущей области видимости)
    std::size_t n = sizeof(data) / sizeof(data[0]);
    

    std::cout << "Количество элементов в массиве: " << n << "\n";
    
    // Вместо троеточия вызываем все функции по очереди:
    std::cout << "Сумма (arr_sum):                  " << arr_sum(data, n) << '\n';
    std::cout << "Максимум (arr_max):               " << arr_max(data, n) << '\n';
    std::cout << "Минимум (arr_min):                " << arr_min(data, n) << '\n';
    std::cout << "Среднее значение (arr_average):   " << arr_average(data, n) << '\n';
    std::cout << "Положительных чисел:             " << arr_count_positive(data, n) << '\n';
    std::cout << "Отрицательных чисел:             " << arr_count_negative(data, n) << '\n';
    std::cout << "Количество нулей:                 " << arr_count_zero(data, n) << '\n';
    std::cout << "Произведение (arr_product):       " << arr_product(data, n) << '\n';
    std::cout << "Медиана (arr_median):             " << arr_median(data, n) << '\n';


    return 0;
}
