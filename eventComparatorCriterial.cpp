//AUTORE: Leonardo Fasolo

#include "Event.h"
#include "eventComparatorCriterial.h"

bool eventComparatorCriterial::operator()(const Event* left, const Event* right) const
{
	return left->get_time() > right->get_time();
}