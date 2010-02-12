/*
    Copyright (c) 2007-2010 iMatix Corporation

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the Lesser GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Lesser GNU General Public License for more details.

    You should have received a copy of the Lesser GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_OPTIONS_HPP_INCLUDED__
#define __ZMQ_OPTIONS_HPP_INCLUDED__

#include <string>

#include "stddef.h"
#include "stdint.hpp"

namespace zmq
{

    struct options_t
    {
        options_t ();

        int setsockopt (int option_, const void *optval_, size_t optvallen_);

        int64_t hwm;
        int64_t lwm;
        int64_t swap;
        uint64_t affinity;
        std::string identity;

        //  Maximum tranfer rate [kb/s]. Default 100kb/s.
        uint32_t rate;

        //  Reliability time interval [s]. Default 10s.
        uint32_t recovery_ivl;

        //  Enable multicast loopback. Default disabled (false).
        bool use_multicast_loop;

        uint64_t sndbuf;
        uint64_t rcvbuf;

        //  These options are never set by the user directly. Instead they are
        //  provided by the specific socket type.
        bool requires_in;
        bool requires_out;

        //  If true, socket requires tracerouting the messages.
        bool traceroute;
    };

}

#endif
