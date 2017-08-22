#pragma once
#include <iostream>
#include <vector>

class Face
{
	const int FACE_COMPONENTS = 3;
	const int EYES_POSITION = 0;
	const int NOSE_POSITION = 1;
	const int MOUTH_POSITION = 2;
	char* face;
protected:
	void setMood(char moodSign)
	{
		face[MOUTH_POSITION] = moodSign;
	}
	void drawFace()
	{
		std::cout << face[EYES_POSITION] << face[NOSE_POSITION] << face[MOUTH_POSITION];
	}
public:
	Face()
	{
		face = createFaceWithoutEmotion();
	}
	virtual void showEmotion() = 0;
	virtual ~Face() = 0;
private:
	char* createFaceWithoutEmotion()
	{
		char* retFace = new char[FACE_COMPONENTS];
		retFace[EYES_POSITION] = ':';
		retFace[NOSE_POSITION] = '-';
		return retFace;
	}
};
Face::~Face()
{
	delete[] face;
}

class SmileFace : public Face
{
public:
	SmileFace()
	{
		setMood(')');
	}
	void showEmotion()
	{
		std::cout << "I was happy ";
		drawFace();
		std::cout << std::endl;
	}
};

class SadFace : public Face
{
public:
	SadFace()
	{
		setMood('(');
	}
	void showEmotion()
	{
		std::cout << "I was sad ";
		drawFace();
		std::cout << std::endl;
	}
};

class EmotionLessFace : public Face
{
public:
	EmotionLessFace()
	{
		setMood('|');
	}
	void showEmotion()
	{
		std::cout << "I was like whatever ";
		drawFace();
		std::cout << std::endl;
	}
};

class FacialExpressionsComposite : public Face
{
	std::vector<Face*> myFacesDuringTheDay;
public:
	void addExpression(Face* expression)
	{
		myFacesDuringTheDay.push_back(expression);
	}
	void showEmotion()
	{
		for (Face* face : myFacesDuringTheDay)
			face->showEmotion();
	}
	~FacialExpressionsComposite()
	{
		for (Face* face : myFacesDuringTheDay)
			delete face;
	}
};