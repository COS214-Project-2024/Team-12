#include <iostream>
#include<string>

#include "Transport.h"

std::unique_ptr<Transport> Transport::clone() const {
    return std::make_unique<Transport>(*this);
}