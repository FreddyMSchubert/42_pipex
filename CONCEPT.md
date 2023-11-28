# pipex idea / brainstorming / notes/ stuff file

to look at
- pipe max data storable

```
$> ./pipex infile "grep a1" "wc -w" outfile
Should behave like: < infile grep a1 | wc -w > outfile
```

int executecommand (int infd, char *command, int outfd)
	ensure the command exists and can be executed using ACCESS
	pipe
	fork
	in parent, close pipe write
	in child, close pipe read
	in child, set input to infd
	if outfd is -1
		set child output to pipe write
	else
		set child output to outfd
	turn child into a process using execve
	in child, close pipe write (done implicitly if execve ends)
	in parent, waitpid for the child using returned pid from fork
	if (outfd == -1)
		in parent, return pipe read file des to use in subsequent code
	return outfd

int main(blah)
	check files are in file can be read and out file can be written to
	get infile file des
	while (there are still commands to run through)
		infile file des = executecommand(infile file des, -1)
	executecommand(infile file des, outfile file des). this will return invalid file des, dont use it
	yeah done