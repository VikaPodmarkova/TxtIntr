#include <iostream>
#include <algorithm>

int main() {
    
    const int min_operands = 7;
    const int max_operands = 9;
    int num_operands;

    std::cout << "Введите количество операндов (от " << min_operands << " до " << max_operands << "): ";
    std::cin >> num_operands;

    if (num_operands < min_operands || num_operands > max_operands) {
        std::cerr << "Количество операндов не соответствует диапазону." << std::endl;
        return 1;
    }

    double numbers[max_operands];
    std::cout << "Введите " << num_operands << " чисел: ";
    for (int i = 0; i < num_operands; ++i) {
        std::cin >> numbers[i];
    }

    std::sort(numbers, numbers + num_operands);

    double median;
    if (num_operands % 2 == 0) {
        median = (numbers[num_operands / 2 - 1] + numbers[num_operands / 2]) / 2.0;
    } else {
        median = numbers[num_operands / 2];
    }

    std::cout << "Медиана: " << median << std::endl;

    double sum = 0.0;
    std::cout << "Введите " << num_operands << " чисел: ";
    for (int b = 0; b < num_operands; ++b) {
        double number;
        std::cin >> number;
        sum += number;
    }

    double srednee = sum / num_operands;

    std::cout << "Среднее арифметическое: " << srednee << std::endl;

    return 0;
}