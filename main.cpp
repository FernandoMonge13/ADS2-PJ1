#include <iostream>
#include <gtkmm.h>
#include "Gui/MainWindow.h"
#include "Server/Server.h"


int main() {

    //MainWindow window;

    Server hp = Server();
    hp.start();



    return 0;
}
