#ifndef H_LISTENER
#define H_LISTENER

#include <vector>
#include <iterator>
#include <algorithm>
#include "Event.hpp"

using namespace std;

class Listener
{
	private:
		std::vector<Event*> _eventsToListenTo;
	public:
		Listener();
		~Listener();
		void listenEvent(Event* e);
		void unlistenEvent(Event* e);
		void listen();
};

#endif // H_LISTENER