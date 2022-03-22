# $NetBSD$

GITHUB_PROJECT=	sofia-sip
GITHUB_TAG=	refs/tags/v1.13.7
DISTNAME=	v1.13.7
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=freeswitch/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freeswitch/sofia-sip/
COMMENT=	Nokia Sofia SIP Agent
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/sofia-sip-1.13.7
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	packages/sofia-sip-ua-glib.pc.in
PKGCONFIG_OVERRIDE+=	packages/sofia-sip-ua.pc.in

post-extract:
	cd ${WRKSRC} && \
		autoupdate -f; autoreconf -if

.include "../../mk/bsd.pkg.mk"
