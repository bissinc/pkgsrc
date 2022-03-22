# $NetBSD$

DISTNAME=	suricata-6.0.4
CATEGORIES=	security
MASTER_SITES=	https://www.openinfosecfoundation.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openinfosecfoundation.org/download/
COMMENT=	Network IDS, IPS, and NSM engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

#BUILD_DEPENDS+=		py38-setuptools-59.4.*:../../devel/py-setuptools
BUILD_DEPENDS+=		py38-yaml-5.4.*:../../textproc/py-yaml
PYTHON_VERSION_DEFAULT=	38
PYTHON_REPLACE=		*.py

LDFLAGS.SunOS+=		-lsocket

PKGCONFIG_OVERRIDE+=	libhtp/htp.pc.in

CONFIGURE_ARGS+=	--enable-bundled-htp --enable-gccprotect # --enable-ipfw --enable-af-packet --enable-pfring
CONFIGURE_ARGS+=	--enable-suricata-update --enable-lua

.include "../../mk/bsd.prefs.mk"
.include "cargo-depends.mk"

CARGO_WRKSRC=	${WRKSRC}/rust

.include "../../archivers/lz4/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python38/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
