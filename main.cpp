#include <iostream>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <clocale>

// ==========================================
// ОБЪЯВЛЕНИЯ ФУНКЦИЙ БИБЛИОТЕКИ
// ==========================================
int arr_sum(const int* arr, std::size_t n);
int arr_max(const int* arr, std::size_t n);
int arr_min(const int* arr, std::size_t n);
double arr_average(const int* arr, std::size_t n);
int arr_count_positive(const int* arr, std::size_t n);
int arr_count_negative(const int* arr, std::size_t n);
int arr_count_zero(const int* arr, std::size_t n);
long long arr_product(const int* arr, std::size_t n);
double arr_median(const int* arr, std::size_t n);

// ==========================================
// ГЛАВНАЯ ФУНКЦИЯ (ТОЧКА ВХОДА)
// ==========================================
int main() {
    // Установка русской локали для корректного вывода в консоль
    std::setlocale(LC_ALL, "Russian");

    int times[] = {
        248, 261, 239, 275, 252,
        244, 268, 231, 257, 249
    };
    std::size_t n = sizeof(times) / sizeof(times[0]);

    // В спорте меньшее время — это ЛУЧШИЙ результат, а большее — ХУДШИЙ
    int best_time = arr_min(times, n);
    int worst_time = arr_max(times, n);
    double avg_time = arr_average(times, n);
    double median_time = arr_median(times, n);

    // Считаем количество результатов быстрее 250 секунд (время < 250).
    // Составим массив разностей: (250 - время). Если значение > 0, то время < 250.
    std::vector<int> diffs(n);
    for (std::size_t i = 0; i < n; ++i) {
        diffs[i] = 250 - times[i];
    }
    int faster_than_250 = arr_count_positive(diffs.data(), n);

    // Вывод результатов
    std::cout << "--- Результаты забега ---" << std::endl;
    std::cout << "Лучшее время: " << best_time << " сек." << std::endl;
    std::cout << "Худшее время: " << worst_time << " сек." << std::endl;
    std::cout << "Среднее время: " << avg_time << " сек." << std::endl;
    std::cout << "Медиана времени: " << median_time << " сек." << std::endl;
    std::cout << "Количество результатов быстрее 250 секунд: " << faster_than_250 << std::endl;

    return 0;
}

// ==========================================
// РЕАЛИЗАЦИЯ ФУНКЦИЙ БИБЛИОТЕКИ
// ==========================================

int arr_sum(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int arr_max(const int* arr, std::size_t n) {
    if (n == 0) throw std::invalid_argument("Массив пуст");
    int max_val = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > max_val) max_val = arr[i];
    }
    return max_val;
}

int arr_min(const int* arr, std::size_t n) {
    if (n == 0) throw std::invalid_argument("Массив пуст");
    int min_val = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < min_val) min_val = arr[i];
    }
    return min_val;
}

double arr_average(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    return static_cast<double>(arr_sum(arr, n)) / n;
}

int arr_count_positive(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] > 0) ++count;
    }
    return count;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < 0) ++count;
    }
    return count;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int count = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) ++count;
    }
    return count;
}

long long arr_product(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    long long product = 1;
    for (std::size_t i = 0; i < n; ++i) {
        product *= arr[i];
    }
    return product;
}

double arr_median(const int* arr, std::size_t n) {
    if (n == 0) throw std::invalid_argument("Массив пуст");
    
    // Создаем копию во вспомогательный вектор, чтобы не менять исходный массив
    std::vector<int> temp(arr, arr + n);
    std::sort(temp.begin(), temp.end());
    
    if (n % 2 != 0) {
        return static_cast<double>(temp[n / 2]);
    } else {
        return (static_cast<double>(temp[n / 2 - 1]) + temp[n / 2]) / 2.0;
    }
}
