$NetBSD$

--- docker/base_image/healthcheck.sh.orig	2021-10-24 16:39:33.000000000 +0000
+++ docker/base_image/healthcheck.sh
@@ -34,7 +34,7 @@ fs_cli -x status | grep -q ^UP || exit 1
 KAZOO_EXIST=$(fs_cli -x "module_exists mod_kazoo")
 ERLANG_EXITS=$(fs_cli -x "module_exists mod_erlang_event")
 
-if [ "$KAZOO_EXIST" == "true" -o "$ERLANG_EXITS" == "true" ]; then
+if [ "$KAZOO_EXIST" = "true" -o "$ERLANG_EXITS" = "true" ]; then
     /usr/bin/epmd -names | grep -qE "^name freeswitch at port" || exit 1
 fi
 
