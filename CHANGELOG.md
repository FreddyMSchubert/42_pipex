# pipex by @fschuber Changelog

### v0.1.4 - 29.11.23
- Added basic explanatory comments to every function.
- spent two hours trying to get docker to work due to weird makefile stuff.
	- there are some errors. unfixed errors.

### v0.1.3 - 29.11.23
- Made input side of here_doc work. It wasn't that hard. It's all in here_doc.c
- made a fix to file opening by adding O_TRUNC, this now clears the output file every time we run the program in non-here_doc-mode.
- Using O_APPEND flag I now also append things in here_doc. that means im done with the bonus as well!
- Added a tricky_cases.md file which I'll be doing for upcoming projects as well.
- Made my program create the output files if they are not there.

### v0.1.2 - 29.11.23
- Added get_next_line to be able to easily read from stdin, which will be helpful for heredoc
	- to do this, i updated gnl to be a library for easy use now and in the future (-> https://github.com/FreddyMSchubert/42_get_next_line)
- forgot to make the last commit yesterday so im making a commit now

---

### v0.1.1 - 28.11.23
- Added verbose macro, setting it to 1 instead of 0 enables detailed logging
- reworked shell script, now one script initializes the files (with random values) and another executes the program and compares it to intended output to easily verify correctness
- started implementation of here_doc handling.

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