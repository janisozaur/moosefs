/*
 * Copyright (C) 2022 Jakub Kruszona-Zawadzki, Tappest sp. z o.o.
 * 
 * This file is part of MooseFS.
 * 
 * MooseFS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 (only).
 * 
 * MooseFS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with MooseFS; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02111-1301, USA
 * or visit http://www.gnu.org/licenses/gpl-2.0.html
 */

#ifndef _MFSTOOLS_MASTER_H_
#define _MFSTOOLS_MASTER_H_

#include <inttypes.h>
#include <sys/types.h>

int master_prepare_conn(const char *name,uint32_t *inode,mode_t *mode,uint64_t *leng,uint8_t needsamedev,uint8_t needrwfs);
void master_init(void);

uint32_t master_get_version(void);

void master_error(void);
void master_new_packet(void);
void master_put8bit(uint8_t d8);
void master_put16bit(uint16_t d16);
void master_put32bit(uint32_t d32);
void master_put64bit(uint64_t d64);
void master_putname(uint8_t nleng,const char name[256]);
int master_send_and_receive(uint32_t scmd,uint32_t ecmd);
uint32_t master_get_leng(void);
uint8_t master_get8bit(void);
uint16_t master_get16bit(void);
uint32_t master_get32bit(void);
uint64_t master_get64bit(void);
void master_getname(char name[256]);
uint32_t master_bytes_left(void);
uint8_t master_end_packet(void);

#endif
