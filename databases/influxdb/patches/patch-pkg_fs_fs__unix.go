$NetBSD$

--- pkg/fs/fs_unix.go.orig	2021-11-08 18:37:04.000000000 +0000
+++ pkg/fs/fs_unix.go
@@ -66,8 +66,8 @@ func CreateFile(newpath string) (*os.Fil
 
 // DiskUsage returns disk usage of disk of path
 func DiskUsage(path string) (*DiskStatus, error) {
-	fs := unix.Statfs_t{}
-	if err := unix.Statfs(path, &fs); err != nil {
+	fs := unix.Statvfs_t{}
+	if err := unix.Statvfs(path, &fs); err != nil {
 		return nil, err
 	}
 
