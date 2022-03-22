$NetBSD$

--- urbackupcommon/sha2/sha2.h.orig	2018-02-17 19:53:09.000000000 +0000
+++ urbackupcommon/sha2/sha2.h
@@ -210,7 +210,7 @@ typedef SHA512_CTX sha512_ctx;
 #include <sha.h>
 #else
 #include "../../config.h"
-#define CRYPTOPP_INCLUDE_SHA <CRYPTOPP_INCLUDE_PREFIX/sha.h>
+#define CRYPTOPP_INCLUDE_SHA <cryptopp/sha.h>
 #include CRYPTOPP_INCLUDE_SHA
 #endif
 typedef struct {
