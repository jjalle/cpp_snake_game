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
			kernel.trigger(ExitEvent());
		}
	}
}

} // namespace Game
