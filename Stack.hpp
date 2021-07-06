#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>

class	Stack
{
	private:
	public:
		Stack(void);
		Stack(Stack const &src);
		~Stack(void);
		Stack &operator=(Stack const &rhs);
};

//std::ostream    &operator<<(std::ostream &o, Stack const &rhs);

#endif
