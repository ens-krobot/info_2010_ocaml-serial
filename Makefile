OCAMLFIND=ocamlfind
OCAMLC=ocamlc
OCAMLOPT=ocamlopt
OCAMLMKLIB=ocamlmklib
TO_COMPILE=serial.cma serial.cmxa
TO_INSTALL=$(wildcard *.cmi *.cma *.cmxa *.cmx *.a *.so)

all: $(TO_COMPILE)

clean:
	rm -f *.cm* *.o *.a *.so

install:
	$(OCAMLFIND) install serial META $(TO_INSTALL)

uninstall:
	$(OCAMLFIND) remove serial

reinstall:
	-$(MAKE) uninstall
	$(MAKE) install

$(TO_COMPILE): serial.cmo serial.cmx serial_stubs.o
	$(OCAMLMKLIB) -o serial $^

%.o: %.c
	$(OCAMLC) -c $<

%.cmo: %.ml
	$(OCAMLC) -c $<

%.cmx: %.ml
	$(OCAMLOPT) -c $<
