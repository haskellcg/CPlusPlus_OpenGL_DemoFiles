#include "drawtriangle.h"

static GLBatch triangleBatch;
static GLShaderManager shaderManager;

static void ChangeSize(int w, int h)
{
	glViewport(0, 0, w, h);
}

static void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	shaderManager.InitializeStockShaders();

	GLfloat vVerts[] = {
		-0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	triangleBatch.Begin(GL_TRIANGLES, 3);
	triangleBatch.CopyVertexData3f(vVerts);
	triangleBatch.End();
}

static void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
	triangleBatch.Draw();

	glutSwapBuffers();
}

int drawtriangle_test(int argc, char *argv[])
{
	gltSetWorkingDirectory(argv[0]);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Triangle");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);

	GLenum err = glewInit();
	if (GLEW_OK != err){
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
		return 1;
	}

	SetupRC();

	glutMainLoop();

	return 0;
}