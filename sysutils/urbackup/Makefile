# $NetBSD$

DISTNAME=	urbackup-server-2.4.14
CATEGORIES=	sysutils
MASTER_SITES=	https://hndl.urbackup.org/Server/2.4.14/

MAINTAINER=	john.barfieled@joyent.com
HOMEPAGE=	https://hndl.urbackup.org/Server/2.4.14/
COMMENT=	Opensource network backup
LICENSE=	gnu-agpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cryptoplugin/src/libcryptopp.pc.in

.include "../../mk/bsd.prefs.mk"

LDFLAGS.SunOS+=		-lsocket -lssp -fstack-protector
CFLAGS.SunOS+=		-Wno-deprecated-declarations -D_FILE_OFFSET_BITS=64 
CFLAGS.SunOS+=		-Du_int64_t=uint64_t -Du_int32_t=uint32_t -fPIC
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS -DHAVE_STRSTREAM 
CFLAGS.SunOS+=		-DHAVE_SSTREAM -fstack-protector 

SUBST_CLASSES.SunOS+=	crypto
SUBST_STAGE.crypto=	pre-build
SUBST_FILES.crypto=	cryptoplugin/cryptopp_inc.h
SUBST_SED.crypto=	-e 's/CRYPTOPP_INCLUDE_PREFIX/cryptopp/g'

CONFIGURE_ARGS+=	--without-embedded-lmdb --with-pic

pre-build:
	${CP} files/os_functions_lin.cpp  ${WRKSRC}/urbackupcommon/#&& \
		${CP} files/tclap_config.h ${WRKSRC}/tclap/config.h

.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/lmdb/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
