$NetBSD$

--- urbackupserver/cmdline_preprocessor.cpp.orig	2019-09-30 14:07:38.000000000 +0000
+++ urbackupserver/cmdline_preprocessor.cpp
@@ -15,12 +15,14 @@
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************************/
-#include "../tclap/CmdLine.h"
+#include <tclap/CmdLine.h>
 #include <vector>
 #include "../stringtools.h"
 #include "../urbackupcommon/os_functions.h"
 #include <stdlib.h>
 
+#define PACKAGE_VERSION "2.4.14.0"
+
 #ifndef _WIN32
 #	include "../Server.h"
 #	include <sys/types.h>
@@ -44,7 +46,7 @@
 #include "config.h"
 #define _getcwd getcwd
 #else
-#define PACKAGE_VERSION "unknown"
+#define PACKAGE_VERSION "2.4.14.0"
 #define VARDIR ""
 #define BINDIR ""
 #define DATADIR ""
