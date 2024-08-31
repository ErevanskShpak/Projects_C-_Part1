#include "Teacher.h"

istream& operator>>(istream& is, Teacher*& op) {
    op->setName();
    op->setSurname();

    return is;
}