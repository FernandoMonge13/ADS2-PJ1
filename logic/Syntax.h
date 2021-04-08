//
// Created by camanem on 3/4/21.
//

#ifndef ADS2_PJ1_SYNTAX_H
#define ADS2_PJ1_SYNTAX_H
#include "string"


class Syntax {

private:
    void ignore_spaces(std::string* _text);
    std::string identify_type(std::string* _string);
    std::string identify_label(std::string* _string);
    std::string identify_command(std::string* _text);
    std::string identify_value(std::string* _text);

public:
    Syntax();
    void analyze(std::string text);

};


#endif //ADS2_PJ1_SYNTAX_H
