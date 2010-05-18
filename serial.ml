(*
 * serial.ml
 * ---------
 * Copyright : (c) 2010, Stéphane Glondu <steph@glondu.net>
 * Licence   : BSD3
 *)

external crtscts : Unix.file_descr -> int = "ml_crtscts"
(** Enable RTS/CTS (hardware) flow control. See CRTSCTS in
    tcsetattr(3). *)

external tiocmget : Unix.file_descr -> int = "ml_tiocmget"
(** Get the status of modem bits. See TIOCMGET in tty_ioctl(4). *)

external tiocmset : Unix.file_descr -> int -> int = "ml_tiocmset"
(** Set the satus of modem bits. See TIOCMSET in tty_ioctl(4). *)

external tiocmbic : Unix.file_descr -> int -> int = "ml_tiocmbic"
(** Clear the indicated modem bits. See TIOCMBIC in tty_ioctl(4). *)

external tiocmbis : Unix.file_descr -> int -> int = "ml_tiocmbis"
(** Set the indicated modem bits. See TIOCMBIC in tty_ioctl(4). *)
