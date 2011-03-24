/*
 * ProFTPD - FTP server daemon
 * Copyright (c) 2006-2011 The ProFTPD Project team
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307, USA.
 *
 * As a special exemption, the ProFTPD Project and other respective copyright
 * holders give permission to link this program with OpenSSL, and distribute
 * the resulting executable, without including the source code for OpenSSL in
 * the source distribution.
 */

/* Trace API
 * $Id: trace.h,v 1.5 2011-03-24 21:57:05 castaglia Exp $
 */

#ifndef PR_TRACE_H
#define PR_TRACE_H

#define PR_TRACE_DEFAULT_CHANNEL	"DEFAULT"

pr_table_t *pr_trace_get_table(void);
int pr_trace_get_level(const char *);
int pr_trace_get_max_level(const char *);
int pr_trace_get_min_level(const char *);

/* Parse the given str to get the log level range.  Returns 0 on success,
 * and -1 (setting errno appropriately) if there was a parse error.  The
 * parsed min and max levels will be returned in the level pointers.
 *
 * For example, a string of "17-20" would return a min level of 17, and
 * a max level of 20.  A string of "20" would return a min level of 1 and
 * a max level of 20.
 */
int pr_trace_parse_levels(char *str, int *min_level, int *max_level);

int pr_trace_set_file(const char *);
int pr_trace_set_levels(const char *, int, int);

int pr_trace_set_options(unsigned long trace_opts);
#define PR_TRACE_OPT_DEFAULT			0x0000
#define PR_TRACE_OPT_LOG_CONN_IPS		0x0001
#define PR_TRACE_OPT_USE_TIMESTAMP_MILLIS	0x0002

int pr_trace_msg(const char *, int, const char *, ...)
#ifdef __GNUC__
      __attribute__ ((format (printf, 3, 4)));
#else
      ;
#endif

int pr_trace_vmsg(const char *, int, const char *, va_list);

#endif /* PR_TRACE_H */
