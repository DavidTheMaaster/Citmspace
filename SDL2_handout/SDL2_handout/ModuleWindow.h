#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

struct SDL_Window;

// TODO 1: Create the declaration of ModuleWindow class
class ModuleWindow : public Module
{
public:
	bool Init();
	bool CleanUp();

public:
	SDL_Window* win=nullptr;
};

#endif // __ModuleWindow_H__