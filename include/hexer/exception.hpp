/*****************************************************************************

    (c) 2013 Hobu, Inc. hobu.inc@gmail.com

    Author: Andrew Bell andrew.bell.ia at gmail.com

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the COPYING file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#ifndef INCLUDED_HEXER_EXCEPTION_HPP
#define INCLUDED_HEXER_EXCEPTION_HPP

#include <stdexcept>

namespace hexer
{
    
class hexer_error : public std::runtime_error
{
public:
    hexer_error(std::string const& msg)
        : std::runtime_error(msg)
    {}
};

}

#endif
