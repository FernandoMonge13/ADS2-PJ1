//
// Created by camanem on 2/4/21.
//
#ifndef ADS2_PJ1_MAINWINDOW_H
#define ADS2_PJ1_MAINWINDOW_H

#include <gtkmm.h>

using namespace Gtk;

/**
 * @file MainWindow.h
 * @version 1.1
 * @date 02/04/2021
 * @author CAMANEM
 * @title Main Window
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
    Button button_startDebug;
    Button button_next;

    Label label_ram;

    std::string debug_Text;

    void update(std::string ram_data);
    std::string showData(std::string* text, int max_lenght);

public:

    /*
     * @brief Generates the window with all its components
     */
    MainWindow();
    void run_button_clicked();

};


#endif //ADS2_PJ1_MAINWINDOW_H
