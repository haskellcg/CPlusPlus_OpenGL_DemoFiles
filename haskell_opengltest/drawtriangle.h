#ifndef __DRAWTRIANGLE_H__
#define __DRAWTRIANGLE_H__

#include <GLTools.h>
#include <GLShaderManager.h>

#ifdef __APPLE__
#include <freeglut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif


/**
 *@brief drawtriangle_test
 *@param int argc, 
 *@param char *argv[],
 *@return int
 *@remarks
 */
int drawtriangle_test(int argc, char *argv[]);

#endif //__DRAWTRIANGLE_H__