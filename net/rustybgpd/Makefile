# $NetBSD$

GITHUB_PROJECT=	rustybgp
GITHUB_TAG=	0eb7f8d48dfee925aba264cc08ce81b10df850f1
DISTNAME=	0.0.0.248
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wolfpeak-io/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/osrg/rustybgp/
COMMENT=	RustyBGP Routing daemon
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_LANGUAGES=		c c++

.include "cargo-depends.mk"

# Uncomment for cargo cert issues on crates.io
#PKGSRC_MAKE_ENV+=	CARGO_HTTP_CAINFO=/etc/ssl/certs/ca-certificates.crt

SUBST_CLASSES.SunOS+=	event
SUBST_STAGE.event=	pre-build
SUBST_FILES.event=	daemon/src/event.rs
SUBST_SED.event=	-e '/sock.set_reuse/s/^/\/\//g'

.include "go-modules.mk"

GOOS.SunOS=		GOOS=illumos

GO_MOD_EXTRA_DIRS+=	${WRKSRC}/gobgp-3.0.0-rc4

GOBGP=			v3.0.0-rc4.tar.gz
SITES.${GOBGP}=		${MASTER_SITE_GITHUB:=osrg/}gobgp/archive/refs/tags/
EXTRACT_DIR.${GOBGP}=	${WRKSRC}

DISTFILES+=		${DEFAULT_DISTFILES} 
DISTFILES+=		${GOBGP}

GOBGP_GO_FLAGS=		-s
GOBGP_GO_FLAGS+=	-X main.version=v3.0.0-rc4

BIN_FILES+=	target/release/rustybgpd gobgp-3.0.0-rc4/gobgp 

# Build section

pre-build:
.if defined(GOOS.SunOS)
	${RUN} ${CP} -rf files/zapi_illumos.go ${GO_MOD_EXTRA_DIRS}/internal/pkg/zebra/ && \
		cd ${GO_MOD_EXTRA_DIRS} && \
		${PKGSRC_SETENV} ${MAKE_ENV} ${GOOS.SunOS} ${GO} build -ldflags "${GOBGP_GO_FLAGS}" -tags assets ./cmd/gobgp
.endif

do-install:
.for f in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../lang/go/go-module.mk"

.include "../../mk/bsd.pkg.mk"
