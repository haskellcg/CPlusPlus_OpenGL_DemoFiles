#include "drawline.h"

static void init(void)
{  
    glClearColor(1.0, 1.0, 1.0, 0.0);  //������ɫ(��:[0.0~1.0]R, ��:[0.0~1.0]G����:[0.0~1.0]B, ͸����:[0.0~1.0]A)
										/*ʹ����ͶӰ����������ϵ��λ�������������ӳ�䵽��Ļ�ϣ������x����ֵ��0.0��200.0��y����ֵ��0.0��150.0*/
    glMatrixMode(GL_PROGRAM);  
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);  
}  

static void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//GL_COLOR_BUFFER_BIT��һ��OpenGL���ų���������ָ��������ɫ���棨ˢ�»��棩�е�λֵ���û��潫ʹ��                                      glClearColor������ָ����ֵ���趨��
    glColor3f(1.0f, 0.0f, 0.0f);//�����߶���ɫΪ��ɫ

    /*������һ���������ѿ����˵����꣨180��15����(10, 145)�Ķ�άֱ�߶�*/
    glBegin(GL_LINES);
    glVertex2i(180, 15);
    glVertex2i(10, 145);
    glEnd();

    glFlush(); //ִ�����е�OpenGL����
} 
int drawline_test(int argc, char *argv[])
{
    glutInit(&argc, argv);//��ʼ��GULT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//������ʾģʽ
    glutInitWindowPosition(50, 100);//�������ϽǴ�����ʾλ��
    glutInitWindowSize(400, 300);//���ô�����ʾ�Ŀ����
    glutCreateWindow("An Example OpenGL Program��");//����һ������
	init();//ִ�г�ʼ������
	glutDisplayFunc(lineSegment);//��ͼ����ʾ�ڴ���
    glutMainLoop();//��ʾ���в�����ȴ�״̬

	return 0;
}