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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "cic_moving_average_impl.h"

namespace gr {
  namespace wilab {

    cic_moving_average::sptr
    cic_moving_average::make(int length)
    {
      return gnuradio::get_initial_sptr
        (new cic_moving_average_impl(length));
    }

    /*
     * The private constructor
     */
    cic_moving_average_impl::cic_moving_average_impl(int length)
      : gr::sync_block("cic_moving_average",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float))),
	d_length(length)
    {
	set_history(length);
    }

    /*
     * Our virtual destructor.
     */
    cic_moving_average_impl::~cic_moving_average_impl()
    {
    }

    int
    cic_moving_average_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const float *in = (const float *) input_items[0];
        float *out = (float *) output_items[0];

        // Perform moving average and remember that
	// first d_length-1 samples are from the past
	int sample = 0;
	out[sample] = d_lastOutput + in[d_length-1] - in[sample];
	for (sample = 1; sample < noutput_items; sample++)
	{
		out[sample] = out[sample-1] + in[d_length-1+sample] - in[sample-1];
	}
	// Save last output
	d_lastOutput = out[noutput_items-1];

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace wilab */
} /* namespace gr */

