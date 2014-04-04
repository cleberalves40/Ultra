#include "../helper.h"

using namespace std;

//ggpht.com -last check: 2011-05-15
int ggpht(string *domain, string *urlf)
{
	if(regexMatch("\\.ggpht\\.com/$", *domain)){
		if(regexMatch("^http://lh.\\.", *domain)){
			*urlf = "http://ggpht.Ultra/" + get_path(*urlf,'N');
		}
		return 1;
	}
	return 0;
}
