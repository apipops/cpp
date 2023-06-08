#include "Point.hpp"

// cf. https://forums.futura-sciences.com/mathematiques-superieur/521026-caracteriser-point-a-linterieur-dun-triangle-quelconque.html#:~:text=En%20effet%2C%20si%20le%20point,angles%20%C3%A0%20une%20orientation%20oppos%C3%A9e.&text=sont%20de%20m%C3%AAme%20signe%2C%20alors,il%20est%20%C3%A0%20l'ext%C3%A9rieur.
static Fixed	dot_product(Point const p, Point const s1, Point const s2)
{
	return ((s1.getX() - p.getX()) * (s2.getY() - p.getY()) 
	- (s1.getY() - p.getY()) * (s2.getX() - p.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ABdot = dot_product(point, a, b);
	Fixed	BCdot = dot_product(point, b, c);
	Fixed	CAdot = dot_product(point, c, a);

	if (ABdot > 0 && BCdot > 0 && CAdot > 0)
		return true;
	if (ABdot < 0 && BCdot < 0 && CAdot < 0)
		return true;
	return false;

}