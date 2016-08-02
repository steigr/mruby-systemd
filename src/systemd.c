#include <mruby.h>
#include <mruby/string.h>
#include <systemd/sd-daemon.h>

static mrb_value
mrb_c_systemd_notify(mrb_state *mrb, mrb_value self)
{
	mrb_int unset_environment;
	mrb_value state;
	mrb_get_args(mrb,"iS", &unset_environment, &state);
	const char *cstate;
	int cunset_environment;
	cstate = mrb_string_value_cstr(mrb, &state);
	cunset_environment = (int) unset_environment;
	return mrb_fixnum_value(sd_notify(cunset_environment,cstate));
}

void
mrb_systemd_gem_init(mrb_state* mrb) {
  struct RClass *csystemd;
  csystemd = mrb_define_class(mrb, "CSystemd",  mrb->object_class);
  mrb_define_class_method(mrb, csystemd, "notify", mrb_c_systemd_notify, MRB_ARGS_REQ(2));
}

void
mrb_systemd_gem_final(mrb_state* mrb) {
  /* finalizer */
}
