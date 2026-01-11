#include <iostream>
#include <filesystem>  // C++17 标准库
namespace fs = std::filesystem;

int main() {
    // 获取程序所在目录
    fs::path current_dir = fs::current_path();
    std::cout << "当前目录: " << current_dir << "\n";
    
    // 遍历目录
    for (const auto& entry : fs::directory_iterator(current_dir)) {
        const auto& path = entry.path();
        
        if (fs::is_directory(entry.status())) {
            std::cout << "[目录] ";
        } else if (fs::is_regular_file(entry.status())) {
            std::cout << "[文件] ";
        }
        
        std::cout << path.filename() << "\n";
    }
    
    return 0;
}
