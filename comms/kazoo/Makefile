# $NetBSD$

GITHUB_PROJECT=	kazoo
GITHUB_TAG=	refs/tags/4.3.142
DISTNAME=	4.3.142
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=2600hz/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/2600hz/kazoo/
COMMENT=	API driven cloud telephony platform
LICENSE=	mpl

WRKSRC=	${WRKDIR}/kazoo-4.3.142

USE_TOOLS=	gmake

.include "../../lang/erlang/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
