#ifndef BUTTON_HPP
# define BUTTON_HPP

# include "../../Utilities/Utilities.typedef.hpp"
# include "../../Container/Container.hpp"

class Button : public Container
{
	private:
		string	_label;

	public:
		Button(void);
		Button(Button const &);
		Button(cstring const &);
		virtual ~Button(void);

		Button	&operator=(Button const &);

		cstring	&getLabel(void) const;
		void	setLabel(cstring const &);


};

#endif

