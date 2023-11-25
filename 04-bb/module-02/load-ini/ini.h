#pragma once
#include <unordered_map>
#include <string>
#include <istream>
using std::string;
using std::unordered_map;

namespace Ini{

    using Section = unordered_map<string, string>;


    class Document {
    public:
        Section& AddSection(string name){
            sections.insert({name,Section()});
            return sections.at(name);
        }
        const Section& GetSection(const string& name) const {
            return sections.at(name);
        }
        size_t SectionCount() const {
            return sections.size();
        }

    private:
        unordered_map<string, Section> sections;
    };

    Document Load(std::istream& input){

    }

}
