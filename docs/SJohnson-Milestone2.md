# Milestone 2 — Simple Asset Tracker

## Features Added
I added the ability to delete an asset by its ID, with 0 used to cancel. The asset list now shows the total number of assets and displays costs with two decimal places.

## Code Structure
I separated the program into three classes. Asset stores and displays one asset’s information. AssetTracker manages the list and menu actions. InputReader handles numeric input validation.

## Usability Improvements
Invalid menu choices and costs now show a message and let the user try again. Blank names and incorrect recurring payment answers also retry without losing the other information entered.

## Testing
I tested invalid menu choices, blank names, negative costs, and text entered as a cost. I also tested adding and viewing assets, recurring payment frequency, and deleting an asset. I fixed errors with function calls while moving the code into classes.

## Still In Progress
Assets are only stored during the current session. Saving and loading files is planned for a later milestone.