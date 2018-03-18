/*
** mrb_capacity.c - Capacity class
**
** Copyright (c) pyama86 2018
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "mrb_capacity.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

static mrb_value
mrb_str_get_capacity(mrb_state *mrb, mrb_value self)
{
  struct RString *s = mrb_str_ptr(self);
  return mrb_fixnum_value(RSTR_CAPA(s));
}

static mrb_value
mrb_str_set_capacity(mrb_state *mrb, mrb_value self)
{
  mrb_value v;

  mrb_get_args(mrb, "o", &v);
  if (!mrb_fixnum_p(v))
    mrb_raise(mrb, E_TYPE_ERROR, "non int value");

  return mrb_str_resize(mrb, self, mrb_fixnum(v));
}

static mrb_value
mrb_array_get_capacity(mrb_state *mrb, mrb_value self)
{
  struct RArray *a;
  a = mrb_ary_ptr(self);
  return mrb_fixnum_value(ARY_CAPA(a));
}

static mrb_value
mrb_array_set_capacity(mrb_state *mrb, mrb_value self)
{
  mrb_value v;

  mrb_get_args(mrb, "o", &v);
  if (!mrb_fixnum_p(v))
    mrb_raise(mrb, E_TYPE_ERROR, "non int value");

  return mrb_ary_resize(mrb, self, mrb_fixnum(v));
}
void mrb_mruby_capacity_gem_init(mrb_state *mrb)
{
  struct RClass * s = mrb->string_class;
  struct RClass * a = mrb->array_class;
  mrb_define_method(mrb, s, "capacity", mrb_str_get_capacity, MRB_ARGS_NONE());
  mrb_define_method(mrb, s, "capacity=", mrb_str_set_capacity, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, a, "capacity", mrb_array_get_capacity, MRB_ARGS_NONE());
  mrb_define_method(mrb, a, "capacity=", mrb_array_set_capacity, MRB_ARGS_REQ(1));
  DONE;
}

void mrb_mruby_capacity_gem_final(mrb_state *mrb)
{
}

