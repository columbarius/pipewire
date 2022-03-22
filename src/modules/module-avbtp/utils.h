/* AVB support
 *
 * Copyright © 2022 Wim Taymans
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef AVBTP_UTILS_H
#define AVBTP_UTILS_H

#include <spa/utils/json.h>

#include "internal.h"

static inline char *avbtp_utils_format_id(char *str, size_t size, const uint64_t id)
{
	snprintf(str, size, "%02x:%02x:%02x:%02x:%02x:%02x:%04x",
			(uint8_t)(id >> 56),
			(uint8_t)(id >> 48),
			(uint8_t)(id >> 40),
			(uint8_t)(id >> 32),
			(uint8_t)(id >> 24),
			(uint8_t)(id >> 16),
			(uint16_t)(id));
	return str;
}

static inline int avbtp_utils_parse_id(const char *str, int len, uint64_t *id)
{
	char s[64];
	uint8_t v[6];
	uint16_t unique_id;
	if (spa_json_parse_stringn(str, len, s, sizeof(s)) <= 0)
		return -EINVAL;
	if (sscanf(s, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx:%hx",
			&v[0], &v[1], &v[2], &v[3],
			&v[4], &v[5], &unique_id) == 7) {
		*id = (uint64_t) v[0] << 56 |
			    (uint64_t) v[1] << 48 |
			    (uint64_t) v[2] << 40 |
			    (uint64_t) v[3] << 32 |
			    (uint64_t) v[4] << 24 |
			    (uint64_t) v[5] << 16 |
			    unique_id;
	} else if (!spa_atou64(str, id, 0))
		return -EINVAL;
	return 0;
}


#endif /* AVBTP_UTILS_H */
