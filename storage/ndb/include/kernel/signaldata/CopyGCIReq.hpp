/* Copyright (c) 2003, 2005 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA */

#ifndef COPY_GCI_REQ_HPP
#define COPY_GCI_REQ_HPP

#include "SignalData.hpp"

/**
 * This signal is used for transfering the sysfile 
 * between Dih on different nodes.
 *
 * The master will distributes the file to the other nodes
 *
 * Since the Sysfile can be larger than on StartMeConf signal,
 *   there might be more than on of these signals sent before
 *   the entire sysfile is transfered

 */
class CopyGCIReq {
  /**
   * Sender(s) / Reciver(s)
   */
  friend class Dbdih;
  
  friend bool printCOPY_GCI_REQ(FILE *, const Uint32 *, Uint32, Uint16);  
public:
  enum CopyReason {
    IDLE                    = 0,
    LOCAL_CHECKPOINT        = 1,
    RESTART                 = 2,
    GLOBAL_CHECKPOINT       = 3,
    INITIAL_START_COMPLETED = 4
  };
  
private:
  
  Uint32 anyData;
  Uint32 copyReason;
  Uint32 startWord;

  /**
   * No of free words to carry data
   */
  STATIC_CONST( DATA_SIZE = 22 );
  
  Uint32 data[DATA_SIZE];
};

#endif
