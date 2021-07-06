#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

class	Map
{
	private:
	public:
		Map(void);
		Map(Map const &src);
		~Map(void);
		Map &operator=(Map const &rhs);
};

//std::ostream    &operator<<(std::ostream &o, Map const &rhs);

#endif
