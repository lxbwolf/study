/*
 * AbstractImplement.cpp
 *
 *  Created on: Dec 17, 2016
 *      Author: liuxb
 */

#include "AbstractImplement.h"

#include <iostream>

namespace bridgemode
{

AbstractImplement::AbstractImplement()
{
    std::cout << __FUNCTION__ << std::endl;
}

AbstractImplement::~AbstractImplement()
{
    std::cout << __FUNCTION__ << std::endl;
}

ConcreteAbstractImplementA::ConcreteAbstractImplementA()
{
    std::cout << __FUNCTION__ << std::endl;
}

ConcreteAbstractImplementA::~ConcreteAbstractImplementA()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ConcreteAbstractImplementA::implement()
{
    std::cout << __FUNCTION__ << std::endl;
}

ConcreteAbstractImplementB::ConcreteAbstractImplementB()
{
    std::cout << __FUNCTION__ << std::endl;
}

ConcreteAbstractImplementB::~ConcreteAbstractImplementB()
{
    std::cout << __FUNCTION__ << std::endl;
}

void ConcreteAbstractImplementB::implement()
{
    std::cout << __FUNCTION__ << std::endl;
}
} /* namespace bridgemode */
