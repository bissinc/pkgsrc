# $NetBSD$

GITHUB_PROJECT=	openbgpd-portable
GITHUB_TAG=	a26095cd1f780b29d3b6fc41278d8035d48af80d
DISTNAME=	7.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=openbgpd-portable/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openbgpd-portable/openbgpd-portable/
COMMENT=	OpenBSD BGP Routing daemon
LICENSE=	isc

#BUILD_DEPENDS+=         py38-yaml-5.4.*:../../textproc/py-yaml
#BUILD_DEPENDS+=	coreutils-9.*:../../sysutils/coreutils
#BUILD_DEPENDS+=	vis-0.*:../../textproc/vis


WRKSRC=	${WRKDIR}/openbgpd-portable-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake bison flex
USE_LANGUAGES+=	c c++

LDFLAGS.SunOS+=	-lsocket
CFLAGS.SunOS+=	-Du_int64_t=uint64_t

pre-patch:
	set -e; \
		cd ${WRKSRC} && printf "${DISTNAME}" > ${WRKSRC}/VERSION ; \
		mkdir -p m4; rm -rf autom4te.cache; \
		autoupdate -v -f && autoreconf -i -f 


#post-extract:
#	${CP} -r ${FILESDIR}/include/* ${WRKSRC}/include/ && \
#		${CP} -r ${FILESDIR}/compat/* ${WRKSRC}/compat/ 
	#${FIND} ${WRKSRC} -name '*.[cy]' -exec \
	#	${AWK} '/^#include /{c += 1;} \
	#		c == 1 { \
	#		gsub("(^#include )", "#include \"openbsd-compat.h\"\n&", $$0) \
	#		} \
	#		{print $$0 > "{}.back"} \
	#		' \
	#		{} \;
	#${FIND} ${WRKSRC} -name '*.[cy]' -exec \
		cp {}.back {} \;
	#${CP} -r ${FILESDIR}/openbsd-compat/* ${WRKSRC}/include/ && \
	${CP} -r ${FILESDIR}/compat/* ${WRKSRC}/compat/ 
		#${CP} ${FILESDIR}/openbsd-compat/{imsg*,siphash*} ${WRKSRC}/compat/ && \
		#	${CP} ${FILESDIR}/siphash.c ${WRKSRC}/compat/



#.include "../../wip/libtermkey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
