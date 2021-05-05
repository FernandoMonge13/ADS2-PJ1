//
// Created by camanem on 2/4/21.
//

#include "MainWindow.h"
#include "iostream"
#include "../logic/Syntax.h"
#include "spdlog/spdlog.h"

Syntax* syntax = new Syntax;

MainWindow::MainWindow() {


    label_ram.set_text("Ram Live View");
    ListViewText listViewText(4, true);

    button_run.add_label("Run");
    button_startDebug.add_label("Debug");
    button_next.add_label("Next");

//    button_run.add_pixlabel("info.xpm", "Run");
//    button_run.signal_clicked().connect([this]{this->//m}); // Clases

    window.set_default_size(1100,800);
    window.set_title("C!  --  IDE");
    window.set_position(Gtk::WIN_POS_CENTER);
    window.add(fixed);

    stdout_.set_editable(false);
    app_log.set_editable(false);
    ram_view.set_editable(false);

    syntax->setLogger(&app_log);


    scroll_editor.add(editor);
    scroll_stdout_.add(stdout_);
    scroll_app_log.add(app_log);
    scroll_ram_view.add(ram_view);

    scroll_editor.set_size_request(400,500);
    scroll_stdout_.set_size_request(400, 125);
    scroll_app_log.set_size_request(400, 125);
    scroll_ram_view.set_size_request(670, 500);

    fixed.put(button_run, 5, 0);
    fixed.put(button_startDebug, 52, 0);
    fixed.put(button_next, 115, 0);
    fixed.put(scroll_editor, 5, 35);
    fixed.put(scroll_stdout_, 5, 540);
    fixed.put(scroll_app_log, 5, 670);
    fixed.put(label_ram, 735, 10);
    fixed.put(scroll_ram_view,420, 35);
    fixed.put(listViewText, 450, 700);

    //ram_view.resize(10,10);
    //fixed.put(ram_view, 500,200);

    stdout_.get_buffer()->set_text(">>");

    ram_view.get_buffer()->set_text("\tDirection\t\t\t\t\t\tValue\t\t\t\t\t\t"
                                    "Label\t\t\t\t\tRefs");
//    stdout_.get_buffer()->set_text(stdout_.get_buffer()->get_text()+"text"); // Command to add text and not overwrite
//    editor.set_size_request(200, 100);
//    editor.get_buffer()->get_text();
//    editor.get_buffer()->set_text("");
//    editor.set_editable(false);
    button_run.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::run_button_clicked) );
    button_startDebug.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::debugStart) );
    button_next.signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::next_pressed) );


    window.show_all_children();
    main.run(window);
}

void MainWindow::run_button_clicked(){

//    std::cout << "Contenido del editor:" << std::endl;
//    std::cout << editor.get_buffer()->get_text() << std::endl;
    std::string text = editor.get_buffer()->get_text();
    if (!text.empty()){
        std::string ram_data;
        stdout_.get_buffer()->set_text(">> ");
        ram_data = syntax->analyze(editor.get_buffer()->get_text(), &stdout_);
        if (ram_data != "Error"){
            update(ram_data);
        }
    }
}

void MainWindow::debugStart() {

    debug_Text = editor.get_buffer()->get_text();
    Syntax* syntax = new Syntax;
    syntax->DebugStart();
}

void MainWindow::next_pressed() {

    if (!debug_Text.empty()){
        std::string ram_data;
        stdout_.get_buffer()->set_text(">> ");
        ram_data = syntax->debugText(&debug_Text, &stdout_);
        if (ram_data != "Error"){
            update(ram_data);
        }
    }

}

void MainWindow::update(std::string ram_data) {

    if (ram_data.empty()){
        std::cout << "QUÉ PUTAS?? POR QUÉ ESTÁ VACÍO???" << std::endl;
    }
    else{

        std::cout << ram_data << std::endl;

        auto json = json::parse(ram_data);
        std::string visual_data = "\tDirection\t\t\t\t\t\tValue\t\t\t\t\t\t"
                                  "Label\t\t\t\t\tRefs\n";
        std::string addresses = json["Addresses"].get<std::string>();
        std::string values = json["Values"].get<std::string>();
        std::string labels = json["Labels"].get<std::string>();
        std::string refs = json["Refs_Count"].get<std::string>();

        std::string character;


        while (addresses != "" && addresses != "skip"){
            visual_data.append(showData(&addresses, 16));
            visual_data.append(showData(&values, 90/3));
            visual_data.append(showData(&labels, 42/3));
//        visual_data.append(showData(&refs, ?));
            visual_data.append("\n");
        }
        std::cout << "listo" << std::endl;
        ram_view.get_buffer()->set_text(visual_data);
    }

}

std::string MainWindow::showData(std::string* text, int max_lenght) {

    std::string data_to_show;
    std::string character;
    int counter = 0;
    while (!text->empty()){
        character = ((*text)[0]);
        if (character == " "){
            text->erase(text->begin());
            break;
        }
        else {
            text->erase(text->begin());
            if (counter<max_lenght){
                data_to_show.append(character);
                counter++;
            }
        }
    }
    if (counter < max_lenght && 1 < max_lenght-counter){
        int spaces = (((max_lenght*3)-(counter*3))/2);
        for (int i=0; i<spaces; i++){
            data_to_show = " " + data_to_show + " ";
        }
    }
    return data_to_show;
}
