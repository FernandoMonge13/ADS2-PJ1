#include <iostream>
#include <gtkmm.h>
#include "Gui/MainWindow.h"
#include "Server/Server.h"
#include "Client/Client.h"


int main() {

/*
    Client hp = Client();
    hp.construction("Int", "numero", "25745846", "TRUE");
    hp.start();

    std::cout << "Hello, World!" << std::endl;

    bool * memoria = (bool *)malloc(1000);

    std::cout << sizeof(*memoria) << std::endl;
    std::cout << memoria << std::endl;

    *((int *)(memoria)) = 20;
    ((char *)(memoria+4)[1]) = "a";

    std::cout << *((char *)(memoria+4)) << std::endl;

    free(memoria);
*/
//

    MainWindow window;
    Server hp = Server();
    hp.start();

    return 0;
}
