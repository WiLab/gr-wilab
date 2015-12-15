/* -*- c++ -*- */

#define WILAB_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "wilab_swig_doc.i"

%{
#include "wilab/cic_moving_average.h"
%}


%include "wilab/cic_moving_average.h"
GR_SWIG_BLOCK_MAGIC2(wilab, cic_moving_average);
