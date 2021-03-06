/* -*- c++ -*- */
/* 
 * Copyright 2013 Achilleas Anastasopoulos, Zhe Feng.
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

#ifndef INCLUDED_CDMA_VECTOR_INSERT2_IMPL_H
#define INCLUDED_CDMA_VECTOR_INSERT2_IMPL_H

#include <cdma/vector_insert2.h>

namespace gr {
  namespace cdma {

    class vector_insert2_impl : public vector_insert2
    {
     private:
      std::vector< gr_complex > d_data;
      int d_offset;
      int d_periodicity;

     public:
      vector_insert2_impl(const std::vector< gr_complex > data, int periodicity, int offset);
      ~vector_insert2_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace cdma
} // namespace gr

#endif /* INCLUDED_CDMA_VECTOR_INSERT2_IMPL_H */

