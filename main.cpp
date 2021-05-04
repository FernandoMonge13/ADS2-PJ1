#include <gtkmm.h>
#include <iostream>
#include "Gui/MainWindow.h"
#include "Server/Server.h"
#include "Client/Client.h"



int main() {
    int option;

    std::cin>> option;

    if (option == 1){
        Server hp = Server();
        hp.start();

    }else{
        MainWindow window;
    }

    return 0;
}
