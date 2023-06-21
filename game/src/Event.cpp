#include "Event.h"
namespace Game {

EventKernel::EventKernel() : subcriptions_(), processQueue_()
{
}

void EventKernel::subscribe(const EventType type, EventCallback callback)
{
	subcriptions_[type].push_back(callback);
}

void EventKernel::trigger(const Event& event)
{
	processQueue_.push_back(event);
}

void EventKernel::process()
{
	for (const auto& event : processQueue_)
	{
		auto type = event.getType();
		for (const auto& callback : subcriptions_[type])
		{
			callback(event);
		}
	}
	processQueue_.clear();
}

} // namespace Game
