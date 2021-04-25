//
// Created by camanem on 3/4/21.
//

#ifndef ADS2_PJ1_SYNTAX_H
#define ADS2_PJ1_SYNTAX_H
#include "string"


class Syntax {

private:
    bool fatal_error;
    void ignore_spaces(std::string* _text);
    std::string identify_print(std::string* _text);
    std::string identify_type(std::string* _string);
    std::string identify_label(std::string* _string);
    std::string identify_value(std::string* _text);
    std::string identify_instruction(std::string* _text, std::string type);
    std::string identify_operation(std::string* _text);
    bool finisihed_sentence(std::string* _text);
    bool arytmethic(std::string _text);
    bool Only_1_Value(std::string _text);
    int calculate(std::string _variable_1, std::string _variable_2, std::string _operation);



public:
    Syntax();
    void analyze(std::string text);

};


#endif //ADS2_PJ1_SYNTAX_H
