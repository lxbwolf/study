/*
 * singleton.h
 *
 *  Created on: Apr 8, 2017
 *      Author: liuxb
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

namespace singleton
{
template <typename T>
class Singleton
{
    static T* getInstance()
    {
        if (NULL == m_instance)
        {
            m_instance = new (T)();
        }
        return m_instance;
    }

    static void destroyInstance()
    {
        if (m_instance)
        {
            delete m_instance;
            m_instance = NULL;
        }
    }

protected:
    Singleton() {}
    ~Singleton() {}

private:
    static T* m_instance;
};

template <typename T>
T* Singleton<T>::m_instance = NULL;
}
#endif /* SINGLETON_H_ */
