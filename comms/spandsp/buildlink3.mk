# $NetBSD$

BUILDLINK_DEPMETHOD.spandsp?=	build
BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=284fe91dd068d0cf391139110fdc2811043972b9
BUILDLINK_PKGSRCDIR.spandsp?=	../../comms/spandsp

#.include "../../graphics/tiff/buildlink3.mk"
.endif	# SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
