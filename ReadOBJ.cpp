#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include "ReadOBJ.h"

using namespace std;

ReadOBJ::ReadOBJ(){
	nVertex=0;
	nFaces=0;
}

void ReadOBJ::loadFile(char* filename){
	FILE* file = fopen(filename,"r");

	if(!file){
		printf("ERRO AO ABRIR AQUIVO %s\n",filename );
		exit(0);
	}

	while( 1 ){

		char lineHeader[128];
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break;

		if ( strcmp( lineHeader, "v" ) == 0 ){
			Point aux;
			fscanf(file, "%f %f %f\n", &aux.x, &aux.y, &aux.z );
			vertices.push_back(aux);

			printf("Vertice = %f %f %f\n", aux.x, aux.y,aux.z );
		}else if ( strcmp( lineHeader, "vt" ) == 0 ){
			Texture aux;
			fscanf(file, "%f %f\n", &aux.x, &aux.y );
			texture.push_back(aux);

			printf("Texture = %f %f\n", aux.x, aux.y );

		}else if ( strcmp( lineHeader, "vn" ) == 0 ){
		 	Point aux;
			fscanf(file, "%f %f %f\n", &aux.x, &aux.y, &aux.z );
			normals.push_back(aux);

			printf("Normals = %f %f %f\n", aux.x, aux.y,aux.z );
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
		 	Faces aux;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &aux.v[0], &aux.vt[0], &aux.vn[0],
																	   &aux.v[1], &aux.vt[1], &aux.vn[1],
																	   &aux.v[2], &aux.vt[2], &aux.vn[2]);
			if (matches != 9){
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				//return false;
			}

			printf("%d/%d/%d %d/%d/%d %d/%d/%d\n",aux.v[0], aux.vt[0], aux.vn[0],
												  aux.v[1], aux.vt[1], aux.vn[1],
												  aux.v[2], aux.vt[2], aux.vn[2]);

			faces.push_back(aux);
		}else{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
	}

	printf("FIM DO ARQUIVO!!!!\n");

	fclose(file);
}

std::vector<Point> ReadOBJ::getVertices(){
	return vertices;
}

std::vector<Texture> ReadOBJ::getTexture(){
	return texture;
}

std::vector<Point> ReadOBJ::getNormals(){
	return normals;
}

std::vector<Faces> ReadOBJ::getFaces(){
	return faces;
}