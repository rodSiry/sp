/*
 * =====================================================================================
 *
 *       Filename:  Pave.cpp
 *
 *    Description:  Implémentation Pave.h
 *
 *        Version:  1.0
 *        Created:  16/07/2017 22:03:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigue Siry, rodsiry@gmail.com
 *   Organization:  Ecole supérieure d'électricité
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "../include/ship.h"
using namespace glm;
using namespace std;
Ship::Ship():shader(){
	vector<float>vertices;
	vector<float>normals;
	addTetra(&vertices, &normals, mat4(1.0f));
	data=createVAO(&vertices[0], &normals[0],vertices.size());
	shader=createProgram("shaders/pave.vert","shaders/pave.frag");
}
void Ship::Draw(float x, float y, float z, mat4 projection, mat4 model, mat4 view, vec3 dim){
	printTetra(data, shader.pID, 36, projection, model, view, dim);	
}
Ship::~Ship(){
	freeProgram(shader);
	freeVAO(data);
}
