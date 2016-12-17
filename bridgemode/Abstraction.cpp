/*
 * Abstraction.cpp
 *
 *  Created on: Dec 17, 2016
 *      Author: liuxb
 */

#include "Abstraction.h"

#include <iostream>

#include "AbstractImplement.h"

namespace bridgemode
{

Abstraction::Abstraction(AbstractImplement* imp)
    : m_imp(imp)
{
    std::cout << __FUNCTION__ << std::endl;
}

Abstraction::~Abstraction()
{
    std::cout << __FUNCTION__ << std::endl;
    if (m_imp)
    {
        delete m_imp;
        m_imp = nullptr;
    }
}

RedefinedAbstractionA::RedefinedAbstractionA(AbstractImplement* imp)
    : Abstraction(imp)
{
    std::cout << __FUNCTION__ << std::endl;
}

RedefinedAbstractionA::~RedefinedAbstractionA()
{
    std::cout << __FUNCTION__ << std::endl;
}

void RedefinedAbstractionA::operation()
{
    std::cout << __FUNCTION__ << std::endl;
    m_imp->implement();
}

RedefinedAbstractionB::RedefinedAbstractionB(AbstractImplement* imp)
    : Abstraction(imp)
{
    std::cout << __FUNCTION__ << std::endl;
}

RedefinedAbstractionB::~RedefinedAbstractionB()
{
    std::cout << __FUNCTION__ << std::endl;
}

void RedefinedAbstractionB::operation()
{
    std::cout << __FUNCTION__ << std::endl;
}
} /* namespace bridgemode */
