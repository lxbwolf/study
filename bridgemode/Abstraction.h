/*
 * Abstraction.h
 *
 *  Created on: Dec 17, 2016
 *      Author: liuxb
 */

#ifndef ABSTRACTION_H_
#define ABSTRACTION_H_

namespace bridgemode
{
class AbstractImplement;

class Abstraction
{
public:
    virtual ~Abstraction();

    virtual void operation() = 0;

protected:
    Abstraction(AbstractImplement* imp);

protected:
    AbstractImplement* m_imp;
};

class RedefinedAbstractionA : public Abstraction
{
public:
    RedefinedAbstractionA(AbstractImplement* imp);
    ~RedefinedAbstractionA();

    virtual void operation();
};

class RedefinedAbstractionB : public Abstraction
{
public:
    RedefinedAbstractionB(AbstractImplement* imp);
    ~RedefinedAbstractionB();

    virtual void operation();
};
} /* namespace bridgemode */

#endif /* ABSTRACTION_H_ */
