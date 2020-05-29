CFLAGS = -O2 -Wall
UTILS = ipx_configure ipx_interface ipx_internal_net ipx_route
CC=gcc

all: $(UTILS)
	
clean:
	rm -f $(UTILS) *.o rip sap ipxrcv ipxsend

install: $(UTILS)
	for i in $(UTILS); \
	do \
		install $$i ${DESTDIR}/sbin; \
		install $$i.8 ${DESTDIR}/usr/share/man/man8; \
	done
#	install init.ipx /etc/rc.d/init.d/ipx
#	install -m 0644 config.ipx /etc/sysconfig/ipx
