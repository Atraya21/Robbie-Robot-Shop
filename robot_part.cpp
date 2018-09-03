#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "robot_part.h"


Head::Head(string nameS,int model_numberS,double costS,string descriptionS,double powerS, string typeS)
{
name = nameS;
model_number = model_numberS;
cost = costS;
description = descriptionS;
power = powerS;
type = typeS;


};
int Head::save()
{
	ofstream HeadFile;
	HeadFile.open ("heads.txt", ofstream::app);
	HeadFile << type << '|';
	HeadFile << name << '|';
	HeadFile << model_number << '|';
	HeadFile << cost << '|';
	HeadFile << description <<'|';
	HeadFile << power << '|' << "\n";
	HeadFile.close();
};
/*load()
{
ifstream HeadFile;
HeadFile.open("heads.txt", ofstream::in);
string typeS;
string nameS;
string descriptionS;
int model_numberS;
double powerS;
double costS;

getline(HeadFile,typeS, '|');
getline(HeadFile,nameS, '|');
getline(HeadFile,model_numberS, '|');
getline(HeadFile,costS, '|');
getline(HeadFile,descriptionS, '|');
getline(HeadFile,powerS, '|');


}*/

Locomoter::Locomoter(string nameS,int model_numberS,double costS,string descriptionS,double max_power_locomoterS,string typeS)
{
name = nameS;
model_number = model_numberS;
cost = costS;
description = descriptionS;
max_power = max_power_locomoterS;
type = typeS;


};
int Locomoter::save()
{
	ofstream MoterFile;
	MoterFile.open ("moters.txt", ofstream::app);
	MoterFile << type <<'|';
	MoterFile << name <<'|';
	MoterFile << model_number << '|';
	MoterFile << cost << '|';
	MoterFile << description << '|';
	MoterFile << max_power << '|' << "\n";
	MoterFile.close();
};


Torso::Torso(string nameS,int model_numberS,double costS,string descriptionS,int battery_compartmentsS,int max_armsS, string typeS)
{
name = nameS;
model_number = model_numberS;
cost = costS;
description = descriptionS;
battery_compartments = battery_compartmentsS;
max_arms = max_armsS;
type = typeS;

};
int Torso::save()
{
	ofstream TorsoFile;
	TorsoFile.open ("torsos.txt", ofstream::app);
	TorsoFile << type <<'|';
	TorsoFile << name << '|';
	TorsoFile << model_number << '|';
	TorsoFile << cost << '|';
	TorsoFile << description << '|';
	TorsoFile << battery_compartments << '|';
	TorsoFile << max_arms << '|' << "\n";
};

Battery::Battery(string nameS,int model_numberS,double costS,string descriptionS,double power_availableS,double max_energyS, string typeS)
{

name = nameS;
model_number = model_numberS;
cost = costS;
description = descriptionS;
power_available = power_availableS;
max_energy = max_energyS;
type = typeS;

};
int Battery::save()
{
	ofstream BatteryFile;
	BatteryFile.open ("batteries.txt", ofstream::app);
	BatteryFile << type << '|';
	BatteryFile << name << '|';
	BatteryFile << model_number << '|';
	BatteryFile << cost << '|';
	BatteryFile << description << '|';
	BatteryFile << power_available << '|';
	BatteryFile << max_energy << '|' << "\n";
};

Arm::Arm(string nameS,int model_numberS,double costS,string descriptionS,double max_power_armS, string typeS)
{
name = nameS;
model_number = model_numberS;
cost = costS;
description = descriptionS;
max_power = max_power_armS;
type = typeS;

};
int Arm::save()
{
	ofstream ArmFile;
	ArmFile.open ("arms.txt", ofstream::app);
	ArmFile << type << '|';
	ArmFile << name << '|';
	ArmFile << model_number << '|';
	ArmFile << cost << '|';
	ArmFile << description << '|';
	ArmFile << max_power << '|' << "\n";
};


 string robot_part::display_name()
{
	 return name;
	
}
