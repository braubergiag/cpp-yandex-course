#include "ini.h"

Ini::Document Ini::Load(std::istream &input) {
    Document doc;
    std::string current_section_name;
    Section  * section = nullptr;
    for (string line; getline(input,line);){
        auto left_brace_pos = line.find('[');
        if (left_brace_pos != std::string::npos){
            auto right_brace_pos = line.find(']');
            current_section_name = line.substr(left_brace_pos + 1,right_brace_pos - left_brace_pos - 1);
            section = &doc.AddSection(current_section_name);
            continue;
        }
        auto equal_sign_pos = line.find('=');
        if (equal_sign_pos != std::string::npos){
            auto key_start_pos = line.find_first_not_of(' ');
            auto key = line.substr(line.find_first_not_of(' '),equal_sign_pos  - key_start_pos);
            auto value = line.substr(equal_sign_pos + 1,line.size());
            section->emplace(key,value);
        }

    }

    return doc;
}
