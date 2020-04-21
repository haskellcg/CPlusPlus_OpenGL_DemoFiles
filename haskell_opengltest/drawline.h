#ifndef _DRAWLINE_H__
#define _DRAWLINE_H__

#include <glew/glew.h>

#ifdef __APPLE__
#include <freeglut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

/**
 *@brief drawline_test
 *@param int argc,
 *@param char *argv[],
 *@return int
 *@remarks
 */
int drawline_test(int argc, char *argv[]);

#endif //_DRAWLINE_H__