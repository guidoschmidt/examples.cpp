#ifndef H_SIMPLEEVENT
#define H_SIMPLEEVENT

#include "Event.hpp"

class SimpleEvent : public Event
{
	private:
	public:
		void fireEvent(const Listener& listener);
};

#endif // H_SIMPLEEVENT
