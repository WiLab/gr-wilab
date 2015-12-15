#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2015 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import wilab_swig as wilab

class qa_cic_moving_average (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_crc_moving_average (self):

	src_data = range(1,10)
	#src_data = range(1,20)
	exp_data = (1.0, 3.0, 6.0, 9.0, 12.0, 15.0, 18.0, 21.0, 24.0, 27.0, 30.0, 33.0, 36.0, 39.0, 42.0, 45.0, 48.0, 51.0, 54.0, 57.0)
	src = blocks.vector_source_f(src_data)
	crc = wilab.crc_moving_average(3)
	dst = blocks.vector_sink_f()

	self.tb.connect(src, crc)
        self.tb.connect(crc, dst)

        # set up fg
        self.tb.run ()
        self.tb.run ()
        # check data
	result_data = dst.data()
	print result_data
	#print exp_data

if __name__ == '__main__':
    gr_unittest.run(qa_cic_moving_average, "qa_cic_moving_average.xml")
