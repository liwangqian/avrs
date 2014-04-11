/*
 * Copyright (C) 2011-2014 Fabián C. Tommasini <fabian@tommasini.com.ar>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 *
 */

#ifndef VIRTUALSOURCE_HPP_
#define VIRTUALSOURCE_HPP_

#include "surface.hpp"
#include "common.hpp"

namespace avrs
{

typedef struct VirtualSource
{
	typedef boost::shared_ptr<VirtualSource> ptr_t;

	unsigned long id;
	point3d_t pos;
	short order;
	float dist_listener;
	float time_abs_ms;
	float time_rel_ms;
	Surface::ptr_t surface_ptr;
	point3d_t intersection_point;
	bool audible;
	point3d_t pos_ref_listener; // to listener
	boost::shared_ptr<VirtualSource> parent_ptr;
	orientation_angles_t orientation_ref_listener; // referenced to listener
	orientation_angles_t orientation_initial; // initial orientation
} virtualsource_t;

}  // namespace avrs

#endif /* VIRTUALSOURCE_HPP_ */