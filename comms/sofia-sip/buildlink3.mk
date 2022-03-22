# $NetBSD$
BUILDLINK_DEPMETHOD.sofia-sip?=	build

BUILDLINK_TREE+=	sofia-sip

.if !defined(SOFIA_SIP_BUILDLINK3_MK)
SOFIA_SIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sofia-sip+=	sofia-sip>=1.13.7
BUILDLINK_PKGSRCDIR.sofia-sip?=	../../comms/sofia-sip
.endif	# SOFIA_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-sofia-sip
