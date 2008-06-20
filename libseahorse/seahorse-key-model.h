/*
 * Seahorse
 *
 * Copyright (C) 2006 Stefan Walter
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * SeahorseKeyModel: A GtkTreeModel that can assign certain rows as 
 *   'key rows' which are updated when a key is updated. 
 *
 * Signals:
 *   update-row: A request to update a row 
 */
 
#ifndef __SEAHORSE_KEY_MODEL_H__
#define __SEAHORSE_KEY_MODEL_H__

#include <gtk/gtk.h>
#include "seahorse-key.h"

#define SEAHORSE_TYPE_KEY_MODEL               (seahorse_key_model_get_type ())
#define SEAHORSE_KEY_MODEL(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), SEAHORSE_TYPE_KEY_MODEL, SeahorseKeyModel))
#define SEAHORSE_KEY_MODEL_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass), SEAHORSE_TYPE_KEY_MODEL, SeahorseKeyModelClass))
#define SEAHORSE_IS_KEY_MODEL(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SEAHORSE_TYPE_KEY_MODEL))
#define SEAHORSE_IS_KEY_MODEL_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass), SEAHORSE_TYPE_KEY_MODEL))
#define SEAHORSE_KEY_MODEL_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), SEAHORSE_TYPE_KEY_MODEL, SeahorseKeyModelClass))

typedef struct _SeahorseKeyModel SeahorseKeyModel;
typedef struct _SeahorseKeyModelClass SeahorseKeyModelClass;
    
struct _SeahorseKeyModel {
    GtkTreeStore parent;
};

struct _SeahorseKeyModelClass {
    GtkTreeStoreClass parent_class;
    
    /* signals --------------------------------------------------------- */
    
    /* A key was added to this view */
    void (*update_row)   (SeahorseKeyModel *skmodel, SeahorseKey *skey, GtkTreeIter *iter);
};

GType               seahorse_key_model_get_type                (void);

SeahorseKeyModel*   seahorse_key_model_new                     (gint n_columns,
                                                                GType *types);

void                seahorse_key_model_set_column_types        (SeahorseKeyModel *skmodel, 
                                                                gint n_columns,
                                                                GType *types);

void                seahorse_key_model_set_row_key             (SeahorseKeyModel *skmodel,
                                                                GtkTreeIter *iter,
                                                                SeahorseKey *skey);

SeahorseKey*        seahorse_key_model_get_row_key             (SeahorseKeyModel *skmodel,
                                                                GtkTreeIter *iter);

GSList*             seahorse_key_model_get_rows_for_key        (SeahorseKeyModel *skmodel,
                                                                SeahorseKey *skey);

void                seahorse_key_model_remove_rows_for_key     (SeahorseKeyModel *skmodel,
                                                                SeahorseKey *skey);

void                seahorse_key_model_free_rows               (GSList *rows);

#endif /* __SEAHORSE_KEY_SET_H__ */
