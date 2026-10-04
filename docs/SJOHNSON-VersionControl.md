# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Project and Portfolio: 1 <-- Replace all text in brackets ]

- **[ Scott Johnson ]**
- **[ 10/4/2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ cls ]: Clear the Screen
- [ cd ]: Print the "Working Directory"
- [ dir ]: List files and folders
- [ dir /a ]: List files and folders, including invisible files
- [ dir /a ]: List all files and folders, in human readable form
- [ cd "foldername" ]: Change directory
- [ cd \ ]: Change directory, go to root directory
- [ cd /d "%USERPROFILE%" ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ..\.. ]: Change directory, go up two folder levels
- [ cd /d "%USERPROFILE%\Desktop" ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ when I pasted a folder it took me to the directory where i could run commands directly in that folder(like installing a node package, running a python script ect.) when I pasted a file it said it cannot open this type ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Localized version control - where u save file history on the computer allowing ability to recover the files 
centralized version control - stores shared repo on central server like a cloud host of sorts
distributed version control - like github where u get all commits, versions and more]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone "repolink" ]: Clone a repository
- [ git config --global user.name "Scott Johnson" ]: Set-up a global user name
- [ git config --global user.email "email" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add . ]: Add modified files to the next commit
- [ git commit -m "commit message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git --help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ open repo on github, click code and https then copy the url, open the cmd terminal in folder where local repo is created, run git clone followed by the url, it will download then enter it with cd, use git remote -v and verify it uses https. use a personal access token and not a password if github requires extra protection ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [it specifies the files and folders that git should not keep track of, this helps keep local and un-used files to not be uploaded to tracked]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [ its a macos file to make diplay settings like icon positions, its unrelated to code so ignore]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [ignore .vs/ cause it makes the source way to big (tracks your build and downloaded depends and such), and then also i would hide the debug build folder as there is no need to upload debug builds]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[Site Address](https://ubuntu.com/tutorials/command-line-for-beginners)

**Three Types of Version Control**  
[Site Address](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)

**Git Commands**  
[Site Address](https://git-scm.com/docs)

**Connecting to GitHub using Terminal**  
[Site Address](https://docs.github.com/en/get-started/git-basics/about-remote-repositories)

**Using .gitignore and Why it's Important**  
[Site Address](https://git-scm.com/docs/gitignore)
