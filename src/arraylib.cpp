#include "arraylib.h"
#include <algorithm> 
#include <vector>   

int arr_sum(const int* arr, std::size_t n) {
    int sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int arr_max(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int max_val = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int arr_min(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int min_val = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

// 4. Среднее арифметическое значение
double arr_average(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    // Делим сумму на количество элементов, приводя сумму к типу double
    return static_cast<double>(arr_sum(arr, n)) / n;
}

// 5. Количество положительных элементов
int arr_count_positive(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] > 0) count++;
    }
    return count;
}

// 6. Количество отрицательных элементов
int arr_count_negative(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < 0) count++;
    }
    return count;
}

// 7. Количество нулей в массиве
int arr_count_zero(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) count++;
    }
    return count;
}

// 8. Произведение всех элементов массива
int arr_product(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int prod = 1;
    for (std::size_t i = 0; i < n; ++i) {
        prod *= arr[i];
    }
    return prod;
}

// 9. Поиск медианы массива
double arr_median(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    
    // Создаем копию массива в виде вектора, чтобы не портить исходный массив сортировкой
    std::vector<int> vec(arr, arr + n);
    std::sort(vec.begin(), vec.end());
    
    // Если количество элементов нечетное — берем центральный
    if (n % 2 != 0) {
        return vec[n / 2];
    }
    // Если четное — среднее арифметическое двух центральных
    return (vec[(n / 2) - 1] + vec[n / 2]) / 2.0;
}
