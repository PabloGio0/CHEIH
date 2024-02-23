//Práctica 2 semestre 2024-2: índices, mesh, proyecciones, transformaciones geométricas
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<Windows.h>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp> //libreria matematica con funciones para graficos por computadora
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>//cada varibale uniform ssera mandada desde openGl
//clases para dar orden y limpieza al código
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;

//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";
static const char* vShaderColorRojo = "shaders/shaderColorRojo.vert";
static const char* fShaderColorRojo = "shaders/shaderColorRojo.frag";
static const char* vShaderColorVerde = "shaders/shaderColorVerde.vert";
static const char* fShaderColorVerde = "shaders/shaderColorVerde.frag";
static const char* vShaderColorCafe = "shaders/shaderColorCafe.vert";
static const char* fShaderColorCafe = "shaders/shaderColorCafe.frag";
static const char* vShaderColorAzul = "shaders/shaderColorAzul.vert";
static const char* fShaderColorAzul = "shaders/shaderColorAzul.frag";
static const char* vShaderColorVerdeFuerte = "shaders/shaderColorVerdeFuerte.vert";
static const char* fShaderColorVerdeFuerte = "shaders/shaderColorVerdeFuerte.frag";



//shaders nuevos se crearían acá

float angulo = 0.0f;

//color café en RGB : 0.478, 0.255, 0.067

//Pirámide triangular regular
void CreaPiramide()
{
	unsigned int indices[] = { 
		//caras
		0,1,2,
		1,3,2,
		3,0,2,
		1,0,3
		
	};
	GLfloat vertices[] = {
		//vertices
		-0.5f, -0.5f,0.0f,	//0
		0.5f,-0.5f,0.0f,	//1
		0.0f,0.5f, -0.25f,	//2
		0.0f,-0.5f,-0.5f,	//3

	};
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);
}

//Vértices de un cubo
void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

GLfloat cubo_vertices[] = {
	// front
	-0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	// back
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_vertices, cubo_indices,24, 36);
meshList.push_back(cubo);
}

void CrearLetrasyFiguras()
{
	GLfloat vertices_letras[] = {	
			//X			Y			Z			R		G		B
			//Letra P 
			-1.0,   1.0,	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	1.0,	 0, 0.0f,	0.0f,	1.0f,
			-1.0,	0.8,	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	1.0,	 0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.8,	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.8,	 0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.7,	 0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.6,	 0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.7,	 0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.6, 	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.6, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.6, 	0, 0.0f,	0.0f,	1.0f,
			-0.8, 	0.6, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.4, 	0, 0.0f,	0.0f,	1.0f,
			-0.8, 	0.4, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.4, 	0, 0.0f,	0.0f,	1.0f,
			-0.8, 	0.6, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.8, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-0.8, 	0.8, 	0, 0.0f,	0.0f,	1.0f,
			-0.8, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-0.8, 	0.8, 	0, 0.0f,	0.0f,	1.0f,
			-1.0, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-0.7, 	0.8, 	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.8, 	0, 0.0f,	0.0f,	1.0f,
			-0.7, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-0.7, 	0.7, 	0, 0.0f,	0.0f,	1.0f,
			-0.6, 	0.8, 	0, 0.0f,	0.0f,	1.0f,

			//Letra G

			-0.2, 	1.0, 	0, 1.0f,	0.0f,	1.0f,
			0.2, 	1.0, 	0, 1.1f,	0.0f,	1.0f,
			-0.2, 	0.85, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	1.0, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.85,	0, 1.1f,	0.0f,	1.0f,
			-0.2, 	0.85, 	0, 1.1f,	0.0f,	1.0f,
			-0.05, 	0.85, 	0, 1.1f,	0.0f,	1.0f,
			-0.2,	0.85, 	0, 1.1f,	0.0f,	1.0f,
			-0.2, 	0.4, 	0, 1.1f,	0.0f,	1.0f,
			-0.05, 	0.85, 	0, 1.1f,	0.0f,	1.0f,	
			-0.05, 	0.4, 	0, 1.1f,	0.0f,	1.0f,
			-0.2, 	0.4, 	0, 1.1f,	0.0f,	1.0f,
			-0.05, 	0.55, 	0, 1.1f,	0.0f,	1.0f,
			-0.05, 	0.4, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.55, 	0, 1.1f,	0.0f,	1.0f,
			-0.05, 	0.4, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.55, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.4, 	0, 1.1f,	0.0f,	1.0f,
			0,		0.7, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.7, 	0, 1.1f,	0.0f,	1.0f,
			0, 		0.6, 	0, 1.1f,	0.0f,	1.0f,
			0, 		0.6, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.7, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.6, 	0, 1.1f,	0.0f,	1.0f,
			0.1, 	0.6, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.6, 	0, 1.1f,	0.0f,	1.0f,
			0.1, 	0.55, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.55, 	0, 1.1f,	0.0f,	1.0f,		
			0.1, 	0.55, 	0, 1.1f,	0.0f,	1.0f,
			0.2, 	0.6, 	0, 1.1f,	0.0f,	1.0f,

			//Letra C
			0.6, 	1.0, 	0, 1.0f,	1.0f,	0.0f,
			1.0, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			1.0, 	1.0, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	1.0, 	0, 1.0f,	1.0f,	0.0f,
			1.0, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			1.0, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.4, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.4, 	0, 1.0f,	1.0f,	0.0f,
			1.0, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			1.0, 	0.4, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.8, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			0.8, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			0.8, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.8, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			0.8, 	0.8, 	0, 1.0f,	1.0f,	0.0f,
			0.6, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			0.8, 	0.6, 	0, 1.0f,	1.0f,	0.0f,
			
	};

	MeshColor *letras = new MeshColor();
	letras->CreateMeshColor(vertices_letras,504);
	meshColorList.push_back(letras);

	
}


void CreateShaders()
{

	Shader* shader1 = new Shader(); //shader para usar índices: objetos: cubo y  pirámide
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader* shader2 = new Shader();//shader para usar color como parte del VAO: letras 
	shader2->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader2);

	Shader* shader3 = new Shader();//shader para usar color como parte del VAO: letras 
	shader3->CreateFromFiles(vShaderColorRojo, fShaderColorRojo);
	shaderList.push_back(*shader3);

	Shader* shader4 = new Shader();
	shader4->CreateFromFiles(vShaderColorVerde, fShaderColorVerde); 
	shaderList.push_back(*shader4);

	Shader* shader5 = new Shader();
	shader5->CreateFromFiles(vShaderColorCafe, fShaderColorCafe);
	shaderList.push_back(*shader5);

	Shader* shader6 = new Shader();
	shader6->CreateFromFiles(vShaderColorAzul, fShaderColorAzul);
	shaderList.push_back(*shader6);

	Shader* shader7 = new Shader();
	shader7->CreateFromFiles(vShaderColorVerdeFuerte, fShaderColorVerdeFuerte);
	shaderList.push_back(*shader7);
}



int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	CreaPiramide(); //índice 0 en MeshList
	CrearCubo();//índice 1 en MeshList
	CrearLetrasyFiguras(); //usa MeshColor, índices en MeshColorList
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	//Projection: Matriz de Dimensión 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	//glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	
	//Model: Matriz de Dimensión 4x4 en la cual se almacena la multiplicación de las transformaciones geométricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad
	glm::mat4 model2(1.0);
	glm::mat4 model3(1.0);
	glm::mat4 model4(1.0);
	glm::mat4 model5(1.0);

	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(1.0f,1.0f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		
		//Para el cubo y la pirámide se usa el primer set de shaders con índice 0 en ShaderList
		//Triangulo Azul (Techo)
		shaderList[5].useShader();
		uniformModel = shaderList[5].getModelLocation();
		uniformProjection = shaderList[5].getProjectLocation();
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.121f, -0.4f));
		model = glm::scale(model, glm::vec3(0.33f, 0.16f, 0.0f)); 
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		meshList[0]->RenderMesh();

		//Cuadrado rojo
		shaderList[2].useShader(); 
		uniformModel = shaderList[2].getModelLocation();
		uniformProjection = shaderList[2].getProjectLocation();
		model2 = glm::mat4(1.0);
		model2 = glm::translate(model2, glm::vec3(0.0f, -0.16f, -0.95f));
		model2 = glm::scale(model2, glm::vec3(0.4f, 0.48f, 0.5f));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model2));
		meshList[1]->RenderMesh(); 

		//Cuadrados verdes (ventanas)
		shaderList[3].useShader();
		uniformModel = shaderList[3].getModelLocation();
		uniformProjection = shaderList[3].getProjectLocation();
		model3 = glm::mat4(1.0);
		model3 = glm::translate(model3, glm::vec3(0.09f, -0.07f, -0.9f));
		model3 = glm::scale(model3, glm::vec3(0.12f, 0.12f, 0.5f));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model3));
		meshList[1]->RenderMesh();
		
		model3 = glm::mat4(1.0);
		model3 = glm::translate(model3, glm::vec3(-0.09f, -0.07f, -0.9f));
		model3 = glm::scale(model3, glm::vec3(0.12f, 0.12f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model3));
		meshList[1]->RenderMesh();

		//Puerta 
		model3 = glm::mat4(1.0);
		model3 = glm::translate(model3, glm::vec3(0.0f, -0.291f, -0.9f));
		model3 = glm::scale(model3, glm::vec3(0.127f, 0.16f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model3));
		meshList[1]->RenderMesh();

		//Cuadrados Cafe (troncos) 
		shaderList[4].useShader();
		uniformModel = shaderList[4].getModelLocation();
		uniformProjection = shaderList[4].getProjectLocation();
		model4 = glm::mat4(1.0);
		model4 = glm::translate(model4, glm::vec3(-0.45f, -0.42f, -0.9f)); 
		model4 = glm::scale(model4, glm::vec3(0.1f, 0.19f, 0.04f));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model4));
		meshList[1]->RenderMesh();

		model4 = glm::mat4(1.0);
		model4 = glm::translate(model4, glm::vec3(0.45f, -0.42f, -0.9f));
		model4 = glm::scale(model4, glm::vec3(0.1f, 0.19f, 0.04f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model4));
		meshList[1]->RenderMesh();

		//Traingulos Verdes (arboles) 
		shaderList[6].useShader();
		uniformModel = shaderList[6].getModelLocation();
		uniformProjection = shaderList[6].getProjectLocation();
		model5 = glm::mat4(1.0);
		model5 = glm::translate(model5, glm::vec3(-0.2f, -0.08f, -0.4f));
		model5 = glm::scale(model5, glm::vec3(0.12f, 0.15f, 0.04f));
		model5 = glm::rotate(model5, 10 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model5));
		meshList[0]->RenderMesh();

		model5 = glm::mat4(1.0);
		model5 = glm::translate(model5, glm::vec3(0.2f, -0.08f, -0.4f));
		model5 = glm::scale(model5, glm::vec3(0.12f, 0.15f, 0.04f));
		model5 = glm::rotate(model5, 10 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model5));
		meshList[0]->RenderMesh();



		glUseProgram(0);
		mainWindow.swapBuffers();

	}
	return 0;
}
// inicializar matriz: glm::mat4 model(1.0);
// reestablecer matriz: model = glm::mat4(1.0);
//Traslación
//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
//////////////// ROTACIÓN //////////////////
// //model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
////////////////  ESCALA ////////////////
//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
///////////////////// T+R////////////////
/*model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));
*/
/////////////R+T//////////
/*model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
*/