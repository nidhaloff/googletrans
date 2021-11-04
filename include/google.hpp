#pragma once

#include <string>


namespace googletrans {

    class GoogleTranslator final {

        public:
        GoogleTranslator(const std::string& from, const std::string& to);
        std::string translate(const std::string& text);
        std::string translateFile(const std::string& path);

        private:
        std::string m_from;
        std::string m_to;
    };
}