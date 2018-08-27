/* Simple Plugin API
 * Copyright (C) 2016 Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __SPA_EVENT_NODE_H__
#define __SPA_EVENT_NODE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <spa/utils/defs.h>
#include <spa/pod/event.h>
#include <spa/node/node.h>

/* object id of SPA_TYPE_EVENT_Node */
enum spa_node_event {
	SPA_NODE_EVENT_Error,
	SPA_NODE_EVENT_Buffering,
	SPA_NODE_EVENT_RequestRefresh,
};

#define SPA_NODE_EVENT_ID(ev)	SPA_EVENT_ID(ev, SPA_TYPE_EVENT_Node)

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* __SPA_EVENT_NODE_H__ */
