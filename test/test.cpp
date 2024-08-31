#include <iostream>
#include <sstream>
#include <string>

int main() {
    // �������� ������� ostringstream
    std::ostringstream oss;

    // ���������� �������������� (���������� ������������� cout)
    oss << "Hello, " << 42 << " World!";

    // ��������� ������ �� ostringstream
    std::string result = oss.str();

    // ����� ����������
    std::cout << "Formatted String: " << result << std::endl;

    return 0;
}
