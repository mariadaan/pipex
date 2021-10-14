# pipex

![Alt text](/plaatje-donker.png)

  ███                                                              ███
  ███                                                              ███
||███|████████████████████████████████████████████████████████████|███||
||███|████████       ██   ███       ██       ███   ████   ████████|███||
||███|████████   █   ██   ███   █   ██   ████████   ██   █████████|███||
||███|████████       ██   ███       ██       ██████    ███████████|███||
||███|████████   ██████   ███   ██████   ████████   ██   █████████|███||
||███|████████   ██████   ███   ██████       ███   ████   ████████|███||
||███|████████████████████████████████████████████████████████████|███||
  ███                                                              ███
  ███                                                              ███

The execution of the pipex program mimics the functionality as a shell command that looks like this:

   ```console
    < file1 cmd1 | cmd2 > file2
   ```

To do this, the pipex program should be executed this way:
   ```console
    ./pipex file1 cmd1 cmd2 file2
   ```

'file1' is the input filename
'file2' is the output filename
'cmd1' and 'cmd2' are shell commands with their parameters

### Pipex Tester
I also made a tester for this project, make sure to check it out and test your own pipex!

[PIPEXaminator](https://github.com/mariadaan/PIPEXaminator)