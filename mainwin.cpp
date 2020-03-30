#include "mainwin.h"
#include <cstdlib>

std::string big(int card)
{
std::string sCard = "LargeCards/" + std::to_string(card) + ".jpg";
return sCard;
}
std::string sml(int card)
{
std::string sCard = "SmallCards/" + std::to_string(card) + ".jpg";
return sCard;
}
Mainwin::Mainwin()   
{
	
	set_title(APP_TITLE);    //Application Title
	set_default_size(800, 600);   //default size of application window

	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
        add(*vbox);
	
	vbox->override_background_color(Gdk::RGBA{"green"}); //changes background color of the vbox

	//hbox.pack_start(vbox);
	//action1.set_text("Calls $175");
	//vbox.pack_start(hbox);
	//vbox.pack_start(action1);

	p1.set_text("player 1");
	p2.set_text("player 2");
	p3.set_text("player 3");
	p4.set_text("player 4");
	p5.set_text("player 5");

    	vbox->pack_start(m_Grid, Gtk::PACK_SHRINK, 10);
    	m_Grid.set_row_homogeneous(true);
    	m_Grid.set_column_homogeneous(true);
    	m_Grid.attach(p1, 0, 0, 1, 1);
    	m_Grid.attach(p2, 1, 0, 1, 1);
    	m_Grid.attach(p3, 2, 0, 1, 1);
    	m_Grid.attach(p4, 3, 0, 1, 1);
    	m_Grid.attach(p5, 4, 0, 1, 1);

	//vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
	p1.override_background_color(Gdk::RGBA{"yellow"});
	p2.override_background_color(Gdk::RGBA{"blue"});
	p3.override_background_color(Gdk::RGBA{"magenta"});
	p4.override_background_color(Gdk::RGBA{"cyan"});
	p5.override_background_color(Gdk::RGBA{"orange"});

	action1.set_text("\nP1 Action");
	action2.set_text("\nP2 Action");
	action3.set_text("\nP3 Action");
	action4.set_text("\nP4 Action");
	action5.set_text("\nP5 Action");

	m_Grid.attach(action1, 0, 1, 1, 1);
    	m_Grid.attach(action2, 1, 1, 1, 1);
    	m_Grid.attach(action3, 2, 1, 1, 1);
    	m_Grid.attach(action4, 3, 1, 1, 1);
    	m_Grid.attach(action5, 4, 1, 1, 1);

	balance1.set_text("\n$" + std::to_string(balance));
	balance2.set_text("\n$175");
	balance3.set_text("\n$175");
	balance4.set_text("\n$175");
	balance5.set_text("\n$175");

	//add(balanceHbox);
	m_Grid.attach(balance1, 0, 2, 1, 1);
    	m_Grid.attach(balance2, 1, 2, 1, 1);
    	m_Grid.attach(balance3, 2, 2, 1, 1);
    	m_Grid.attach(balance4, 3, 2, 1, 1);
    	m_Grid.attach(balance5, 4, 2, 1, 1);
	
	image11.set_text(" | ");
	image12.set_text(" | ");
	image13.set_text(" | ");
	image14.set_text(" | ");


//	cvbox.pack_start(publicCardHbox);
//	publicCardHbox.pack_start(image11, Gtk::PACK_END, 0);
//	publicCardHbox.pack_start(image12, Gtk::PACK_END, 0);
//	publicCardHbox.pack_start(image13, Gtk::PACK_END, 0);
//	publicCardHbox.pack_start(image14,Gtk::PACK_END, 0);
//	publicCardHbox.pack_start(image15,Gtk::PACK_END, 0);

	h1 =Gtk::manage(new Gtk::Image{sml(21)});
	h2 =Gtk::manage(new Gtk::Image{sml(121)});
	h3 =Gtk::manage(new Gtk::Image{sml(113)});
	h4 =Gtk::manage(new Gtk::Image{sml(122)});
	h5 =Gtk::manage(new Gtk::Image{sml(123)});

	h6 =Gtk::manage(new Gtk::Image{sml(11)});
	h7 =Gtk::manage(new Gtk::Image{sml(11)});
	h8 =Gtk::manage(new Gtk::Image{sml(11)});
	h9 =Gtk::manage(new Gtk::Image{sml(11)});
	h10 =Gtk::manage(new Gtk::Image{sml(11)});

	h11 =Gtk::manage(new Gtk::Image{sml(11)});
	h12 =Gtk::manage(new Gtk::Image{sml(11)});
	h13 =Gtk::manage(new Gtk::Image{sml(11)});
	h14 =Gtk::manage(new Gtk::Image{sml(11)});
	h15 =Gtk::manage(new Gtk::Image{sml(11)});

	h16 =Gtk::manage(new Gtk::Image{sml(11)});
	h17 =Gtk::manage(new Gtk::Image{sml(11)});
	h18 =Gtk::manage(new Gtk::Image{sml(11)});
	h19 =Gtk::manage(new Gtk::Image{sml(11)});
	h20 =Gtk::manage(new Gtk::Image{sml(11)});

	h21 =Gtk::manage(new Gtk::Image{sml(11)});
	h22 =Gtk::manage(new Gtk::Image{sml(11)});
	h23 =Gtk::manage(new Gtk::Image{sml(11)});
	h24 =Gtk::manage(new Gtk::Image{sml(11)});
	h25 =Gtk::manage(new Gtk::Image{sml(11)});


	small_card_grid1.attach(*h1, 0, 0, 1, 1);
    	small_card_grid1.attach(*h2, 1, 0, 1, 1);
    	small_card_grid1.attach(*h3, 2, 0, 1, 1);
    	small_card_grid1.attach(*h4, 3, 0, 1, 1);
    	small_card_grid1.attach(*h5, 4, 0, 1, 1);
    
    	small_card_grid2.attach(*h6, 0, 0, 1, 1);
    	small_card_grid2.attach(*h7, 1, 0, 1, 1);
    	small_card_grid2.attach(*h8, 2, 0, 1, 1);
    	small_card_grid2.attach(*h9, 3, 0, 1, 1);
    	small_card_grid2.attach(*h10, 4, 0, 1, 1);
    
    	small_card_grid3.attach(*h11, 0, 0, 1, 1);
    	small_card_grid3.attach(*h12, 1, 0, 1, 1);
    	small_card_grid3.attach(*h13, 2, 0, 1, 1);
    	small_card_grid3.attach(*h14, 3, 0, 1, 1);
    	small_card_grid3.attach(*h15, 4, 0, 1, 1);

    	small_card_grid4.attach(*h16, 0, 0, 1, 1);
    	small_card_grid4.attach(*h17, 1, 0, 1, 1);
    	small_card_grid4.attach(*h18, 2, 0, 1, 1);
    	small_card_grid4.attach(*h19, 3, 0, 1, 1);
    	small_card_grid4.attach(*h20, 4, 0, 1, 1);

    	small_card_grid5.attach(*h21, 0, 0, 1, 1);
    	small_card_grid5.attach(*h22, 1, 0, 1, 1);
    	small_card_grid5.attach(*h23, 2, 0, 1, 1);
    	small_card_grid5.attach(*h24, 3, 0, 1, 1);
    	small_card_grid5.attach(*h25, 4, 0, 1, 1);

	m_Grid.attach(small_card_grid1, 0, 3, 1, 1);
    	m_Grid.attach(small_card_grid2, 1, 3, 1, 1);
    	m_Grid.attach(small_card_grid3, 2, 3, 1, 1);
    	m_Grid.attach(small_card_grid4, 3, 3, 1, 1);
    	m_Grid.attach(small_card_grid5, 4, 3, 1, 1);
    
        shiftIndicator();

	pot.set_text("\nPOT: $" +std::to_string(potVal));
	//pot.override_foreground_color(Gdk::RGBA{"gold"});
	m_Grid.attach(pot, 2, 5, 1, 1);
	
	timer.set_text("Timer time: ");
        m_Grid.attach(timer, 4, 5, 1, 1);
        Glib::signal_timeout().connect( sigc::mem_fun(*this, &Mainwin::on_my_timeout), 1000 );
	
	bh1 =Gtk::manage(new Gtk::Image{big(21)});
	bh2 =Gtk::manage(new Gtk::Image{big(121)});
	bh3 =Gtk::manage(new Gtk::Image{big(113)});
	bh4 =Gtk::manage(new Gtk::Image{big(122)});
	bh5 =Gtk::manage(new Gtk::Image{big(123)});
	

	//image21.override_background_color(Gdk::RGBA{"black"});
	vbox->pack_start(sep2);
	vbox->pack_start(privateCardHbox);
	//image21.set_text(" \n");
	//privateCardHbox.pack_start(image21);
    	privateCardHbox.pack_start(*bh1); 
    	privateCardHbox.pack_start(*bh2); 
    	privateCardHbox.pack_start(*bh3); 
    	privateCardHbox.pack_start(*bh4); 
    	privateCardHbox.pack_start(*bh5); 

	vbox->pack_start(cardSelectionHbox);    
	cardSelectionHbox.pack_start(RB1,Gtk::PACK_END, 0);
	cardSelectionHbox.pack_start(RB2,Gtk::PACK_END, 0);
	cardSelectionHbox.pack_start(RB3,Gtk::PACK_END, 0);
	cardSelectionHbox.pack_start(RB4,Gtk::PACK_END, 0);
	cardSelectionHbox.pack_start(RB5,Gtk::PACK_END, 0);

	vbox->pack_start(exchangeHbox);    
	exchangeHbox.pack_start(exchange ,Gtk::PACK_END, 0);
  	exchange.signal_clicked().connect([this] {this->on_exchange_click();});
  	exchange.show();
 	vbox->pack_start(sep3);

	image21.set_text(" \n");
	//playHbox.pack_start(image21);

	HScale.set_digits(1);
	HScale.set_value_pos(Gtk::POS_TOP);
 	HScale.set_draw_value();

	//cvbox.pack_start(image21);  
	vbox->pack_start(playHbox); 
	playHbox.pack_start(fold ,Gtk::PACK_END, 0);
	playHbox.pack_start(check ,Gtk::PACK_END, 0);
	playHbox.pack_start(bet ,Gtk::PACK_END, 0);
	fold.set_size_request(250,30);
	check.set_size_request(250,30);
	bet.set_size_request(250,30);
	call.set_size_request(250,30);
	raise.set_size_request(250,30);
  	fold.signal_clicked().connect([this] {this->on_fold_click();});
  	fold.show();

  	check.signal_clicked().connect([this] {this->on_check_click();});
  	check.show();
  	bet.signal_clicked().connect([this] {this->on_bet_click();});
  	bet.show();

  	
	//playHbox.pack_start(sep4);
	playHbox.pack_end(HScale);
	HScale.set_range(5, 175);
	HScale.set_increments(1, 1);
	HScale.signal_value_changed().connect([this] {this->on_HScale_value_changed();});
	vbox->pack_start(image21);  

	//RB1.set_active();
	//RB2.set_active();
	//nhbox.show_all();
	//hbox.show_all();
	add(hbox);

	vbox->show_all();
	
	show_all_children();


}

Mainwin::~Mainwin() { }

void Mainwin::on_fold_click() {
reset=true;
action1.set_text("\nFolded");

std::cout << "Player Folded!" << std::endl;
shiftIndicator();
}

void Mainwin::on_check_click() {
reset=true;
action1.set_text("\nChecked");
std::cout << "Player Checked!" << std::endl;
shiftIndicator();
}

void Mainwin::on_bet_click() {
reset=true;
int sp = HScale.get_value();
TESTVAL = sp;
std::string to_call_button = "CALL $" + std::to_string(TESTVAL);
call.set_label(to_call_button);
action1.set_text("\nBet $" + std::to_string(sp));
std::cout << "Player Bet $" + std::to_string(sp) + "!"<< std::endl;
check.hide();
bet.hide();
playHbox.pack_start(call ,Gtk::PACK_END, 0);
playHbox.pack_start(raise ,Gtk::PACK_END, 0);
HScale.set_value(5);
call.signal_clicked().connect([this] {this->on_call_click();});
call.show();
raise.signal_clicked().connect([this] {this->on_raise_click();});
raise.show();
balance = balance - TESTVAL;
balance1.set_text("\n$" + std::to_string(balance));
shiftIndicator();
potVal = potVal + TESTVAL;
pot.set_text("\nPOT: $" +std::to_string(potVal));
}

void Mainwin::on_call_click() {
reset=true;
action1.set_text("\nCalled $" + std::to_string(TESTVAL));
std::cout << "Player Called $" + std::to_string(TESTVAL) + "!"<< std::endl;
shiftIndicator();
balance = balance - TESTVAL;
balance1.set_text("\n$" + std::to_string(balance));
potVal = potVal + TESTVAL;
pot.set_text("\nPOT: $" +std::to_string(potVal));
}

void Mainwin::on_raise_click() {
reset=true;
int sp = HScale.get_value();
action1.set_text("\nRaised $" + std::to_string(sp));
std::cout << "Player Raised $" + std::to_string(sp) + "!"<< std::endl;
TESTVAL += sp;
std::string to_call_button = "CALL $" + std::to_string(TESTVAL);
call.set_label(to_call_button);
shiftIndicator();
balance = balance - TESTVAL;
balance1.set_text("\n$" + std::to_string(balance));
potVal = potVal + TESTVAL;
pot.set_text("\nPOT: $" +std::to_string(potVal));
}

void Mainwin::on_HScale_value_changed() {
int sp = HScale.get_value();
std::string to_bet_button = "BET $" + std::to_string(sp);
std::string to_raise_button = "RAISE $" + std::to_string(sp);
if (sp == 175)
{
to_bet_button = "ALL IN $" + std::to_string(sp) + "!";
to_raise_button = "ALL IN $" + std::to_string(sp) + "!";
}
raise.set_label(to_raise_button);
bet.set_label(to_bet_button);
}
void Mainwin::on_exchange_click(){
if(RB1.get_active())
{
bh1->set(big(142));
h1->set(sml(142));
RB1.set_sensitive(false);
}
if(RB2.get_active())
{
bh2->set(big(94));
h2->set(sml(94));
RB2.set_sensitive(false);
}
if(RB3.get_active())
{
bh3->set(big(41));
h3->set(sml(41));
RB3.set_sensitive(false);
}
if(RB4.get_active())
{
bh4->set(big(111));
h4->set(sml(111));
RB4.set_sensitive(false);
}
if(RB5.get_active())
{
bh5->set(big(22));
h5->set(sml(22));
RB5.set_sensitive(false);
}
RB1.set_active(false);
RB2.set_active(false);
RB3.set_active(false);
RB4.set_active(false);
RB5.set_active(false);
}

void Mainwin::shiftIndicator(){
reset=false;
seconds=30;
m_Grid.remove(*indicator);
m_Grid.attach(*indicator, TESTTURN, 4, 1, 1);
TESTTURN += 1;
if (TESTTURN == 5) TESTTURN = 0;
}

bool Mainwin::on_my_timeout()
{
        char Text[50];
        sprintf (Text,"Timer: %d s",--seconds);
        timer.set_text(Text);
	if (seconds==5)
	{
		system("canberra-gtk-play  -f tick.wav &");
		std::cout<<"sound need to be played here"<<std::endl;
	}
        if (seconds==0)
        {
		system("canberra-gtk-play  -f buzzer.wav &");
		std::cout<<"sound need to be played here"<<std::endl;

                Mainwin::on_fold_click();
                seconds=30;
        }
      if (reset==true)
        {
              reset=false;  
	      Mainwin::shiftIndicator();
        }
        return true;
}









