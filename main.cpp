#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

// Declare (or define) the callback before main
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
//Input control which takes the window as a input with a key to set up esc for leave
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    // Setting up GLFW with certain settings https://www.glfw.org/docs/latest/window.html#window_hints
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Making the window object with the parameters of height, width, window game, and ignore last 2 parameters
    GLFWwindow* window = glfwCreateWindow(800, 600, "ArushTheGoat", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // Create window

    // Initalize glad (openGL), glad manages the pointer addresses to OpenGl functions to save time
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // Size of window and where the bottom left corner is (0,0)
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Call refresh window functiom


    while(!glfwWindowShouldClose(window))
    {
        /* INPUTS */
        processInput(window); // Input control function (esc to leave)

        /* RENDERING */
        glClearColor(0.9f, 0.0f, 0.9f, 1.0f); // RGBA, the color to be set after buffer resets
        glClear(GL_COLOR_BUFFER_BIT);


        // A screen buffer is a two-dimensional array of character and color data for output in a console window.
        glfwSwapBuffers(window);
        glfwPollEvents();  // Looks for events likee keyboard input and etc..
    }

    glfwTerminate(); // Exit render loop
    return 0;
}