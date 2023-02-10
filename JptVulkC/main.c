#include <stdio.h>

#include "jptCore.h"

int main() {
	initWindowContext();

	struct JptWindow window = createWindow();


	JptContext context = initJptVulk(window);

	while (!shouldWindowClose(window)) {
		pollWindowEvents(window);
	}

	freeVulkan(&context);
	destroyWindow(&window);
	freeWindowContext();
	return 0;
}