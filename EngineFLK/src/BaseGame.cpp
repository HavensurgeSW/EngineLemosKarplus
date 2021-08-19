#include "BaseGame.h"

BaseGame::BaseGame(){
   
}

void BaseGame::launchGod() {
  
        /* Initialize the library */
        if (!glfwInit())
           std::cout<<"Error de inicializacion"<<std::endl;

        _window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
       
        if (!_window) {
            glfwTerminate();
            std::cout << "Terminate() successful" << std::endl;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(_window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(_window)){
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(_window);
            glfwPollEvents();
        
        }

        glfwTerminate();    
}