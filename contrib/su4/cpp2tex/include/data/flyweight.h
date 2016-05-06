/*
 * This file [data/flyweight.h] is part of the “libtamias” library
 * Copyright (c) 2007-2010 Oleg Davydov, Yury Petrov
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Our contacts:
 *   mailto: burunduk3@gmail.com (Oleg Davydov)
 *   mailto: jpsbur@gmail.com (Yury Petrov)
 */

#pragma once

namespace tamias {
  template <typename Type> class Flyweight; // some data that shouldn't be dublicated by copying object
}

#include "../basic/types.h"

template <typename Type>
  class tamias::Flyweight {
    protected:
      Flyweight();
      Flyweight( Flyweight const &fly );
      Flyweight& operator = ( Flyweight const &fly );
      ~Flyweight();

      Type& data();
      Type const& data() const;
      
    private:
      struct Data {
        sizetype counter;
        Type data;
      } *mData;
  };

#include "flyweight_implementation.h"

