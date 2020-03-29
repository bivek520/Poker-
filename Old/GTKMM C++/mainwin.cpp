#include "mainwin.h"

Mainwin::Mainwin()
{
	set_title(APP_TITLE);    //Application Title
	set_default_size(800, 600);   //default size of application window

	//vbox = Gtk::manage (new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	//add(vbox);

	//hbox.pack_start(vbox);
	action1.set_text("Calls $175");
	vbox.pack_start(action1);


	p1.set_text("player 1");
	hbox.pack_start(p1);
	p2.set_text("player 2");
	hbox.pack_start(p2);
	p3.set_text("player 3");
	hbox.pack_start(p3);
	p4.set_text("player 4");
	hbox.pack_start(p4);
	p5.set_text("player 5");
	hbox.pack_start(p5);

	action1.set_text("Calls $175");
	vbox.pack_start(action1);

	hbox.show_all();
	add(hbox);

	vbox.show_all();
	add(vbox);
	show_all_children();


}

Mainwin::~Mainwin() { }






