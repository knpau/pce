/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:     src/ibmpc/pce.h                                            *
 * Created:       2001-05-01 by Hampa Hug <hampa@hampa.ch>                   *
 * Last modified: 2003-08-30 by Hampa Hug <hampa@hampa.ch>                   *
 * Copyright:     (C) 1996-2003 by Hampa Hug <hampa@hampa.ch>                *
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

/* $Id: pce.h,v 1.13 2003/08/30 17:16:18 hampa Exp $ */


#ifndef PCE_H
#define PCE_H 1


#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifndef PCE_HOST_FOSC
#define PCE_HOST_FOSC 100000000UL
#endif

#define PCE_EMU_FOSC 4772393

#define PCE_BRK_STOP  1
#define PCE_BRK_ABORT 2
#define PCE_BRK_SNAP  3


typedef void (*seta_uint8_f) (void *ext, unsigned long addr, unsigned char val);
typedef void (*seta_uint16_f) (void *ext, unsigned long addr, unsigned short val);
typedef unsigned char (*geta_uint8_f) (void *ext, unsigned long addr);
typedef unsigned short (*geta_uint16_f) (void *ext, unsigned long addr);

typedef void (*set_uint8_f) (void *ext, unsigned char val);
typedef void (*set_uint16_f) (void *ext, unsigned short val);
typedef unsigned char (*get_uint8_f) (void *ext);
typedef unsigned short (*get_uint16_f) (void *ext);


extern char     *par_terminal;
extern char     *par_video;
extern unsigned par_boot;
extern char     *par_cpu;


void pce_log_set_fp (FILE *fp, int close);
void pce_log_set_fname (const char *fname);
void pce_log (unsigned level, const char *str, ...);


#include <e8086/e8086.h>
#include <chipset/e8253.h>
#include <chipset/e8255.h>
#include <chipset/e8259.h>

#include <libini/libini.h>

#include <terminal/terminal.h>
#include <terminal/vt100.h>

#ifdef PCE_X11_USE
#include <terminal/xterm.h>
#endif

#include "log.h"
#include "memory.h"
#include "disk.h"
#include "video.h"
#include "mda.h"
#include "hgc.h"
#include "cga.h"
#include "mouse.h"
#include "parport.h"
#include "ibmpc.h"


#endif