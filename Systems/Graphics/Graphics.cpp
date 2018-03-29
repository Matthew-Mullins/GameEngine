#include "Graphics.h"

//Initialize Sky Color
const glm::vec3 Graphics::SKY_COLOR = glm::vec3(144.0f, 195.0f, 212.0f) / 255.0f;

Graphics::Graphics() {}
Graphics &Graphics::Instance() {
	static Graphics instance;
	return instance;
}

bool Graphics::Initialize(char* windowTitle) {
	//Initialize GLFW
	if (!glfwInit()) {
		std::cout << "Error initializing GLFW." << std::endl;
		return false;
	}

	//Create Window
	glfwWindowHint(GLFW_SAMPLES, 4);									//4x Anti-aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);						//OpenGL 4.4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);		//Dont want old OpenGL

	//Create Window Context
	window = glfwCreateWindow(1024, 768, "Window Title", NULL, NULL);
	if (window == NULL) {
		std::cout << "Error creating window." << std::endl;
		return false;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);		//Double Buffering

	//Set Callbacks
	glfwSetKeyCallback(window, Keyboard::KeyCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);

	//Center Window
	const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (vidMode->width - windowWidth) / 2;
	int yPos = (vidMode->height - windowHeight) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//Z-Buffer
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Set Sky Color
	glClearColor(SKY_COLOR.r, SKY_COLOR.g, SKY_COLOR.b, 1.0f);

	//Initialize GLEW
	glewExperimental = true;		//Needed for core profile
	if (glewInit() != GLEW_OK) {
		std::cout << "Error initializing GLEW." << std::endl;
		return false;
	}
	return true;
}

void Graphics::Update() {
	//Get Events
	glfwPollEvents();
	//Clear Color and Depth Bits
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Draw Stuff



	//Swap Buffers
	glfwSwapBuffers(window);
}

GLFWwindow* Graphics::GetWindow() const {
	return window;
}