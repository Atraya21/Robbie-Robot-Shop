#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>
#include "gui.h"

using namespace std;



string view::get_menu(){
	string menu = R"( ==================================
	Atlas Software Robot Creator
==================================
Publications
------------
(1) Add a part 
(2) List all parts 
(3) Build a robot 
(4) List all robots
(5) Add a customer
(6) List customers
(7) Add a sales associate
(8) List employees
(9) Buy a Robot
(10) Sales completion (for employees)
(0) End the program
)";
	cout<<"Here in GUI";
	return menu;
}
/*string view::get_customer_list(){
fl_message_title("Listal of our favorite customers");
fl_mess

}*/