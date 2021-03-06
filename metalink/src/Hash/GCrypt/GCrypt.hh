/*
	This file is part of the metalink program
	Copyright (C) 2008  A. Bram Neijt <bneijt@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/





#ifndef _GCrypt_HH_INCLUDED_
#define	_GCrypt_HH_INCLUDED_

#include <gcrypt.h>
#include <string>

#include "../Hash.hh"
namespace bneijt
{
/** \brief Class based libgcrypt interface
Simple wrapper for a few libgcrypt functions.
*/
class GCrypt: public Hash
{
		std::string d_value;
		gcry_md_hd_t d_hash;
		int d_algo;
		
	public:
		GCrypt(int algo)
			:
			d_algo(algo)
		{
			gcry_md_open(&d_hash, d_algo, 0);
		}
		
		~GCrypt()
		{
			gcry_md_close(d_hash);
		}

		virtual std::string name() const;

		unsigned size()
		{
			return gcry_md_get_algo_dlen(d_algo);
		}
		void from(char const *data, unsigned len, unsigned char* key) const;
		virtual void update(char const *bytes, unsigned numbytes);
		virtual void finalize();
		
		virtual std::string const &value() const;
};
}//namespace
#endif

