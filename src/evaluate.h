/*
  Prisoners' Chess, a UCI chess playing engine derived from Stockfish 10
  Copyright © 2004-2008 Tord Romstad (Glaurung author)
  Copyright © 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright © 2015-2019 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
  Copyright © 2019 Lucio Crusca

  Prisoners' Chess is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Prisoners' Chess is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVALUATE_H_INCLUDED
#define EVALUATE_H_INCLUDED

#include <string>

#include "types.h"

class Position;

namespace Eval {

constexpr Value Tempo = Value(28); // Must be visible to search

std::string trace(const Position& pos);

Value evaluate(const Position& pos);
}

#endif // #ifndef EVALUATE_H_INCLUDED
