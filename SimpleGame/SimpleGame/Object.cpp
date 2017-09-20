#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
}

void Object::SetInitialPosition(Vec3 input)
{
	m_InitialPosition.Set(input.m_x, input.m_y, input.m_z);
}
void Object::SetCurrentPosition(Vec3 input)
{
	m_CurrentPosition.Set(input.m_x, input.m_y, input.m_z);
}
void Object::SetInitialSpeed(Vec3 input)
{
	m_InitialSpeed.Set(input.m_x, input.m_y, input.m_z);
}
void Object::SetCurrentSpeed(Vec3 input)
{
	m_CurrentSpeed.Set(input.m_x, input.m_y, input.m_z);
}
void Object::SetInitialSize(Vec3 input)
{
	m_InitialSize.Set(input.m_x, input.m_y, input.m_z);
}
void Object::SetCurrentSize(Vec3 input)
{
	m_CurrentSize.Set(input.m_x, input.m_y, input.m_z);
}

Vec3 Object::GetInitialPosition()
{
	return m_InitialPosition;
}
Vec3 Object::GetCurrentPosition()
{
	return m_CurrentPosition;
}
Vec3 Object::GetInitialSpeed()
{
	return m_InitialSpeed;
}
Vec3 Object::GetCurrentSpeed()
{
	return m_CurrentSpeed;
}
Vec3 Object::GetInitialSize()
{
	return m_InitialSize;
}
Vec3 Object::GetCurrentSize()
{
	return m_CurrentSize;
}