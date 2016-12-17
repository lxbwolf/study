/*
 * AbstractImplement.h
 *
 *  Created on: Dec 17, 2016
 *      Author: liuxb
 */

#ifndef ABSTRACTIMPLEMENT_H_
#define ABSTRACTIMPLEMENT_H_

namespace bridgemode
{
class AbstractImplement
{
public:
    virtual ~AbstractImplement();

    virtual void implement() = 0;

protected:
    AbstractImplement();
};

class ConcreteAbstractImplementA : public AbstractImplement
{
public:
    ConcreteAbstractImplementA();
    ~ConcreteAbstractImplementA();

    virtual void implement();
};

class ConcreteAbstractImplementB : public AbstractImplement
{
public:
    ConcreteAbstractImplementB();
    ~ConcreteAbstractImplementB();

    virtual void implement();
};

} /* namespace bridgemode */

#endif /* ABSTRACTIMPLEMENT_H_ */
