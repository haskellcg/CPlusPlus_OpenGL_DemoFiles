#include "drawsquaremove.h"

static GLBatch squareBatch;
static GLShaderManager shaderManager;

static GLfloat blockSize = 0.4f;
static GLfloat vVerts[] = {
	-blockSize, -blockSize, 0.0f,
	 blockSize, -blockSize, 0.0f,
	 blockSize,  blockSize, 0.0f,
	-blockSize,  blockSize, 0.0f,
};

static void ChangeSize(int w, int h)
{
	glViewport(0, 0, w, h);
}

static void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	shaderManager.InitializeStockShaders();

	squareBatch.Begin(GL_TRIANGLE_FAN, 4);
	squareBatch.CopyVertexData3f(vVerts);
	squareBatch.End();
}

static void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	GLfloat vRed[] = {1.0f, 0.0f, 0.0f, 1.0f};
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
	squareBatch.Draw();

	glutSwapBuffers();
}

static void SpecialKeys(int key, int x, int y)
{
	GLfloat stepSize = 0.1f;

	GLfloat blockX = vVerts[0];
	GLfloat blockY = vVerts[7];

	if (GLUT_KEY_UP == key){
		blockY += stepSize;
	} else if (GLUT_KEY_DOWN == key){
		blockY -= stepSize;
	} else if (GLUT_KEY_LEFT == key){
		blockX -= stepSize;
	} else if (GLUT_KEY_RIGHT == key){
		blockX += stepSize;
	}

	if (blockX < -1.0f){
		blockX = -1.0f;
	}
	if (blockX > (1.0f - blockSize * 2)){
		blockX = 1.0f - blockSize * 2;
	}
	if (blockY > 1.0f){
		blockY = 1.0f;
	}
	if (blockY < (-1.0f + blockSize * 2)){
		blockY = -1.0f + blockSize * 2;
	}

	vVerts[0] = blockX;
	vVerts[1] = blockY - blockSize * 2;
	vVerts[3] = blockX + blockSize * 2;
	vVerts[4] = blockY - blockSize * 2;
	vVerts[6] = blockX + blockSize * 2;
	vVerts[7] = blockY;
	vVerts[9] = blockX;
	vVerts[10] = blockY;

	squareBatch.CopyVertexData3f(vVerts);

	glutPostRedisplay();
}

int drawsquaremove_test(int argc, char *argv[])
{
	gltSetWorkingDirectory(argv[0]);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Move Block with Arrow Keys");

	GLenum err = glewInit();
	if (GLEW_OK != err){
		fprintf(stderr, "Error: %s", glewGetErrorString(err));
		return 1;
	}

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutSpecialFunc(SpecialKeys);

	SetupRC();

	glutMainLoop();

	return 0;
}