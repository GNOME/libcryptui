/* 
 * Seahorse
 * 
 * Copyright (C) 2008 Stefan Walter
 * 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *  
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, see <http://www.gnu.org/licenses/>.  
 */

#ifndef SEAHORSEPGP_H_
#define SEAHORSEPGP_H_

#define SEAHORSE_PGP_STR                     "openpgp"
#define SEAHORSE_PGP                         (g_quark_from_static_string (SEAHORSE_PGP_STR))

void         seahorse_pgp_module_init        (void);

#endif /*SEAHORSEPGP_H_*/
