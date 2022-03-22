$NetBSD$

--- md5.h.orig	2018-11-27 19:03:53.000000000 +0000
+++ md5.h
@@ -120,7 +120,7 @@ private:
 #include <md5.h>
 #else
 #include "config.h"
-#define CRYPTOPP_INCLUDE_MD5 <CRYPTOPP_INCLUDE_PREFIX/md5.h>
+#define CRYPTOPP_INCLUDE_MD5 <cryptopp/md5.h>
 #include CRYPTOPP_INCLUDE_MD5
 #endif
 
@@ -155,4 +155,4 @@ private:
 
 #endif //DO_NOT_USE_CRYPTOPP_MD5
 
-#endif //MD5_H
\ No newline at end of file
+#endif //MD5_H
