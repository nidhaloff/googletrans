
#include <iostream>

#include <cpr/cpr.h>

#include "constants.hpp"
#include "google.hpp"

namespace googletrans {

    GoogleTranslator::GoogleTranslator(const std::string& from, const std::string& to)
    : m_from{from}, m_to{to}
    {
        std::cout << "google translator created\n";
    }

    
    std::string GoogleTranslator::translate(const std::string& text) {
        // get a html response
        const cpr::Response r = cpr::Get(
                            cpr::Url{constants::URL}, 
                            cpr::Parameters{
                                {"tl", m_to},
                                {"sl", m_from},
                                {"q", text}
                            }
        );
        // scrap and search html
        auto startHtmlIdx = r.text.find(constants::HTML_PATTERN);
        if (startHtmlIdx == std::string::npos) {
            throw "No translation found!";
        }

        // Find the translated content using the defined html/css pattern
        startHtmlIdx += constants::HTML_PATTERN.length();
        const std::string body = r.text.substr(startHtmlIdx);

        // Find end html index to cut text and get the translation
        auto endHtmlIdx = body.find(constants::END_PATTERN);
        const std::string translation = body.substr(0, endHtmlIdx);
        return translation;
    }

    std::string GoogleTranslator::translateFile(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            std::string content( 
                (std::istreambuf_iterator<char>(file) ),
                (std::istreambuf_iterator<char>()    ) 
            );

            return translate(content);
        }
        // file cannot be open
        else {
            throw std::runtime_error("File could not be open!");
        }
    }
}