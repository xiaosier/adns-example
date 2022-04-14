#BASEDIR=../src
#include ../src/larbin.make

CFLAGS = -g
TARGETS=libadns.a

LIBOBJS=types.o event.o query.o reply.o general.o setup.o transmit.o \
		parse.o poll.o check.o addrfam.o

all: test_txt

test_txt: test_txt.c libadns.a

libadns.a: $(LIBOBJS)
		rm -f $@
		$(AR) cq $@ $(LIBOBJS)

clean:
	rm -f $(LIBOBJS) libadns.a *~ config.status

distclean: clean
	rm -f config.h .depend

$(LIBOBJS):	adns.h internal.h config.h
