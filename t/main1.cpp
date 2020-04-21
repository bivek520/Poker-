#include "mainwin.h"
#include "chat_client.h"
Mainwin *win = nullptr;

int main(int argc, char* argv[]){
    
    auto app = Gtk::Application::create(argc,argv,"Nirakar.test");
    Gtk::Main kit(argc, argv);

    asio::io_context io_context;

    tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve("127.0.0.1", "8000");
    chat_client c(io_context, endpoints);

    std::thread t([&io_context](){ io_context.run(); });



    win = new Mainwin(&c);
    win->show();
    kit.run();
    app->run(*win);

    // you get here after the window is killed
    c.close();
    t.join();

}

