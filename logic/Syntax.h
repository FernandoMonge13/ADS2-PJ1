//
// Created by camanem on 3/4/21.
//

#ifndef ADS2_PJ1_SYNTAX_H
#define ADS2_PJ1_SYNTAX_H
#include "string"
#include <gtkmm.h>
#include "../Client/Client.h"

using namespace Gtk;

/*!
 * This class is the one that validates the different possibilities that could appear in to the IDE structure
 */
class Syntax {

private:
    int calculate(std::string _variable_1, std::string _variable_2, std::string _operation);
    std::string identify_instruction(std::string* _text, std::string type);
    std::string identify_print(std::string* _text, TextView* _stdout);
    std::string identify_operation(std::string* _text);
    std::string identify_label(std::string* _string);
    std::string identify_type(std::string* _string);
    std::string identify_value(std::string* _text);
    std::string getSize(std::string _type);
    void validate_definition(std::string _type, std::string _value);
    void ignore_spaces(std::string* _text);
    bool finisihed_sentence(std::string* _text);
    bool Only_1_Value(std::string _text);
    bool calculable(std::string _text, std::string* _value);
    bool fatal_error;
    bool flag_condition = false;
    int access = 0;
    TextView* logger_box ;
    std::string data = "";


public:
    /*!
     * @brief analyze the info that is on the IDE in automatic mode
     * @param text that is going to be analyzed
     * @param _stdout_ where an out put info is gonna be
     * @return single IDE line analyzed
     */
    std::string analyze(std::string text, TextView* _stdout_);

    /*!
     * @brief analyze the info that is on the IDE in debug mode
     * @param text that is going to be analyzed
     * @param _stdout_ where an out put info is gonna be
     * @return single IDE line analyzed
     */
    std::string debugText(std::string* text, TextView* _stdout_);

    /*!
     * @brief obtain the logger objet
     * @param _logger window object where is gonna be the logg info
     */
    void setLogger(TextView* _logger);

    /*!
     * @brief info that is gonna be on the logger
     * @param where the problem happened
     * @param error message
     */
    void logger(std::string, std::string);

    /*!
     * @brief start the debug mode
     */
    void DebugStart();

    /*!
     * @brief constructor
     */
    Syntax();

};


#endif //ADS2_PJ1_SYNTAX_H
