#include "Point.hpp"

// cf. https://forums.futura-sciences.com/mathematiques-superieur/521026-caracteriser-point-a-linterieur-dun-triangle-quelconque.html#:~:text=En%20effet%2C%20si%20le%20point,angles%20%C3%A0%20une%20orientation%20oppos%C3%A9e.&text=sont%20de%20m%C3%AAme%20signe%2C%20alors,il%20est%20%C3%A0%20l'ext%C3%A9rieur.
// cf. https://www.google.com/search?q=comment+savoir+si+un+point+est+dans+un+triangle&sxsrf=APwXEdfWQ4_zAXC4j30ubk5gIo4r0rruBw%3A1686563158937&ei=VumGZKDhOK-rkdUPs86-2AI&oq=comment&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAxgBMgcIIxCKBRAnMgcIIxCKBRAnMgcIIxCKBRAnMgcIABCKBRBDMgcIABCKBRBDMgcIABCKBRBDMgsIABCABBCxAxCDATIFCAAQgAQyBQgAEIAEMgUIABCABDoKCAAQRxDWBBCwAzoKCAAQigUQsAMQQzoHCCMQ6gIQJzoHCC4Q6gIQJzoPCAAQigUQ6gIQtAIQQxgBOhUIABADEI8BEOoCELQCEIwDEOUCGAI6FQguEAMQjwEQ6gIQtAIQjAMQ5QIYAjoLCC4QigUQsQMQgwE6CAgAEIAEELEDOhEILhCABBCxAxCDARDHARDRAzoLCAAQigUQsQMQgwE6CggAEIAEEBQQhwJKBAhBGABQgwZYuhFglRxoBHABeACAAVqIAb0EkgEBN5gBAKABAbABFMABAcgBA9oBBggBEAEYAdoBBggCEAEYCw&sclient=gws-wiz-serp#fpstate=ive&vld=cid:ff66528f,vid:kkucCUlyIUE
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