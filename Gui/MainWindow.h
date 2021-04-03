//
// Created by camanem on 2/4/21.
//
#ifndef ADS2_PJ1_MAINWINDOW_H
#define ADS2_PJ1_MAINWINDOW_H

#include <gtkmm.h>

using namespace Gtk;

/*
 * @file MainWindow.h
 * @version 1.0
 * @date 02/04/2021
 * @author CAMANEM
 * @title Main Window
 * @code
 * int main(){
 *      MainWindow main_window;
 * }
 * @endcode
 *
 * @brief MainWindow creates and contains the program window and all graphic objects
 */

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

    /*
     * @brief Generates the window with all its components
     */
    MainWindow();
    void holamundo(Label*);

};


#endif //ADS2_PJ1_MAINWINDOW_H
