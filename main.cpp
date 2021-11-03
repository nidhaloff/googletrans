
#include <iostream>
#include "google.hpp"

int main(int argc, char** argv) {

    googletrans::GoogleTranslator g("en", "de");
    std::string g_translation = g.translate("hi man");
    std::cout << "google translation: " << g_translation << std::endl;
}
