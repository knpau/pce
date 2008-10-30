/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:   src/devices/video/hgc.h                                      *
 * Created:     2003-08-19 by Hampa Hug <hampa@hampa.ch>                     *
 * Copyright:   (C) 2003-2008 Hampa Hug <hampa@hampa.ch>                     *
 *****************************************************************************/

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/

/* $Id$ */


#ifndef PCE_HGC_H
#define PCE_HGC_H 1


#include <libini/libini.h>
#include <terminal/terminal.h>
#include <devices/video/video.h>


typedef struct {
	video_t       video;

	mem_blk_t     *memblk;
	unsigned char *mem;

	mem_blk_t     *regblk;
	unsigned char *reg;

	terminal_t    *term;

	unsigned char reg_crt[18];

	unsigned char *font;

	/* these are derived from the crtc registers */
	unsigned      w;
	unsigned      h;
	unsigned      ch;
	unsigned long hsync;
	unsigned long vsync;

	unsigned      buf_w;
	unsigned      buf_h;
	unsigned long bufmax;
	unsigned char *buf;

	unsigned char update_state;
} hgc_t;


hgc_t *hgc_new (unsigned long io, unsigned long mem, unsigned long size);

video_t *hgc_new_ini (ini_sct_t *sct);


#endif
