#include "includes/GLFW/glfw3.h"
#include <iostream>

float COLORS[3] = {0.0f, 0.0f, 1.0f};

bool CanChange = true;

void ChangeColors(GLFWwindow* WINM) {
    if (glfwGetKey(WINM, GLFW_KEY_W) && CanChange == true) {
	std::cout << "COLOR CHANGE REQUEST" << std::endl;
        COLORS[0] = 1.0f;
        COLORS[1] = 0.0f;
        COLORS[2] = 0.0f;
        glClearColor(COLORS[0],COLORS[1],COLORS[2],1.0f);
	CanChange = false;
    } else {
	COLORS[0] = 0.0f;
	COLORS[1] = 0.0f;
	COLORS[2] = 1.0f;
	glClearColor(COLORS[0],COLORS[1],COLORS[2],1.0f);
}
}

int main(void) {
    glfwInit();
    std::cout << "INIT" << std::endl;
    GLFWwindow* Win = glfwCreateWindow(800, 600, "Hello OPENGL", NULL, NULL);
    if(Win == NULL) {
        std::cout << "HELLO WORLD ERROR";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(Win);
    glViewport(0, 0, 800, 600);
    while(!glfwWindowShouldClose(Win)) {
        ChangeColors(Win);
        glClearColor(COLORS[0],COLORS[1],COLORS[2],1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(Win);
	CanChange = true;
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}