#include <gtkmm.h>
#include <iostream>
#include "Gui/MainWindow.h"
#include "Server/Server.h"
#include "Client/Client.h"


int main() {

    std::cout << "1 for Server, 2 for Client";
    int input;
    cin >> input;
    if (input == 1){
        Server server = Server();
        server.start();
    }
    else{
        MainWindow window;
    }
    return 0;
}
