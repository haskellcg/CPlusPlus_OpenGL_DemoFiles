#ifndef __DRAWSQUAREMOVE_H__
#define __DRAWSQUAREMOVE_H__

#include <GLTools.h>
#include <GLShaderManager.h>

#ifdef __APPLE__
#include <freeglut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

/**
 *@brief drawsquaremove_test
 *@param int argc,
 *@param char *argv[]
 *@return int
 *@remarks
 */
int drawsquaremove_test(int argc, char *argv[]);

#endif //__DRAWSQUAREMOVE_H__