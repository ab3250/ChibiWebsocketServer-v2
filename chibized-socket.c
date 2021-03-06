/* Automatically generated by chibi-ffi; version: 0.4 */

#include <chibi/eval.h>
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "ws.h"

sexp ctx2;

 void onopen(int fd)
 { 
  sexp ctx = ctx2;
  sexp_gc_var1(cmd); 
  sexp_gc_preserve1(ctx,cmd);
  cmd = sexp_list2(ctx, sexp_intern(ctx, "onopen", -1),sexp_make_integer(ctx, fd));
  sexp_eval(ctx, cmd, NULL);
  sexp_gc_release1(ctx);
 }

void onclose(int fd)
{
   sexp ctx = ctx2;
  sexp_gc_var1(cmd); 
  sexp_gc_preserve1(ctx,cmd);
  cmd = sexp_list2(ctx, sexp_intern(ctx, "onclose", -1),sexp_make_integer(ctx, fd));
  sexp_eval(ctx, cmd, NULL);
  sexp_gc_release1(ctx); 
}

void onmessage(int fd, const unsigned char *msg, uint64_t size, int type)
{  
   sexp ctx = ctx2;
  sexp_gc_var1(cmd); 
  sexp_gc_preserve1(ctx,cmd);
  cmd = sexp_list3(ctx,sexp_c_string(ctx, msg, -1),
         sexp_make_integer(ctx, size),sexp_make_integer(ctx, type));
  cmd = sexp_cons(ctx,sexp_make_integer(ctx, fd), cmd);
  cmd = sexp_cons(ctx,sexp_intern(ctx, "onmessage", -1),cmd); 
  sexp_eval(ctx, cmd, NULL);
  sexp_gc_release1(ctx);   
}

void init(void)
{  

  sexp ctx = ctx2;
  struct ws_events evs;
  evs.onopen    = &onopen;
  evs.onclose   = &onclose;
  evs.onmessage = &onmessage;
  ws_socket(&evs, 8080, 1); /* Never returns. */
//  sexp_gc_var3(arg_sym,arg_val,ret); 
//  sexp_gc_preserve3(ctx,arg_sym,arg_val,ret);
  // // arg_sym = sexp_intern(ctx, "fp", -1);
  // // arg_val = &evs;  
  // // sexp_env_define(ctx,sexp_context_env(ctx), arg_sym, arg_val); 
  // // ret=sexp_eval_string(ctx, "(init fp)", -1, NULL);

//  ret = sexp_eval_string(ctx, "(main)", -1, NULL);
//  sexp_debug(ctx, "message: ", ret);
//  sexp_print_exception(ctx, ret, SEXP_FALSE);
//  sexp_gc_release3(ctx);	
  printf("Server Initialized!\n");  	
}

int ws_start(void){
 sexp ctx = ctx2;
// sexp_scheme_init();
// sexp_load_standard_env(ctx, NULL, SEXP_SEVEN);
// sexp_load_standard_ports(ctx, NULL, stdin, stdout, stderr, 1);
 setbuf(stdout, NULL); 
 init();    
}
 
sexp sexp_ws_socket_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1, sexp arg2) {
  sexp res;
  if (! sexp_exact_integerp(arg1))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg1);
  if (! sexp_exact_integerp(arg2))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg2);
  res = sexp_make_integer(ctx, ws_socket(arg0, sexp_sint_value(arg1), sexp_sint_value(arg2)));
  return res;
}

sexp sexp_ws_sendframe_bin_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1, sexp arg2, sexp arg3) {
  sexp res;
  if (! sexp_exact_integerp(arg0))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg0);
  if (! sexp_stringp(arg1))
    return sexp_type_exception(ctx, self, SEXP_STRING, arg1);
  if (! sexp_exact_integerp(arg2))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg2);
  res = sexp_make_integer(ctx, ws_sendframe_bin(sexp_sint_value(arg0), sexp_string_data(arg1), sexp_uint_value(arg2), sexp_truep(arg3)));
  return res;
}

sexp sexp_ws_sendframe_txt_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1, sexp arg2) {
  sexp res;
  if (! sexp_exact_integerp(arg0))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg0);
  if (! sexp_stringp(arg1))
    return sexp_type_exception(ctx, self, SEXP_STRING, arg1);
  res = sexp_make_integer(ctx, ws_sendframe_txt(sexp_sint_value(arg0), sexp_string_data(arg1), sexp_truep(arg2)));
  return res;
}

sexp sexp_ws_start_stub (sexp ctx, sexp self, sexp_sint_t n) {
  sexp res;
  res = sexp_make_integer(ctx, ws_start());
  return res;
}


sexp sexp_init_library (sexp ctx, sexp self, sexp_sint_t n, sexp env, const char* version, const sexp_abi_identifier_t abi) {


  sexp sexp_ws_events_type_obj;
  sexp_gc_var3(name, tmp, op);
  if (!(sexp_version_compatible(ctx, version, sexp_version)
        && sexp_abi_compatible(ctx, abi, SEXP_ABI_IDENTIFIER)))
    return SEXP_ABI_ERROR;
  sexp_gc_preserve3(ctx, name, tmp, op);
  name = sexp_c_string(ctx, "ws_events", -1);
  sexp_ws_events_type_obj = sexp_register_c_type(ctx, name, sexp_finalize_c_type);
  tmp = sexp_string_to_symbol(ctx, name);
  sexp_env_define(ctx, env, tmp, sexp_ws_events_type_obj);
  op = sexp_define_foreign(ctx, env, "ws_socket", 3, sexp_ws_socket_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg3_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
  }  
  op = sexp_define_foreign(ctx, env, "ws_sendframe_bin", 4, sexp_ws_sendframe_bin_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_STRING);
    sexp_opcode_arg3_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_argn_type(op) = sexp_make_vector(ctx, SEXP_ONE, sexp_make_fixnum(SEXP_OBJECT));
    sexp_vector_set(sexp_opcode_argn_type(op), SEXP_ZERO, sexp_make_fixnum(SEXP_BOOLEAN));
  }
  op = sexp_define_foreign(ctx, env, "ws_sendframe_txt", 3, sexp_ws_sendframe_txt_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_STRING);
    sexp_opcode_arg3_type(op) = sexp_make_fixnum(SEXP_BOOLEAN);
  }
  op = sexp_define_foreign(ctx, env, "ws_start", 0, sexp_ws_start_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
  }
  sexp_gc_release3(ctx);

  ctx2 = ctx;  
  return SEXP_VOID;
}

