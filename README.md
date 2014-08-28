#shell-remind

I frequently forget that I have processes running in the terminal. This
simple program plays a user specified sound when a process is complete.

##Dependencies
This project relies on SFML 2.1, you can find it [here](http://sfml-dev.org/).

##Usage
###Command line flags:
Required:

-e: the executable that you want to run. For long complex commands,
use a shell script

-s: the sound that is to be played

Optional:

-l: loop the sound until the process is ctrl-Z'd	
