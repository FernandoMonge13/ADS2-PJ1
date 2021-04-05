//
// Created by camanem on 3/4/21.
//

#ifndef ADS2_PJ1_SYNTAX_H
#define ADS2_PJ1_SYNTAX_H
#include "string"


class Syntax {

private:
    bool ignore_character(std::string& _character);
    std::string identify_type(std::string _string);
    std::string indentify_label(std::string _string, std::string type);

public:
    Syntax();
    void analyze(std::string text);

};


#endif //ADS2_PJ1_SYNTAX_H
