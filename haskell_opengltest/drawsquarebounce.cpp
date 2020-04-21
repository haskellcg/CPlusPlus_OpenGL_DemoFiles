#include "drawsquarebounce.h"

static GLBatch squareBatch;
static GLShaderManager shaderManager;

static GLfloat blockSize = 0.2f;
static GLfloat vVerts[] = {
	-blockSize - 0.5f, -blockSize, 0.0f,
	 blockSize - 0.5f, -blockSize, 0.0f,
	 blockSize - 0.5f,  blockSize, 0.0f,
	-blockSize - 0.5f,  blockSize, 0.0f
};

static void ChangeSize(int w, int h)
{
	glViewport(0, 0, w, h);
}

static void SetupRC(void)
{
	//默认就是黑色
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	shaderManager.InitializeStockShaders();

	squareBatch.Begin(GL_TRIANGLE_FAN, 4);
	squareBatch.CopyVertexData3f(vVerts);
	squareBatch.End();
}

static void BounceFunction(void)
{
	//设置不同的值，移动轨迹会慢慢改变
	static GLfloat xDir = 0.25f;
	static GLfloat yDir = 0.28f;

	GLfloat stepSize = 0.04f;
	
	GLfloat blockX = vVerts[0];
	GLfloat blockY = vVerts[7];

	blockX += stepSize * xDir;
	blockY += stepSize * yDir;

	if (blockX < -1.0f){
		blockX = -1.0f;
		xDir *= -1.0f;
	}
	if (blockX > (1.0f - blockSize * 2)){
		blockX = 1.0f - blockSize * 2;
		xDir *= -1.0f;
	}
	if (blockY > 1.0f){
		blockY = 1.0f;
		yDir *= -1.0f;
	}
	if (blockY < (-1.0f + blockSize * 2)){
		blockY = -1.0f + blockSize * 2;
		yDir *= -1.0f;
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
}

static void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	GLfloat vGreen[] = {1.0f, 1.0f, 0.0f, 1.0f};
	shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vGreen);
	squareBatch.Draw();

	glutSwapBuffers();

	BounceFunction();
	glutPostRedisplay();
}



int drawsquarebounce_test(int argc, char *argv[])
{
	gltSetWorkingDirectory(argv[0]);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bouncing Block");

	GLenum err = glewInit();
	if (GLEW_OK != err){
		fprintf(stderr, "Error: %s", glewGetErrorString(err));
		return 1;
	}

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);

	SetupRC();

	glutMainLoop();

	return 0;
}