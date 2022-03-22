$NetBSD$

--- file_linux.cpp.orig	2020-09-09 23:00:44.000000000 +0000
+++ file_linux.cpp
@@ -66,7 +66,7 @@
 #define pwrite64 pwrite
 #define pread64 pread
 #else
-#include <linux/fs.h>
+#include <sys/fs/zfs.h>
 
 #if !defined(BLKGETSIZE64) && defined(__i386__) && defined(__x86_64__)
 #define BLKGETSIZE64 _IOR(0x12,114,size_t)
