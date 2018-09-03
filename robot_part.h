#ifndef ROBOT_PART_H
#define ROBOT_PART_H
#include <string>
using namespace std;

class robot_part
{
public:
  string display_name();
  double power;
  double max_power;
  string name;
  string type;
  double power_available;
  double max_energy;
  int battery_compartments;
  int max_arms;
  int model_number;
  double cost;
  string description;
  
};
class Head : public robot_part
{
public:
	Head(string nameS, int model_numberS,double costS,string descriptionS,double powerS,string typeS);
  int load();
  int save();
};

class Locomoter : public robot_part
{
public:
	Locomoter(string nameS, int model_numberS,double costS,string descriptionS,double max_power_locomoterS,string typeS);
  int save();
};
class Torso : public robot_part
{
public:

Torso(string nameS,int model_numberS,double costS,string descriptionS,int battery_compartmentsS,int max_armsS, string typeS);
int save();
};

class Battery : public robot_part
{
public:

Battery(string nameS,int model_numberS,double costS,string descriptionS,double power_availableS,double max_energy, string typeS);
int save();

};
class Arm : public robot_part
{
public:
	Arm(string nameS, int model_numberS,double costS,string descriptionS,double max_power_armS, string typeS);
  int save();
};
#endif