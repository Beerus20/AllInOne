#ifndef THREAD_HPP
# define THREAD_HPP

# include <threads.h>

typedef int (*fthread)(void *);

class Thread
{
	private:
		thrd_t		_thread;

	public:
		Thread(void);
		Thread(fthread);
		Thread(Thread const &);
		virtual ~Thread(void);

		Thread		&operator=(Thread const &);
		bool		init(fthread);
		bool		join(void);
};

#endif
