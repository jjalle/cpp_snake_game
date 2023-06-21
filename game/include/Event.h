#pragma once

#include <vector>
#include <map>
#include <functional>

namespace Game {
	enum EventType {
		MOVE_UP,
		MOVE_DOWN,
		MOVE_RIGHT,
		MOVE_LEFT,
		EAT,
		DEATH,
		EXIT
	};
	class Event {
	public:
		Event(EventType type): type_(type) {};
		EventType getType() const { return type_; };
	private:
		EventType type_{};
	};
	class MoveUpEvent : public Event {
	public:
		MoveUpEvent() : Event(EventType::MOVE_UP) {};
	};
	class MoveDownEvent : public Event {
	public:
		MoveDownEvent() : Event(EventType::MOVE_DOWN) {};
	};
	class MoveRightEvent : public Event {
	public:
		MoveRightEvent() : Event(EventType::MOVE_RIGHT) {};
	};
	class MoveLeftEvent : public Event {
	public:
		MoveLeftEvent() : Event(EventType::MOVE_LEFT) {};
	};
	class EatEvent : public Event {
	public:
		EatEvent() : Event(EventType::EAT) {};
	};
	class DeathEvent : public Event {
	public:
		DeathEvent() : Event(EventType::DEATH) {};
	};
	class ExitEvent : public Event {
	public:
		ExitEvent() : Event(EventType::EXIT) {};
	};
	typedef std::function<void(const Event&)> EventCallback;
	class EventKernel {
	public:
		EventKernel();
		void subscribe(const EventType type, EventCallback callback);
		void trigger(const Event& event);
		void process();
	private:
		std::unordered_map<EventType, std::vector<EventCallback>> subcriptions_;
		std::vector<Event> processQueue_;
	};
} // namespace Game