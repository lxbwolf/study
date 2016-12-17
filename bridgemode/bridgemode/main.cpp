#include <QCoreApplication>

#include <iostream>

#include "AbstractImplement.h"
#include "Abstraction.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bridgemode::AbstractImplement * abs_imp = nullptr;
    bridgemode::Abstraction* abstrction = nullptr;

    abs_imp = new bridgemode::ConcreteAbstractImplementA();
    abstrction = new bridgemode::RedefinedAbstractionA(abs_imp);
    abstrction->operation();

    delete abstrction;
    abstrction = nullptr;

    std::cout << "================================" << std::endl;
    abs_imp = new bridgemode::ConcreteAbstractImplementA();
    abstrction = new bridgemode::RedefinedAbstractionB(abs_imp);
    abstrction->operation();

    delete abs_imp;
    abs_imp = nullptr;

    std::cout << "================================" << std::endl;
    abs_imp = new bridgemode::ConcreteAbstractImplementB();
    abstrction = new bridgemode::RedefinedAbstractionA(abs_imp);
    abstrction->operation();

    delete abs_imp;
    abs_imp = nullptr;

    std::cout << "================================" << std::endl;
    abs_imp = new bridgemode::ConcreteAbstractImplementB();
    abstrction = new bridgemode::RedefinedAbstractionA(abs_imp);
    abstrction->operation();

    delete abs_imp;
    abs_imp = nullptr;

    return a.exec();
}

