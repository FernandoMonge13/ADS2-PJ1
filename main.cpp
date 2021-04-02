#include <iostream>
#include <gtkmm.h>

using namespace Gtk;

void holamundo( Label *);

int main() {

    Main main;
    Window window;
    Fixed fixed;
    Button button1;
    Label label;
    TextView box1;
    ScrolledWindow scroll1;

    window.set_default_size(800,800);

    window.add(fixed);

    button1.add_pixlabel("info.xpm", "ASSSSS");

    label.set_text("hola");

    fixed.put(button1, 10, 10);

    fixed.put(label, 50, 50);

    //button1.signal_clicked().connect([this]{this->//m}); // Clases

    box1.set_size_request(200, 100);

    scroll1.add(box1);
    scroll1.set_size_request(200,100);



    fixed.put(scroll1, 200, 200);

//    box1.get_buffer()->get_text();
//    box1.get_buffer()->set_text("");

//    box1.set_editable(false);



    window.show_all_children();
    main.run(window);

    return 0;
}

void holamundo(Label * hol){


    }