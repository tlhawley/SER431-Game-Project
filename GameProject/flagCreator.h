#define V_NUMPOINTS    4
#define U_NUMPOINTS	   4
#define V_NUMKNOTS    (V_NUMPOINTS + 4)
#define U_NUMKNOTS    (U_NUMPOINTS + 4)

using namespace std;
using namespace Imath;

// Knot sequences for cubic bezier surface and trims 
GLfloat sknots[V_NUMKNOTS] = { 0., 0., 0., 0., 1., 1., 1., 1. };
GLfloat tknots[U_NUMKNOTS] = { 0., 0., 0., 0., 1., 1., 1., 1. };

// Control points for the flag. The Z values are modified to make it wave
GLfloat ctlpoints[V_NUMPOINTS][U_NUMPOINTS][3] = {
	{ { 0., 3., 0. },{ 1., 3., 0. },{ 2., 3., 0 },{ 3., 3., 0. } },
{ { 0., 2., 0. },{ 1., 2., 0. },{ 2., 2., 0 },{ 3., 2., 0. } },
{ { 0., 1., 0. },{ 1., 1., 0. },{ 2., 1., 0 },{ 3., 1., 0. } },
{ { 0., 0., 0. },{ 1., 0., 0. },{ 2., 0., 0 },{ 3., 0., 0. } }
};

GLUnurbsObj *nurbsflag;

// draw_nurb
void draw_nurb() {

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	nurbsflag = gluNewNurbsRenderer();
	gluNurbsProperty(nurbsflag, GLU_SAMPLING_TOLERANCE, 100.0);
	gluNurbsProperty(nurbsflag, GLU_DISPLAY_MODE, GLU_FILL); //GLU_OUTLINE_POLYGON

	GLfloat mat_diffuse[] = { 1.0f, 0.5f, 0.31f, 1. };
	GLfloat mat_specular[] = { 0.5f, 0.5f, 0.5f, 1. };
	GLfloat mat_ambient[] = { 1.0f, 0.5f, 0.31f, 1. };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 32.0);

	static GLfloat angle = 0.0;
	int i, j;
	// wave the flag by rotating Z coords though a sine wave
	for (i = 1; i<4; i++)
		for (j = 0; j<4; j++)
			ctlpoints[i][j][2] = sin((GLfloat)i + angle);
	angle += 0.1;
	glPushMatrix();
	gluBeginSurface(nurbsflag);
	gluNurbsSurface(nurbsflag, V_NUMKNOTS, sknots, U_NUMKNOTS, tknots,
		3 * U_NUMPOINTS, 3,
		&ctlpoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
	gluEndSurface(nurbsflag);


	GLfloat mat_diffuse2[] = { 1.0f, 1.0f, 1.0f, 1. };
	GLfloat mat_specular2[] = { 0.5f, 0.5f, 0.5f, 1. };
	GLfloat mat_ambient2[] = { 0.2f, 0.2f, 0.2f, 1. };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular2);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 32.0);
	glPopMatrix();

}

struct flag {
	bool active;
	float x;
	float y;
	float z;
};

flag newFlag(float x, float y, float z);
void initFlags();
void displayFlags();

#define maxFlags 20
flag flags[maxFlags];
int flagAmount;

flag newFlag(float x, float y, float z) {
	flagAmount++;
	flag theFlag;
	theFlag.active = true;
	theFlag.x = x;
	theFlag.y = y;
	theFlag.z = z;
	return theFlag;
}

void initFlags() {
	flagAmount = 0;
	// Intro to graphics 332 map


	if (currentLevel == 0) {
		flags[flagAmount - 1] = newFlag(-18.5f, 8.0f, 10.0f);
	}

}

void displayFlags() {
	for (int i = 0; i < flagAmount; i++) {
		if (flags[i].active == true) {
			if (abs(camx - flags[i].x) < 120 && abs(camz - flags[i].z) < 120) {
				objPlacementTRS(draw_nurb, flags[i].x, flags[i].y, flags[i].z, 0.0, 0.0, 90.0, 0.5, 0.5, 0.5);
			}
		}
	}
}