#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "part_holder.h"
#include "robot_part.h"
#include <fstream>
#include <sstream>
#include <exception>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>

using namespace std;
part_holder::part_holder(){};
int part_holder::add_customer()
{
	
	string CnameS;
	string CnumberS;
	string CpnumberS;
	string CemailS;
	string CpasswordS;
	customers.push_back(customer());
	string Pname = "enter your first and last name: ";
	fl_message_title("Adding customer");
	CnameS = fl_input(Pname.c_str(), 0);
	string Pnum = "enter your customer number: ";
	fl_message_title("Adding customer");
	CnumberS = fl_input(Pnum.c_str(), 0);
	string Ppnum = "enter your phone number: ";
	fl_message_title("Adding customer");
	CpnumberS = fl_input(Ppnum.c_str(), 0);
	string Pemail = "enter your email: ";
	fl_message_title("Adding customer");
	CemailS = fl_input(Pemail.c_str(), 0);
	string Paddress = "enter your shipping address: ";
	fl_message_title("Adding customer");
	string Caddress = fl_input(Paddress.c_str(), 0);
	string Ppassword = "enter your password: ";
	fl_message_title("Adding customer");
	CpasswordS = fl_input(Ppassword.c_str(), 0);
	customers[customer_counter].customer_name = CnameS;
	customers[customer_counter].customer_number = CnumberS;
	customers[customer_counter].customer_phone_number = CpnumberS;
	customers[customer_counter].customer_email = CemailS;
	customers[customer_counter].customer_shipping = Caddress;
	customers[customer_counter].customer_password = CpasswordS;
	customer_counter++;
}
int part_holder::add_sales_associate()
{
	string PnameS;
	string PnumberS;
	sales_associates.push_back(sales_associate());
	string Pname = "enter your first and last name: ";
	fl_message_title("Adding wage slave");
	PnameS = fl_input(Pname.c_str(), 0);
	string Pnum = "enter your employee number: ";
	fl_message_title("Adding wage slave");
	PnumberS = fl_input(Pnum.c_str(), 0);
	sales_associates[employee_counter].employee_name = PnameS;
	sales_associates[employee_counter].employee_number = PnumberS;
	employee_counter++;
}

int part_holder::add_part(int robot_part_choice)
{
	if (robot_part_choice == 1)
	{
		add_head();
		
	}
	if (robot_part_choice ==2)
	{
		add_locomoter();
	}
	if (robot_part_choice ==3)
	{
		add_torso();
	}
	if (robot_part_choice ==4)
	{
		add_battery();
	}
	if (robot_part_choice ==5)
	{
		add_arm();
	}
}
int part_holder::add_locomoter()
{
	string Pname = "enter a name for the part: ";
	fl_message_title("Adding locomoter");
	nameS =fl_input(Pname.c_str(), 0);
	string Pmodel = "enter the model number: ";
	fl_message_title("Adding locomoter");
	model_numberS =atoi(fl_input(Pmodel.c_str(), 0));
	string Pprice = "enter the cost of the part: ";
	fl_message_title("Adding locomoter");
	costS = atof(fl_input(Pprice.c_str(), 0));
	string Pdescription = "enter the decription of the part: ";
	fl_message_title("Adding locomoter");
	descriptionS =fl_input(Pdescription.c_str(), 0);
	string Ppower = "enter the max power of the part: ";
	fl_message_title("Adding locomoter");
	max_power_armS = atof(fl_input(Ppower.c_str(), 0));
	typeS = "LOCOMOTER";
part_stash.push_back(new Locomoter( nameS, model_numberS, costS, descriptionS, max_power_locomoterS, typeS));
	ofstream MoterFile;
	MoterFile.open ("moters.txt", ofstream::app);
	MoterFile << typeS <<'|';
	MoterFile << nameS <<'|';
	MoterFile << model_numberS << '|';
	MoterFile << costS << '|';
	MoterFile << descriptionS << '|';
	MoterFile << max_power_locomoterS << '|' << "\n";
	MoterFile.close();
counter++;
}

int part_holder::add_torso()
{
	string Pname = "enter a name for the part: ";
	fl_message_title("Adding torso");
	nameS =fl_input(Pname.c_str(), 0);
	string Pmodel = "enter the model number: ";
	fl_message_title("Adding torso");
	model_numberS =atoi(fl_input(Pmodel.c_str(), 0));
	string Pdescription = "enter the decription of the part: ";
	fl_message_title("Adding torso");
	descriptionS =fl_input(Pdescription.c_str(), 0);
	string batteries = "enter the number of battery compartments on the part: ";
	fl_message_title("Adding torso");
	battery_compartmentsS = atoi(fl_input(batteries.c_str(), 0));
	string Parms = "enter the max number of arms that can be attached: ";
	fl_message_title("Adding torso");
	max_armsS = atoi(fl_input(Parms.c_str(), 0));
	string Pprice = "enter the cost of the part: ";
	fl_message_title("Adding torso");
	costS = atof(fl_input(Pprice.c_str(), 0));
	typeS = "TORSO";
part_stash.push_back(new Torso( nameS, model_numberS, costS, descriptionS, battery_compartmentsS,max_armsS, typeS));
	ofstream TorsoFile;
	TorsoFile.open ("torsos.txt", ofstream::app);
	TorsoFile << typeS <<'|';
	TorsoFile << nameS << '|';
	TorsoFile << model_numberS << '|';
	TorsoFile << costS << '|';
	TorsoFile << descriptionS << '|';
	TorsoFile << battery_compartmentsS << '|';
	TorsoFile << max_armsS << '|' << "\n";

counter++;
}

int part_holder::add_head()
{
	string Pname = "enter a name for the part: ";
	fl_message_title("Adding head");
	nameS =fl_input(Pname.c_str(), 0);
	string Pmodel = "enter the model number: ";
	fl_message_title("Adding head");
	model_numberS =atoi(fl_input(Pmodel.c_str(), 0));
	string Pprice = "enter the cost of the part: ";
	fl_message_title("Adding head");
	costS = atof(fl_input(Pprice.c_str(), 0));
	string Pdescription = "enter the decription of the part: ";
	fl_message_title("Adding head");
	descriptionS =fl_input(Pdescription.c_str(), 0);
	string Ppower = "enter the power of the part: ";
	fl_message_title("Adding head");
	powerS = atof(fl_input(Ppower.c_str(), 0));
	typeS = "HEAD";
part_stash.push_back(new Head( nameS, model_numberS, costS, descriptionS, powerS, typeS));
	ofstream HeadFile;
	HeadFile.open ("heads.txt", ofstream::app);
	HeadFile << typeS << '|';
	HeadFile << nameS << '|';
	HeadFile << model_numberS << '|';
	HeadFile << costS << '|';
	HeadFile << descriptionS <<'|';
	HeadFile << powerS << '|' << "\n";
	HeadFile.close();
//part_stash[counter].save()
	


counter++;
}


int part_holder::add_battery()
{
	string Pname = "enter a name for the part: ";
	fl_message_title("Adding battery");
	nameS =fl_input(Pname.c_str(), 0);
	string Pmodel = "enter the model number: ";
	fl_message_title("Adding battery");
	model_numberS =atoi(fl_input(Pmodel.c_str(), 0));
	string Pdescription = "enter the decription of the part: ";
	fl_message_title("Adding battery");
	descriptionS =fl_input(Pdescription.c_str(), 0);
	string power = "enter the amount of power storage: ";
	fl_message_title("Adding battery");
	power_availableS = atoi(fl_input(power.c_str(), 0));
	string max_powerP = "enter the max power: ";
	fl_message_title("Adding battery");
	max_energyS = atoi(fl_input(max_powerP.c_str(), 0));
	string Pprice = "enter the cost of the part: ";
	fl_message_title("Adding battery");
	costS = atof(fl_input(Pprice.c_str(), 0));
	typeS = "BATTERY";
part_stash.push_back(new Battery( nameS, model_numberS, costS, descriptionS, power_availableS,max_energyS, typeS));
	ofstream BatteryFile;
	BatteryFile.open ("batteries.txt", ofstream::app);
	BatteryFile << typeS << '|';
	BatteryFile << nameS << '|';
	BatteryFile << model_numberS << '|';
	BatteryFile << costS << '|';
	BatteryFile << descriptionS << '|';
	BatteryFile << power_availableS << '|';
	BatteryFile << max_energyS << '|' << "\n";
	counter++;
}

int part_holder::add_arm()
{
	string Pname = "enter a name for the part: ";
	fl_message_title("Adding arm");
	nameS =fl_input(Pname.c_str(), 0);
	string Pmodel = "enter the model number: ";
	fl_message_title("Adding arm");
	model_numberS =atoi(fl_input(Pmodel.c_str(), 0));
	string Pprice = "enter the cost of the part: ";
	fl_message_title("Adding arm");
	costS = atof(fl_input(Pprice.c_str(), 0));
	string Pdescription = "enter the decription of the part: ";
	fl_message_title("Adding arm");
	descriptionS =fl_input(Pdescription.c_str(), 0);
	string Ppower = "enter the max power of the part: ";
	fl_message_title("Adding arm");
	max_power_armS = atof(fl_input(Ppower.c_str(), 0));
	typeS = "ARM";
part_stash.push_back(new Arm( nameS, model_numberS, costS, descriptionS, max_power_armS,typeS));
	ofstream ArmFile;
	ArmFile.open ("arms.txt", ofstream::app);
	ArmFile << typeS << '|';
	ArmFile << nameS << '|';
	ArmFile << model_numberS << '|';
	ArmFile << costS << '|';
	ArmFile << descriptionS << '|';
	ArmFile << max_power_armS << '|' << "\n";
counter++;
}

robot_model::robot_model(){};
string part_holder::list_customers()
{
	string customer_list = R"(
-------------------------------
List of our favorite customers
-------------------------------
)";
	for(y = 0; y < customer_counter ; y++)
	{ 
		
		customer_list += "\n";
		customer_list += "	name:  ";
		customer_list += customers[y].customer_name;
		customer_list += "	number:  ";
		customer_list += customers[y].customer_number;
		customer_list += "\n";
		}
	return customer_list;
}
string part_holder::list_employees()
{
		string employee_list = R"(
------------------------
List of our wage slaves
------------------------
)";
	for(y = 0; y < employee_counter ; y++)
	{
		employee_list += "\n";
		employee_list += "	name:  ";
		employee_list += sales_associates[y].employee_name;
		employee_list += "  number:  ";
		employee_list +=sales_associates[y].employee_number;
		
		/*cout <<"("<< y<<") "<< sales_associates[y].employee_name <<" employee number ["<<sales_associates[y].employee_number<<"] \n";*/
	}
	return employee_list;
}
string part_holder::list_part_names()
{

	fl_message_title("List of our robot parts");
	string robot_parts_list = R"(
	------------------
	Here is our parts
	------------------
	)";
	for ( y = 0; y < counter ; y++)
	{
		string num = to_string(y);
		robot_parts_list += "\n";
		robot_parts_list += num;
		robot_parts_list += "  name:  ";
		robot_parts_list += part_stash[y]->name;
		robot_parts_list += "  type:  ";
		robot_parts_list += part_stash[y]->type;

		if (part_stash[y]->type == "TORSO")
		{
		robot_parts_list += "  battery compartments  :";
		robot_parts_list += to_string(part_stash[y]->battery_compartments);
		robot_parts_list += "  cost:  ";
		robot_parts_list += to_string(part_stash[y]->cost);
			
		}
		else
		{
		robot_parts_list += "  cost:  ";
		robot_parts_list += to_string(part_stash[y]->cost);
		}
		
	}
	return robot_parts_list;
}
/*string Pname = "enter a name for the part: ";
fl_message_title("Adding arm");
nameS =fl_input(Pname.c_str(), 0);*/
int part_holder::make_a_robot()
	{
		string list;
		ofstream myfile;
		myfile.open ("robot_models.txt", ofstream::app);
		robot_model thing{};
		list = list_part_names();
		string choice = "Please select the number of the HEAD you require: \n";
		choice += list;
		fl_message_title("Pick a Head");
		part_choice = atoi(fl_input(choice.c_str(), 0));
		if (part_stash[part_choice]->type != "HEAD")
		{
			fl_message_title("ERROR");
			fl_message("that is not a head please pick again ");
			make_a_robot();
		}
		nameS = part_stash[part_choice]->name;
		model_numberS =part_stash[part_choice]->model_number;
		costS = part_stash[part_choice]->cost;
		robot_costS = costS;
		descriptionS = part_stash[part_choice]->description;
		powerS = part_stash[part_choice]->power;
		thing.add_a_head( nameS ,  model_numberS ,  costS ,  descriptionS ,  powerS);
		myfile << part_stash[part_choice]->type <<'|';
		myfile << nameS <<'|';
		myfile << model_numberS <<'|';
		myfile << descriptionS  <<'|';
		myfile << costS <<'|';
		myfile << powerS <<'|';
		
		
		string list2 = list_part_names();
		string choice2 = "Please select the number of the LOCOMOTER you require: \n";
		choice2 += list2;
		fl_message_title("Pick a Moter");
		part_choice = atoi(fl_input(choice2.c_str(), 0));
		
		if (part_stash[part_choice]->type != "LOCOMOTER")
		{
			fl_message_title("ERROR");
			fl_message("that is not a locomoter please pick again ");
			make_a_robot();
		}
		nameS = part_stash[part_choice]->name;
		model_numberS =part_stash[part_choice]->model_number;
		costS = part_stash[part_choice]->cost;
		robot_costS += costS;
		descriptionS = part_stash[part_choice]->description;
		max_power_locomoterS = part_stash[part_choice]->max_power;
		thing.add_a_locomoter( nameS ,  model_numberS ,  costS ,  descriptionS ,  max_power_locomoterS);
		myfile << part_stash[part_choice]->type <<'|';
		myfile << part_stash[part_choice]->name <<'|';
		myfile << part_stash[part_choice]->model_number <<'|';
		myfile << part_stash[part_choice]->cost <<'|';
		myfile << part_stash[part_choice]->description <<'|';
		myfile << part_stash[part_choice]->max_power <<'|';
	
		
		
		string list3 = list_part_names();
		string choice3 = "Please select the number of the torso you require: \n";
		choice3 += list3;
		fl_message_title("Pick a Torso");
		part_choice = atoi(fl_input(choice3.c_str(), 0));
		if (part_stash[part_choice]->type != "TORSO")
		{
			fl_message_title("ERROR");
			fl_message("that is not a torso please pick again ");
			make_a_robot();
		}
		nameS = part_stash[part_choice]->name;
		model_numberS =part_stash[part_choice]->model_number;
		costS = part_stash[part_choice]->cost;
		robot_costS += costS;
		descriptionS = part_stash[part_choice]->description;
		battery_compartmentsS = part_stash[part_choice]->battery_compartments;
		max_armsS =  part_stash[part_choice]->max_arms;
		maximum_batteries = battery_compartmentsS;
		maximum_arms = max_armsS;
		thing.add_a_torso( nameS ,  model_numberS ,  costS ,  descriptionS ,  battery_compartmentsS , max_armsS);
		myfile << part_stash[part_choice]->type <<'|';
		myfile << part_stash[part_choice]->name <<'|';
		myfile << part_stash[part_choice]->model_number <<'|';
		myfile << part_stash[part_choice]->cost <<'|';
		myfile << part_stash[part_choice]->description <<'|';
		myfile << part_stash[part_choice]->battery_compartments <<'|';
		myfile << part_stash[part_choice]->max_arms <<'|';
		
		for ( x = 0 ; x < maximum_batteries ; x++)
		{
		int batteryC = maximum_batteries;
		string list4 = list_part_names();
		string choice4 = "Please select the number of the BATTERY you require: \n";
		choice4 += list4;
		fl_message_title("Pick a BATTERY");
		part_choice = atoi(fl_input(choice4.c_str(), 0));
			if (part_stash[part_choice]->type != "BATTERY")
		{
			fl_message_title("ERROR");
			fl_message("that is not a BATTERY please pick again ");
			make_a_robot();
		}
		nameS = part_stash[part_choice]->name;
		model_numberS =part_stash[part_choice]->model_number;
		costS = part_stash[part_choice]->cost;
		robot_costS += costS;
		descriptionS = part_stash[part_choice]->description;
		power_availableS = part_stash[part_choice]->power_available;
		max_energyS = part_stash[part_choice]->max_energy;
		thing.add_a_battery( nameS ,  model_numberS ,  costS ,  descriptionS ,  power_availableS,  max_energyS);
		}
		myfile << part_stash[part_choice]->type <<'|';
		myfile << maximum_batteries << '|';	
		myfile << part_stash[part_choice]->name <<'|';
		myfile << part_stash[part_choice]->model_number <<'|';
		myfile << part_stash[part_choice]->cost <<'|';
		myfile << part_stash[part_choice]->description <<'|';
		myfile << part_stash[part_choice]->power_available <<'|';
		myfile << part_stash[part_choice]->max_energy <<'|';
	
		
		
		for ( z = 0; z < maximum_arms ; z++)
		{
		string list5 = list_part_names();
		string choice5 = "Please select the number of the ARM you require: \n";
		choice5 += list5;
		fl_message_title("Pick a ARM");
		part_choice = atoi(fl_input(choice5.c_str(), 0));
			if (part_stash[part_choice]->type != "ARM")
		{
			fl_message_title("ERROR");
			fl_message("that is not a ARM please pick again ");
			make_a_robot();
		}
		nameS = part_stash[part_choice]->name;
		model_numberS =part_stash[part_choice]->model_number;
		costS = part_stash[part_choice]->cost;
		robot_costS += costS;
		descriptionS = part_stash[part_choice]->description;
		max_power_armS = part_stash[part_choice]->max_power;
		thing.add_a_arm( nameS ,  model_numberS ,  costS ,  descriptionS ,  max_power_armS);
		}
		myfile << part_stash[part_choice]->type <<'|';
		myfile << maximum_arms << '|';	
		myfile << part_stash[part_choice]->name <<'|';
		myfile << part_stash[part_choice]->model_number <<'|';
		myfile << part_stash[part_choice]->cost <<'|';
		myfile << part_stash[part_choice]->description <<'|';
		myfile << part_stash[part_choice]->max_power <<'|';
			
		
		
		
	string getname = "Enter the name of your Robot : \n";
	fl_message_title("What is its name");
	thing.robot_name = fl_input(getname.c_str(), 0);
	thing.robot_cost = robot_costS;
	myfile << thing.robot_name <<'|';
	myfile << thing.robot_cost <<'|' <<'\n';
	robot_list.push_back(thing);	
	robot_counter++;
	
};

string part_holder::list_robots()
{
	
	
	string list_robot = R"(
------------------
List of our Robots
------------------
)";
	for(y = 0; y < robot_counter ; y++)
	{ 
		
		list_robot += "\n";
		list_robot += to_string(y);
		list_robot += "	name:  ";
		list_robot += robot_list[y].robot_name;
		list_robot += "	cost:  ";
		list_robot += to_string(robot_list[y].robot_cost);
		}
	return list_robot;

}
int robot_model::add_a_head(string nameS , int model_numberS , double costS , string descriptionS , double powerS)
{
	robot_head.head_name = nameS;
	robot_head.head_model_number = model_numberS;
	robot_head.head_cost = costS;
	robot_head.head_description = descriptionS;
	robot_head.head_power = powerS;
	
}
int robot_model::add_a_locomoter(string nameS , int model_numberS , double costS , string descriptionS , double max_power_locomoterS)
{
	robot_locomoter.locomoter_name = nameS;
	robot_locomoter.locomoter_model_number = model_numberS;
	robot_locomoter.locomoter_cost = costS;
	robot_locomoter.locomoter_description = descriptionS;
	robot_locomoter.locomoter_max_power = max_power_locomoterS;

}
int robot_model::add_a_torso(string nameS , int model_numberS , double costS , string descriptionS , int battery_compartmentsS, int max_armsS)
{
	robot_torso.torso_name = nameS;
	robot_torso.torso_model_number = model_numberS;
	robot_torso.torso_cost = costS;
	robot_torso.torso_description = descriptionS;
	robot_torso.torso_battery_compartments = battery_compartmentsS;
	robot_torso.torso_max_arms = max_armsS;

}
int robot_model::add_a_battery(string nameS , int model_numberS , double costS , string descriptionS , double power_availableS, double max_energyS)
{
	batteries.push_back(robot_battery());
	batteries[b].battery_name = nameS;
	batteries[b].battery_model_number = model_numberS;
	batteries[b].battery_cost = costS;
	batteries[b].battery_description = descriptionS;
	batteries[b].battery_power_available = power_availableS;
	batteries[b].battery_max_energy = max_energyS;
	b++;
}
int robot_model::add_a_arm(string nameS , int model_numberS , double costS , string descriptionS , double max_power_armS)
{
	arms.push_back(robot_arm());
	arms[a].arm_name = nameS;
	arms[a].arm_model_number = model_numberS;
	arms[a].arm_cost = costS;
	arms[a].arm_description = descriptionS;
	arms[a].arm_max_power = max_power_armS;
	a++;
	
}

int part_holder::add_a_purchace(int customer_choice, string customer_name_choice, string password_attempt, bool buying_robot)
{
	
	
	purchace_choice_name = robot_list[customer_choice].robot_name;
	purchace_choice_cost = robot_list[customer_choice].robot_cost;
	password_of_user = password_attempt;
	name_of_user = customer_name_choice;
	int status =1;
	
	purchace_order purchace(password_of_user, purchace_choice_name, purchace_choice_cost, name_of_user, status);
	
	purchaces.push_back(purchace);
	purchace_order_counter++;
//	if (buying_robot == false)
//	{
	//purchaces.push_back(purchace);
	//purchace_order_counter++;
//	}
	
}

purchace_order::purchace_order(string password_of_user, string purchace_choice_name, double purchace_choice_cost, string username, int status )
{
	
total_purchace_cost += purchace_choice_cost;
user_login = username;
user_password = password_of_user;
robot_costs.push_back(purchace_choice_cost);
robots_purchaced.push_back(purchace_choice_name);
purchace_counter++;
complete == status;
	
};
string part_holder::display_purchases()
{
	/*list_customers();
	cout << "please select your user id : \n";
	cin >> customer_choice;
	cout << "enter your password: \n";
	cin >> password_attempt;
	
		if (username_attempt.compare(purchaces[customer_choice].user_password) == 0)
		{
			for (x = 0; x < purchace_order_counter; x++)
			{
				cout <<"robot name: " <<purchaces[customer_choice].robots_purchaced[x] << " cost: "<<purchaces[customer_choice].robot_costs[x] <<"\n";
				
				
			}
			cout << "total cost: " << purchaces[customer_choice].total_purchace_cost;
			
		}
	
	*/
	string purchase_list = " Here is the list of customer purchases ";
	for( int c =0; purchace_order_counter; c++)
	{
		if(purchaces[c].complete == 1)
		{
			string num = to_string(c);
			purchase_list += "\n";
			purchase_list += num;
			purchase_list += " Customer Name: ";
			purchase_list += purchaces[c].user_login;
			purchase_list += " Customer Purchase: ";
			purchase_list += purchaces[c].robots_purchaced[0];
			purchase_list += " Purchace Cost: ";
			purchase_list +=  to_string(purchaces[c].robot_costs[0]);
		}
		return purchase_list;
	}
	
}
int part_holder::purchase_bot()
{
	string list = list_customers();
	string list2 = list_customers();
	string choice = " \nPlease type in your user name";
	string choice2 = " \nPlease type in your password";
	list += choice;
	list2 += choice2;
	fl_message_title("log in");
	string user_name = fl_input(list.c_str(),0);
		for(int c =0; c<customer_counter;c++)
		{
		 string check = customers[c].customer_name;
			if (check == user_name)
{
			fl_message_title("log in");
	string password_attempt = fl_input(list2.c_str(),0);
		for(int c =0; c<customer_counter;c++)
					{
		 string check = customers[c].customer_password;
			if (check == password_attempt)
					{
	while (buying_robot == true)
	{
	fl_message_title("Please select a Robot");
	string robot_select = list_robots();
	
	robot_select += "\n please select the robot you wish to buy : \n";
	customer_choice = atoi(fl_input(robot_select.c_str(),0));
	add_a_purchace( customer_choice,user_name,password_attempt,first_purchace);
	first_purchace = false;
	string message =  robot_list[customer_choice].robot_name ;
	message += " was added to your order ";
	message += "\n do you wish to buy a new robot [Y/n]? : \n";
	yes_no = fl_input(message.c_str(),0);
		if (yes_no == "Y")
		{
			buying_robot = true;
		}
		if (yes_no == "n")
		{
			buying_robot = false;	
		}
		else 
		{
			cout << "please enter a [Y] or a [n] \n";	
		}
		
	}
				}
				}
}
			
		}
	

	while (buying_robot == true)
	{
	fl_message_title("Please select a Robot");
	string robot_select = list_robots();
	
	robot_select += "\n please select the robot you wish to buy : \n";
	customer_choice = atoi(fl_input(robot_select.c_str(),0));
	add_a_purchace( customer_choice,user_name,password_attempt,first_purchace);
	first_purchace = false;
	string message =  robot_list[customer_choice].robot_name ;
	message += " was added to your order ";
	message += "\n do you wish to buy a new robot [Y/n]? : \n";
	yes_no = fl_input(message.c_str(),0);
		if (yes_no == "Y")
		{
			buying_robot = true;
		}
		if (yes_no == "n")
		{
			buying_robot = false;	
		}
		else 
		{
			cout << "please enter a [Y] or a [n] \n";	
		}
		
	}
	
	if (buying_robot == false)
	{
	string display = "saving and submiting your purchace order \n";
		fl_message(display.c_str(),0);
		add_a_purchace( customer_choice,user_name,password_attempt,buying_robot);

	}
	
}
int part_holder::complete_order()
{
	fl_message_title("Employee login");
	string list = list_employees();
	string list2 = list;
	list += "\n Please enter your employee name";
	list2 += "\n Please enter your employee number";
	string name = fl_input(list.c_str(),0);
	int num = atoi(fl_input(list2.c_str(),0));
	string list3 = display_purchases();
	int choice = atoi(fl_input(list3.c_str(),0));
	string checker = purchaces[choice].user_login;
	for (int c=0; c <purchace_order_counter; c++);
	{
	 if (customers[c].customer_name == checker &&purchaces[c].complete == 1)
	 {
		 string customer_info = " Here is the customer information:  \n";
		 customer_info += "  name:  ";
		 customer_info += customers[c].customer_name;
		 customer_info += "  adress:  ";
		 customer_info += customers[c].customer_shipping;
		 customer_info += "  purchace cost:  ";
		 customer_info += to_string(purchaces[c].robot_costs[0]);
		 string customer_info3 ="  Please enter the price:  \n";
		 string customer_info2 ="  Please enter the shipping adress:  \n";
		 customer_info3 += customer_info;
		 customer_info2 += customer_info; 
		 string address = fl_input(customer_info2.c_str(),0);
		 string cost = fl_input(customer_info3.c_str(),0);
		 string date =fl_input("when would you like this to be shipped",0);
		 purchaces[c].complete = 0;
		 
	 }
	}
	
}
int part_holder::savePurchaces()
{
	ofstream file;
	file.open ("purchace_file.txt");
	for(int c=0; c < purchaces.size(); c++){
	file << purchaces[c].robots_purchaced[0] << '|';
	file << purchaces[c].user_password << '|';
	file << purchaces[c].robot_costs[0] << '|';
	file << purchaces[c].user_login << '|';
	file << purchaces[c].complete << '|' << '\n';
	}
	file.close();
}
	
int part_holder::save()
{
/*cout << "saved 1";
ofstream output_file("./parts.txt");
ostream_iterator<robot_part*> iterator(output_file, "\n");
copy(part_stash.begin(), part_stash.end(), iterator);
cout << "saved 2";
*/
	//customers.push_back(customer());
	
	ofstream myfile;
	myfile.open ("customersXD.txt");
	for(int i=0; i < customers.size(); i++){

	myfile << customers[i].customer_name << '|';
	myfile << customers[i].customer_number << '|';
	myfile << customers[i].customer_phone_number << '|';
	myfile << customers[i].customer_email << '|';
	myfile << customers[i].customer_shipping << '|';
	myfile << customers[i].customer_password << '|' << '\n' ;
	}
	myfile.close();
	ofstream myfile2;
	myfile2.open ("salesassociates.txt");
	for(int i=0; i < sales_associates.size(); i++){
	myfile2 << sales_associates[i].employee_name << '|';
	myfile2 << sales_associates[i].employee_number << '|';
	myfile2 << sales_associates[i].sales << '|' << '\n';
	
	}
	myfile2.close();
		
}
int part_holder::load()
{
int i =0;
int c =0;
ifstream inputFile;
string holder;
string data;
inputFile.open("customersXD.txt");
	if (inputFile.is_open()&&!inputFile.eof())
	{
		
		while (inputFile.good() ){
		getline(inputFile, data,'|');
		if (data == "")
		{
		break;
		}
		else{
		
		customers.push_back(customer());
		customers[i].customer_name = data;
		//stringstream linestream(holder);
	//	getline(inputFile, customers[i].customer_name, '|');
		getline(inputFile, customers[i].customer_number, '|');
		getline(inputFile, customers[i].customer_phone_number, '|');
		getline(inputFile, customers[i].customer_email, '|');
		getline(inputFile, customers[i].customer_shipping, '|');
		getline(inputFile, customers[i].customer_password, '|');
		getline(inputFile, holder);
	    customer_counter++;		
		i++;
		}
								}
	

	}
	 inputFile.close();
	 i=0;
	ifstream inputFile2;
	inputFile2.open("salesassociates.txt");
	if (inputFile2.is_open() &&!inputFile2.eof()){
	
		while(inputFile2.good())
		{
		getline(inputFile2,data, '|');
		if(data == ""){
		break;
		}
		else{
		sales_associates.push_back(sales_associate());
		sales_associates[i].employee_name = data;
		//getline(inputFile2, sales_associates[i].employee_name, '|');
		getline(inputFile2, sales_associates[i].employee_number, '|');
		getline(inputFile2, sales_associates[i].sales, '|');
		getline(inputFile2, holder);
		i++;
		employee_counter++;
		}
		}
		inputFile2.clear();
											   }
	
}

int part_holder::loadHead()
{
	
string check;
string holder;
ifstream HeadFile;
HeadFile.open("heads.txt");
string typeS;
string nameS;
string descriptionS;
string model_numR;
string powerR;
string costR;
int model_numberS;
double powerS;
double costS;

while(HeadFile.is_open()&&!HeadFile.eof())
{
	
getline(HeadFile,check, '|');
	if(check == ""){
	break;}
typeS = check;
getline(HeadFile,nameS, '|');
getline(HeadFile,model_numR, '|');
getline(HeadFile,costR, '|');
getline(HeadFile,descriptionS, '|');
getline(HeadFile,powerR, '|');
model_numberS = atoi(model_numR.c_str());
getline(HeadFile, holder);
powerS = atof(powerR.c_str());
costS = atof(costR.c_str());
part_stash.push_back(new Head( nameS, model_numberS, costS, descriptionS, powerS, typeS));
	counter++;
}
HeadFile.close();

}

int part_holder::loadArm()
{
	
string check;
string holder;
ifstream ArmFile;
ArmFile.open("arms.txt");
string typeS;
string nameS;
string descriptionS;
string model_numR;
string powerR;
string costR;
int model_numberS;
double powerS;
double costS;

while(ArmFile.is_open()&&!ArmFile.eof())
{
	
getline(ArmFile,check, '|');
	if(check == ""){
	break;}
typeS = check;
getline(ArmFile,nameS, '|');
getline(ArmFile,model_numR, '|');
getline(ArmFile,costR, '|');
getline(ArmFile,descriptionS, '|');
getline(ArmFile,powerR, '|');
model_numberS = atoi(model_numR.c_str());
getline(ArmFile, holder);
max_power_armS = atof(powerR.c_str());
costS = atof(costR.c_str());
part_stash.push_back(new Arm( nameS, model_numberS,costS,descriptionS,max_power_armS, typeS));
	counter++;
}
ArmFile.close();

}
int part_holder::loadMotor()
{
	
string check;
string holder;
ifstream MotorFile;
MotorFile.open("moters.txt");
string typeS;
string nameS;
string descriptionS;
string model_numR;
string powerR;
string costR;
int model_numberS;
double powerS;
double costS;

while(MotorFile.is_open()&&!MotorFile.eof())
{
	
getline(MotorFile,check, '|');
	if(check == ""){
	break;}
typeS = check;
getline(MotorFile,nameS, '|');
getline(MotorFile,model_numR, '|');
getline(MotorFile,costR, '|');
getline(MotorFile,descriptionS, '|');
getline(MotorFile,powerR, '|');
model_numberS = atoi(model_numR.c_str());
getline(MotorFile, holder);
max_power_locomoterS = atof(powerR.c_str());
costS = atof(costR.c_str());
part_stash.push_back(new Locomoter( nameS, model_numberS,costS,descriptionS,max_power_locomoterS, typeS));
	counter++;
}
MotorFile.close();

}

int part_holder::loadBattery()
{
	
string check;
string holder;
ifstream BatteryFile;
BatteryFile.open("batteries.txt");
string typeS;
string nameS;
string descriptionS;
string model_numR;
string powerR;
string max_powerR;
string costR;
int model_numberS;
double powerS;
double costS;
double max_energyS;

while(BatteryFile.is_open()&&!BatteryFile.eof())
{
	
getline(BatteryFile,check, '|');
	if(check == ""){
	break;}
typeS = check;
getline(BatteryFile,nameS, '|');
getline(BatteryFile,model_numR, '|');
getline(BatteryFile,costR, '|');
getline(BatteryFile,descriptionS, '|');
getline(BatteryFile,powerR, '|');
getline(BatteryFile,max_powerR,'|');
model_numberS = atoi(model_numR.c_str());
getline(BatteryFile, holder);
power_availableS = atof(powerR.c_str());
max_energyS = atof(max_powerR.c_str());
costS = atof(costR.c_str());
part_stash.push_back(new Battery( nameS, model_numberS, costS, descriptionS, power_availableS,max_energyS, typeS));
	counter++;
}
BatteryFile.close();

}

int part_holder::loadTorso()
{
	
string check;
string holder;
ifstream TorsoFile;
TorsoFile.open ("torsos.txt");
string typeS;
string nameS;
string descriptionS;
string model_numR;
string batter_compartmentsR;
string max_armsR;
string costR;
int model_numberS;
int max_armsS;
int battery_compartmentsS;
double costS;

while(TorsoFile.is_open()&&!TorsoFile.eof())
{
	
getline(TorsoFile,check, '|');
	if(check == ""){
	break;}
typeS = check;
getline(TorsoFile,nameS, '|');
getline(TorsoFile,model_numR, '|');
getline(TorsoFile,costR, '|');
getline(TorsoFile,descriptionS, '|');
getline(TorsoFile,batter_compartmentsR, '|');
getline(TorsoFile,max_armsR,'|');
model_numberS = atoi(model_numR.c_str());
getline(TorsoFile, holder);
battery_compartmentsS = atoi(batter_compartmentsR.c_str());
max_armsS = atoi(max_armsR.c_str());
costS = atof(costR.c_str());
part_stash.push_back(new Torso( nameS, model_numberS, costS, descriptionS, battery_compartmentsS,max_armsS, typeS));
	counter++;
}
TorsoFile.close();

}

int part_holder::loadRobot()
{
	string check;
	string catcher;
	string typeS;
	string nameS;
	string descriptionS;
	string model_numR;
	string batter_compartmentsR;
	string max_armsR;
	string costR;
	string powerR;
	string max_powerR;
	string robot_costS;
	string how_many_armsR;
	string how_many_batsR;
	int how_many_arms;
	int how_many_bats;
	int model_numberS;
	int max_armsS;
	int battery_compartmentsS;
	double power_availableS;
	double powerS;
	double max_energyS;
	double costS;
	double max_power_locomoterS;
	double max_power_armS;
	ifstream robotFile;
	robotFile.open ("robot_models.txt");
	robot_model thing{};
	
	while(robotFile.is_open()&&!robotFile.eof())
	{
	
		
	getline(robotFile,check, '|');
	if(check == "")
	{
	break;
	}
	else if(check == "HEAD") 
	{
	getline(robotFile,nameS, '|');
	getline(robotFile,model_numR, '|');
	getline(robotFile,descriptionS,'|');
	getline(robotFile,costR, '|');
	getline(robotFile,powerR, '|');
	costS = atof(costR.c_str());
	powerS = atof(powerR.c_str());
	thing.add_a_head( nameS, model_numberS,  costS ,  descriptionS ,  powerS);
	}
	getline(robotFile,check, '|');
	if(check == "LOCOMOTER")
	{
	getline(robotFile,nameS, '|');
	getline(robotFile,model_numR, '|');
	getline(robotFile,costR, '|');
	getline(robotFile,descriptionS, '|');
	getline(robotFile,powerR, '|');
	model_numberS = atoi(model_numR.c_str());
	max_power_locomoterS = atof(powerR.c_str());
	costS = atof(costR.c_str());
	thing.add_a_locomoter(nameS ,  model_numberS ,  costS ,  descriptionS ,  max_power_locomoterS);
	}
	getline(robotFile,check, '|');
	if(check == "TORSO")
	{
	getline(robotFile,nameS, '|');
	getline(robotFile,model_numR, '|');
	getline(robotFile,costR, '|');
	getline(robotFile,descriptionS, '|');
	getline(robotFile,batter_compartmentsR, '|');
	getline(robotFile,max_armsR, '|');
	costS = atof(costR.c_str());
	model_numberS = atoi(model_numR.c_str());
	max_armsS = atoi(max_armsR.c_str());
	battery_compartmentsS = atoi(batter_compartmentsR.c_str());
	thing.add_a_torso( nameS ,  model_numberS ,  costS ,  descriptionS ,  battery_compartmentsS , max_armsS);
	}
	getline(robotFile,check, '|');
	if(check == "BATTERY")
	{
	getline(robotFile,how_many_batsR, '|');
	how_many_bats = atoi(how_many_batsR.c_str());
	getline(robotFile,nameS, '|');
	getline(robotFile,model_numR, '|');
	getline(robotFile,costR, '|');
	getline(robotFile,descriptionS, '|');
	getline(robotFile,powerR, '|');
	getline(robotFile,max_powerR, '|');
	costS = atof(costR.c_str());
	power_availableS = atof(powerR.c_str());
	max_energyS =  atof(max_powerR.c_str());
	model_numberS = atoi(model_numR.c_str());
	for( int z=0; z<how_many_bats; z++){
	thing.add_a_battery( nameS ,  model_numberS ,  costS ,  descriptionS ,  power_availableS,  max_energyS);
	}
	}
	getline(robotFile,check, '|');
	if(check == "ARM")
	{
	getline(robotFile,how_many_armsR, '|');
	how_many_arms = atoi(how_many_armsR.c_str());
	getline(robotFile,nameS, '|');
	getline(robotFile,model_numR, '|');
	getline(robotFile,costR, '|');
	getline(robotFile,descriptionS, '|');
	getline(robotFile,max_powerR, '|');
	costS = atof(costR.c_str());
	model_numberS = atoi(model_numR.c_str());
	max_power_armS =  atof(max_powerR.c_str());
	for( int z=0; z<how_many_arms; z++){
	thing.add_a_arm( nameS ,  model_numberS ,  costS ,  descriptionS ,  max_power_armS);
	}
	}

	getline(robotFile,thing.robot_name, '|');
	getline(robotFile,robot_costS, '|');
	getline(robotFile,catcher);
	thing.robot_cost = atof(robot_costS.c_str());
	robot_list.push_back(thing);
	robot_counter++;
	}
	

	

}
int part_holder::loadPurchaces()
{
	string purchace_choice_name;
	string cost;
	string password;
	double purchace_choice_cost;
	string name_of_user;
	string complete2;
	string catcher;
	string check;
	int complete;
	ifstream file;
	file.open("purchace_file.txt");
	while(file.is_open()&&!file.eof())
	{
	
		
	getline(file,check, '|');
	if(check == "")
	{
	break;
	}
		else{
	purchace_choice_name = check;
	getline(file,password,'|');
	getline(file,cost, '|');
	getline(file,name_of_user, '|');
	getline(file,complete2,'|');
	getline(file,catcher);
	purchace_choice_cost = atof(cost.c_str());
	complete = atoi(complete2.c_str());
	purchace_order purchace(password, purchace_choice_name, purchace_choice_cost, name_of_user, complete);
	purchaces.push_back(purchace);
	purchace_order_counter++;
		}
		file.close();
	}
	/*
	purchace_choice_name = robot_list[customer_choice].robot_name;
	purchace_choice_cost = robot_list[customer_choice].robot_cost;
	password_of_user = password_attempt;
	name_of_user = customer_name_choice;
	purchace_order purchace(password_of_user, purchace_choice_name, purchace_choice_cost, name_of_user);
	file << purchace_choice_name << '|';
	file << purchace_choice_cost << '|';
	file << name_of_user << '|';
	file << purchace.complete << '|';
	*/
}


