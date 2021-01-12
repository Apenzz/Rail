//AUTORE: Leonardo Fasolo

#pragma once

struct eventComparatorCriterial
{
    bool operator() (const Event* left, const Event* right) const;
};