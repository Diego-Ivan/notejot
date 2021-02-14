/* Application.c generated by valac 0.50.3, the Vala compiler
 * generated from Application.vala, do not modify */

/*
* Copyright (c) 2017-2021 Lains
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 3 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA
*
*/

#include <gtk/gtk.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <handy.h>
#include <glib.h>
#include "config.h"
#include <stdlib.h>
#include <string.h>

#define NOTEJOT_TYPE_APPLICATION (notejot_application_get_type ())
#define NOTEJOT_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOTEJOT_TYPE_APPLICATION, NotejotApplication))
#define NOTEJOT_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOTEJOT_TYPE_APPLICATION, NotejotApplicationClass))
#define NOTEJOT_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOTEJOT_TYPE_APPLICATION))
#define NOTEJOT_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOTEJOT_TYPE_APPLICATION))
#define NOTEJOT_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOTEJOT_TYPE_APPLICATION, NotejotApplicationClass))

typedef struct _NotejotApplication NotejotApplication;
typedef struct _NotejotApplicationClass NotejotApplicationClass;
typedef struct _NotejotApplicationPrivate NotejotApplicationPrivate;
enum  {
	NOTEJOT_APPLICATION_0_PROPERTY,
	NOTEJOT_APPLICATION_NUM_PROPERTIES
};
static GParamSpec* notejot_application_properties[NOTEJOT_APPLICATION_NUM_PROPERTIES];

#define NOTEJOT_TYPE_MAIN_WINDOW (notejot_main_window_get_type ())
#define NOTEJOT_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), NOTEJOT_TYPE_MAIN_WINDOW, NotejotMainWindow))
#define NOTEJOT_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), NOTEJOT_TYPE_MAIN_WINDOW, NotejotMainWindowClass))
#define NOTEJOT_IS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NOTEJOT_TYPE_MAIN_WINDOW))
#define NOTEJOT_IS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NOTEJOT_TYPE_MAIN_WINDOW))
#define NOTEJOT_MAIN_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), NOTEJOT_TYPE_MAIN_WINDOW, NotejotMainWindowClass))

typedef struct _NotejotMainWindow NotejotMainWindow;
typedef struct _NotejotMainWindowClass NotejotMainWindowClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _NotejotApplication {
	GtkApplication parent_instance;
	NotejotApplicationPrivate * priv;
};

struct _NotejotApplicationClass {
	GtkApplicationClass parent_class;
};

static gpointer notejot_application_parent_class = NULL;
extern NotejotMainWindow* notejot_application_win;
NotejotMainWindow* notejot_application_win = NULL;
extern GSettings* notejot_application_gsettings;
GSettings* notejot_application_gsettings = NULL;

GType notejot_application_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (NotejotApplication, g_object_unref)
GType notejot_main_window_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (NotejotMainWindow, g_object_unref)
NotejotApplication* notejot_application_new (void);
NotejotApplication* notejot_application_construct (GType object_type);
static void notejot_application_real_activate (GApplication* base);
NotejotMainWindow* notejot_main_window_new (GtkApplication* application);
NotejotMainWindow* notejot_main_window_construct (GType object_type,
                                                  GtkApplication* application);
gint notejot_application_main (gchar** args,
                               gint args_length1);
static void notejot_application_finalize (GObject * obj);
static GType notejot_application_get_type_once (void);

NotejotApplication*
notejot_application_construct (GType object_type)
{
	NotejotApplication * self = NULL;
#line 26 "../src/Application.vala"
	self = (NotejotApplication*) g_object_new (object_type, "flags", G_APPLICATION_FLAGS_NONE, "application-id", APP_ID, NULL);
#line 25 "../src/Application.vala"
	return self;
#line 99 "Application.c"
}

NotejotApplication*
notejot_application_new (void)
{
#line 25 "../src/Application.vala"
	return notejot_application_construct (NOTEJOT_TYPE_APPLICATION);
#line 107 "Application.c"
}

static void
notejot_application_real_activate (GApplication* base)
{
	NotejotApplication * self;
	NotejotMainWindow* _tmp0_;
	NotejotMainWindow* _tmp2_;
#line 35 "../src/Application.vala"
	self = (NotejotApplication*) base;
#line 36 "../src/Application.vala"
	_tmp0_ = notejot_application_win;
#line 36 "../src/Application.vala"
	if (_tmp0_ != NULL) {
#line 122 "Application.c"
		NotejotMainWindow* _tmp1_;
#line 37 "../src/Application.vala"
		_tmp1_ = notejot_application_win;
#line 37 "../src/Application.vala"
		gtk_window_present ((GtkWindow*) _tmp1_);
#line 38 "../src/Application.vala"
		return;
#line 130 "Application.c"
	}
#line 40 "../src/Application.vala"
	_tmp2_ = notejot_main_window_new ((GtkApplication*) self);
#line 40 "../src/Application.vala"
	g_object_ref_sink (_tmp2_);
#line 40 "../src/Application.vala"
	_g_object_unref0 (notejot_application_win);
#line 40 "../src/Application.vala"
	notejot_application_win = _tmp2_;
#line 140 "Application.c"
}

gint
notejot_application_main (gchar** args,
                          gint args_length1)
{
	NotejotApplication* app = NULL;
	NotejotApplication* _tmp0_;
	gint result = 0;
#line 43 "../src/Application.vala"
	_tmp0_ = notejot_application_new ();
#line 43 "../src/Application.vala"
	app = _tmp0_;
#line 44 "../src/Application.vala"
	result = g_application_run ((GApplication*) app, (gint) args_length1, args);
#line 44 "../src/Application.vala"
	_g_object_unref0 (app);
#line 44 "../src/Application.vala"
	return result;
#line 160 "Application.c"
}

int
main (int argc,
      char ** argv)
{
#line 42 "../src/Application.vala"
	return notejot_application_main (argv, argc);
#line 169 "Application.c"
}

static void
notejot_application_class_init (NotejotApplicationClass * klass,
                                gpointer klass_data)
{
	GSettings* _tmp0_;
#line 21 "../src/Application.vala"
	notejot_application_parent_class = g_type_class_peek_parent (klass);
#line 21 "../src/Application.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) notejot_application_real_activate;
#line 21 "../src/Application.vala"
	G_OBJECT_CLASS (klass)->finalize = notejot_application_finalize;
#line 32 "../src/Application.vala"
	_tmp0_ = g_settings_new ("io.github.lainsce.Notejot");
#line 32 "../src/Application.vala"
	_g_object_unref0 (notejot_application_gsettings);
#line 32 "../src/Application.vala"
	notejot_application_gsettings = _tmp0_;
#line 189 "Application.c"
}

static void
notejot_application_instance_init (NotejotApplication * self,
                                   gpointer klass)
{
}

static void
notejot_application_finalize (GObject * obj)
{
	NotejotApplication * self;
#line 21 "../src/Application.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, NOTEJOT_TYPE_APPLICATION, NotejotApplication);
#line 21 "../src/Application.vala"
	G_OBJECT_CLASS (notejot_application_parent_class)->finalize (obj);
#line 206 "Application.c"
}

static GType
notejot_application_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (NotejotApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) notejot_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (NotejotApplication), 0, (GInstanceInitFunc) notejot_application_instance_init, NULL };
	GType notejot_application_type_id;
	notejot_application_type_id = g_type_register_static (gtk_application_get_type (), "NotejotApplication", &g_define_type_info, 0);
	return notejot_application_type_id;
}

GType
notejot_application_get_type (void)
{
	static volatile gsize notejot_application_type_id__volatile = 0;
	if (g_once_init_enter (&notejot_application_type_id__volatile)) {
		GType notejot_application_type_id;
		notejot_application_type_id = notejot_application_get_type_once ();
		g_once_init_leave (&notejot_application_type_id__volatile, notejot_application_type_id);
	}
	return notejot_application_type_id__volatile;
}
