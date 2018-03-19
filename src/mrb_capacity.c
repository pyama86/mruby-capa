/*
** mrb_capacity.c - Capacity class
**
** Copyright (c) pyama86 2018
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/array.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mrb_capacity.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

#define CAPACITY_INTERFACE(type, method_name, class)                                               \
  static mrb_value mrb_##type##_get_capacity(mrb_state *mrb, mrb_value self)                       \
  {                                                                                                \
    struct R##class *s = mrb_##type##_ptr(self);                                                   \
    return mrb_fixnum_value(method_name##_CAPA(s));                                                \
  }                                                                                                \
                                                                                                   \
  static mrb_value mrb_##type##_set_capacity(mrb_state *mrb, mrb_value self)                       \
  {                                                                                                \
    mrb_value v;                                                                                   \
    mrb_int slen;                                                                                  \
    struct R##class *s = mrb_##type##_ptr(self);                                                   \
    slen = method_name##_LEN(s);                                                                   \
    mrb_get_args(mrb, "o", &v);                                                                    \
    if (!mrb_fixnum_p(v))                                                                          \
      mrb_raise(mrb, E_TYPE_ERROR, "non int value");                                               \
                                                                                                   \
    if (method_name##_CAPA(s) != mrb_fixnum(v))                            \
      mrb_##type##_resize(mrb, self, mrb_fixnum(v));                                               \
    method_name##_SET_LEN(s, slen);                                                                \
    return self;                                                                                   \
  }

CAPACITY_INTERFACE(str, RSTR, String)
CAPACITY_INTERFACE(ary, ARY, Array)

void mrb_mruby_capacity_gem_init(mrb_state *mrb)
{
  struct RClass *s = mrb->string_class;
  struct RClass *a = mrb->array_class;
  mrb_define_method(mrb, s, "capacity", mrb_str_get_capacity, MRB_ARGS_NONE());
  mrb_define_method(mrb, s, "capacity=", mrb_str_set_capacity, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, a, "capacity", mrb_ary_get_capacity, MRB_ARGS_NONE());
  mrb_define_method(mrb, a, "capacity=", mrb_ary_set_capacity, MRB_ARGS_REQ(1));
  DONE;
}

void mrb_mruby_capacity_gem_final(mrb_state *mrb)
{
}
