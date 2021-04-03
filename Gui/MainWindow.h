//
// Created by camanem on 2/4/21.
//
#ifndef ADS2_PJ1_MAINWINDOW_H
#define ADS2_PJ1_MAINWINDOW_H

#include <gtkmm.h>

using namespace Gtk;


class MainWindow {

private:

    Main main;
    Window window;
    Fixed fixed;

    TextView editor;
    TextView stdout_;
    TextView app_log;
    TextView ram_view;

    ScrolledWindow scroll_editor;
    ScrolledWindow scroll_stdout_;
    ScrolledWindow scroll_app_log;
    ScrolledWindow scroll_ram_view;

    Button button_run;

    Label label_ram;

public:

    MainWindow();
    void holamundo(Label*);

};


#endif //ADS2_PJ1_MAINWINDOW_H
