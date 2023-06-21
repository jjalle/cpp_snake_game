#include <vector>

#include "Event.h"
#include "Config.h"

namespace Game {
	class Input {
	public:
		Input(const Config& config) : Input() { };
		Input();
		void pollEvents(EventKernel& kernel);
	};
}