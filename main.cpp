
#include <iostream>
#include "google.hpp"

#include <array>
#include <vector>

int main(int argc, char** argv) {

    googletrans::GoogleTranslator g("en", "de");
    std::string g_translation = g.translate("hi man");
    std::cout << "google translation: " << g_translation << std::endl;

    auto content = g.translateFile("../file.txt");
    std::cout << "file: " << content << std::endl;

    std::vector<std::string> arr = {"good", "bad"};
    auto arr_res = g.translateBatch(arr);
    for (auto x : arr_res) std::cout << "arr res: " << x << std::endl;
}
