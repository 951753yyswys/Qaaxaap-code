#include <iostream>

int main() {
    std::cout << "\x1B[?1049h"; // 进入替代缓冲区
    std::cout << "\x1B[2J\x1B[H"; // 清屏并光标归位
    std::cout << "Hello TUI" << std::endl;

    std::string dummy;
    std::getline(std::cin, dummy);

    std::cout << "\x1B[?1049l"; // 返回主缓冲区
}

