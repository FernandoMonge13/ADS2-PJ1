//
// Created by camanem on 3/4/21.
//
#include <iostream>

#include "Syntax.h"

Syntax::Syntax() {

}

bool Syntax::ignore_character(std::string &_character) {

    if (_character == " "){
        std::cout << "espacio" << std::endl;
        return true;
    }
    else if (_character == "\n"){
        std::cout << "backslash" << std::endl;
        return true;
    }
    else if (_character == "\t"){
        std::cout << "Tab" << std::endl;
        return true;
    }
    else{
        return false;
    }
}

void Syntax::analyze(std::string text) {

    std::string character;
    std::string new_variable;


    std::cout << "Proceso de interpretación:" << std::endl;


    while (text != ""){

        character = text[0];

        if (ignore_character(character)){
            // character is ignored and the analysis continues
        }
        else{
            std::cout << character << std::endl;
            new_variable = identify_type(text.substr(0, text.find(";")));
            std::cout << new_variable << std::endl;
            break;
            //std::cout << text.substr(index, 3) << std::endl;
        }
        text.erase(text.begin());
    }
    std::cout << "----------------" << std::endl;
}

std::string Syntax::identify_type(std::string _string) {

    //_string.find("int") != std::string::npos

    // validate word "int" followed by a space
    if (_string.substr(0, 3) == "int" && _string.substr(3, 1) == " "){
        std::cout << "string: "+ _string << std::endl;
        _string.erase(0, 4);
        indentify_label(_string.substr(0, _string.find("=")), "int");
        return "int found";
    }
    else if (_string.substr(0, 4) == "long" && _string.substr(4, 1) == " "){
        return "long found";
    }
    else if (_string.substr(0, 4) == "char" && _string.substr(4, 1) == " "){
        return "char found";
    }
    else if (_string.substr(0, 5) == "float" && _string.substr(5, 1) == " "){
        return "float found";
    }
    else if (_string.substr(0, 6) == "double" && _string.substr(6, 1) == " "){
        return "double found";
    }
    else if (_string.substr(0, 6) == "struct" && _string.substr(6, 1) == " "){
        return "struct found";
    }
    else if (_string.substr(0, 9) == "reference" && _string.substr(9, 1) == " "){
        return "reference found";
    }
    return "error finding type";
    // wtf se arregló el error 15
}

std::string Syntax::indentify_label(std::string _string, std::string type) {



    std::cout << _string << std::endl;
    return _string;
}
