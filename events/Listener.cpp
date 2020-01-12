#include "Listener.hpp"

Listener::Listener()
{

}

void Listener::listenEvent(Event* e)
{
	_eventsToListenTo.push_back(e);
}

void Listener::unlistenEvent(Event* e)
{
  auto resultIterator =
      std::find(_eventsToListenTo.begin(), _eventsToListenTo.end(), e);
  _eventsToListenTo.erase(resultIterator);
}
