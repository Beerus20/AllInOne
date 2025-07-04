#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include "../../Box/includes/Box.hpp"
# include "../../includes/typedefs.hpp"
# include "../../Draw/includes/Draw.hpp"

class Container : public Box
{
	private:
		Boxs	_content;

	public:
		Container(void);
		Container(Container const &);
		virtual ~Container(void);

		Container	&operator=(Container const &);

		

};

#endif
