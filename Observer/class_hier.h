#pragma once
#include <iostream>
#include <string>
#include <list>

static constexpr int STANDARD_BLOOD_PREASSURE = 60;
static constexpr int STANDARD_MUSCLE_PREASSURE = 30;
static constexpr int PREASSURE_INTERVAL = 5;

class AbstractPatient;

class AbstractMeasurerObs
{
public:
	virtual void update(AbstractPatient*) = 0;
};

class AbstractPatient
{
	std::list<AbstractMeasurerObs*> obsDevices;
public:
	virtual void attachObsDevice(AbstractMeasurerObs* obs)
	{
		obsDevices.push_back(obs);
	}
	virtual void detachObsDevice(AbstractMeasurerObs* obs)
	{
		obsDevices.remove(obs);
	}
	virtual void notify()
	{
		std::list<AbstractMeasurerObs*>::iterator iter = obsDevices.begin();
		for (; iter != obsDevices.end(); iter++)
			(*iter)->update(this);
	}
	virtual ~AbstractPatient() = 0;
};
AbstractPatient::~AbstractPatient()
{
	std::list<AbstractMeasurerObs*>::iterator iter = obsDevices.begin();
	for (; iter != obsDevices.end(); iter++)
		delete *iter;
}

class Patient : public AbstractPatient
{
	int bloodPreassure;
	int musclePreassure;
public:
	Patient() : bloodPreassure(STANDARD_BLOOD_PREASSURE), musclePreassure(STANDARD_MUSCLE_PREASSURE)
	{}
	Patient(int bloodPreassure, int musclePreassure) : bloodPreassure(bloodPreassure), musclePreassure(musclePreassure)
	{}
	void preassureRise()
	{
		bloodPreassure += PREASSURE_INTERVAL;
		musclePreassure += PREASSURE_INTERVAL;
		notify();
	}
	void preassureDrop()
	{
		bloodPreassure -= PREASSURE_INTERVAL;
		musclePreassure -= PREASSURE_INTERVAL;
		notify();
	}
	int getPatientBloodPreassureCondition()
	{
		return bloodPreassure;
	}
	int getPatientMusclePreassureCondition()
	{
		return musclePreassure;
	}
	~Patient() 
	{}
};

class BloodPreassureMeasurer : public AbstractMeasurerObs
{
	int currBloodPreasure;
	void changeCurrDeviceIndication()
	{
		std::cout << "Current blood preasure  = " + std::to_string(currBloodPreasure) << std::endl;
	}
public:
	void update(AbstractPatient* patient)
	{
		Patient* currExaminatedPatient = dynamic_cast<Patient*>(patient);
		if (currExaminatedPatient != nullptr)
		{
			currBloodPreasure = currExaminatedPatient->getPatientBloodPreassureCondition();
		}
		changeCurrDeviceIndication();
	}
};

class MusclePreassureMeasurer : public AbstractMeasurerObs
{
	int currMusclePreasure;
	void changeCurrDeviceIndication()
	{
		std::cout << "Current muscle preasure  = " + std::to_string(currMusclePreasure) << std::endl;
	}
public:
	void update(AbstractPatient* patient)
	{
		Patient* currExaminatedPatient = dynamic_cast<Patient*>(patient);
		if (currExaminatedPatient != nullptr)
		{
			currMusclePreasure = currExaminatedPatient->getPatientMusclePreassureCondition();
		}
		changeCurrDeviceIndication();
	}
};