AM_CFLAGS = -Wall -Wextra

bin_PROGRAMS =			\
	ipx_configure		\
	ipx_interface		\
	ipx_internal_net	\
	ipx_route

ipx_configure_SOURCES =		\
	src/ipx_configure.c

ipx_interface_SOURCES =		\
	src/ipx_interface.c

ipx_internal_net_SOURCES =	\
	src/ipx_internal_net.c

ipx_route_SOURCES =		\
	src/ipx_route.c

man_MANS =			\
	docs/ipx_configure.8	\
	docs/ipx_interface.8	\
	docs/ipx_internal_net.8	\
	docs/ipx_route.8

samples_files =			\
	Samples/ipxrcv.c	\
	Samples/ipxsend.c	\
	Samples/rip.c		\
	Samples/sap.c

EXTRA_DIST =			\
	$(man_MANS)		\
	$(samples_files)	\
	autogen.sh		\
	scripts/config.ipx	\
	scripts/init.ipx
