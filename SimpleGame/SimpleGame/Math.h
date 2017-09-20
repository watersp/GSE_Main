#pragma once
class Vec3
{
public:
	Vec3()
	{

	};
	~Vec3()
	{

	};

	Vec3(float x, float y, float z)
	{
		m_x = x; m_y = y; m_z = z;
	};

	void Set(float x, float y, float z)
	{
		m_x = x; m_y = y; m_z = z;
	};

	float m_x;
	float m_y;
	float m_z;
};

class Math
{
public:
	Math();
	~Math();
};

