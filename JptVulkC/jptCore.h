#pragma once
#include "jptWindows.h"

struct JptContext {
	struct JptWindow window;
	VkInstance vk_instance;
	VkPhysicalDevice vk_phy_device;
	VkDevice vk_device;
};
typedef struct JptContext JptContext;


JptContext initJptVulk(struct JptWindow window);

void freeVulkan(struct JptContext* pcontext);