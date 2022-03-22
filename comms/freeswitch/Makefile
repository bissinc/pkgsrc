# $NetBSD: Makefile,v 1.26 2021/09/17 13:52:53 bsiegert Exp $

DISTNAME=		freeswitch-1.10.7
MASTER_SITES=		${MASTER_SITE_GITHUB:=signalwire/}
PKGREVISION=		1
CATEGORIES=		comms
GITHUB_PROJECT=		freeswitch
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		john.barfield@joyent.com
HOMEPAGE=		https://github.com/signalwire/freeswitch
COMMENT=		Software defined telecom switch
LICENSE=		mpl

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake autoreconf perl
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-cpp --enable-static --disable-core-libedit-support

#PKGCONFIG_OVERRIDE+=	${PREFIX}/lib/pkgconfig/speex.pc

DATADIR=		${VARBASE}/lib/freeswitch
LOGDIR=			${VARBASE}/log/freeswitch

BUILD_DEFS+=		FREESWITCH_USER FREESWITCH_GROUP VARBASE
FILES_SUBST+=		FREESWITCH_USER=${FREESWITCH_USER:Q}
FILES_SUBST+=		FREESWITCH_GROUP=${FREESWITCH_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

FREESWITCH_USER?=	freeswitch
FREESWITCH_GROUP?=	freeswitch
OWN_DIRS_PERMS+=	${DATADIR} ${FREESWITCH_USER} ${FREESWITCH_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${FREESWITCH_USER} ${FREESWITCH_GROUP} 0700
PKG_USERS_VARS+=	FREESWITCH_USER
PKG_GROUPS_VARS+=	FREESWITCH_GROUP
PKG_GROUPS=		${FREESWITCH_GROUP}
PKG_USERS=		${FREESWITCH_USER}:${FREESWITCH_GROUP}

PKG_SYSCONFSUBDIR=	freeswitch
RCD_SCRIPTS=		freeswitch

post-extract:
	set -e; cd ${WRKSRC}; \
		autoupdate -f; autoreconf -if && \
		mv libs libs.bkp && \
		cd ${WRKDIR}/

.include "../../comms/spandsp/buildlink3.mk"
.include "../../comms/sofia-sip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/iksemel/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
