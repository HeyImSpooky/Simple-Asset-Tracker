> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name: **
→   Simple Asset Tracker
  
**What does your program currently do? (1–3 sentences)**   
→ It adds assets with names and costs, recurring payment details and unique ids. Users can access and view saved assets within the program, but they currently dont use file I/O for saving outside of the program for next start.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   adding and view assets, assigning ids, recurring costs
  
**What is NOT working or incomplete?**   
→   saving/loading, numeric cost validation, and three class design
  
**What feels confusing or messy in your code?**   
→ most logic is standalone functions and input validation isnt resuable 

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   validating inputs
  
**What does this feature do?**   
→   checks answers and asks again when input is invalid
  
**Why is this feature important?**   
→   stops bad input from cuasing problems
  
---
### Feature 2  
**Name:**   
→   deleting assets
  
**What does this feature do?**   
→   remove an asset using its id
  
**Why is this feature important?**   
→   lets people remove mistakes, un-used, or unwanted assets
  
---
  
### Feature 3 (optional)  
**Name:**   
→   improve asset display
  
**What does this feature do?**   
→   show asset details clearly and count assets
  
**Why is this feature important?**   
→   makes the list easier to read and adds QOL
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   Asset: stores one assets information
AssetTracker: manages the asset list, ids and adding, viewing and deleting
InputReader: checks user input and asks again when it is invalid
  
**Will you modify any existing classes? How?**   
→   converting the Asset struct into a class and move the standalone tracker functions into the AssetTracker class
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   std::vector<Asset> to store multiple assets
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   displays menu
2. User chooses →   add, view, delete or exit
3. Program responds →   checks input, performs action, diplays result
4. Loop/next step →   returns to menu until users chooses to exit
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   explain what to enter such as "Enter a cost of 0 or more."
  
- Better error handling:   
→   explain invalid input and let the user retry without loosing entered asset details
  
- Improved menu/navigation:   
→   clearly label each option and retun to the menu after each action
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   catching up as I have been late with real life schedual, and restructuring the program
  
**What is your plan if you get stuck?**   
→   review the day 3 lecture from last week as its the main part of where i need to fix my control flow, test small changes at a time
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   organizing code into classes and validation of user inputs
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   review day 3 lecture, practice one change at a time, and test valid and invalid inputs
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ Oragnize code ]   
- [Add reusavle input and validation with retry messages ]   
- [ add deletion of assets by id]   
- [ improve asset display with clear labels and an asset count ]   
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [ yes ] Do I know what I’m building this week?   
- [ yes ] Do I know where to start?   
- [ yes ] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.