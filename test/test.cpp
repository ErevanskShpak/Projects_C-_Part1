#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Создание объекта ostringstream
    std::ostringstream oss;

    // Внутреннее форматирование (аналогично использованию cout)
    oss << "Hello, " << 42 << " World!";

    // Получение строки из ostringstream
    std::string result = oss.str();

    // Вывод результата
    std::cout << "Formatted String: " << result << std::endl;

    return 0;
}
