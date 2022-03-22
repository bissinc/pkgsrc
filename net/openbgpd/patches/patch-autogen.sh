$NetBSD$

--- autogen.sh.orig	2021-09-22 11:14:05.000000000 +0000
+++ autogen.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 set -e
 
-./update.sh
+#./update.sh
 mkdir -p m4
 rm -fr autom4te.cache
 autoreconf -i -f
