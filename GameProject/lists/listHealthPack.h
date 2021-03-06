
GLuint listHealthPackList();

GLuint listHealthPack(int num) {
	// Creates a health pack
	GLuint healthPack = glGenLists(num);

	glNewList(healthPack, GL_COMPILE);

	glBegin(GL_TRIANGLES);
	glColor3f(0.625, 0.625, 0.625);
	glVertex3f(0.851468, 0.851468, 1.0);
	glVertex3f(-0.851468, -0.851468, 1.0);
	glVertex3f(0.851468, -0.851468, 1.0);

	glColor3f(0.6875, 0.6875, 0.6875);
	glVertex3f(1.0, 0.851468, -0.851468);
	glVertex3f(1.0, -0.851468, 0.851468);
	glVertex3f(1.0, -0.851468, -0.851468);

	glColor3f(0.8125, 0.8125, 0.8125);
	glVertex3f(-0.851468, 1.0, -0.851468);
	glVertex3f(0.851468, 1.0, 0.851468);
	glVertex3f(0.851468, 1.0, -0.851468);

	glColor3f(0.4375, 0.4375, 0.4375);
	glVertex3f(-1.0, 0.851468, 0.851468);
	glVertex3f(-1.0, -0.851468, -0.851468);
	glVertex3f(-1.0, -0.851468, 0.851468);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.851468, 0.851468, -1.0);
	glVertex3f(0.851468, -0.851468, -1.0);
	glVertex3f(-0.851468, -0.851468, -1.0);

	glColor3f(0.3820625, 0.3820625, 0.3820625);
	glVertex3f(-0.851468, -1.0, 0.851468);
	glVertex3f(-0.851468, -0.851468, 1.0);
	glVertex3f(-1.0, -0.851468, 0.851468);

	glColor3f(0.6707625, 0.6707625, 0.6707625);
	glVertex3f(-0.851468, 0.851468, 1.0);
	glVertex3f(-0.851468, 1.0, 0.851468);
	glVertex3f(-1.0, 0.851468, 0.851468);

	glColor3f(0.3098875, 0.3098875, 0.3098875);
	glVertex3f(-0.851468, -1.0, -0.851468);
	glVertex3f(-1.0, -0.851468, -0.851468);
	glVertex3f(-0.851468, -0.851468, -1.0);

	glColor3f(0.5985875, 0.5985875, 0.5985875);
	glVertex3f(-0.851468, 1.0, -0.851468);
	glVertex3f(-0.851468, 0.851468, -1.0);
	glVertex3f(-1.0, 0.851468, -0.851468);

	glColor3f(0.5264125, 0.5264125, 0.5264125);
	glVertex3f(0.851468, -1.0, 0.851468);
	glVertex3f(1.0, -0.851468, 0.851468);
	glVertex3f(0.851468, -0.851468, 1.0);

	glColor3f(0.81511253, 0.81511253, 0.81511253);
	glVertex3f(0.851468, 1.0, 0.851468);
	glVertex3f(0.851468, 0.851468, 1.0);
	glVertex3f(1.0, 0.851468, 0.851468);

	glColor3f(0.4542375, 0.4542375, 0.4542375);
	glVertex3f(0.851468, -1.0, -0.851468);
	glVertex3f(0.851468, -0.851468, -1.0);
	glVertex3f(1.0, -0.851468, -0.851468);

	glColor3f(0.7429375, 0.7429375, 0.7429375);
	glVertex3f(0.851468, 1.0, -0.851468);
	glVertex3f(1.0, 0.851468, -0.851468);
	glVertex3f(0.851468, 0.851468, -1.0);

	glColor3f(0.2973375, 0.2973375, 0.2973375);
	glVertex3f(-0.851468, -1.0, 0.851468);
	glVertex3f(-1.0, -0.851468, -0.851468);
	glVertex3f(-0.851468, -1.0, -0.851468);

	glColor3f(0.51830626, 0.51830626, 0.51830626);
	glVertex3f(-0.851468, 0.851468, 1.0);
	glVertex3f(-1.0, -0.851468, 0.851468);
	glVertex3f(-0.851468, -0.851468, 1.0);

	glColor3f(0.6508875, 0.6508875, 0.6508875);
	glVertex3f(-0.851468, 1.0, -0.851468);
	glVertex3f(-1.0, 0.851468, 0.851468);
	glVertex3f(-0.851468, 1.0, 0.851468);

	glColor3f(0.42991877, 0.42991877, 0.42991877);
	glVertex3f(-0.851468, -0.851468, -1.0);
	glVertex3f(-1.0, 0.851468, -0.851468);
	glVertex3f(-0.851468, 0.851468, -1.0);

	glColor3f(0.34153125, 0.34153125, 0.34153125);
	glVertex3f(-0.851468, -1.0, -0.851468);
	glVertex3f(0.851468, -0.851468, -1.0);
	glVertex3f(0.851468, -1.0, -0.851468);

	glColor3f(0.69508123, 0.69508123, 0.69508123);
	glVertex3f(0.851468, 1.0, -0.851468);
	glVertex3f(-0.851468, 0.851468, -1.0);
	glVertex3f(-0.851468, 1.0, -0.851468);

	glColor3f(0.60669374, 0.60669374, 0.60669374);
	glVertex3f(1.0, -0.851468, -0.851468);
	glVertex3f(0.851468, 0.851468, -1.0);
	glVertex3f(1.0, 0.851468, -0.851468);

	glColor3f(0.4741125, 0.4741125, 0.4741125);
	glVertex3f(0.851468, -1.0, -0.851468);
	glVertex3f(1.0, -0.851468, 0.851468);
	glVertex3f(0.851468, -1.0, 0.851468);

	glColor3f(0.82766247, 0.82766247, 0.82766247);
	glVertex3f(0.851468, 1.0, 0.851468);
	glVertex3f(1.0, 0.851468, -0.851468);
	glVertex3f(0.851468, 1.0, -0.851468);

	glColor3f(0.69508123, 0.69508123, 0.69508123);
	glVertex3f(0.851468, -0.851468, 1.0);
	glVertex3f(1.0, 0.851468, 0.851468);
	glVertex3f(0.851468, 0.851468, 1.0);

	glColor3f(0.42991877, 0.42991877, 0.42991877);
	glVertex3f(0.851468, -1.0, 0.851468);
	glVertex3f(-0.851468, -0.851468, 1.0);
	glVertex3f(-0.851468, -1.0, 0.851468);

	glColor3f(0.7834687, 0.7834687, 0.7834687);
	glVertex3f(-0.851468, 1.0, 0.851468);
	glVertex3f(0.851468, 0.851468, 1.0);
	glVertex3f(0.851468, 1.0, 0.851468);

	glColor3f(0.3125, 0.3125, 0.3125);
	glVertex3f(0.851468, -1.0, -0.851468);
	glVertex3f(-0.851468, -1.0, 0.851468);
	glVertex3f(-0.851468, -1.0, -0.851468);

	glColor3f(0.625, 0.625, 0.625);
	glVertex3f(0.851468, 0.851468, 1.0);
	glVertex3f(-0.851468, 0.851468, 1.0);
	glVertex3f(-0.851468, -0.851468, 1.0);

	glColor3f(0.6875, 0.6875, 0.6875);
	glVertex3f(1.0, 0.851468, -0.851468);
	glVertex3f(1.0, 0.851468, 0.851468);
	glVertex3f(1.0, -0.851468, 0.851468);

	glColor3f(0.8125, 0.8125, 0.8125);
	glVertex3f(-0.851468, 1.0, -0.851468);
	glVertex3f(-0.851468, 1.0, 0.851468);
	glVertex3f(0.851468, 1.0, 0.851468);

	glColor3f(0.4375, 0.4375, 0.4375);
	glVertex3f(-1.0, 0.851468, 0.851468);
	glVertex3f(-1.0, 0.851468, -0.851468);
	glVertex3f(-1.0, -0.851468, -0.851468);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.851468, 0.851468, -1.0);
	glVertex3f(0.851468, 0.851468, -1.0);
	glVertex3f(0.851468, -0.851468, -1.0);

	glColor3f(0.2973375, 0.2973375, 0.2973375);
	glVertex3f(-0.851468, -1.0, 0.851468);
	glVertex3f(-1.0, -0.851468, 0.851468);
	glVertex3f(-1.0, -0.851468, -0.851468);

	glColor3f(0.51830626, 0.51830626, 0.51830626);
	glVertex3f(-0.851468, 0.851468, 1.0);
	glVertex3f(-1.0, 0.851468, 0.851468);
	glVertex3f(-1.0, -0.851468, 0.851468);

	glColor3f(0.6508875, 0.6508875, 0.6508875);
	glVertex3f(-0.851468, 1.0, -0.851468);
	glVertex3f(-1.0, 0.851468, -0.851468);
	glVertex3f(-1.0, 0.851468, 0.851468);

	glColor3f(0.42991877, 0.42991877, 0.42991877);
	glVertex3f(-0.851468, -0.851468, -1.0);
	glVertex3f(-1.0, -0.851468, -0.851468);
	glVertex3f(-1.0, 0.851468, -0.851468);

	glColor3f(0.34153125, 0.34153125, 0.34153125);
	glVertex3f(-0.851468, -1.0, -0.851468);
	glVertex3f(-0.851468, -0.851468, -1.0);
	glVertex3f(0.851468, -0.851468, -1.0);

	glColor3f(0.69508123, 0.69508123, 0.69508123);
	glVertex3f(0.851468, 1.0, -0.851468);
	glVertex3f(0.851468, 0.851468, -1.0);
	glVertex3f(-0.851468, 0.851468, -1.0);

	glColor3f(0.60669374, 0.60669374, 0.60669374);
	glVertex3f(1.0, -0.851468, -0.851468);
	glVertex3f(0.851468, -0.851468, -1.0);
	glVertex3f(0.851468, 0.851468, -1.0);

	glColor3f(0.4741125, 0.4741125, 0.4741125);
	glVertex3f(0.851468, -1.0, -0.851468);
	glVertex3f(1.0, -0.851468, -0.851468);
	glVertex3f(1.0, -0.851468, 0.851468);

	glColor3f(0.82766247, 0.82766247, 0.82766247);
	glVertex3f(0.851468, 1.0, 0.851468);
	glVertex3f(1.0, 0.851468, 0.851468);
	glVertex3f(1.0, 0.851468, -0.851468);

	glColor3f(0.69508123, 0.69508123, 0.69508123);
	glVertex3f(0.851468, -0.851468, 1.0);
	glVertex3f(1.0, -0.851468, 0.851468);
	glVertex3f(1.0, 0.851468, 0.851468);

	glColor3f(0.42991877, 0.42991877, 0.42991877);
	glVertex3f(0.851468, -1.0, 0.851468);
	glVertex3f(0.851468, -0.851468, 1.0);
	glVertex3f(-0.851468, -0.851468, 1.0);

	glColor3f(0.7834687, 0.7834687, 0.7834687);
	glVertex3f(-0.851468, 1.0, 0.851468);
	glVertex3f(-0.851468, 0.851468, 1.0);
	glVertex3f(0.851468, 0.851468, 1.0);

	glColor3f(0.3125, 0.3125, 0.3125);
	glVertex3f(0.851468, -1.0, -0.851468);
	glVertex3f(0.851468, -1.0, 0.851468);
	glVertex3f(-0.851468, -1.0, 0.851468);


	// red cross
	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(1.1, 0.65, 0.15);
	glVertex3f(-1.1, -0.65, 0.15);
	glVertex3f(1.1, -0.65, 0.15);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-1.1, 0.65, 0.15);
	glVertex3f(-1.1, -0.65, -0.15);
	glVertex3f(-1.1, -0.65, 0.15);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(-1.1, 0.65, -0.15);
	glVertex3f(1.1, -0.65, -0.15);
	glVertex3f(-1.1, -0.65, -0.15);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(1.1, 0.65, -0.15);
	glVertex3f(1.1, -0.65, 0.15);
	glVertex3f(1.1, -0.65, -0.15);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(-1.1, -0.65, -0.15);
	glVertex3f(1.1, -0.65, 0.15);
	glVertex3f(-1.1, -0.65, 0.15);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(-1.1, 0.65, 0.15);
	glVertex3f(1.1, 0.65, -0.15);
	glVertex3f(-1.1, 0.65, -0.15);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(1.1, 0.15, -0.65);
	glVertex3f(-1.1, 0.15, 0.65);
	glVertex3f(1.1, 0.15, 0.65);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-1.1, 0.15, -0.65);
	glVertex3f(-1.1, -0.15, 0.65);
	glVertex3f(-1.1, 0.15, 0.65);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(-1.1, -0.15, -0.65);
	glVertex3f(1.1, -0.15, 0.65);
	glVertex3f(-1.1, -0.15, 0.65);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(1.1, -0.15, -0.65);
	glVertex3f(1.1, 0.15, 0.65);
	glVertex3f(1.1, -0.15, 0.65);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(-1.1, -0.15, 0.65);
	glVertex3f(1.1, 0.15, 0.65);
	glVertex3f(-1.1, 0.15, 0.65);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(-1.1, 0.15, -0.65);
	glVertex3f(1.1, -0.15, -0.65);
	glVertex3f(-1.1, -0.15, -0.65);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-0.15, 0.65, 1.1);
	glVertex3f(-0.15, -0.65, -1.1);
	glVertex3f(-0.15, -0.65, 1.1);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(-0.15, 0.65, -1.1);
	glVertex3f(0.15, -0.65, -1.1);
	glVertex3f(-0.15, -0.65, -1.1);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(0.15, 0.65, -1.1);
	glVertex3f(0.15, -0.65, 1.1);
	glVertex3f(0.15, -0.65, -1.1);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(0.15, 0.65, 1.1);
	glVertex3f(-0.15, -0.65, 1.1);
	glVertex3f(0.15, -0.65, 1.1);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(0.15, -0.65, -1.1);
	glVertex3f(-0.15, -0.65, 1.1);
	glVertex3f(-0.15, -0.65, -1.1);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(-0.15, 0.65, -1.1);
	glVertex3f(0.15, 0.65, 1.1);
	glVertex3f(0.15, 0.65, -1.1);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(0.65, 0.15, 1.1);
	glVertex3f(-0.65, 0.15, -1.1);
	glVertex3f(-0.65, 0.15, 1.1);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(0.65, 0.15, -1.1);
	glVertex3f(-0.65, -0.15, -1.1);
	glVertex3f(-0.65, 0.15, -1.1);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(0.65, -0.15, -1.1);
	glVertex3f(-0.65, -0.15, 1.1);
	glVertex3f(-0.65, -0.15, -1.1);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(0.65, -0.15, 1.1);
	glVertex3f(-0.65, 0.15, 1.1);
	glVertex3f(-0.65, -0.15, 1.1);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-0.65, -0.15, -1.1);
	glVertex3f(-0.65, 0.15, 1.1);
	glVertex3f(-0.65, 0.15, -1.1);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(0.65, 0.15, -1.1);
	glVertex3f(0.65, -0.15, 1.1);
	glVertex3f(0.65, -0.15, -1.1);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(1.1, 0.65, 0.15);
	glVertex3f(-1.1, 0.65, 0.15);
	glVertex3f(-1.1, -0.65, 0.15);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-1.1, 0.65, 0.15);
	glVertex3f(-1.1, 0.65, -0.15);
	glVertex3f(-1.1, -0.65, -0.15);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(-1.1, 0.65, -0.15);
	glVertex3f(1.1, 0.65, -0.15);
	glVertex3f(1.1, -0.65, -0.15);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(1.1, 0.65, -0.15);
	glVertex3f(1.1, 0.65, 0.15);
	glVertex3f(1.1, -0.65, 0.15);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(-1.1, -0.65, -0.15);
	glVertex3f(1.1, -0.65, -0.15);
	glVertex3f(1.1, -0.65, 0.15);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(-1.1, 0.65, 0.15);
	glVertex3f(1.1, 0.65, 0.15);
	glVertex3f(1.1, 0.65, -0.15);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(1.1, 0.15, -0.65);
	glVertex3f(-1.1, 0.15, -0.65);
	glVertex3f(-1.1, 0.15, 0.65);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-1.1, 0.15, -0.65);
	glVertex3f(-1.1, -0.15, -0.65);
	glVertex3f(-1.1, -0.15, 0.65);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(-1.1, -0.15, -0.65);
	glVertex3f(1.1, -0.15, -0.65);
	glVertex3f(1.1, -0.15, 0.65);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(1.1, -0.15, -0.65);
	glVertex3f(1.1, 0.15, -0.65);
	glVertex3f(1.1, 0.15, 0.65);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(-1.1, -0.15, 0.65);
	glVertex3f(1.1, -0.15, 0.65);
	glVertex3f(1.1, 0.15, 0.65);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(-1.1, 0.15, -0.65);
	glVertex3f(1.1, 0.15, -0.65);
	glVertex3f(1.1, -0.15, -0.65);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-0.15, 0.65, 1.1);
	glVertex3f(-0.15, 0.65, -1.1);
	glVertex3f(-0.15, -0.65, -1.1);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(-0.15, 0.65, -1.1);
	glVertex3f(0.15, 0.65, -1.1);
	glVertex3f(0.15, -0.65, -1.1);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(0.15, 0.65, -1.1);
	glVertex3f(0.15, 0.65, 1.1);
	glVertex3f(0.15, -0.65, 1.1);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(0.15, 0.65, 1.1);
	glVertex3f(-0.15, 0.65, 1.1);
	glVertex3f(-0.15, -0.65, 1.1);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(0.15, -0.65, -1.1);
	glVertex3f(0.15, -0.65, 1.1);
	glVertex3f(-0.15, -0.65, 1.1);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(-0.15, 0.65, -1.1);
	glVertex3f(-0.15, 0.65, 1.1);
	glVertex3f(0.15, 0.65, 1.1);

	glColor3f(0.8125, 0.16250001, 0.16250001);
	glVertex3f(0.65, 0.15, 1.1);
	glVertex3f(0.65, 0.15, -1.1);
	glVertex3f(-0.65, 0.15, -1.1);

	glColor3f(0.5, 0.1, 0.1);
	glVertex3f(0.65, 0.15, -1.1);
	glVertex3f(0.65, -0.15, -1.1);
	glVertex3f(-0.65, -0.15, -1.1);

	glColor3f(0.3125, 0.0625, 0.0625);
	glVertex3f(0.65, -0.15, -1.1);
	glVertex3f(0.65, -0.15, 1.1);
	glVertex3f(-0.65, -0.15, 1.1);

	glColor3f(0.625, 0.125, 0.125);
	glVertex3f(0.65, -0.15, 1.1);
	glVertex3f(0.65, 0.15, 1.1);
	glVertex3f(-0.65, 0.15, 1.1);

	glColor3f(0.4375, 0.0875, 0.0875);
	glVertex3f(-0.65, -0.15, -1.1);
	glVertex3f(-0.65, -0.15, 1.1);
	glVertex3f(-0.65, 0.15, 1.1);

	glColor3f(0.6875, 0.1375, 0.1375);
	glVertex3f(0.65, 0.15, -1.1);
	glVertex3f(0.65, 0.15, 1.1);
	glVertex3f(0.65, -0.15, 1.1);

	glEnd();
	glEndList();

	return healthPack;
}