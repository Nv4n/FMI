import java.beans.XMLEncoder;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ExamQuestionsBank {

    private List<Question> questionsList;

    public List<Question> getQuestionsList() {
        return questionsList;
    }

    public void initializeQuestions() {
        questionsList = new ArrayList<>();
        //Question #1
        questionsList.add(new Question(
                "If the shell variable filenames contained a list of filenames, separated by spaces, how can you extract the second name in the list into a variable called second?",
                "echo $filenames|cut -f2 -d \" \">second",
                "second =$ -d\" \" $filename>second",
                "cut -f2 -d\" \" $filenames>second",
                "second =`cut -f2 -d \" \" $filenames`",
                QuestionOption.D
        ));
        //Question #2
        questionsList.add(new Question(
                "In \"let\" statements what action does \"/\" represent?",
                "escape the meaning of next character ",
                "division",
                "percentage",
                "remainder",
                QuestionOption.B
        ));
        //Question #3
        questionsList.add(new Question(
                "What is the purpose of the lost+found directory? ",
                "allows fsck to recover orphaned files and directories",
                "required on JFS file systems for journaling",
                "functions as a trash can for the file system ",
                "a temporary storage for deleted files",
                QuestionOption.A
        ));
        //Question #4
        questionsList.add(new Question(
                "What describes the difference between block and character I/O? ",
                "Block I/O is used to send data to disk and character I/O is not. ",
                "Character I/O is used to send data to disk and block I/O is not",
                "Block I/O goes through the buffer cache and character I/O does not.",
                "Character I/O goes through the buffer cache and block I/O does not.",
                QuestionOption.C
        ));
        //Question #5
        questionsList.add(new Question(
                "How do you turn a local variable into an environmental variable in the POSIX shell? ",
                "set variable",
                "env variable",
                "echo variable",
                "export variable",
                QuestionOption.D
        ));
        //Question #6
        questionsList.add(new Question(
                "Which statement is true regarding a device file's major number?",
                "It is determined by its hardware address.",
                "It points to the associated kernel driver.",
                "It is used to allocate buffer space.",
                "It determines the device's interrupt priority.",
                QuestionOption.B
        ));
        //Question #7
        questionsList.add(new Question(
                "What does the pvcreate command create?",
                "a hard partition",
                "a physical volume device file",
                "the lvm disk resident structures",
                "the physical links",
                QuestionOption.C
        ));
        //Question #8
        questionsList.add(new Question(
                "What is the best example of a good password?",
                "RobertSmith123",
                "TheQuickRedFoxJumpedOverTheLazyBrownDog ",
                "9874539763",
                "ornY3.%dy",
                QuestionOption.D
        ));
        //Question #9
        questionsList.add(new Question(
                "How do you change permission on a file so the owner can modify it, the owner's group can read it, and all other users can execute it?",
                "chmod file u+rw,g+r, o+xr file",
                "chomd file 754 file",
                "chmod file u+x, g+r, o+w file",
                "chmod file a=w, u-r, o+x",
                QuestionOption.A
        ));
        //Question #10
        questionsList.add(new Question(
                "The default size of a physical extent in LVM is_________",
                "twice the size of a logical extent",
                "the same size as the resident file system's disk block",
                "1/1024 of the total volume size",
                "4MB",
                QuestionOption.D
        ));

        //Q13 download
        //Question #11
        questionsList.add(new Question(
                "A journaled file system intent log is used to____________ ",
                "store user data prior to a physical write ",
                "log meta data changes ",
                "improve buffer cache performance ",
                "provide an audit trial ",
                QuestionOption.B
        ));
        //Question #12
        questionsList.add(new Question(
                "Which directory contains the HP-UX kernel? ",
                "/stand ",
                "/etc ",
                "/var ",
                "/kernel ",
                QuestionOption.A
        ));
        //Question #13
        questionsList.add(new Question(
                "What does a hard link between two files do? ",
                "allows 2 users to own the same file ",
                "ensures that 2 files get deleted together ",
                "allows data to span 2 files ",
                "allows multiple file names to reference the same data on disk ",
                QuestionOption.D
        ));
        //Question #14
        questionsList.add(new Question(
                "What is the functionality of cron? ",
                "to set carriage return on ",
                "to update the system clock using FTP ",
                "to order processes chronologically ",
                "to schedule execution of processes ",
                QuestionOption.D
        ));
        //Question #15
        questionsList.add(new Question(
                "Which command lists hardware devices? ",
                "lssf ",
                "dmsg ",
                "iomap ",
                "ioscan ",
                QuestionOption.D
        ));
        //Question #16
        questionsList.add(new Question(
                "Which filenames are matched by ab[cde]fg?",
                "abfg.abcdefg",
                "abcfg, abdfg, abefg",
                "abcfg, abdfg, abdefg, abfg",
                "abcfg, abdfg, abefg, abcdfg, abcefg, abdefg",
                QuestionOption.B
        ));
        //Question #17
        questionsList.add(new Question(
                "What does the command touch Myfile do if Myfile exixts?",
                "nothing",
                "gives an error",
                "sets the filesize to zero",
                "updates the date/time stamp",
                QuestionOption.D
        ));
        //Question #18
        questionsList.add(new Question(
                "What does a user id of zero indicate?",
                "a root user",
                "an invalid user",
                "an anonymous user",
                "a deactivated user",
                QuestionOption.A
        ));
        //Question #19
        questionsList.add(new Question(
                "Which Statement are true for a LVM logical volume",
                "It is a file system",
                "It is not a file system",
                "A logical volume contains one or more volume groups",
                "A logical volume contains one or more plexes",
                QuestionOption.B
        ));
        //Question #20
        questionsList.add(new Question(
                "How do you change from your current directory to your home directory?",
                "cd",
                "cd/",
                "cd..",
                "cdhome",
                QuestionOption.A
        ));
        //Question #21
        questionsList.add(new Question(
                "Which symbol is used to append error messages to a file in the POSIX shell?",
                "2>",
                ">>2",
                "2<<",
                "2>>",
                QuestionOption.D
        ));
        //Question #22
        questionsList.add(new Question(
                "Where does the output from background jobs go by default?",
                "to stdout",
                "to/dev/null",
                "to $HOME/out",
                "to the system console",
                QuestionOption.A
        ));
        //Question #23
        questionsList.add(new Question(
                "What is the result of the command ps?",
                "Print the current screen to the default printer.",
                "Display the status of system processes.",
                "Pauses the system.",
                "Displays a status of the default print queue.",
                QuestionOption.B
        ));
        //Question #24
        questionsList.add(new Question(
                "What command is used to change password aging?",
                "usered",
                "usermod",
                "useradd",
                "userage",
                QuestionOption.B
        ));
        //Question #25
        questionsList.add(new Question(
                "Which file would you edit to display a message when any user logs in?",
                "/var/motd",
                "/etc/motd",
                "$HOME/messages",
                "/var/adm/messages",
                QuestionOption.B
        ));
        //Question #26
        questionsList.add(new Question(
                "What does the following command do? cp -r dir2 dir3",
                "copies and removes the files from dir2 to dir3",
                "renames the directory from dir2 to dir3",
                "copies all the files and subdirectories from dir2 to dir3",
                "copies all files and subdirectories from dir3 to dir2",
                QuestionOption.C
        ));
        //Question #27
        questionsList.add(new Question(
                "Which command set the permissions on a file to be rwxr - xr-x?",
                "chmodd 557 file",
                "chmod 575 file",
                "chmod 755 file",
                "chmod u=rx,g=rwx,0=rx",
                QuestionOption.C
        ));
        //Question #28
        questionsList.add(new Question(
                "Which file permissions are indicated by the value of 721?",
                "read,write and execute for owner",
                "read,write and execute for group",
                "execute only for owner",
                "execute only for group",
                QuestionOption.A
        ));
        //Question #29
        questionsList.add(new Question(
                "What characteristics are required for a non-root password?",
                "Upper and lower case letters",
                "At least to alphabetical and one numeric or special character",
                "More than eight character",
                "At least two digits",
                QuestionOption.B
        ));
        //Question #30
        questionsList.add(new Question(
                "Which commands are used to list device file details?",
                "lssf",
                "lsdev",
                "ll -d",
                "lsf -a",
                QuestionOption.A
        ));
        //Question #31
        questionsList.add(new Question(
                "Which command is used to pvcreate a disk that has been previously used in LVM?",
                "pvcreate -F /dev/dsk/clt2d0",
                "pvcreate -f /dev/dsk/clt2d0",
                "pvcreate -B /dev/rdsk/clt2d0",
                "pvcreate -f /dev/rdsk/clt2d0",
                QuestionOption.D
        ));
        //Question #32
        questionsList.add(new Question(
                "How does a user define a different default printer for their login session?",
                "use the lpset command",
                "use the lpadmin command",
                "set the LPDEF environment variable",
                "set the LPDEST environment variable",
                QuestionOption.D
        ));
        //Question #33
        questionsList.add(new Question(
                "Which file is used to automatically check and mount file systems?",
                "/etc/mnttab",
                "/var/adm/fstab",
                "/etc/sbtab",
                "/etc/fstab",
                QuestionOption.C
        ));
        //Question #34
        questionsList.add(new Question(
                "You attempt to unmount a file system./mydata, and get an error stating \"device busy\". How do you determine the cause?",
                "showmount -a",
                "fuser -uk   ./mydata",
                "showmount ./mydata",
                "mount -v  ./mydata",
                QuestionOption.B
        ));
        //Question #35
        questionsList.add(new Question(
                "What does find / -name datafile return?",
                "the relative path names of all files called datafile in your current directory",
                "the number of files called datafile in your current directory",
                "the path names of all files called datafile",
                "the relative path of files called datafile from your current directory down.",
                QuestionOption.C
        ));
        //Question #36
        questionsList.add(new Question(
                "Which command shows all physical volume in a volume group?",
                "vgdisplay",
                "pvdisplay",
                "lvdisplay",
                "lvmdisplay",
                QuestionOption.A
        ));
        //Question #37
        questionsList.add(new Question(
                "Which folder contains the LVM configuration information?",
                "/etc/lvmrc",
                "/etc/lvmpvg",
                "/etc/lvmconf",
                "/etc/lvmtab",
                QuestionOption.C
        ));
        //Question #38
        questionsList.add(new Question(
                "Which file contains information about unsuccessful login attempts?",
                "/etc/utmp",
                "/etc/btmp",
                "/etc/wtmp",
                "/etc/nolog",
                QuestionOption.B
        ));
        //Question #39
        questionsList.add(new Question(
                "Which command makes additional crontab entries?",
                "cronedit",
                "crontab -e",
                "vi /etc/crontab",
                "/usr/sbin/cron -e",
                QuestionOption.B
        ));
        //Question #40
        questionsList.add(new Question(
                "How do you find the text \"string\" in the files a, b and c?",
                "find string a b c",
                "grep string a b c",
                "fstring string a b c",
                "search string a b c",
                QuestionOption.B
        ));
        //Question #41
        questionsList.add(new Question(
                "The Shell Pipe Command \"|\"(Certical Bar) Allows:",
                "The ouput of several commands to be appended to the same file.",
                "Data to be rapidly transported to another user's session.",
                "The output of a command to be connected to the input of another command.",
                "The paralled execution of many commands.",
                QuestionOption.C
        ));
        //Question #42
        questionsList.add(new Question(
                "Quoting is used in shell scripts to:",
                "Remove the meaning of special characters.",
                "Ensure capital letters print.",
                "Establish command substitution.",
                "Print in bold type face.",
                QuestionOption.A
        ));
        //Question #43
        questionsList.add(new Question(
                "If you wish to extract all lines from a file that do not contain a specified pattern, what command would you use?",
                "sort-i filename",
                "grep -v pattern filename",
                "ext-M pattern filename",
                "key-n pattern <filename",
                QuestionOption.B
        ));
        //Question #44
        questionsList.add(new Question(
                "How do you rename a directory callled 'tmp' to a directory called \"temp\" in the present working directory?",
                "ln tmp temp",
                "rn tmp temp",
                "mv tmp temp",
                "cn tmp temp",
                QuestionOption.C
        ));
        //Question #45
        questionsList.add(new Question(
                "Which command shows you your current group?",
                "newgroup",
                "who",
                "id",
                "whoami",
                QuestionOption.C
        ));
        //Question #46
        questionsList.add(new Question(
                "What is the command chown used for?",
                "Changing your user id.",
                "Making you the owner of all files in your directory.",
                "Changing the time stamp of a file or directory.",
                "Changing the ownership of a file or directory",
                QuestionOption.D
        ));
        //Question #47
        questionsList.add(new Question(
                "What backup utility is available on the greatest number of operating systems?",
                "tar",
                "cpio",
                "fbackup",
                "dd",
                QuestionOption.A
        ));
        //Question #48
        questionsList.add(new Question(
                "What signifies the end of an \"if\" statement in the POSIX Shell?",
                "endif",
                "fi",
                "}",
                "elseif",
                QuestionOption.B
        ));
        //Question #49
        questionsList.add(new Question(
                "The \"break\" command in the POSIX shell is used to break out of a:",
                "Shell script",
                "Function",
                "Loop structure",
                "Sleep routine",
                QuestionOption.C
        ));
        //Question #50
        questionsList.add(new Question(
                "How would you capture the result of a \"who\" and a \"date\" command into a variable in the POSIX Shell?",
                "Variable= (who+date)",
                "Variable=$(who) $(date)",
                "Variable=(who date)",
                "who> (Variable;date)> Variable.",
                QuestionOption.B
        ));
        //Question #51
        questionsList.add(new Question(
                "What command counts the number of words in a file?",
                "fcount",
                "wc",
                "wordc",
                "grep",
                QuestionOption.B
        ));
        //Question #52
        questionsList.add(new Question(
                "Which of the following command could never be used to enable additional swap space on an HP-UX system?",
                "swapon /dev/vg01/swap",
                "swapon -a",
                "swapon /swap",
                "swapon /dev/rdsk/c1t5d0",
                QuestionOption.B
        ));
        //Question #53
        questionsList.add(new Question(
                "Can a user define a printer for their session (separate from the system's default printer)?",
                "No, you specify the printer with the lp command",
                "Yes, using the lpadmin command",
                "Yes, using the LPDEST environmental variable.",
                "No, users are not allowed spooler configuration capability.",
                QuestionOption.C
        ));
        //Question #54
        questionsList.add(new Question(
                "Which of the following is not affected by the insf command?",
                "/etc/ioconfig",
                "the kernel resident I/O tree",
                "/devl/*",
                "/var/adm/iomap",
                QuestionOption.B
        ));
        //Question #55
        questionsList.add(new Question(
                "You have created a directory for the volume group named /dev/vg01. which command would you use to create the group file for this volume group?",
                "mk group",
                "insf",
                "mksf",
                "mknod",
                QuestionOption.D
        ));
        //Question #56
        questionsList.add(new Question(
                "Which of the following is NOT one of the fields in the password file?",
                "Uid",
                "TERM",
                "HOME",
                "SHELL",
                QuestionOption.B
        ));
        //Question #57
        questionsList.add(new Question(
                "In the output of an ioscan command the description \"initiator\" refers to:",
                "The first instance of a device",
                "The first device to respond to a bus poll",
                "A SCSI bus controller located on the device adapter",
                "An \"initial\" configuration template for a; devices on a bus.",
                QuestionOption.C
        ));
        //Question #58
        questionsList.add(new Question(
                "To find the number of disk connected to a SCSI controller and their associated device files, you would use the following command?",
                "diskinfo -n",
                "ioscan -fn",
                "lsdev",
                "cat  /etc/scsi.conf",
                QuestionOption.B
        ));
        //Question #59
        questionsList.add(new Question(
                "Which of the following methods allow for the variable, $var, to be substituted when the string is evaluated by the POSIX shell?",
                "\"cmd   $var\"",
                "'cmd    $var'",
                "${cmd $var}",
                "{'cmd\\$var'}",
                QuestionOption.A
        ));
        //Question #60
        questionsList.add(new Question(
                "Which of the following commands would print the file /etc/hosts on the printer /j4?",
                "lp -p lj4 /etc/hosts",
                "lp -d lj4 /etc/hosts",
                "lp /etc/host -dlj4",
                "lp /etc/hosts to lj4",
                QuestionOption.B
        ));
        //Question #61
        questionsList.add(new Question(
                "When discussing UNIX file attributes, the term \"links\" refers to:",
                "The Number of directory names in a files path.",
                "the number of file named associated with a single collection of data.",
                "The Number of identical Copies of a file that exist in a file system.",
                "A pointer to a file owner's User ID.",
                QuestionOption.B
        ));
        //Question #62
        questionsList.add(new Question(
                "To Print a document on a HP-UX system, the user would enter the __________ command.",
                "lp",
                "lpr",
                "pr",
                "lpc",
                QuestionOption.A
        ));
        //Question #63
        questionsList.add(new Question(
                "What is the difference between \"[$x-eq $y]\" and \"[$x=$y]\" in the POSIX shell?",
                "The \"-eq\" is used for numerical tests & the \"=\" is used for string tests.",
                "The \"-eq\" is used for string  tests & the \"=\" is used numerical tests.",
                "There is no Difference.",
                "The \"-eq\" is used to test for inequality & the \"=\" is used to test for equality.",
                QuestionOption.A
        ));
        //Question #64
        questionsList.add(new Question(
                "Which command would print all the dot files to the screen excluding . and ..?",
                "echo.*",
                "echo.?*",
                "echo.[.]*",
                "echo.[!]*",
                QuestionOption.D
        ));
        //Question #65
        questionsList.add(new Question(
                "A file path description that starts with \"/\" (forward slash) and contains a full list of all directories between the file system root and the object file is said to be a(n)_________ pathname.",
                "Complete",
                "Relative",
                "absolute",
                "extended",
                QuestionOption.C
        ));
        //Question #66
        questionsList.add(new Question(
                "The lpadmin command can be used to configure a new printer when:",
                "All queries are empty.",
                "The scheduler is not running.",
                "All Printers are online.",
                "Only in single user mode.",
                QuestionOption.B
        ));
        //Question #67
        questionsList.add(new Question(
                "The command to show all the physical voulmes in a volume group is:",
                "vgexport -v",
                "vgdisplay -v",
                "pvdisplay -v",
                "lvdisplay -v",
                QuestionOption.B
        ));
        //Question #68
        questionsList.add(new Question(
                "Which of the following represents a valid use of the pvcreate command?",
                "pvcreate /dev/rdsk/c1t2d0",
                "pvcreate -f/dev/vgo1/vol1",
                "pvcreate -M vxfs/dev/dsk/c1t2d0",
                "pvcreate /dev/vg01",
                QuestionOption.A
        ));
        //Question #69
        questionsList.add(new Question(
                "The file used to ensure that the LP spooling scheduler does not run twice is called:",
                "/adm/busy/spool",
                "/usrl/spool/lockfile",
                "/var/spool/lp/SCHEDLOCK",
                "/etc/SPOOLER",
                QuestionOption.C
        ));
        //Question #70
        questionsList.add(new Question(
                "How would you move a file called datafile, from your current directory to the /var directory ?",
                "mv datafile /var",
                "mv /var datafile",
                "mv datafile -d/var",
                "mv datafile ../var",
                QuestionOption.A
        ));
        //Question #71
        questionsList.add(new Question(
                "Hard links are",
                "a safe way to link files across file system boundaries",
                "should not be used unless absolutely necessary",
                "a safe way to link files and directories within a file system",
                "a safe way to link files within a file system",
                QuestionOption.D
        ));
        //Question #72
        questionsList.add(new Question(
                "What keywords define the scope of an \"until\" loop in the POSIX shell?",
                "\"begin\" and \"end\"",
                "\"do\" and 'end\".",
                "\"do\" and \"done\"",
                "\"begin\" and \"enduntil\"",
                QuestionOption.C
        ));
        //Question #73
        questionsList.add(new Question(
                "The suggested method for the redirection of std-out and std-error to the same file is:",
                "cmd 1>file2>file",
                "cmd 2 & 1>file",
                "cmd >file2>file1",
                "cmd >file",
                QuestionOption.C
        ));
        //Question #74
        questionsList.add(new Question(
                "If you wanted to pull the second word out of a variable, how would you do it, assuming that the words were separated by one space?",
                "echo $variable | cut -f2 -d\" \"",
                "echo $variable | cut -c2",
                "cut -f2 -d\" \" < $variable",
                "cut -f2 -d\" \" $variable",
                QuestionOption.A
        ));
        //Question #75
        questionsList.add(new Question(
                "Which one of the following statements is false? ",
                "Every file in a JFS file system has a JFS superblock ",
                "JFS inodes are created as needed ",
                "The JFS extend size varies ",
                "Every file in a JFS file system has an inode ",
                QuestionOption.A
        ));
    }
}

