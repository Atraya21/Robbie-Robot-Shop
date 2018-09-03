#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>
#include "gui.h"
#include "part_holder.h"
#include "robot_part.h"
using namespace std;
 main (void)
{
	Fl_Window beacon(1, 1);
    beacon.show();
	view View{};
	part_holder Holder{};
	int counter=0;
	int user_input = -1;
	int robot_part_choice;
	Holder.loadRobot();
	Holder.load();
	Holder.loadHead();
    Holder.loadArm();
	Holder.loadMotor();
	Holder.loadBattery();
	Holder.loadTorso();
	Holder.loadPurchaces();
	string no_label ="";
	string menu = View.get_menu() + "\nCommand? ";
	
	while (user_input != 0)
	{
	fl_message_title("Robby Robots");
	user_input = atoi(fl_input(menu.c_str(), 0));
	
	
	//user_input =atoi(fl_i
	/*cout << "==================================\n";
	cout << "Atlas Software Robot Creator\n";
	cout << "==================================\n";
	cout << "\nPublications\n";
	cout << "------------\n";
	cout << "(1) Add a part \n";
	cout << "(2) List all parts \n";
	cout << "(3) Build a robot \n";
	cout << "(4) List all robots \n";
	cout << "(5) Add a customer \n";
	cout << "(6) List customers \n";
	cout << "(7) Add a sales associate \n";
	cout << "(8) List employees \n";
	cout << "(9) Buy a Robot \n";
	cout << "(0) End the program \n";
	cout <<"enter the number for the task you want to do: \n";*/
	
		
		
		
	//cin >> user_input;
	if (user_input ==1)
	{
        
	   string option_menu  = R"(
       please select the part you wish to add: 
		(1) Head
		(2) Locomoter
		(3) Torso 
		(4) Battery
		(5) Arm )";
		fl_message_title("What Part");
        robot_part_choice = atoi(fl_input(option_menu.c_str(), 0));
		if (robot_part_choice ==1)
	{
		Holder.add_head();
		cout <<"head created\n";
		
	}
	if (robot_part_choice ==2)
	{
		Holder.add_locomoter();
		cout <<"locomoter created\n";
		
		
	}	
	if (robot_part_choice ==3)
	{
		Holder.add_torso();
		cout <<"torso created\n";
		
		
	}
		if (robot_part_choice ==4)
	{
		Holder.add_battery();
		cout <<"battery created\n";
		
		
	}
	if (robot_part_choice ==5)
	{
		Holder.add_arm();
		cout <<"arm created\n";
		
	}
	if (robot_part_choice <0|robot_part_choice>5)
	{
	cout <<"invalid part choice\n";	
		
	}
}
	if (user_input == 2)
	{
        string parts_list = Holder.list_part_names();
        fl_message_title("List of our parts");
		fl_message(parts_list.c_str());
		//cout << "List of robot parts  \n";
		//cout << "=================== \n";
		//Holder.list_part_names();
	}
	if (user_input == 3)
	{
	
		Holder.make_a_robot();
	}
	if (user_input == 4)
	{
		
		string list = Holder.list_robots();
        fl_message_title("List of our Robots");
		fl_message(list.c_str());
	}
	if (user_input == 5)
	{
		Holder.add_customer();
	}
	if (user_input == 6)
	{
        
		string list = Holder.list_customers();
        fl_message_title("List of our customers");
		fl_message(list.c_str());
	}
	if (user_input == 7)
	{
		Holder.add_sales_associate();
	}
	if (user_input == 8)
	{
		string list = Holder.list_employees();
        fl_message_title("List of our wage slaves");
        fl_message(list.c_str());
	}
	if (user_input == 9)
	{
		Holder.purchase_bot();	
		
	}
	if (user_input == 11)
	{
		Holder.display_purchases();	
		
	}
	if (user_input == 10)
	{
		Holder.complete_order();
	}
//}


	}
	Holder.save();
Holder.savePurchaces();}
