#include <sstream>

#include "Input.h"
#include "SDL.h"

namespace Game {

Input::Input() {

}

void Input::pollEvents(EventKernel& kernel) {
	auto event = SDL_Event{ 0 };
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			kernel.trigger(ExitEvent());
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDL_SCANCODE_UP ||
				event.key.keysym.sym == SDL_SCANCODE_A)
			{
				kernel.trigger(MoveUpEvent());
			}
			else if (event.key.keysym.sym == SDL_SCANCODE_DOWN ||
				event.key.keysym.sym == SDL_SCANCODE_S)
			{
				kernel.trigger(MoveDownEvent());
			}
			else if (event.key.keysym.sym == SDL_SCANCODE_RIGHT ||
				event.key.keysym.sym == SDL_SCANCODE_D)
			{
				kernel.trigger(MoveRightEvent());
			}
			else if (event.key.keysym.sym == SDL_SCANCODE_LEFT ||
				event.key.keysym.sym == SDL_SCANCODE_A)
			{
				kernel.trigger(MoveLeftEvent());
			}
			else if (event.key.keysym.sym == SDL_SCANCODE_ESCAPE)
			{
				kernel.trigger(ExitEvent());
			}
		}
	}
}

} // namespace Game
