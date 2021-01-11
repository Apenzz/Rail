//AUTORE: Leonardo Fasolo

struct eventComparatorCriterial {
    bool operator() (const event* left, const event* right) const {
        return left->time > right->time;
    }
};