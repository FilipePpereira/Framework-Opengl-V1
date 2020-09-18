#include "Game.h"
#include"Shader.h"
#include"InputManager.h"


Game* Game::s_pGame = nullptr;



Game::Game() : m_pWindow(nullptr), m_triangle(nullptr), lastTime(0.0f), currentTime(0.0f), deltaTime(0.0f)
{
}

Game::~Game()
{

	delete m_pWindow;
	m_pWindow = 0;

}

void Game::InitShaders()//m_pShaderCube
{
	m_pShaderTriangle = new ShaderManager();
	m_pShaderTriangle->InitializedShaderManager("assets/vertexShader.glsl", "assets/fragmentShader.glsl");


	m_pShaderCube = new ShaderManager();
	m_pShaderCube->InitializedShaderManager("assets/light_cubeVertex.glsl", "assets/light_cubeFrag.glsl");
}

void Game::CreateGameObjects()//m_CubeObject
{
	m_pPlayerControl = new PlayerControl();
	m_pPlayerControl->Initialized(m_pWindow);

	m_triangle = new GameObjectsManager();
	m_triangle->GetTriangle()->Initialized();

	m_CubeObject = new GameObjectsManager();
	m_CubeObject->GetCubeObject()->Initialized();
}

bool Game::Initialized(std::string title, int width, int height)
{

	m_screenWidth = width;
	m_screenHeight = height;

	if (!glfwInit())
	{
		std::cout << "Failed Init GLFW " << "\n";
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	m_pWindow = glfwCreateWindow(m_screenWidth, m_screenHeight, title.c_str(), NULL, NULL);

	if (!m_pWindow)
	{
		std::cout << "Failed Create Window " << "\n";
		return false;
	}

	glfwMakeContextCurrent(m_pWindow);
	glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);

	glfwSetKeyCallback(m_pWindow, InputManager::InputManagerCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}


	InitShaders();
	CreateGameObjects();


	return true;

}

void Game::Run()
{
	while (!glfwWindowShouldClose(m_pWindow))
	{
		Update();
		
		Draw();
	}

	Shutdown();
}



void Game::Update()
{
	lastTime = (float)glfwGetTime();
	deltaTime = lastTime - currentTime;
	currentTime = lastTime;

	std::cout << "current Time: " << 1 / deltaTime << "\n";
	//m_pShaderTriangle->UpdateShaderManager();
	//m_triangle->GetTriangle()->Draw(*m_pShaderTriangle);

	
	glfwPollEvents();
	m_pPlayerControl->Update(deltaTime);
	m_pShaderCube->UpdateShaderManager();

	// setup view matrix
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);


	trans = glm::translate(trans, glm::vec3(m_pPlayerControl->GetCameraPosition()));
	model = glm::translate(trans, glm::vec3(0.0f, 0.0f, -3.0f));
	model = glm::rotate(model, glm::radians(0.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
	model = glm::scale(model, glm::vec3(1.0f));

	view = m_pPlayerControl->GetCameraView();

	float aspect = (float)m_screenWidth / (float)m_screenHeight;
	projection = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 10000.0f);

	m_pShaderCube->GetShader()->SetMat4("model", model);
	m_pShaderCube->GetShader()->SetMat4("view", view);
	m_pShaderCube->GetShader()->SetMat4("projection", projection);

	m_CubeObject->GetCubeObject()->Draw(*m_pShaderCube);
	

	glfwSwapBuffers(m_pWindow);

	
}

void Game::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	
}

void Game::Shutdown()
{
	m_triangle->GetTriangle()->ShutDown();
	
	m_CubeObject->GetCubeObject()->Shutdown();


	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}

void Game::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
