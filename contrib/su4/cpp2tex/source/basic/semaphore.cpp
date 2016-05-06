/*
 * This file [basic/semaphore.cpp] is part of the “libtamias” library
 * Copyright (c) 2007-2009 Oleg Davydov, Yury Petrov
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

#include "../../include/basic/semaphore.h"

using tamias::Semaphore;

Semaphore::Semaphore()
{
  ::sem_init(&semaphore, 0, 1);
}

Semaphore::Semaphore( const Semaphore &second ) : semaphore(second.semaphore)
{
}

Semaphore::~Semaphore()
{
  ::sem_destroy(&semaphore);
}

Semaphore& Semaphore::operator = ( const Semaphore &second )
{
  semaphore = second.semaphore;
  return *this;
}

void Semaphore::lock()
{
  ::sem_wait(&semaphore);
}

void Semaphore::unlock()
{
  ::sem_post(&semaphore);
}

