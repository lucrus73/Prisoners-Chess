## Overview

Prisoners' Chess (PC for short) is a free, powerful UCI chess engine forked from Stockfish. 
It aims to implement the Prisoners' Chess variant  outlined [here](https://www.chess.com/forum/view/chess960-chess-variants/prisoners-chess),
but, as of today, it's a work in progress.
Like Stockfish, it is not a complete chess program and requires a
UCI-compatible GUI (e.g. XBoard with PolyGlot, Scid, Cute Chess, eboard, Arena,
Sigma Chess, Shredder, Chess Partner or Fritz) in order to be used comfortably.
Read the documentation for your GUI of choice for information about how to use
Stockfish with it: the same instructions are valid for PC too.


## Files

This distribution of PC consists of the following files:

  * Readme.md, the file you are currently reading.

  * Copying.txt, a text file containing the GNU General Public License version 3.

  * src, a subdirectory containing the full source code, including a Makefile
    that can be used to compile PC on Unix-like systems.


## UCI parameters

Currently, PC has the following UCI options:

  * #### Debug Log File
    Write all communication to and from the engine into a text file.

  * #### Contempt
    A positive value for contempt favors middle game positions and avoids draws.

  * #### Analysis Contempt
    By default, contempt is set to prefer the side to move. Set this option to "White" 
    or "Black" to analyse with contempt for that side, or "Off" to disable contempt.

  * #### Threads
    The number of CPU threads used for searching a position. For best performance, set 
    this equal to the number of CPU cores available.

  * #### Hash
    The size of the hash table in MB.

  * #### Clear Hash
    Clear the hash table.

  * #### Ponder
    Let PC ponder its next move while the opponent is thinking.

  * #### MultiPV
    Output the N best lines (principal variations, PVs) when searching.
    Leave at 1 for best performance.

  * #### Skill Level
    Lower the Skill Level in order to make PC play weaker.

  * #### Move Overhead
    Assume a time delay of x ms due to network and GUI overheads. This is useful to 
    avoid losses on time in those cases.

  * #### Minimum Thinking Time
    Search for at least x ms per move. 

  * #### Slow Mover
    Lower values will make PC take less time in games, higher values will 
    make it think longer.

  * #### nodestime
    Tells the engine to use nodes searched instead of wall time to account for 
    elapsed time. Useful for engine testing.

  * #### UCI_Chess960
    An option handled by your GUI. If true, PC will play Chess960.

  * #### UCI_AnalyseMode
    An option handled by your GUI.

  * #### SyzygyPath
    Path to the folders/directories storing the Syzygy tablebase files. Multiple 
    directories are to be separated by ";" on Windows and by ":" on Unix-based 
    operating systems. Do not use spaces around the ";" or ":".
    
    Example: `C:\tablebases\wdl345;C:\tablebases\wdl6;D:\tablebases\dtz345;D:\tablebases\dtz6`
    
    It is recommended to store .rtbw files on an SSD. There is no loss in storing 
    the .rtbz files on a regular HD. It is recommended to verify all md5 checksums
    of the downloaded tablebase files (`md5sum -c checksum.md5`) as corruption will
    lead to engine crashes.

  * #### SyzygyProbeDepth
    Minimum remaining search depth for which a position is probed. Set this option
    to a higher value to probe less agressively if you experience too much slowdown
    (in terms of nps) due to TB probing.

  * #### Syzygy50MoveRule
    Disable to let fifty-move rule draws detected by Syzygy tablebase probes count
    as wins or losses. This is useful for ICCF correspondence games.

  * #### SyzygyProbeLimit
    Limit Syzygy tablebase probing to positions with at most this many pieces left
    (including kings and pawns).


## What to expect from Syzygybases?

If the engine is searching a position that is not in the tablebases (e.g.
a position with 8 pieces), it will access the tablebases during the search.
If the engine reports a very large score (typically 153.xx), this means
that it has found a winning line into a tablebase position.

If the engine is given a position to search that is in the tablebases, it
will use the tablebases at the beginning of the search to preselect all
good moves, i.e. all moves that preserve the win or preserve the draw while
taking into account the 50-move rule.
It will then perform a search only on those moves. **The engine will not move
immediately**, unless there is only a single good move. **The engine likely
will not report a mate score even if the position is known to be won.**

It is therefore clear that this behaviour is not identical to what one might
be used to with Nalimov tablebases. There are technical reasons for this
difference, the main technical reason being that Nalimov tablebases use the
DTM metric (distance-to-mate), while Syzygybases use a variation of the
DTZ metric (distance-to-zero, zero meaning any move that resets the 50-move
counter). This special metric is one of the reasons that Syzygybases are
more compact than Nalimov tablebases, while still storing all information
needed for optimal play and in addition being able to take into account
the 50-move rule.


## Compiling PC yourself from the sources

On Unix-like systems, it should be possible to compile PC
directly from the source code with the included Makefile.

PC has support for 32 or 64-bit CPUs, the hardware POPCNT
instruction, big-endian machines such as Power PC, and other platforms.

In general it is recommended to run `make help` to see a list of make
targets with corresponding descriptions. When not using the Makefile to
compile (for instance with Microsoft MSVC) you need to manually
set/unset some switches in the compiler command line; see file *types.h*
for a quick reference.


### Donating hardware

Please don't. If you ever feel like that, please donate it to Stockfish instead, thanks.

### Improving the code

If you want to help improve the code, please do so only if you want to make it better
implement the specific PC variant rules. 

Any other FIDE chess improvement, or Chess960 improvement, or any improvement of anything 
Stockfish does, should be based on Stockfish and not on PC.

* The latest source can always be found on [GitHub](https://github.com/lucrus73/Prisoners-Chess).


## Terms of use

Prisoners' Chess is free, and distributed under the **GNU General Public License version 3**
(GPL v3). Essentially, this means that you are free to do almost exactly
what you want with the program, including distributing it among your
friends, making it available for download from your web site, selling
it (either by itself or as part of some bigger software package), or
using it as the starting point for a software project of your own.

The only real limitation is that whenever you distribute Prisoners' Chess in
some way, you must always include the full source code, or a pointer
to where the source code can be found. If you make any changes to the
source code, these changes must also be made available under the GPL.

For full details, read the copy of the GPL v3 found in the file named
*Copying.txt*.
