/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Object.h"
#include "Math.h"

Renderer *g_Renderer = NULL;
Object* g_TestObject = NULL;
int g_ObjectCount = 50;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test

	g_Renderer->DrawSolidRect(0, 0, 0, 4, 1, 0, 1, 1);

	for (int i = 0; i < g_ObjectCount; i++)
	{
		Vec3 pos = g_TestObject[i].GetCurrentPosition();
		Vec3 size = g_TestObject[i].GetCurrentSize();
		g_Renderer->DrawSolidRect(pos.m_x, pos.m_y, pos.m_z, size.m_x, 1, 0, 1, 1);
	}

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	// Initialize Objects
	g_TestObject = new Object[g_ObjectCount];
	for (int i = 0; i < g_ObjectCount; i++)
	{
		Vec3 position;
		position.Set(
			((rand() / RAND_MAX) - 0.5f) * 500,
			((rand() / RAND_MAX) - 0.5f) * 500,
			0
		);

		Vec3 size;
		float value = (rand() / RAND_MAX) * 6.f;
		size.Set(value, value, value);

		g_TestObject[i].SetCurrentPosition(position);
		g_TestObject[i].SetCurrentSize(size);
	}

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

    return 0;
}

