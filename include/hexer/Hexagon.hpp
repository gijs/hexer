/*****************************************************************************

    (c) 2013 Hobu, Inc. hobu.inc@gmail.com

    Author: Andrew Bell andrew.bell.ia at gmail.com

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the COPYING file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#ifndef INCLUDED_PSHAPE_HEXAGON_HPP
#define INCLUDED_PSHAPE_HEXAGON_HPP

#include <boost/cstdint.hpp>

#include "export.hpp"
#include "Mathpair.hpp"

namespace hexer
{

class HEXER_DLL Hexagon
{
public:
    Hexagon(int x, int y) : m_x(x), m_y(y), m_count(0), m_dense(false),
        m_dense_neighbors(0)
        {}

    boost::uint64_t key()
    {
        return key(m_x, m_y);
    }

    void increment()
       { m_count++; }

    static boost::uint64_t key(boost::int32_t x, boost::int32_t y)
    {
        boost::uint32_t ux = (boost::uint32_t)x;
        boost::uint32_t uy = (boost::uint32_t)y;
        return (ux | ((boost::uint64_t)uy << 32));
    }

    int x() const
        { return m_x; }

    int y() const
        { return m_y; }

    bool xodd() const
        { return (x() % 2 != 0); }

    bool xeven() const
        { return !xodd(); }

    void setDense()
        { m_dense = true; }

    bool dense() const
        { return m_dense; }

    int count() const
        { return m_count; } 

    void setCount(int count)
        { m_count = count; }

    void setDenseNeighbor(int dir)
        { m_dense_neighbors |= (1 << dir); }

    // We're surrounded by dense neighbors when the six low bits are set.
    bool surrounded() const
        { return (m_dense && (m_dense_neighbors == 0x3F)); }

    bool possibleRoot() const
    {
        const int TOP = (1 << 0);     // Top is side 0.
        return (m_dense && ((m_dense_neighbors & TOP) == 0) );
    }

    bool less(Hexagon *h) const;
    bool yless(Hexagon *h) const;
    Coord neighborCoord(int dir) const;

private:
    boost::int32_t m_x;
    boost::int32_t m_y;
    int m_count;
    bool m_dense;
    int m_dense_neighbors;
};

} // namespace

#endif // file guard
