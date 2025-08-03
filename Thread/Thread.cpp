#include "includes/Thread.hpp"
#include "../Error/includes/Error.hpp"
#include <threads.h>

Thread::Thread(void) {}
Thread::Thread(fthread func)
{
	if (!this->init(func))
		Error::warning("Bad thread init");
}
Thread::Thread(Thread const &) {}
Thread::~Thread(void) {}

Thread	&Thread::operator=(Thread const &)
{
	return (*this);
}


bool	Thread::init(fthread func)
{
	if (thrd_create(&this->_thread, func, NULL) != thrd_success)
	{
		Error::warning("Thread creation error");
		return (false);
	}
	return (true);
}

bool	Thread::join(void)
{
	thrd_join(this->_thread, NULL);
}