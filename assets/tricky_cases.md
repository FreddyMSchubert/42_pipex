# Tricky cases

This file contains some tricky cases i stumbled upon during my doing of this project.
If you're doing the project, consider having a look at them.
If you are evaluating someone, check these.

### BASIC

- Ensure the outfile is actually cleared and not just overwritten. Test this by first outputting something long to the outfile and then something much shorter and see whether you've got a mix of both. (-> O_TRUNC)

### BONUS

- Can you use the limiter in the middle of a line? I implemented this falsely believing it would work, and then actually had to reduce the features of my program. Technically, this would be an issue.