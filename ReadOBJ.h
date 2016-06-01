#ifndef READ_OBJ_H
#define READ_OBJ_H

#include <stdlib.h>
#include <vector>

typedef struct {
    float x, y, z;
}Point;

typedef struct {
	float x,y;
}Texture;

typedef struct {
	unsigned int v[3];
	unsigned int vt[3];
	unsigned int vn[3];	
}Faces;

class ReadOBJ{

	private:
		std::vector<Point> vertices;
		std::vector<Texture> texture;
		std::vector<Point> normals;
		std::vector<Faces> faces;

		int nVertex, nFaces;
	public:
        ReadOBJ();
        ~ReadOBJ();
        void loadFile(char* filename);
        std::vector<Point> getVertices();
        std::vector<Texture> getTexture();
        std::vector<Point> getNormals();
        std::vector<Faces> getFaces();

        
        
};

#endif