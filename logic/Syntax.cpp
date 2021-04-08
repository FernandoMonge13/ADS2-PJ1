//
// Created by camanem on 3/4/21.
//
#include <iostream>

#include "Syntax.h"

Syntax::Syntax() {

}

void Syntax::ignore_spaces(std::string* _text) {

    std::string character;

    while (!_text->empty()) {

        character = *_text;
        character = character[0];

        if (character == " ") {
            std::cout << "espacio" << std::endl;
        }
        else if (character == "\n") {
            std::cout << "backslash" << std::endl;
        }
        else if (character == "\t") {
            std::cout << "Tab" << std::endl;
        }
        else {
            break;
        }
        _text->erase(_text->begin());
    }
}


std::string Syntax::identify_type(std::string* _string) {

    ignore_spaces(_string);

    if (_string->empty()){
        return "error: insufficient text for identify type";
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
        return "error finding type";
        // wtf se arregló el error 15
    }
}

std::string Syntax::identify_label(std::string *_string) {

    ignore_spaces(_string);

    if (_string->empty()) {
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
            return "error label";
        }
        else {
            return label;
        }
    }
}

std::string Syntax::identify_command(std::string *_text) {

    ignore_spaces(_text);
    if (_text->empty()){
        return "error: no txt for identify_command";
    }
    else {
        std::string character = *_text;
        character = character[0];
        _text->erase(_text->begin());

        if (character == ".") {
            return "method";
        } else if (character == ";") {
            return "declaration";
        } else if (character == "=") {
            return "definition";
        } else {
            return "error: instruction not identified";
        }
    }
}

void Syntax::analyze(std::string text) {

    std::string type;
    std::string label;

    std::string instruction;
    std::string value;


    std::cout << "Proceso de interpretación:" << std::endl;


    while (!text.empty()){

        type = identify_type(&text);
        std::cout << "tipo: " + type << std::endl;

        label = identify_label(&text);
        std::cout << "etiqueta: " + label << std::endl;

        instruction = identify_command(&text);
        std::cout << "instrucción: " +  instruction << std::endl;

        if (instruction != "declaration"){
            value = identify_value(&text);
            std::cout << "value = " + value << std::endl;
        }
        // character is ignored and the analysis continues
        //std::cout << *character << std::endl;
            //std::cout << text.substr(index, 3) << std::endl;

    }
    std::cout << "----------------" << std::endl;
}

std::string Syntax::identify_value(std::string *_text) {

    ignore_spaces(_text);

    if (_text->empty()){
        return "Error: insufficient text to identify value";
    }
    else{

        std::string value = "";
        std::string character = *_text;
        character = character[0];

        while (!_text->empty() && character != " " && character != "\t" && character != "\n" && character != "" && character != ";") {

            value.append(character);
            _text->erase(_text->begin());

            character = *_text;
            character = character[0];
        }
        ignore_spaces(_text);

        if (_text->empty()){
            return "error: no txt after value or ; missed";
        }
        else {
            character = *_text;
            character = character[0];
            if (character == ";" && value != ";") {
                _text->erase(_text->begin());
                ignore_spaces(_text);
                return value;
            } else {
                return "error: ; or value missed";
            }
        }
    }
}

