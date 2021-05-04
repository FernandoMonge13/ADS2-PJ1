#include <gtkmm.h>
#include <iostream>
#include "Gui/MainWindow.h"
#include "Server/Server.h"
#include "Client/Client.h"


int main() {

    // holaa

    MainWindow window;
    Server hp = Server();
    hp.start();


    return 0;
}
