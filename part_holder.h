#ifndef PART_HOLDER_H
#define PART_HOLDER_H
#include <string>
#include "robot_part.h"
#include <vector>
using namespace std;


class robot_model 
{
public:

	struct 
	{
		string head_name;
		int head_model_number;
		double head_cost;
		string head_description;
		double head_power;
	} robot_head;
	struct 
	{
		string locomoter_name;
		int locomoter_model_number;
		double locomoter_cost;
		string locomoter_description;
		double locomoter_max_power;
	} robot_locomoter;
	struct
	{
		string torso_name;
		int torso_model_number;
		double torso_cost;
		string torso_description;
		int torso_battery_compartments;
		int torso_max_arms;
	} robot_torso;
	struct robot_battery
	{
		string battery_name;
		int battery_model_number;
		double battery_cost;
		string battery_description;
		double battery_power_available;
		double battery_max_energy;
	};
	struct robot_arm
	{
		string arm_name;
		int arm_model_number;
		double arm_cost;
		string arm_description;
		double arm_max_power;
	};
	
	string robot_name;
	double robot_cost;
	vector <robot_battery> batteries;
	vector <robot_arm> arms;
	robot_model();
	int b = 0;
	int a = 0;
	int add_a_head(string head_name, int model_numberS, double costS, string descriptionS, double powerS);
	int add_a_locomoter(string nameS , int model_numberS , double costS , string descriptionS , double max_power_locomoterS);
	int add_a_torso(string nameS , int model_numberS , double costS , string descriptionS , int battery_compartmentsS, int max_armsS);
	int add_a_battery(string nameS , int model_numberS , double costS , string descriptionS , double power_availableS, double max_energyS);
	int add_a_arm(string nameS , int model_numberS , double costS , string descriptionS , double max_power_armS);
	
	
	
	
	
	
	

};
class purchace_order
{
public:
purchace_order(string password_of_user, string purchace_choice_name, double purchace_choice_cost, string username, int status);
vector <string> robots_purchaced;
vector <double> robot_costs;
vector <string> user_purchaces;
double total_purchace_cost;
string user_password;
string user_login;
int purchace_counter;
int complete = 1;
};
class part_holder
{

public:
int save();
int load();
struct customer
{
string customer_name;
string customer_number;
string customer_phone_number;
string customer_email;
string customer_password;
string customer_shipping;

};
struct sales_associate
{
string employee_name;
string employee_number;
string sales;

};
int savePurchaces();
int loadPurchaces();
int complete_order();
int loadRobot();
int loadArm();
int loadHead();
int loadMotor();
int loadBattery();
int loadTorso();
int purchace_choice_cost;
string purchace_choice_name;
bool first_purchace = true;
string password_of_user;
string name_of_user;
string username_attempt;
int add_customer();
int add_sales_associate();
string list_customers();
string list_employees();
int add_part(int robot_part_choice);
int add_head();
int add_locomoter();
int add_torso();
int add_battery();
int add_arm();
string list_part_names();
int list_heads();
int make_a_robot();
string list_robots();
int purchase_bot();
int purchace_order_counter =0;
string display_purchases();
int add_a_purchace( int customer_choice, string customer_name_choice, string password_attempt, bool buying_robot);
int customer_choice;
string yes_no;
bool buying_robot = true;
string password_attempt;
part_holder();
int counter=0;
int y = 0;
int x = 0;
int z = 0;
int g = 0;
int c = 0;
int r = 0;
int displayer_counter=0;
int employee_counter = 0;
int customer_counter = 0;
int part_choice;
int robot_counter;
vector<robot_model> robot_list;
vector <purchace_order> purchaces;
vector<customer> customers;
vector<sales_associate> sales_associates;
protected:
vector<robot_part*> part_stash;
private:
string typeS;
string nameS;
int model_numberS;
double costS;
string descriptionS;
double powerS;
double max_power_locomoterS;
int battery_compartmentsS;
int max_armsS;
double power_availableS;
double max_energyS;
double max_power_armS;
double robot_costS;
int maximum_arms;
int maximum_batteries;

};

/*

class robot_model
{
public:

	struct 
	{
		string head_name;
		int head_model_number;
		double head_cost;
		string head_description;
		double head_power;
	} robot_head;
	struct 
	{
		string locomoter_name;
		int locomoter_model_number;
		double locomoter_cost;
		string locomoter_description;
		double locomoter_max_power;
	} robot_locomoter;
	struct
	{
		string torso_name;
		int torso_model_number;
		double torso_cost;
		string torso_description;
		int torso_battery_compartments;
		int torso_max_arms;
	} robot_torso;
	struct robot_battery
	{
		string battery_name;
		int battery_model_number;
		double battery_cost;
		string battery_description;
		double battery_power_available;
		double battery_max_energy;
	};
	struct robot_arm
	{
		string arm_name;
		int arm_model_number;
		double arm_cost;
		string arm_description;
		double arm_max_power;
	};
	
	
	vector <robot_battery> batteries;
	vector <robot_arm> arms;
	robot_model();
	string robot_name;
	int b = 0;
	int a = 0;
	int add_a_head(string head_name, int model_numberS, double costS, string descriptionS, double powerS);
	int add_a_locomoter(string nameS , int model_numberS , double costS , string descriptionS , double max_power_locomoterS);
	int add_a_torso(string nameS , int model_numberS , double costS , string descriptionS , int battery_compartmentsS, int max_armsS);
	int add_a_battery(string nameS , int model_numberS , double costS , string descriptionS , double power_availableS, double max_energyS);
	int add_a_arm(string nameS , int model_numberS , double costS , string descriptionS , double max_power_armS);

	
	
	
	
	
	
	

};*/
#endif
