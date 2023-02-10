#include "jptWindows.h"
#include <string.h>
//Currently does not set error callbacks for glfw here, maybe do such stuff
int initWindowContext(){
    return glfwInit();
}


void freeWindowContext(){
    glfwTerminate();
}

struct JptWindow createWindow(){
    struct JptWindow window;
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //Todo:: check for errors here
    window.window = glfwCreateWindow(700, 700, "Jpt Vulkan - GLFW", NULL, NULL);
    window.width = window.height = 700;
    return window;
}

void destroyWindow(struct JptWindow* pWindow){
    if (!pWindow)
        return;
    //Todo:: Check for errors here
    glfwDestroyWindow(pWindow->window);
    pWindow->window = NULL;
}

Array getReuiredExtensions(){
    int count;
    const char ** names = glfwGetRequiredInstanceExtensions(&count);
    Array arr = createArray(const char*, count);
    memcpy(arr.data, names, arr.size_in_bytes);
    return arr;

}

int shouldWindowClose(JptWindow window){
    return glfwWindowShouldClose(window.window);
}

void pollWindowEvents(JptWindow window){
    glfwPollEvents();
}
