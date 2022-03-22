# $NetBSD$

GITHUB_PROJECT=	spandsp
GITHUB_TAG=	284fe91dd068d0cf391139110fdc2811043972b9
DISTNAME=	284fe91dd068d0cf391139110fdc2811043972b9
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=freeswitch/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freeswitch/spandsp/
COMMENT=	Library of DSP functions for telephony
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/spandsp-284fe91dd068d0cf391139110fdc2811043972b9
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config automake autoconf
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	spandsp.pc.in

CONFIGURE_ARGS+=	--enable-mmx --enable-ssse3 --enable-sse4-1 --enable-sse4-2
CONFIGURE_ARGS+=	--enable-fixed-point

post-extract:
	cd ${WRKSRC}; autoupdate -f; autoreconf -if

INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/DueDiligence ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
