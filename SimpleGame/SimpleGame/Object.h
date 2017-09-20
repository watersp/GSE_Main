#pragma once
#include "Math.h"

class Object
{
public:
	Object();
	~Object();

	void SetInitialPosition(Vec3 input);
	void SetCurrentPosition(Vec3 input);
	void SetInitialSpeed(Vec3 input);
	void SetCurrentSpeed(Vec3 input);
	void SetInitialSize(Vec3 input);
	void SetCurrentSize(Vec3 input);

	Vec3 GetInitialPosition();
	Vec3 GetCurrentPosition();
	Vec3 GetInitialSpeed();
	Vec3 GetCurrentSpeed();
	Vec3 GetInitialSize();
	Vec3 GetCurrentSize();

private:
	Vec3 m_InitialPosition = Vec3(0, 0, 0);
	Vec3 m_CurrentPosition = Vec3(0, 0, 0);
	Vec3 m_InitialSpeed = Vec3(0, 0, 0);
	Vec3 m_CurrentSpeed = Vec3(0, 0, 0);
	Vec3 m_InitialSize = Vec3(0, 0, 0);
	Vec3 m_CurrentSize = Vec3(0, 0, 0);

	float m_Life = 0;

	bool m_bRender = false;
};

