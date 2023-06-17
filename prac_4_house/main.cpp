#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Configuration
{
public:
	virtual void poll() {};
	virtual ~Configuration() {};
};

class ElectricityCounter : public Configuration
{
private:
	std::string name;
public:
	ElectricityCounter() = default;
	void setName(std::string& str)
	{
		name = str;
	}
	void poll() override
	{
		std::cout << name << "\n";
	}
};

class DiscreteSignal : public Configuration
{
private:
	std::string name;
public:
	DiscreteSignal() = default;
	void setName(std::string& str)
	{
		name = str;
	}
	void poll() override
	{
		std::cout << name << "\n";
	}
};

class Heating : public Configuration
{
private:
	std::string name;
public:
	Heating() = default;
	void setName(std::string& str)
	{
		name = str;
	}
	void poll() override
	{
		std::cout << name << "\n";
	}
};




int main()
{
	setlocale(LC_ALL, "ru");
	std::ifstream file;
	file.open("list.txt");
	if (file.is_open())
	{
		std::cout << "The file is open.\n";
	}
	std::string line;
	bool s = true;


	std::vector<Configuration*> configuration;

	while (!file.eof())
	{
		if (s)							//s - флаг, чтобы считать в цикле вайл первую строку только один раз. ¬ последующие разы считывани€ строк идет далее
		{
			std::getline(file, line);
			s=false;
		}
		
		if (line == "Electricity monitors") {
			while (std::getline(file, line), line!= "Discrete signals" && line!="Heating" && !file.eof())
			{
			ElectricityCounter* electricity = new ElectricityCounter();
			electricity->setName(line);
			configuration.push_back(electricity);
			}
		}
		if (line == "Discrete signals") {
			while (std::getline(file, line), line != "Electricity monitors" && line != "Heating" && !file.eof())
			{
				
				DiscreteSignal* signal = new DiscreteSignal();
				signal->setName(line);
				configuration.push_back(signal);
			}
		}
		if (line == "Heating") {
			while (std::getline(file, line), line != "Electricity monitors" && line != "Discrete signals" && !file.eof())
			{
				Heating* heating = new Heating();
				heating->setName(line);
				configuration.push_back(heating);
			}
		}
		 
	}

	file.close();

	for (int i = 0; i < configuration.size(); i++)
	{
		
		std::cout <<std::endl;
		configuration[i]->poll();
	}

	for (int i = 0; i < configuration.size(); i++)
	{
		delete configuration[i];
	}

	return 0;
}