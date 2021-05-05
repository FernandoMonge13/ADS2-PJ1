#include <gtkmm.h>
#include <iostream>
#include "Gui/MainWindow.h"
#include "Server/Server.h"
#include "Client/Client.h"



int main() {

    std::cout << "1 for server, 2 for client";

    int option;

    std::cin>> option;

    if (option == 1){
        Server server = Server();
        server.start();

    }else{
        MainWindow window;
    }

    return 0;
}