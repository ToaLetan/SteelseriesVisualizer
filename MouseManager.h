#ifndef MOUSE_MANAGER_H
#define MOUSE_MANAGER_H

//The following class will eventually be used to handle mouse LED display, so Main doesn't become an absolute mess.
#include <json.h>

class MouseManager;

class MouseManager
{
	public:
		MouseManager();
		~MouseManager();

		void OutputDataTest(const Json::Value & value);
		void SetMouseValues(int value);
};

#endif