#include "sed_page.h"
int sed_to_html(int epscnt,char*expression[],char *file)
{
    char **argv;
    int cnt;
    char *E = "-e";
	argv = malloc ((epscnt* 2 + 3) * sizeof (char *));
	argv[0] = "sed";
    for (cnt = 0; cnt < epscnt;cnt++)
    {
        argv[1 + (cnt << 1)] = E;
        argv[2 + (cnt << 1)] = expression[cnt];
		debug("argv[%d] =%s\r\n",cnt,expression[cnt]);
    }

    argv[1 + (cnt << 1)] = file;
    argv[2 + (cnt << 1)] = (char *) 0;
	pid_t pid;

    pid = fork ();
	debug("pid is:%d\n",pid);
    switch (pid)
    {
        case -1:
            perror ("fork: ");
            exit (1);
        case 0:
            debug ("sed\r\n");
            execv (SED, argv);
            break;
            //exit(0);
        default:
            debug ("over\r\n");
            free (argv);
            return 0;
            break;
    }
		
	//debug("student name:%s\n",info->name);
	return 1;
	
}

int send_fail_html()
{
	fprintf (stdout, "\n<html> \n");
    fprintf (stdout, "<head>\n");
    fprintf (stdout,
        "<link rel=\"stylesheet\" type=\"text/css\" href=\"default.css\">\n");
    fprintf (stdout,
        "<meta http-equiv=\"Cache-Control\" content=\"no-cache\">\n");
    fprintf (stdout,
        "<meta http-equiv=\"Pragma\" content=\"no-cache\">\n");

    fprintf (stdout, "</head>\n");
	fprintf (stdout, "<body bgcolor=\"PaleTurquoise\">\n");
	fprintf (stdout, "<center> \n");
	fprintf (stdout, "<h1>Config param error!!!! Try again</h1>\n");
	fprintf (stdout,
            "<input type=\"button\" value=\"Back\" onclick=\"window.location.href=document.referrer\">\n");
	
	fprintf (stdout, "</body></html>\n");
}

int send_html()
{
	fprintf (stdout, "\n<html> \n");
    fprintf (stdout, "<head>\n");
    fprintf (stdout,
        "<link rel=\"stylesheet\" type=\"text/css\" href=\"css/default.css\">\n");
    fprintf (stdout,
        "<meta http-equiv=\"Cache-Control\" content=\"no-cache\">\n");
    fprintf (stdout,
        "<meta http-equiv=\"Pragma\" content=\"no-cache\">\n");
	fprintf (stdout,"<script language=\"JavaScript\"  src=\"jscripts/jquery.min.js\"></script>\n");
	fprintf (stdout,"<script language=\"JavaScript\"  src=\"jscripts/common.js\"></script>\n");
    //fprintf (stdout, "<meta http-equiv=\"refresh\" content=\"10\">\n");
    fprintf (stdout, "</head>\n");
	fprintf (stdout, "<body bgcolor=\"PaleTurquoise\">\n");
	fprintf (stdout, "<center> \n");
	fprintf (stdout, "<div class=\"wrapper\">\n");
	fprintf (stdout, "<div class=\"load-bar\"> \n");
	fprintf (stdout, "<div class=\"load-bar-inner\" style=\"width:100%\"> <span id=\"counter\"></span> </div>\n");
	fprintf (stdout, "</div>\n");
	fprintf (stdout, "<h1>Configuring</h1>\n");
	fprintf (stdout, " <p id=\"config_status\">Please wait...</p>\n");
	fprintf (stdout, " <p id=\"returnback\"></p>\n");
	fprintf (stdout, "</div>\n");
	fprintf (stdout, "</body></html>\n");
}
