#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>

class Event {
	public:
		Event(void);
		Event(const Event&);
		~Event(void);
		Event			&operator=(const Event&);
		std::ostream&	print(std::ostream& os) const;
		bool			operator==(const Event &other) const;
		bool			operator!=(const Event &other) const;

	private:

};

std::ostream& operator << ( std::ostream& os, const Event &event);

#endif