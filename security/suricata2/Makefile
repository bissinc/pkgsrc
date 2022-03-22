# $NetBSD$

DISTNAME=	suricata-6.0.4
CATEGORIES=	security
MASTER_SITES=	https://www.openinfosecfoundation.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openinfosecfoundation.org/download/
COMMENT=	Suricata is a network IDS, IPS and NSM engine.
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libhtp/htp.pc.in

.include "../../mk/bsd.pkg.mk"
