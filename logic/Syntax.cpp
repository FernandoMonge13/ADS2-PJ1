//
// Created by camanem on 3/4/21.
//
#include <iostream>

#include "Syntax.h"
#include "spdlog/spdlog.h"

Client client = Client();

Syntax::Syntax() {

}

std::string Syntax::identify_instruction(std::string *_text, std::string type) {

    ignore_spaces(_text);
    if (_text->empty()){
        logger("Syntax-identify_instruction", "Fatal Error: no txt to identify instruction");
        fatal_error = true;
        return "error: no txt for identify_instruction";
    }
    else {
        std::string character = *_text;
        character = character[0];
        _text->erase(_text->begin());

        if (character == "." && type == "error") {
            return "method";
        }
        else if (character == ";" && type != "error") {
            return "declaration";
        }
        else if (character == "=") {
            if (type == "error") {
                return "re definition";
            }
            return "definition";
        }
        else {
            logger("Syntax-identify_instruction", "Instruction not identified");
            fatal_error = true;
            return "error: instruction not identified";
        }
    }
}

std::string Syntax::identify_print(std::string *_text, TextView* _stdout) {

    ignore_spaces(_text);

    if (_text->empty()){
        // error: insufficient text for identify type
        spdlog::error("Insufficient text to identify print");
        return "error";
    }
    else if (_text->substr(0, 5) == "print") {
        if (_text->substr(5, 1) == "("){
            _text->erase(0, 6);
            std::string to_print;
            std::string character = *_text;
            character = character[0];
            // caso en el que se desea imprimir un string

            if (character == "'"){
                _text->erase(_text->begin());
                character = *_text;
                character = character[0];
                // extracción de string para printear
                while (!_text->empty() && character != "'"){
                    to_print.append(character);
                    _text->erase(_text->begin());
                    character = *_text;
                    character = character[0];
                }
                _text->erase(_text->begin());
                ignore_spaces(_text);
                character = *_text;
                character = character[0];
                // cierrre del print
                if (character == ")"){
                    _text->erase(_text->begin());
                    if (finisihed_sentence(_text)) {
                        finisihed_sentence(_text);
                        _stdout->get_buffer()->set_text(_stdout->get_buffer()->get_text() + to_print + "\n");
                        return "printed";
                    }
                }
                else {
                    logger("Syntax-identify_print", "    Incorrect print syntax");
                    spdlog::error("Syntax error in print command attempt");
                    return "error";
                }
            }
            else{
                return identify_value(_text);
            }
        }
        else{
            // se encontró la palabra recervada print pero le falta su sintaxis de parentesis correcta"
            logger("Syntax-identify_print", "    Incorrect print syntax");
            spdlog::error("Syntax error in print command attempt");
            return "error";
        }

    }
    else{
        // No print sintaxis
        return "error";
    }

}

std::string Syntax::identify_operation(std::string *_text) {

    ignore_spaces(_text);

    if (_text->empty()) {
        spdlog::error("insufficient text to identify operation");
        logger("Syntax-identify_operation", "Insufficient text to identify operation");
        return "Error: insufficient text to identify value";
    }
    else {
        std::string operation;
        std::string character = *_text;
        character = character[0];

        while (!_text->empty() && character != ";" && character != ")") {

            operation.append(character);
            _text->erase(_text->begin());
            ignore_spaces(_text);
            character = *_text;
            character = character[0];
        }
        if (_text->empty()){
            spdlog::error("insufficient text to identify operation");
            logger("Syntax-identify_operation", "Insufficient text to identify operation");
            fatal_error = true;
            return "error";
        }
        else {
            return operation;
            // Esto podría agregarlo al if del print y ya
//            if (character == ")") {
//                _text->erase(_text->begin());
//                if (finisihed_sentence(_text)) {
//                    return operation;
//                } else {
//                    spdlog::error("Missing ;");
//                    fatal_error = true;
//                    return "error";
//                    // print sintaxis incompleta, missing ;
//                }
//            }
//              if (finisihed_sentence(_text)) {
//                return operation;
//            } else {
//                spdlog::error("Missing ;");
//                fatal_error = true;
//                return "error";
//                // missing ;
//            }
            // por probar y llamar
        }
    }
}

std::string Syntax::identify_label(std::string *_string) {

    ignore_spaces(_string);

    if (_string->empty()) {
        spdlog::error("Insufficient text to identify label");
        logger("Syntax-identify_label", "Insufficient text to identify label");
        fatal_error = true;
        return "error: incomplete text to identify label";
    }
    else{

        std::string label;
        std::string character = *_string;
        character = character[0];
        while (!_string->empty() && character != "." && character != " " && character != "\t" && character != "\n" && character != "=" &&
               character != ";") {

            label.append(character);
            _string->erase(_string->begin());

            character = *_string;
            character = character[0];
        }
        if (label.empty()){
            spdlog::error("No label found");
            logger("Syntax-identify_label", "No label found");
            fatal_error = true;
            return "error label";
        }
        else {
            return label;
        }
    }
}

std::string Syntax::identify_type(std::string* _string) {

    ignore_spaces(_string);

    if (_string->empty()){
        // error: insufficient text for identify type
        logger("Syntax-identify_type", "Insufficient text to identify type");
        spdlog::error("Insufficient text to identify type");
        return "error";
    }
    else {
        //_string.find("int") != std::string::npos

        // validate word "int" followed by a space
        if (_string->substr(0, 3) == "int" && _string->substr(3, 1) == " ") {
            _string->erase(0, 4);
            return "int";
        } else if (_string->substr(0, 4) == "long" && _string->substr(4, 1) == " ") {
            _string->erase(0, 5);
            return "long";
        } else if (_string->substr(0, 4) == "char" && _string->substr(4, 1) == " ") {
            _string->erase(0, 5);
            return "char";
        } else if (_string->substr(0, 5) == "float" && _string->substr(5, 1) == " ") {
            _string->erase(0, 6);
            return "float";
        } else if (_string->substr(0, 6) == "double" && _string->substr(6, 1) == " ") {
            _string->erase(0, 7);
            return "double";
        } else if (_string->substr(0, 6) == "struct" && _string->substr(6, 1) == " ") {
            _string->erase(0, 7);
            return "struct";
        } else if (_string->substr(0, 9) == "reference" && _string->substr(9, 1) == " ") {
            _string->erase(0, 10);
            return "reference";
        }
        // error finding type
        return "error";
    }
}

std::string Syntax::identify_value(std::string *_text) {

    ignore_spaces(_text);

    if (_text->empty()){
        logger("Syntax-identify_value", "Insufficient text to identify value");
        spdlog::error("Insufficient text to identify value");
        fatal_error = true;
        return "Error: insufficient text to identify value";
    }
    else{

        std::string value = "";
        std::string character = *_text;
        character = character[0];

        while (!_text->empty() && character != ";" && character != ")") {

            value.append(character);
            _text->erase(_text->begin());
            ignore_spaces(_text);
            character = *_text;
            character = character[0];
        }
        ignore_spaces(_text);

        if (_text->empty()){
            spdlog::error(" ; missed");
            logger("Syntax-identify_value", "; missed");
            fatal_error = true;
            return "error: no txt after value or ; missed";
        }
        else {
            character = *_text;
            character = character[0];
            if (character == ";" || character == ")") {
                if (value != ";"){
                    return value;
                }
            } else {
                logger("Syntax-identify_value", "; or value missed");
                fatal_error = true;
                return "error: ; or value missed";
            }
        }
    }
}


std::string Syntax::getSize(std::string _type) {
    if (_type == "int"){
        return "4";
    }
    else if (_type == "long"){
        return "8";
    }
    else if (_type == "char"){
        return "1";
    }
    else if (_type == "float"){
        return "4";
    }
    else if (_type == "double"){
        return "8";
    }
}

void Syntax::ignore_spaces(std::string* _text) {


    std::string character;

    while (!_text->empty()) {

        character = *_text;
        character = character[0];

        if (character == " ") {
            //std::cout << "espacio" << std::endl;
        }
        else if (character == "\n") {
            //std::cout << "backslash" << std::endl;
        }
        else if (character == "\t") {
            //std::cout << "Tab" << std::endl;
        }
        else if (character == "{"){
            access++;
        }
        else if (character == "}"){
            access--;
        }
        else {
            break;
        }
        _text->erase(_text->begin());
    }
}

bool Syntax::finisihed_sentence(std::string *_text) {
    ignore_spaces(_text);
    std::string character = *_text;
    character = character[0];
    if (character == ")"){
        _text->erase(_text->begin());
        finisihed_sentence(_text);
    }
    else if (character == ";"){
        _text->erase(_text->begin());
        return true;
    }
    else{
        fatal_error = true;
        logger("Syntax-finisihed_sentence", "Missing ;");
        spdlog::error("Missing ;");
        return false;
    }
}

bool Syntax::calculable(std::string _text, std::string* _value) {
    try{
        std::string variable_1;
        std::string variable_2;
        std::string operation;
        int result;
        std::string character = _text;
        character = character[0];

        while (!_text.empty()){

            if (character == "+" || character == "-" || character == "*" || character == "/"){
                if (variable_1.empty()){
                    spdlog::error("Error getting operation");
                    logger("Syntax-calculable", "Operator before variable");
                    // mega error, hay una operación antes que cualquier variable
                    break;
                }
                    // se encuentra el signo de operacion y eso tambien indica que se tiene la variable 1
                else if (variable_2.empty()) {
                    operation = character;
                    _text.erase(_text.begin());
                    character = _text;
                    character = character[0];
                }
                    // la variable dos no está vacia por lo que se debe utilizar para operación
                else if (!variable_2.empty()){
                    result = calculate(variable_1, variable_2, operation);
                    std::cout << result << std::endl;
                    variable_1 = std::to_string(result);
                    operation = character;
                    _text.erase(_text.begin());
                    character = _text;
                    character = character[0];
                    variable_2 = "";
                }
            }
                // Si aun no ha encontrado una operación, significa que está obteniendo la variable 1
            else if (operation.empty()){
                variable_1.append(character);
                _text.erase(_text.begin());
                character = _text;
                character = character[0];
            }
                // Si se ha encontrado una operación, significa que está obteniendo la variable 2
            else if (!operation.empty()) {
                variable_2.append(character);
                _text.erase(_text.begin());
                character = _text;
                character = character[0];
            }

        }
        if (!variable_2.empty()){
            result = calculate(variable_1, variable_2, operation);
        }
        *_value = std::to_string(result);
        return true;
//        std::cout << result << std::endl;

    }
    catch (std::exception exception){
        std::cout << "Operation requires memory info" << std::endl;
        return false;
    }
}

int Syntax::calculate(std::string _variable_1, std::string _variable_2, std::string _operation) {
    int result;
    try {
        int variable1 = std::stoi(_variable_1);
        int variable2 = std::stoi(_variable_2);

        if (_operation == "+"){
            result = variable1 + variable2;
        }
        else if (_operation == "-"){
            result = variable1 - variable2;
        }
        else if (_operation == "*"){
            result = variable1 * variable2;
        }
        else if (_operation == "/"){
            if (variable2 != 0) {
                result = variable1 / variable2;
            } else{result = 0;
                logger("Syntax-calculate", "Division by zero");
            }
        }
    }
    catch (int exc){
        std::cout << "failed in conversion" << std::endl;
    }
    return result;
}

std::string Syntax::analyze(std::string text, TextView* _stdout_) {
    data  = "";
    logger_box->get_buffer()->set_text(data);
    fatal_error = false;
    std::string instruction = "ReRun";
    std::string to_print;
    std::string label;
    std::string value;
    std::string type;
    std::string _ram_view_status;
    logger("Syntax-analyze", "Server call");
    client.construction("no", "no", "no", instruction, "no", "no");
    std::cout << "Proceso de interpretación:" << std::endl;

    while (!text.empty() && !fatal_error){

        // print case
        to_print = identify_print(&text, _stdout_);
        if (to_print != "error") {
            if (to_print != "printed") {
                value = to_print;
                instruction = "print";
                if (finisihed_sentence(&text)){
                    std::string printeo = client.construction(" ", value, " ", instruction, std::to_string(access), this->getSize(type));
                    std::cout << printeo << std::endl;
                    auto json = json::parse(printeo);
                    _stdout_->get_buffer()->set_text(_stdout_->get_buffer()->get_text() + json["Values"].get<std::string>() + "\n");
                    std::cout << "texto: " + text << std::endl;
                }
                std::cout << "operacion: " + to_print << std::endl;
                //calculable(to_print);
            }
        }
        else {
            type = identify_type(&text);
            label = identify_label(&text);
            instruction = identify_instruction(&text, type);
            if (instruction != "declaration" && !fatal_error) {
                if (Only_1_Value(text)) {
                    value = identify_value(&text);
                    validate_definition(type, value);
                }
                else{
                    value = identify_operation(&text);
                    if (!calculable(value, &value)){
                        if (instruction == "definition"){
                            instruction = "definition_with_operation";
                        } else if (instruction == "re definition"){
                            instruction = "re definition_with_operation";
                        }
                    }
                }
                std::cout << "value = " + value << std::endl;
            }
            if (!fatal_error && finisihed_sentence(&text)) {
                logger("Syntax-analyze", "Server call");
                _ram_view_status = client.construction(type, label, value, instruction, std::to_string(access), this->getSize(type));
            }
        }
    }
    if (fatal_error){
        _stdout_->get_buffer()->set_text("Error: invalid syntax");
        spdlog::error("Fatal Error: canceled analisys \n");
        logger("Syntax-Analyze", "Fatal Error: analisys canceled");
        if (_ram_view_status.empty()){
            return "Error";
        }
        return _ram_view_status;
        //std::cout << "Fatal Error: the interpret process have to stop" << std::endl;
    }
    std::cout << "----------------" << std::endl;
    return _ram_view_status;
}

bool Syntax::Only_1_Value(std::string _text) {

    ignore_spaces(&_text);

    if (_text.empty()) {
        spdlog::error("Insufficient txt to Only_1_Value");
        logger("Syntax-Only_1_Value", "Insufficient text");
        fatal_error = true;
        return true;
    }
    else{
        std::string character = _text;
        character = character[0];

        while (!_text.empty() && character != ";" && character != "+" && character != "-" && character != "*" && character != "/"){

            _text.erase(_text.begin());
            character = _text;
            character = character[0];
        }
        if (character == "+" || character == "-" || character == "*" || character == "/"){
            return false;
        }
        else{
            return true;
        }
    }

}

void Syntax::validate_definition(std::string _type, std::string _value) {

    try {
        if (_type == "int") {
            int variable = std::stoi(_value);
        } else if (_type == "long") {
            long variable = std::stol(_value);
        } else if (_type == "char") {
            char variable = *((char *) _value.c_str());
        } else if (_type == "float") {
            float variable = std::stof(_value);
        } else if (_type == "double") {
            double variable = std::stod(_value);
        } else if (_type == "reference") {
            // Protocol for reference declarations
        } else {
            logger("Syntax-validate_definition", "Type and value incompatibility");
            spdlog::critical("validate_definition: Error al validar");
        }
    }
    catch (std::exception exception){
        logger("Syntax-validate_definition", "Type and value incompatibility");
        spdlog::critical("validate_definition: Error al validar");
        fatal_error = true;
    }
}

std::string Syntax::debugText(std::string *text, TextView *_stdout_) {

    data  = "";
    logger_box->get_buffer()->set_text(data);
    fatal_error = false;
    std::string instruction;
    std::string to_print;
    std::string label;
    std::string value;
    std::string type;
    std::string _ram_view_status;

    if (!text->empty() && !fatal_error){

        // print case
        to_print = identify_print(text, _stdout_);
        if (to_print != "error") {
            if (to_print != "printed") {
                std::cout << "operacion: " + to_print << std::endl;
                //calculable(to_print);
            }
        }
        else {
            type = identify_type(text);
            label = identify_label(text);
            instruction = identify_instruction(text, type);
            if (instruction != "declaration" && !fatal_error) {
                if (Only_1_Value(*text)) {
                    value = identify_value(text);
                    validate_definition(type, value);
                    // verificar type y value compatibles
                }
                else{
                    value = identify_operation(text);
                    if (!calculable(value, &value)){
                        if (instruction == "definition"){
                            instruction = "definition_with_operation";
                        } else if (instruction == "re definition"){
                            instruction = "re definition_with_operation";
                        }
                    }
                }
                std::cout << "value = " + value << std::endl;
            }
            if (!fatal_error && finisihed_sentence(text)) {
                logger("Syntax-debugText", "Server call");
                _ram_view_status = client.construction(type, label, value, instruction, std::to_string(access), this->getSize(type));
            }
        }

    }
    if (fatal_error){
        _stdout_->get_buffer()->set_text("Error: invalid syntax");
        spdlog::error("Fatal Error: canceled analisys ");
        logger("Syntax-Analyze", "Fatal Error: analisys canceled");
        if (_ram_view_status.empty()){
            return "Error";
        }
        return _ram_view_status;
        //std::cout << "Fatal Error: the interpret process have to stop" << std::endl;
    }
    std::cout << "----------------" << std::endl;
    return _ram_view_status;
}

void Syntax::DebugStart() {
    std::string instruction = "ReRun";
    logger("Syntax-DebugStart", "Server call");
    client.construction("no", "no", "no", instruction, "no", "no");
}

void Syntax::setLogger(TextView * _logger) {
    logger_box = _logger;

}

void Syntax::logger(std::string from, std::string info) {
    data.append("\n"+from + " " + info);
    logger_box->get_buffer()->set_text(data);

}
