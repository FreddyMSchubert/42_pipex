# pipex by @fschuber Changelog

### todo
- go crazy on the error handling
	- what if input too large for pipes?

### v0.1.0 - 28.11.23
- wrote out execute command function.
- made exit_error print to stderr so it doesnt save the error messages in our files if something goes wrong.
- things werent as easy as expected, had to make a function that searches for the path to a given command. for this, i added a cmd struct, a create_cmd_struct and a get_command path function.
- i also split up all the code into util, parent, children and a main pipex files.
- code actually works! I just havent implemented the here_doc stuff yet. Incrementing version number!
- Added a script execute_pipex_and_check that executes my executable and the real shell commands and compares the outputs for easy testing. It also creates the files if they dont exist yet, compiles the project and fills it up with dummy content.

### v0.0.1 - 28.11.23
- basic project setup (header, makefile, folder structure, subject)
- written out pretty good seeming concept
- started coding up basics