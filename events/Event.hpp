#ifndef H_EVENT
#define H_EVENT

#include "iostream"
#include "vector"

class Listener;

class Event
{
	private:
	protected:
		Event();
		virtual ~Event();
	public:
		virtual void fireEvent(const Listener& listener);
};

#endif // H_EVENT