/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_WILAB_CIC_MOVING_AVERAGE_H
#define INCLUDED_WILAB_CIC_MOVING_AVERAGE_H

#include <wilab/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace wilab {

    /*!
     * \brief <+description of block+>
     * \ingroup wilab
     *
     */
    class WILAB_API cic_moving_average : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<cic_moving_average> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of wilab::cic_moving_average.
       *
       * To avoid accidental use of raw pointers, wilab::cic_moving_average's
       * constructor is in a private implementation
       * class. wilab::cic_moving_average::make is the public interface for
       * creating new instances.
       */
      static sptr make(int length);
    };

  } // namespace wilab
} // namespace gr

#endif /* INCLUDED_WILAB_CIC_MOVING_AVERAGE_H */

