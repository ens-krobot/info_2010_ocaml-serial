/*
 * rx64.c
 * ------
 * Copyright : (c) 2010, Stéphane Glondu <steph@glondu.net>
 * Licence   : BSD3
 */

#include <termios.h>
#include <sys/ioctl.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>
#include <caml/fail.h>

/* FIXME: proper error handling an OCaml wrapping... */

CAMLprim value ml_crtscts(value mlfd)
{
  CAMLparam1(mlfd);
  struct termios t;
  int r, fd = Int_val(mlfd);

  r = tcgetattr(fd, &t);
  if (!r) {
    t.c_cflag |= CRTSCTS;
    r = tcsetattr(fd, TCSANOW, &t);
  }
  CAMLreturn(Val_int(r));
}

CAMLprim value ml_tiocmget(value mlfd)
{
  CAMLparam1(mlfd);
  int arg = 0;
  int fd = Int_val(mlfd);

  ioctl(fd, TIOCMGET, &arg);
  CAMLreturn(Val_int(arg));
}

CAMLprim value ml_tiocmset(value mlfd, value mlarg)
{
  CAMLparam2(mlfd, mlarg);
  int r, fd = Int_val(mlfd);
  int arg = Int_val(mlarg);

  r = ioctl(fd, TIOCMSET, &arg);
  CAMLreturn(Val_int(r));
}

CAMLprim value ml_tiocmbic(value mlfd, value mlarg)
{
  CAMLparam2(mlfd, mlarg);
  int r, fd = Int_val(mlfd);
  int arg = Int_val(mlarg);

  r = ioctl(fd, TIOCMBIC, &arg);
  CAMLreturn(Val_int(r));
}

CAMLprim value ml_tiocmbis(value mlfd, value mlarg)
{
  CAMLparam2(mlfd, mlarg);
  int fd = Int_val(mlfd), r;
  int arg = Int_val(mlarg);

  r = ioctl(fd, TIOCMBIS, &arg);
  CAMLreturn(Val_int(r));
}
