//
// Created by camanem on 2/4/21.
//

#include "MainWindow.h"

MainWindow::MainWindow() {

    label_ram.set_text("Ram Live View");
    ListViewText listViewText(4, true);

    button_run.add_label("Run");
//    button_run.add_pixlabel("info.xpm", "Run");
//    button_run.signal_clicked().connect([this]{this->//m}); // Clases

    window.set_default_size(800,800);
    window.set_title("C!  --  IDE");
    window.set_position(Gtk::WIN_POS_CENTER);
    window.add(fixed);

    stdout_.set_editable(false);
    app_log.set_editable(false);
    ram_view.set_editable(false);

    scroll_editor.add(editor);
    scroll_stdout_.add(stdout_);
    scroll_app_log.add(app_log);
    scroll_ram_view.add(ram_view);

    scroll_editor.set_size_request(400,500);
    scroll_stdout_.set_size_request(400, 125);
    scroll_app_log.set_size_request(400, 125);
    scroll_ram_view.set_size_request(370, 500);

    fixed.put(button_run, 5, 0);
    fixed.put(scroll_editor, 5, 35);
    fixed.put(scroll_stdout_, 5, 540);
    fixed.put(scroll_app_log, 5, 670);
    fixed.put(listViewText, 400, 700);
    fixed.put(label_ram, 550, 10);
    fixed.put(scroll_ram_view,420, 35);

    //ram_view.resize(10,10);
    //fixed.put(ram_view, 500,200);

    stdout_.get_buffer()->set_text(">>");

    ram_view.get_buffer()->set_text("     Direction                     Value                     Label                   Refs");

//    stdout_.get_buffer()->set_text(stdout_.get_buffer()->get_text() + "ajuuaaaa"); // Command to add text and not overwrite //
//    editor.set_size_request(200, 100);
//    editor.get_buffer()->get_text();
//    editor.get_buffer()->set_text("");
//    editor.set_editable(false);

    window.show_all_children();
    main.run(window);
}

void MainWindow::holamundo(Label * hol){


}