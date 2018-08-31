
/*
* Lecture 23
* http://javiergs.com/teaching/ser332
*
* Note: BMP and OBJ files are needed to run this program
*/



struct Mesh;
GLubyte* load_bmp_file(const char *filename, BITMAPINFO **info);
void texture_from_file(GLuint *textureArray, const char * file);
int StrToInt(const string &str);
vector<string> split_string(const string& str, const string& split_str);
Mesh* loadFile(const char* file);
void calculateNormalPerFace(Mesh* m);
void calculateNormalPerVertex(Mesh* m);
GLuint meshToDisplayList(Mesh* m, int id, GLuint texture);
/*
// Older functions
struct MeshO;
//vector<string> split_stringO(const string& str, const string& split_str);
//MeshO* loadFileO(const char* file);
vector<string> split_stringO(const string& str, const string& split_str);
MeshO* loadFileO(const char* file);
GLuint meshToDisplayListO(MeshO* m2, int id);
*/


// mesh data structure
typedef Vec3<float> Vec3f;
typedef Vec2<float> Vec2f;
struct Mesh {
	// vertex
	vector<Vec3f> dot_vertex;
	vector<Vec3f> dot_normalPerFace;
	vector<Vec3f> dot_normalPerVertex;
	vector<Vec2f> dot_texture;
	// faces
	vector<int> face_index_vertex;
	vector<int> face_index_normalPerFace;
	vector<int> face_index_normalPerVertex;
	vector<int> face_index_texture;
};

/*
//typedef Vec3<float> Vec3f;
//typedef Vec2<float> Vec2f;
struct MeshO {
	// vertex
	vector<Vec3f> dot_vertex;
	vector<Vec3f> dot_normal;
	vector<Vec2f> dot_texture;
	// faces
	vector<int> face_index_vertex;
	vector<int> face_index_normal;
	vector<int> face_index_texture;
};
*/


// Load a DIB or BMP file from disk.
GLubyte* load_bmp_file(const char *filename, BITMAPINFO **info) {
	FILE *fp;
	GLubyte * bits; // bitmap pixel bits
	int bitsize;
	int infosize;
	BITMAPFILEHEADER header;
	if ((fp = fopen(filename, "rb")) == NULL) return NULL;
	// read the file header and any following bitmap information.
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) {
		fclose(fp); // Couldn't read the file header - return NULL.
		return (NULL);
	}
	// Check for BM reversed.
	if (header.bfType != 'MB') {
		// not a bitmap file - return NULL.
		fclose(fp);
		return (NULL);
	}
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL) {
		fclose(fp);
		return (NULL); // couldn't allocate memory for bitmap info
	}
	if (fread(*info, 1, infosize, fp) < infosize) {
		free(*info);
		fclose(fp);
		return (NULL); // Couldn't read the bitmap header.
	}
	// Allocate memory for the bitmap and read
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth*(*info)->bmiHeader.biBitCount + 7) / 8 * abs((*info)->bmiHeader.biHeight);
	if ((bits = (GLubyte *)malloc(bitsize)) == NULL) {
		free(*info);
		fclose(fp);
		return (NULL); // Couldn't allocate memory
	}
	if (fread(bits, 1, bitsize, fp) < bitsize) {
		free(*info);
		free(bits);
		fclose(fp);
		return (NULL); // Couldn't read bitmap
	}
	fclose(fp);
	return (bits); // Everything fine, return the allocated bitmap.
}

// Create texture from a DIB or BMP file
void texture_from_file(GLuint *textureArray, const char * file) {
	BITMAPINFO *bitmapInfo; // Bitmap information
	GLubyte    *bitmapBits; // Bitmap data
	if (!file) {
		cout << "texture file not found!" << endl;
		return;
	}
	// load image
	bitmapBits = load_bmp_file(file, &bitmapInfo);
	// setup texture
	glGenTextures(1, textureArray);
	glBindTexture(GL_TEXTURE_2D, *textureArray);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // must set to 1 for compact data
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bitmapInfo->bmiHeader.biWidth, bitmapInfo->bmiHeader.biHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bitmapBits);
}

/* -------------------------------------------- BEGIN::OBJ-------------------------------------------- */
// str to int
int StrToInt(const string &str) {
	int i;
	if (sscanf_s(str.c_str(), "%i", &i) == 1) return i;
	else return 0;
}

// split string
vector<string> split_string(const string& str, const string& split_str) {
	vector<string> stlv_string;
	string part_string("");
	string::size_type i;
	i = 0;
	while (i < str.size()) {
		if (split_str.find(str[i]) != string::npos) {
			stlv_string.push_back(part_string);
			part_string = "";
			while (split_str.find(str[i]) != string::npos) {
				++i;
			}
		}
		else {
			part_string += str[i];
			++i;
		}
	}
	if (!part_string.empty())
		stlv_string.push_back(part_string);
	return stlv_string;
}

// load file
Mesh* loadFile(const char* file) {
	Mesh *m = new Mesh;
	m->dot_vertex.clear();
	m->face_index_vertex.clear();
	ifstream infile(file);
	if (infile.fail()) {
		cout << "Error opening file " << file;
		return NULL;
	}
	char current_line[1024];
	while (!infile.eof()) {
		infile.getline(current_line, 1024);
		switch (current_line[0]) {
		case'v':
			float x, y, z;
			switch (current_line[1]) {
			case 'n':
				sscanf_s(current_line, "vn %f %f %f", &x, &y, &z);
				m->dot_normalPerFace.push_back(Vec3f(x, y, z));
				m->dot_normalPerVertex.push_back(Vec3f(x, y, z));
				break;
			case 't':
				sscanf_s(current_line, "vt %f %f", &x, &y);
				m->dot_texture.push_back(Vec2f(x, y));
				break;
			default:
				sscanf_s(current_line, "v %f %f %f", &x, &y, &z);
				m->dot_vertex.push_back(Vec3f(x, y, z));
				break;
			}
			break;
		case 'f': {
			vector<string> faces = split_string(current_line, " \t.\r\n");
			int vnt[3][3] = { { -1, -1, -1 },{ -1, -1, -1 },{ -1, -1, -1 } };
			string::size_type begin, end;
			for (int i = 0; i < 2; i++) {
				begin = 0;
				int j = 0;
				do {
					end = faces[i + 1].find_first_of("/", begin);
					if (begin < end) {
						vnt[i][j] = StrToInt(faces[i + 1].substr(begin, end - begin)) - 1;
					}
					else {
						vnt[i][j] = -1;
					}
					begin = end + 1;
					j++;
				} while (end != string::npos);
			}
			for (unsigned int i = 3; i < faces.size(); i++) {
				begin = 0;
				int j = 0;
				do {
					end = faces[i].find_first_of("/", begin);
					if (begin < end) {
						vnt[2][j] = StrToInt(faces[i].substr(begin, end - begin)) - 1;
					}
					else {
						vnt[2][j] = -1;
					}
					begin = end + 1;
					j++;
				} while (end != string::npos);
				for (int j = 0; j < 3; j++) {
					m->face_index_vertex.push_back(vnt[j][0]);
					if (vnt[j][1] != -1) m->face_index_texture.push_back(vnt[j][1]);
					if (vnt[j][2] != -1) m->face_index_normalPerFace.push_back(vnt[j][2]);
					if (vnt[j][2] != -1) m->face_index_normalPerVertex.push_back(vnt[j][2]);
				}
				memcpy(&vnt[1], &vnt[2], sizeof(int) * 3);
			}
		}
				  break;
		default:
			break;
		}
	}

	return m;
}

// normal per face
void calculateNormalPerFace(Mesh* m) {
	Vec3<float> v1, v2, v3, v4, v5;
	for (int i = 0; i < m->face_index_vertex.size(); i += 3) {
		v1 = m->dot_vertex[m->face_index_vertex[i]];
		v2 = m->dot_vertex[m->face_index_vertex[i + 1]];
		v3 = m->dot_vertex[m->face_index_vertex[i + 2]];
		v4 = (v2 - v1);
		v5 = (v3 - v1);
		v4 = v4.cross(v5);
		v4.normalize();
		m->dot_normalPerFace.push_back(v4);
		int pos = m->dot_normalPerFace.size() - 1;
		// same normal for all vertex in this face
		m->face_index_normalPerFace.push_back(pos);
		m->face_index_normalPerFace.push_back(pos);
		m->face_index_normalPerFace.push_back(pos);
	}
}

// calculate normal per vertex
void calculateNormalPerVertex(Mesh* m) {
	m->dot_normalPerVertex.clear();
	m->face_index_normalPerVertex.clear();
	Vec3<float> suma; suma.x = 0; suma.y = 0; suma.z = 0;
	//initialize
	for (unsigned int val = 0; val < m->dot_vertex.size(); val++) {
		m->dot_normalPerVertex.push_back(suma);
	}
	// calculate sum for vertex
	for (long pos = 0; pos < m->face_index_vertex.size(); pos++) {
		m->dot_normalPerVertex[m->face_index_vertex[pos]] +=
			m->dot_normalPerFace[m->face_index_normalPerFace[pos]];
	}
	// normalize for vertex 
	for (unsigned int val = 0; val < m->dot_normalPerVertex.size(); val++) {
		m->dot_normalPerVertex[val] = m->dot_normalPerVertex[val].normalize();
	}
	//normalVertexIndex is the same that vertexIndex
	for (unsigned int pos = 0; pos < m->face_index_vertex.size(); pos++) {
		m->face_index_normalPerVertex.push_back(m->face_index_vertex[pos]);
	}
}


// draw
GLuint meshToDisplayList(Mesh* m, int id, GLuint texture) {
	GLuint listID = glGenLists(id);
	glNewList(listID, GL_COMPILE);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < m->face_index_vertex.size(); i++) {
		// PER VERTEX NORMALS
		if ((!m->dot_normalPerVertex.empty() && !m->face_index_normalPerVertex.empty())) {
			glNormal3fv(&m->dot_normalPerVertex[m->face_index_normalPerVertex[i]].x);
		}
		// TEXTURES
		if (!m->dot_texture.empty() && !m->face_index_texture.empty()) {
			glTexCoord2fv(&m->dot_texture[m->face_index_texture[i]].x);
		}
		// COLOR
		Vec3f offset = (m->dot_vertex[m->face_index_vertex[i]]);
		// VERTEX
		glColor3f(fabs(sin(offset.x)), fabs(cos(offset.y)), fabs(offset.z));
		glVertex3fv(&m->dot_vertex[m->face_index_vertex[i]].x);
	}

	glEnd();

	glDisable(GL_TEXTURE_2D);

	glEndList();
	return listID;
}






































/**
* Lecture 17
* http://javiergs.com/teaching/ser332
*/



// mesh
/*
typedef Vec3<float> Vec3f;
typedef Vec2<float> Vec2f;
struct Mesh {
	// vertex
	vector<Vec3f> dot_vertex;
	vector<Vec3f> dot_normal;
	vector<Vec2f> dot_texture;
	// faces
	vector<int> face_index_vertex;
	vector<int> face_index_normal;
	vector<int> face_index_texture;
};
*/



//int StrToInt(const string &str);
/*
vector<string> split_stringO(const string& str, const string& split_str);
MeshO* loadFileO(const char* file);
GLuint meshToDisplayListO(Mesh* m, int id);
*/



/**
* str to int
*/
/*
int StrToInt(const string &str) {
	int i;
	if (sscanf_s(str.c_str(), "%i", &i) == 1) return i;
	else return 0;
}
*/

/**
* split string
*/
/*
vector<string> split_stringO(const string& str, const string& split_str) {
	vector<string> stlv_string;
	string part_string("");
	string::size_type i;
	i = 0;
	while (i < str.size()) {
		if (split_str.find(str[i]) != string::npos) {
			stlv_string.push_back(part_string);
			part_string = "";
			while (split_str.find(str[i]) != string::npos) {
				++i;
			}
		}
		else {
			part_string += str[i];
			++i;
		}
	}
	if (!part_string.empty())
		stlv_string.push_back(part_string);
	return stlv_string;
}

*/


/**
* load file
*/
/*
MeshO* loadFileO(const char* file) {
	MeshO *m2 = new MeshO;
	m2->dot_vertex.clear();
	m2->face_index_vertex.clear();

	ifstream infile(file);
	if (infile.fail()) {
		cout << "Error opening file " << file;
		char *cwd_buffer = (char*)malloc(sizeof(char) * 100);
		char *cwd_result = _getcwd(cwd_buffer, 100);
		cout << "Current directory is " << cwd_result << endl;
		return NULL;
	}
	char current_line[1024];
	while (!infile.eof()) {
		infile.getline(current_line, 1024);
		switch (current_line[0]) {
		case'v':
			float x, y, z;
			switch (current_line[1]) {
			case 'n':
				sscanf_s(current_line, "vn %f %f %f", &x, &y, &z);
				m2->dot_normal.push_back(Vec3f(x, y, z));
				break;
			case 't':
				sscanf_s(current_line, "vt %f %f", &x, &y);
				m2->dot_texture.push_back(Vec2f(x, y));
				break;
			default:
				sscanf_s(current_line, "v %f %f %f", &x, &y, &z);
				m2->dot_vertex.push_back(Vec3f(x, y, z));
				break;
			}
			break;
		case 'f': {
			vector<string> faces = split_stringO(current_line, " \t.\r\n");
			int vnt[3][3] = { { -1, -1, -1 },{ -1, -1, -1 },{ -1, -1, -1 } };
			string::size_type begin, end;
			for (int i = 0; i < 2; i++) {
				begin = 0;
				int j = 0;
				do {
					end = faces[i + 1].find_first_of("/", begin);
					if (begin < end) {
						vnt[i][j] = StrToInt(faces[i + 1].substr(begin, end - begin)) - 1;
					}
					else {
						vnt[i][j] = -1;
					}
					begin = end + 1;
					j++;
				} while (end != string::npos);
			}
			for (unsigned int i = 3; i < faces.size(); i++) {
				begin = 0;
				int j = 0;
				do {
					end = faces[i].find_first_of("/", begin);
					if (begin < end) {
						vnt[2][j] = StrToInt(faces[i].substr(begin, end - begin)) - 1;
					}
					else {
						vnt[2][j] = -1;
					}
					begin = end + 1;
					j++;
				} while (end != string::npos);
				for (int j = 0; j < 3; j++) {
					m2->face_index_vertex.push_back(vnt[j][0]);
					if (vnt[j][1] != -1) m2->face_index_texture.push_back(vnt[j][1]);
					if (vnt[j][2] != -1) m2->face_index_normal.push_back(vnt[j][2]);
				}
				memcpy(&vnt[1], &vnt[2], sizeof(int) * 3);
			}
		}
				  break;
		default:
			break;
		}
	}
	return m2;
}
*/





/**
* meshToDisplayList
*/
/*
GLuint meshToDisplayListO(MeshO* m2, int id) {
	GLuint listID = glGenLists(id);
	glNewList(listID, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < m2->face_index_vertex.size(); i++) {
		if (!m2->dot_normal.empty() && !m2->face_index_normal.empty())
			glNormal3fv(&m2->dot_normal[m2->face_index_normal[i]].x);
		if (!m2->dot_texture.empty() && !m2->face_index_texture.empty())
			glTexCoord2fv(&m2->dot_texture[m2->face_index_texture[i]].x);
		// color
		Vec3f offset = (m2->dot_vertex[m2->face_index_vertex[i]]);
		glColor3f(fabs(sin(offset.x)), fabs(cos(offset.y)), fabs(offset.z));
		glVertex3fv(&m2->dot_vertex[m2->face_index_vertex[i]].x);
	}
	glEnd();
	glEndList();
	return listID;
}
*/