#pragma once

#include <string>
#include <vector>

namespace googletrans {

    class GoogleTranslator final {

        public:
        GoogleTranslator(const std::string& from, const std::string& to);
        std::string translate(const std::string& text);
        std::string translateFile(const std::string& path);
        
        std::vector<std::string> translateBatch(const std::vector<std::string>& text_array);   
        
        private:
        std::string m_from;
        std::string m_to;
    };
}