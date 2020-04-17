#include "mainwin.h"
#include "ch_header.h"

int main(int argc, char* argv[]){

   auto app = Gtk::Application::create(argc,argv,"Nirakar.test");

   asio::io_context io_context;

   tcp::resolver resolver(io_context);
   auto endpoints = resolver.resolve("127.0.0.1", "8000");
   chat_client *c = new chat_client(io_context, endpoints);
   assert(c);
   std::thread t([&io_context](){ io_context.run(); });


    Gtk::Main kit(argc, argv);
    Mainwin *win = new Mainwin(c);
    win->show();
    kit.run();

    std::cout << "before close of the connection" << std::endl;
    c->close();
    std::cout << "after close of the connection" << std::endl;
    t.join();
    //app->run(*win);


}
