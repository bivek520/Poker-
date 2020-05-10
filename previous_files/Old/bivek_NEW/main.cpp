#include "mainwin.h"

int main(int argc, char* argv[]){
    
    auto app = Gtk::Application::create(argc,argv,"Nirakar.test");
    
    Gtk::Main kit(argc, argv);
    Mainwin *win = new Mainwin();
    win->show();
    kit.run();
    //app->run(*win);
    
    
}
