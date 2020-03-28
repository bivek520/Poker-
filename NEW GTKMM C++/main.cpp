#include "mainwin.h"

int main(int argc, char* argv[]){
  auto app = Gtk::Application::create(argc,argv,"Nirakar.test");
  Mainwin win;
  app->run(win);


}

