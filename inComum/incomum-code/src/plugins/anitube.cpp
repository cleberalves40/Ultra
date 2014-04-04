#include "../helper.h"

using namespace std;

// Anitube videos plugin - last check: 2012-08-29
// example1: http://vid29-wdc07.anitube.com.br/a2b85a360804eecbafb243974fb6fc5a/4ffca930/38452.flv?start=55.013
// example2: http://lb02-wdc.anitube.com.br/mobile/b9751d0c6c19328ec03cb4408aadaeff/4ffca46f/46283.mp4
// example3: http://lb02-wdc.anitube.com.br/4b12a43fc133cd2329efb0411c28b9e8/503eb1e9/49695.flv?start=0
// rewrite to: http://anitube.Ultra/file.flv or http://anitube.Ultra/mobile/file.mp4

int anitube(string *domain, string *urlf)
{
	if(regexMatch("anitube\\.com\\.br/$", *domain)){
		if (regexMatch("\\.flv\\?start=", *urlf)){
			*urlf = "http://anitube.Ultra/" + get_filename(*urlf) + "?start=" + get_var(*urlf, "start");
		} else if (regexMatch("\\.mp4$", *urlf)){
			*urlf = "http://anitube.Ultra/" + get_filename(*urlf);
		}
		return 1;
	}
	return 0;
}
