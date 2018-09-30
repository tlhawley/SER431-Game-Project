
GLuint MeshPlaneO;
GLuint MeshCubeO;
GLuint MeshSphereO;
GLuint MeshCylinderO;
GLuint MeshConeO;
GLuint MeshDomeO;

Mesh* createPlaneO(int arena_width, int arena_depth, int arena_cell);
Mesh* createCubeO(float size);
Mesh* createCylinderO(int rows, int columns, float height, float radius);
Mesh* createSphereO(int rows, int colums, float radius);
Mesh* createConeO(int rows, float height, float radius);
Mesh* createDomeO(int rows, int columns, float radius);
//void project3Init();
//void project3Display();
void quiz6Init();
void quiz6Display();

//float spinningObjects = 0;

void quiz6Init() {

	GLuint texture_array[1];
	texture_from_file(&texture_array[0], "./src/textures/nullTexture.bmp");

	Mesh* Mesh = createPlaneO(64, 64, 4);
	if (Mesh == NULL) exit(1);
	MeshPlaneO = meshToDisplayList(Mesh, 11, texture_array[0]);

	Mesh = createCubeO(2);
	if (Mesh == NULL) exit(1);
	MeshCubeO = meshToDisplayList(Mesh, 12, texture_array[0]);


	Mesh = createCylinderO(32,2,1,1.0f);
	if (Mesh == NULL) exit(1);
	MeshCylinderO = meshToDisplayList(Mesh, 13, texture_array[0]);

	Mesh = createSphereO(32, 32, 1.0f);
	if (Mesh == NULL) exit(1);
	MeshSphereO = meshToDisplayList(Mesh, 14, texture_array[0]);


	Mesh = createConeO(32, 1, 1.0f);
	if (Mesh == NULL) exit(1);
	MeshConeO = meshToDisplayList(Mesh, 15, texture_array[0]);

	Mesh = createDomeO(32, 16, 1.0f);
	if (Mesh == NULL) exit(1);
	MeshDomeO = meshToDisplayList(Mesh, 16, texture_array[0]);

	//createPlane(1,1,20);
}

void quiz6Display() {
	
	//float customMaterial[] = { 0.0f, 0.0f, 0.0f, 1.0f, 0.06f, 0.06f, 0.06f, 1.0f ,2.5f, 2.5f, 2.5f, 1.0f,0.02f, 0.01f, 0.01f, 1.0f , 30.0f };
	//float customMaterial[] = { ar, ag, ab, aa, dr, dg, db, da , sr, sg, sb, sa,er, eg, eb, ea , shine };
	//setMaterialAdvanced2(customMaterial);
	//glCallList(MeshSphere);



	// White Material
	//setmaterial2(0.1f, 0.2f, 0.2f, 0.4f, 0.0001f);
	//glDisable(GL_LIGHTING);

	// Plane Function
	glTranslatef(-2-28, .02, -2-28);
	glCallList(MeshPlaneO);
	glTranslatef(2+28, -0.02, 2+28);

	/*
	glTranslatef(-2, -0.2, -2);
	glCallList(MeshPlaneO);
	glTranslatef(2, 0.2, 2);
	*/

	//setmaterial2(0.1f, 0.4f, 0.4f, 0.4f, 0.0001f);
	setMaterialAdvanced(materialPlasticWhite);



	glTranslatef(0, 5, 0);
	glCallList(MeshCubeO);
	glTranslatef(0, -5, 0);

	/*
	glTranslatef(0, -5, 0);
	glCallList(MeshCubeO);
	glTranslatef(0, 5, 0);
	*/

	
	glTranslatef(0, 7, 0);
	glCallList(MeshCylinderO);
	glTranslatef(0, -7, 0);

	/*
	glTranslatef(0, -7, 0);
	glCallList(MeshCylinderO);
	glTranslatef(0, 7, 0);
	*/


	glTranslatef(0, 9, 0);
	glCallList(MeshSphereO);
	glTranslatef(0, -9, 0);

	/*
	glTranslatef(0, -9, 0);
	glCallList(MeshSphereO);
	glTranslatef(0, 9, 0);
	*/


	glTranslatef(0, 11, 0);
	glCallList(MeshConeO);
	glTranslatef(0, -11, 0);

	/*
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 11, 0);
	glCallList(MeshConeO);
	glTranslatef(0, -11, 0);
	glRotatef(-180, 1, 0, 0);
	*/



	glTranslatef(0, 13, 0);
	glCallList(MeshDomeO);
	glTranslatef(0, -13, 0);

	/*
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 13, 0);
	glCallList(MeshDomeO);
	glTranslatef(0, -13, 0);
	glRotatef(-180, 1, 0, 0);
	*/






	/*
	spinningObjects = spinningObjects + 0.1f;


	for (int i = 0; i < 6; i++) {

		if (i == 0) {
			setMaterialAdvanced(materialGold);
		}
		if (i == 1) {
			setMaterialAdvanced(materialRubberRed);
		}
		if (i == 2) {
			setMaterialAdvanced(materialJade);
		}
		if (i == 3) {
			setMaterialAdvanced(materialChrome);
		}
		if (i == 4) {
			setMaterialAdvanced(materialBronze);
		}
		if (i == 5) {
			setMaterialAdvanced(materialEmerald);
		}

		glRotatef(spinningObjects + i * 60.0f, 0, 1, 0);
		glTranslatef(4, 0, 0);


		glTranslatef(0, 5, 0);
		glCallList(MeshCube);
		glTranslatef(0, -5, 0);
		glTranslatef(0, -5, 0);
		glCallList(MeshCube);
		glTranslatef(0, 5, 0);


		glTranslatef(0, 7, 0);
		glCallList(MeshCylinder);
		glTranslatef(0, -7, 0);
		glTranslatef(0, -7, 0);
		glCallList(MeshCylinder);
		glTranslatef(0, 7, 0);


		glTranslatef(0, 9, 0);
		glCallList(MeshSphere);
		glTranslatef(0, -9, 0);
		glTranslatef(0, -9, 0);
		glCallList(MeshSphere);
		glTranslatef(0, 9, 0);


		glTranslatef(0, 11, 0);
		glCallList(MeshCone);
		glTranslatef(0, -11, 0);
		glRotatef(180, 1, 0, 0);
		glTranslatef(0, 11, 0);
		glCallList(MeshCone);
		glTranslatef(0, -11, 0);
		glRotatef(-180, 1, 0, 0);



		glTranslatef(0, 13, 0);
		glCallList(MeshDome);
		glTranslatef(0, -13, 0);
		glRotatef(180, 1, 0, 0);
		glTranslatef(0, 13, 0);
		glCallList(MeshDome);
		glTranslatef(0, -13, 0);
		glRotatef(-180, 1, 0, 0);

		glTranslatef(-4, 0, 0);
		glRotatef(spinningObjects + i * 60.0f, 0, -1, 0);
	}
	*/



}



Mesh* createPlaneO(int arena_width, int arena_depth, int arena_cell) {
	Mesh *me = new Mesh;
	int n = arena_width / arena_cell;
	int m = arena_depth / arena_cell;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			me->dot_vertex.push_back(Vec3<GLfloat>(i*arena_cell, 00, j*arena_cell));
		}
	}

	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 1, 0));
	

	for (int i = 0; i < (n*m) - m; i++) {
		if ((i + 1) % n == 0) continue;
		me->face_index_vertex.push_back(i);
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_vertex.push_back(i+1);
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_vertex.push_back(i+n);
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_vertex.push_back(i+1);
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_vertex.push_back(i+n+1);
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_vertex.push_back(i+n);
		me->face_index_normalPerVertex.push_back(0);
	}
	return me;
}






Mesh* createCubeO(float size) {
	Mesh *me = new Mesh;

	size = size / 2.0f;

	//v - 1.000000 - 1.000000 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(-size, -size, size));
	//v - 1.000000 1.000000 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(-size, size, size));
	//v - 1.000000 - 1.000000 - 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(-size, -size, -size));
	//v - 1.000000 1.000000 - 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(-size, size, -size));
	//v 1.000000 - 1.000000 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(size, -size, size));
	//v 1.000000 1.000000 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(size, size, size));
	//v 1.000000 - 1.000000 - 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(size, -size, -size));
	//v 1.000000 1.000000 - 1.000000
	me->dot_vertex.push_back(Vec3<GLfloat>(size, size, -size));

	//vn - 1.0000 0.0000 0.0000
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(-1, 0, 0));
	//vn 0.0000 0.0000 - 1.0000
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 0, -1));
	//vn 1.0000 0.0000 0.0000
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(1, 0, 0));
	//vn 0.0000 0.0000 1.0000
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 0, 1));
	//vn 0.0000 - 1.0000 0.0000
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, -1, 0));
	//vn 0.0000 1.0000 0.0000
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 1, 0));
		
	//f 2//1 3//1 1//1
	me->face_index_vertex.push_back(1);
	me->face_index_normalPerVertex.push_back(0);
	me->face_index_vertex.push_back(2);
	me->face_index_normalPerVertex.push_back(0);
	me->face_index_vertex.push_back(0);
	me->face_index_normalPerVertex.push_back(0);

	//f 4//2 7//2 3//2
	me->face_index_vertex.push_back(3);
	me->face_index_normalPerVertex.push_back(1);
	me->face_index_vertex.push_back(6);
	me->face_index_normalPerVertex.push_back(1);
	me->face_index_vertex.push_back(2);
	me->face_index_normalPerVertex.push_back(1);

	//f 8//3 5//3 7//3
	me->face_index_vertex.push_back(7);
	me->face_index_normalPerVertex.push_back(2);
	me->face_index_vertex.push_back(4);
	me->face_index_normalPerVertex.push_back(2);
	me->face_index_vertex.push_back(6);
	me->face_index_normalPerVertex.push_back(2);

	//f 6//4 1//4 5//4
	me->face_index_vertex.push_back(5);
	me->face_index_normalPerVertex.push_back(3);
	me->face_index_vertex.push_back(0);
	me->face_index_normalPerVertex.push_back(3);
	me->face_index_vertex.push_back(4);
	me->face_index_normalPerVertex.push_back(3);

	//f 7//5 1//5 3//5
	me->face_index_vertex.push_back(6);
	me->face_index_normalPerVertex.push_back(4);
	me->face_index_vertex.push_back(0);
	me->face_index_normalPerVertex.push_back(4);
	me->face_index_vertex.push_back(2);
	me->face_index_normalPerVertex.push_back(4);

	//f 4//6 6//6 8//6
	me->face_index_vertex.push_back(3);
	me->face_index_normalPerVertex.push_back(5);
	me->face_index_vertex.push_back(5);
	me->face_index_normalPerVertex.push_back(5);
	me->face_index_vertex.push_back(7);
	me->face_index_normalPerVertex.push_back(5);

	//f 2//1 4//1 3//1
	me->face_index_vertex.push_back(1);
	me->face_index_normalPerVertex.push_back(0);
	me->face_index_vertex.push_back(3);
	me->face_index_normalPerVertex.push_back(0);
	me->face_index_vertex.push_back(2);
	me->face_index_normalPerVertex.push_back(0);

	//f 4//2 8//2 7//2
	me->face_index_vertex.push_back(3);
	me->face_index_normalPerVertex.push_back(1);
	me->face_index_vertex.push_back(7);
	me->face_index_normalPerVertex.push_back(1);
	me->face_index_vertex.push_back(6);
	me->face_index_normalPerVertex.push_back(1);

	//f 8//3 6//3 5//3
	me->face_index_vertex.push_back(7);
	me->face_index_normalPerVertex.push_back(2);
	me->face_index_vertex.push_back(5);
	me->face_index_normalPerVertex.push_back(2);
	me->face_index_vertex.push_back(4);
	me->face_index_normalPerVertex.push_back(2);

	//f 6//4 2//4 1//4
	me->face_index_vertex.push_back(5);
	me->face_index_normalPerVertex.push_back(3);
	me->face_index_vertex.push_back(1);
	me->face_index_normalPerVertex.push_back(3);
	me->face_index_vertex.push_back(0);
	me->face_index_normalPerVertex.push_back(3);

	//f 7//5 5//5 1//5
	me->face_index_vertex.push_back(6);
	me->face_index_normalPerVertex.push_back(4);
	me->face_index_vertex.push_back(4);
	me->face_index_normalPerVertex.push_back(4);
	me->face_index_vertex.push_back(0);
	me->face_index_normalPerVertex.push_back(4);

	//f 4//6 2//6 6//6
	me->face_index_vertex.push_back(3);
	me->face_index_normalPerVertex.push_back(5);
	me->face_index_vertex.push_back(1);
	me->face_index_normalPerVertex.push_back(5);
	me->face_index_vertex.push_back(5);
	me->face_index_normalPerVertex.push_back(5);


	return me;
}



Mesh* createCylinderO(int rows, int columns, float height, float radius) {
	Mesh *me = new Mesh;

	if (rows < 3) {
		rows = 3;
	}
	if (columns < 1) {
		columns = 1;
	}
	float columnCount = height / columns;
	columns = columns + 1;
	
	height = height / 2.0f;
	float rowDegrees = (2.0*3.14159265358979) / rows;
	float rowCount = 0;

	//v 0.000000 1.000000  0.000000 # Top Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, height, 0));
	//v 0.000000 - 1.000000  0.000000 # Bottom Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, -height, 0));

	// Upper Circle Vertices
	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++) {
			me->dot_vertex.push_back(Vec3<GLfloat>(cos(rowCount)*radius, height-j*columnCount, sin(rowCount)*radius));
			rowCount = rowCount + rowDegrees;
		}
	}

	/*
	// Lower Circle Vertices
	rowCount = 0;
	for (int i = 0; i < rows; i++) {
		me->dot_vertex.push_back(Vec3<GLfloat>(cos(rowCount)*radius, -height, sin(rowCount)*radius));
		rowCount = rowCount + rowDegrees;
	}
	*/


	// Top and Bottom Normals
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 1, 0));
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, -1, 0));

	// Side Normals
	rowCount = 0;
	for (int i = 0; i < rows; i++) {
		me->dot_normalPerVertex.push_back(Vec3<GLfloat>(cos(rowCount), 0, sin(rowCount)));
		rowCount = rowCount + rowDegrees;
	}

	// Face Vertices
	int num = 0;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < (columns - 1); j++) {
			me->face_index_vertex.push_back(i + 2 + j*rows);
			num = i + 3;
			if (i == rows - 1) {
				num = 2;
			}
			me->face_index_vertex.push_back(num + j * rows);

			num = i + 3 + rows;
			if (i == rows - 1) {
				num = 2+rows;
			}
			me->face_index_vertex.push_back(num + j * rows);






			num = i + 2;
			//if (i == rows - 1) {
			//	num = 2;
			//}
			me->face_index_vertex.push_back(num + j * rows);

			num = i + 2 + rows;
			me->face_index_vertex.push_back(num + j * rows);

			num = i + 3 + rows;
			if (i == rows - 1) {
				num = rows + 2;
			}
			me->face_index_vertex.push_back(num + j * rows);
		}


		// Top Faces
		me->face_index_vertex.push_back(i + 2);
		num = i + 3;
		if (i == rows - 1) {
			num = 2;
		}
		me->face_index_vertex.push_back(num);
		num = 0;
		me->face_index_vertex.push_back(num);

		// Bottom Faces
		num = i + 2 + rows;
		me->face_index_vertex.push_back(num + (columns - 2)*rows);

		num = i + 3 + rows;
		if (i == rows - 1) {
			num = rows + 2;
		}
		me->face_index_vertex.push_back(num + (columns - 2)*rows);
		me->face_index_vertex.push_back(1);
	}


	
	// Face Normals
	//int num = 0;
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < (columns - 1); j++) {
			me->face_index_normalPerVertex.push_back(i + 2);
			num = i + 3;
			if (i == rows - 1) {
				num = 2;
			}
			me->face_index_normalPerVertex.push_back(num);

			num = i + 3;
			if (i == rows - 1) {
				num = 2;
			}
			me->face_index_normalPerVertex.push_back(num);






			num = i + 2;
			/*
			if (i == rows - 1) {
				num = 2;
			}
			*/
			me->face_index_normalPerVertex.push_back(num);

			num = i + 2;
			me->face_index_normalPerVertex.push_back(num);

			num = i + 3;
			if (i == rows - 1) {
				num = 2;
			}
			me->face_index_normalPerVertex.push_back(num);

		}


		// Top Normals
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_normalPerVertex.push_back(0);
		me->face_index_normalPerVertex.push_back(0);

		// Base Normals
		me->face_index_normalPerVertex.push_back(1);
		me->face_index_normalPerVertex.push_back(1);
		me->face_index_normalPerVertex.push_back(1);



	}
	

	//v - 0.000000 - 1.000000 1.000000
	//v - 0.000000 1.000000 1.000000


	return me;
}

// rows horizontal
// columns vertical
Mesh* createSphereO(int rows, int columns, float radius) {
	Mesh *me = new Mesh;

	if (rows < 3) {
		rows = 3;
	}
	if (columns < 2) {
		columns = 2;
	}

	float rowDegrees = (2.0*3.14159265358979) / rows;
	float rowCount = 0;
	float columnDegrees = (3.14159265358979) / (columns);
	float columnCount = 0;

	//v 0.000000 1.000000  0.000000 # Top Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, radius, 0));
	//v 0.000000 - 1.000000  0.000000 # Bottom Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, -radius, 0));

	// Sphere Vertices
	for (int j = 1; j < columns; j++) {
		for (int i = 0; i < rows; i++) {
			me->dot_vertex.push_back(Vec3<GLfloat>(cos(rowCount)*radius*sin(j*columnDegrees), cos(j*columnDegrees)*radius, sin(rowCount)*radius*sin(j*columnDegrees)));
			rowCount = rowCount + rowDegrees;
		}
	}

	// Top and Bottom Normals
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 1.0f, 0));
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, -1.0f, 0));

	// Sphere Normals
	rowCount = 0;
	for (int j = 1; j < columns; j++) {
		for (int i = 0; i < rows; i++) {
			me->dot_normalPerVertex.push_back(Vec3<GLfloat>(cos(rowCount)*sin(j*columnDegrees), cos(j*columnDegrees), sin(rowCount)*sin(j*columnDegrees)));
			rowCount = rowCount + rowDegrees;
		}
	}

	// Face Vertices
	int num = 0;
	for (int j = 0; j < columns; j++){
	for (int i = 0; i < rows; i++) {
		
		if (j == 0) { // Top Triangles
			me->face_index_vertex.push_back(0);
			me->face_index_normalPerVertex.push_back(0);
			me->face_index_vertex.push_back(2+i);
			me->face_index_normalPerVertex.push_back(2 + i);
			if (i < rows - 1) { 
				me->face_index_vertex.push_back(3 + i);
				me->face_index_normalPerVertex.push_back(3 + i);
			}
			else { 
				me->face_index_vertex.push_back(2);
				me->face_index_normalPerVertex.push_back(2);
			}
		}
		else {
			if (j == columns - 1) { // Base Triangles
				
				me->face_index_vertex.push_back(2 + rows * (j-1) + i);
				me->face_index_normalPerVertex.push_back(2 + rows * (j - 1) + i);
				if (i < rows - 1) {
					me->face_index_vertex.push_back(3 + rows * (j - 1) + i);
					me->face_index_normalPerVertex.push_back(3 + rows * (j - 1) + i);
				}
				else {
					me->face_index_vertex.push_back(2 + rows * (j - 1));
					me->face_index_normalPerVertex.push_back(2 + rows * (j - 1));
				}
				me->face_index_vertex.push_back(1);
				me->face_index_normalPerVertex.push_back(1);
				
			}
			else { // Center Triangles
				
				
				me->face_index_vertex.push_back(2 + rows * (j) + i);
				me->face_index_normalPerVertex.push_back(2 + rows * (j)+i);
				me->face_index_vertex.push_back(2 + rows * (j - 1) + i);
				me->face_index_normalPerVertex.push_back(2 + rows * (j - 1) + i);
				if (i < rows - 1) {
					me->face_index_vertex.push_back(3 + rows * (j - 1) + i);
					me->face_index_normalPerVertex.push_back(3 + rows * (j - 1) + i);
				}
				else {
					me->face_index_vertex.push_back(2 + rows * (j - 1));
					me->face_index_normalPerVertex.push_back(2 + rows * (j - 1));
				}

				if (i < rows - 1) {
					me->face_index_vertex.push_back(3 + rows * (j) + i);
					me->face_index_normalPerVertex.push_back(3 + rows * (j)+i);
				}
				else {
					me->face_index_vertex.push_back(2 + rows * (j));
					me->face_index_normalPerVertex.push_back(2 + rows * (j));
				}
				me->face_index_vertex.push_back(2 + rows * (j) + i);
				me->face_index_normalPerVertex.push_back(2 + rows * (j)+i);
				if (i < rows - 1) {
					me->face_index_vertex.push_back(3 + rows * (j - 1) + i);
					me->face_index_normalPerVertex.push_back(3 + rows * (j - 1) + i);
				}
				else {
					me->face_index_vertex.push_back(2 + rows * (j - 1));
					me->face_index_normalPerVertex.push_back(2 + rows * (j - 1));
				}
				
				
			}
		}


		}
	}

	return me;
}







Mesh* createConeO(int rows, float height, float radius) {
	Mesh *me = new Mesh;

	if (rows < 3) {
		rows = 3;
	}

	height = height / 2.0f;
	float rowDegrees = (2.0*3.14159265358979) / rows;
	float rowCount = 0;

	//v 0.000000 1.000000  0.000000 # Top Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, height, 0));
	//v 0.000000 - 1.000000  0.000000 # Bottom Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, -height, 0));

	// Cone Circle Vertices
	for (int i = 0; i < rows; i++) {
		me->dot_vertex.push_back(Vec3<GLfloat>(cos(rowCount)*radius, -height, sin(rowCount)*radius));
		rowCount = rowCount + rowDegrees;
	}

	// Top and Bottom Normals
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 1, 0));
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, -1, 0));

	// Side Normals
	rowCount = 0;
	for (int i = 0; i < rows; i++) {
		me->dot_normalPerVertex.push_back(Vec3<GLfloat>(cos(rowCount)*radius, height, sin(rowCount)*radius));
		rowCount = rowCount + rowDegrees;
	}

	// Face Vertices
	int num = 0;
	for (int i = 0; i < rows; i++) {

		// Top Faces
		me->face_index_vertex.push_back(i + 2);
		me->face_index_normalPerVertex.push_back(i + 2);
		num = i + 3;
		if (i == rows - 1) {
			num = 2;
		}
		me->face_index_vertex.push_back(num);
		me->face_index_normalPerVertex.push_back(num);
		num = 0;
		me->face_index_vertex.push_back(num);
		me->face_index_normalPerVertex.push_back(i+2);

		// Bottom Faces
		me->face_index_vertex.push_back(i + 2);
		num = i + 3;
		if (i == rows - 1) {
			num = 2;
		}
		me->face_index_vertex.push_back(num);
		me->face_index_vertex.push_back(1);

		me->face_index_normalPerVertex.push_back(1);
		me->face_index_normalPerVertex.push_back(1);
		me->face_index_normalPerVertex.push_back(1);

	}

	return me;
}








// Creates a half sphere
Mesh* createDomeO(int rows, int columns, float radius) {
	Mesh *me = new Mesh;

	if (rows < 3) {
		rows = 3;
	}
	if (columns < 1) {
		columns = 1;
	}

	float rowDegrees = (2.0*3.14159265358979) / rows;
	float rowCount = 0;
	float columnDegrees = (0.5*3.14159265358979) / (columns);
	float columnCount = 0;
	columns = columns + 1;

	//v 0.000000 1.000000  0.000000 # Top Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, radius, 0));
	//v 0.000000 - 1.000000  0.000000 # Bottom Center
	me->dot_vertex.push_back(Vec3<GLfloat>(0, 0, 0));

	// Sphere Vertices
	for (int j = 1; j < columns+1; j++) {
		for (int i = 0; i < rows; i++) {
			me->dot_vertex.push_back(Vec3<GLfloat>(cos(rowCount)*radius*sin(j*columnDegrees), cos(j*columnDegrees)*radius, sin(rowCount)*radius*sin(j*columnDegrees)));
			rowCount = rowCount + rowDegrees;
		}
	}

	// Top and Bottom Normals
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, 1, 0));
	me->dot_normalPerVertex.push_back(Vec3<GLfloat>(0, -1, 0));

	// Sphere Normals
	rowCount = 0;
	for (int j = 1; j < columns; j++) {
		for (int i = 0; i < rows; i++) {
			me->dot_normalPerVertex.push_back(Vec3<GLfloat>(cos(rowCount)*sin(j*columnDegrees), cos(j*columnDegrees), sin(rowCount)*sin(j*columnDegrees)));
			rowCount = rowCount + rowDegrees;
		}
	}

	// Face Vertices
	int num = 0;
	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++) {

			if (j == 0) { // Top Triangles
				me->face_index_vertex.push_back(0);
				me->face_index_normalPerVertex.push_back(0);
				me->face_index_vertex.push_back(2 + i);
				me->face_index_normalPerVertex.push_back(2 + i);
				if (i < rows - 1) {
					me->face_index_vertex.push_back(3 + i);
					me->face_index_normalPerVertex.push_back(3 + i);
				}
				else {
					me->face_index_vertex.push_back(2);
					me->face_index_normalPerVertex.push_back(2);
				}
			}
			else {
				if (j == columns - 1) { // Base Triangles

					me->face_index_vertex.push_back(2 + rows * (j - 1) + i);
					//me->face_index_normalPerVertex.push_back(2 + rows * (j - 1) + i);
					if (i < rows - 1) {
						me->face_index_vertex.push_back(3 + rows * (j - 1) + i);
						//me->face_index_normalPerVertex.push_back(3 + rows * (j - 1) + i);
					}
					else {
						me->face_index_vertex.push_back(2 + rows * (j - 1));
						//me->face_index_normalPerVertex.push_back(2 + rows * (j - 1));
					}
					me->face_index_vertex.push_back(1);
					me->face_index_normalPerVertex.push_back(1);
					me->face_index_normalPerVertex.push_back(1);
					me->face_index_normalPerVertex.push_back(1);

				}
				else { // Center Triangles


					me->face_index_vertex.push_back(2 + rows * (j)+i);
					me->face_index_normalPerVertex.push_back(2 + rows * (j)+i);
					me->face_index_vertex.push_back(2 + rows * (j - 1) + i);
					me->face_index_normalPerVertex.push_back(2 + rows * (j - 1) + i);
					if (i < rows - 1) {
						me->face_index_vertex.push_back(3 + rows * (j - 1) + i);
						me->face_index_normalPerVertex.push_back(3 + rows * (j - 1) + i);
					}
					else {
						me->face_index_vertex.push_back(2 + rows * (j - 1));
						me->face_index_normalPerVertex.push_back(2 + rows * (j - 1));
					}

					if (i < rows - 1) {
						me->face_index_vertex.push_back(3 + rows * (j)+i);
						me->face_index_normalPerVertex.push_back(3 + rows * (j)+i);
					}
					else {
						me->face_index_vertex.push_back(2 + rows * (j));
						me->face_index_normalPerVertex.push_back(2 + rows * (j));
					}
					me->face_index_vertex.push_back(2 + rows * (j)+i);
					me->face_index_normalPerVertex.push_back(2 + rows * (j)+i);
					if (i < rows - 1) {
						me->face_index_vertex.push_back(3 + rows * (j - 1) + i);
						me->face_index_normalPerVertex.push_back(3 + rows * (j - 1) + i);
					}
					else {
						me->face_index_vertex.push_back(2 + rows * (j - 1));
						me->face_index_normalPerVertex.push_back(2 + rows * (j - 1));
					}


				}
			}


		}
	}

	return me;
}