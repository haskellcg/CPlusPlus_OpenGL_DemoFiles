#ifndef __DRAWSQUAREBOUNCE_H__
#define __DRAWSQUAREBOUNCE_H__

#include <GLTools.h>
#include <GLShaderManager.h>

#ifdef __APPLE__
#include <freeglut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif


/**
 *@brief drawsquarebounce_test
 *@param int argc,
 *@param char *argv,
 *@return int
 *@remarks
 */
int drawsquarebounce_test(int argc, char *argv[]);

#endif //__DRAWSQUAREBOUNCE_H__