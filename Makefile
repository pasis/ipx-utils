CFLAGS = -O2 -Wall
UTILS = ipx_configure ipx_interface ipx_internal_net ipx_route
CC=gcc

all: $(UTILS)
	
clean:
	rm -f $(UTILS) *.o rip sap ipxrcv ipxsend

install: $(UTILS)
	for i in $(UTILS); \
	do \
		install --strip $$i /sbin; \
		install $$i.8 /usr/man/man8; \
	done
	install init.ipx /etc/rc.d/init.d/ipx
	install -m 0644 config.ipx /etc/sysconfig/ipx
	rm -f /etc/rc.d/rc2.d/S15ipx
	ln -sf /etc/rc.d/init.d/ipx /etc/rc.d/rc2.d/S15ipx
	rm -f /etc/rc.d/rc3.d/S15ipx
	ln -sf /etc/rc.d/init.d/ipx /etc/rc.d/rc3.d/S15ipx
	rm -f /etc/rc.d/rc5.d/S15ipx
	ln -sf /etc/rc.d/init.d/ipx /etc/rc.d/rc5.d/S15ipx
	rm -f /etc/rc.d/rc6.d/K55ipx
	ln -sf /etc/rc.d/init.d/ipx /etc/rc.d/rc6.d/K55ipx

