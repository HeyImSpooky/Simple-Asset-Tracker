# Milestone 4: Final Development & Project Wrap-Up

## ⚙️ Final Features Implemented
- **Save and load (file I/O)**: Assets are now saved to a text file (`assets.txt`) after every add and delete, and loaded back automatically when the program starts. This was the main piece that was still missing in earlier milestones, so the program finally keeps data between sessions.
- **ID stays correct after reloading**: The next ID value is written as the first line of the save file and read back on load, so reopening the program does not reuse an ID that already exists.
- **Finalized menu and input handling**: The add / view / delete / exit menu is complete, and every numeric prompt still goes through the reusable `InputReader` so bad input is caught and retried instead of crashing.

## 🧹 Refactoring Improvements
- **Added file logic to the tracker class**: `SaveAssets()` and `LoadAssets()` were added as private methods on `AssetTracker` instead of loose functions, so `main()` is still just creating the tracker and calling `Run()`.
- **Replaced the leftover TODOs**: The two `// TODO: save/load later` comments in `AssetTracker` were removed and replaced with the actual save and load calls.
- **Reference use**: The save loop passes each asset by `const` reference (`const Asset&`) so nothing is copied or changed while writing the file.

## 🐛 Bug Fixes
- **Data no longer lost on exit**: Before this milestone every asset disappeared when the program closed because nothing was saved. Adding file I/O fixed that.
- **Bad save data is skipped, not fatal**: `LoadAssets()` wraps the number conversions in try/catch, so a damaged or half-written record is skipped instead of crashing the program on startup.
- **Write failures are reported**: If the save file cannot be opened for writing, the program shows an error message instead of silently losing the data.

## ✨ Usability Updates
- **Persistent asset list**: Users can close the program and their assets are still there next time, which is the behavior expected from a tracker.
- **Clear status messages**: Adds, deletes, warnings, and errors still use the colored `[SUCCESS]` / `[WARNING]` / `[ERROR]` messages for readability.
- **Graceful exit**: Choosing Exit (or closing the input stream) ends the program cleanly with a goodbye message, and the latest data is already saved.