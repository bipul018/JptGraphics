#include "jptCore.h"
#include <assert.h>

#include <stdio.h>
//Debug callback function
// Provided by VK_EXT_debug_utils
 static VkBool32 debugCallbackUtilsMessenger(
    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
    void* pUserData) {

     printf("Debug Callback Message : %s\n", pCallbackData->pMessage);
     return VK_TRUE;
}

 //Validation layer name
 const char* enabledLayers[] = {
     ""
 };


static int initVulkInstance(JptContext* cxt) {

    assert(cxt != NULL);

    VkApplicationInfo app_info = { 0 };
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName = "Vulkan Application";
    app_info.applicationVersion = VK_MAKE_VERSION(0, 0, 0);
    app_info.pEngineName = "Jpt";
    app_info.engineVersion = VK_MAKE_VERSION(0, 0, 0);
    app_info.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo create_info = { 0 };
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &app_info;
    
    Array extensions = getReuiredExtensions();
    create_info.enabledExtensionCount = getArrSize(const char*, extensions);
    create_info.ppEnabledExtensionNames = extensions.data;
    create_info.enabledLayerCount = 0;
    create_info.ppEnabledLayerNames = NULL;
    
    //todo:: later make it so that this only happens if debug is enabled
    VkDebugUtilsMessengerCreateInfoEXT debug_info = { 0 };
    debug_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    debug_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    debug_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT |
        VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT;
    debug_info.pfnUserCallback = debugCallbackUtilsMessenger;
    
    create_info.pNext = &debug_info;

    //Todo:: Add validation layer + other layers avaibility



    VkResult result = VK_FALSE;
    if ((result = vkCreateInstance(&create_info, NULL, &(cxt->vk_instance))) != VK_SUCCESS)
        return result;


    freeArray(&extensions);
    return VK_SUCCESS;
}

static int initPhysicalDevice(JptContext* cxt) {

}

JptContext initJptVulk(struct JptWindow window){
    JptContext cxt;
    cxt.window = window;

    //Todo:: Check for errors
    initVulkInstance(&cxt);

    return cxt;
}

void freeVulkan(JptContext* pcxt){
    assert(pcxt != NULL);

    vkDestroyInstance(pcxt->vk_instance, NULL);
    pcxt->vk_instance = NULL;
}
