#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// General definits will be coded here
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
#endif

// Import Libs
#include <iostream>
#include <vector>
#include "Elemento.h"

// Desired dimensions
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

// Initial Position
#define INIT_POS_X 750
#define INIT_POS_Y 900
#define Y_CORRECTION 150
#define X_CORRECTION 7
#define SOFTWARE_TITLE "Trabalho Final"

// Min distance between points
#define MIN_DISTANCE 10

// Global variables
extern unsigned int **pgmMatrix;
extern int MAIN_WIDTH;
extern int keyStatus[256];

#endif // __GLOBALS_H__