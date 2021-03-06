/*****************************************************************************

    (c) 2013 Hobu, Inc. hobu.inc@gmail.com

    Author: Andrew Bell andrew.bell.ia at gmail.com

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the COPYING file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#ifndef INCLUDED_PSHAPE_MATHPAIR_HPP
#define INCLUDED_PSHAPE_MATHPAIR_HPP

#include "export.hpp"

namespace hexer
{

template <typename T>
struct HEXER_DLL Mathpair
{
public:
    Mathpair() : m_x(0.0), m_y(0.0)
    {}

    Mathpair(T x, T y) : m_x(x), m_y(y)
    {}

    T m_x;
    T m_y;

    void operator -= (const Mathpair& p)
    {
       m_x -= p.m_x;
       m_y -= p.m_y;
    }

    Mathpair& operator += (const Mathpair& p)
    {
        m_x += p.m_x;
        m_y += p.m_y;
        return *this;
    }

    friend Mathpair operator - (Mathpair p1, const Mathpair& p2)
    {
        p1 -= p2;
        return p1;
    }

    friend Mathpair operator + (Mathpair p1, const Mathpair& p2)
    {
        p1 += p2;
        return p1;
    }
};

typedef Mathpair<double> Point;
typedef Mathpair<int> Coord;

} // namespace

#endif // file guard
