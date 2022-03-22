# $NetBSD$

GITHUB_PROJECT=	imsg-compat
GITHUB_TAG=	refs/tags/6.8.2
DISTNAME=	6.8.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bsd-ac/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bsd-ac/imsg-compat/
COMMENT=	OpenBSD imsg compat
LICENSE=	isc

WRKSRC=		${WRKDIR}/imsg-compat-6.8.2
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libimsg.pc.in

.include "../../mk/bsd.pkg.mk"
