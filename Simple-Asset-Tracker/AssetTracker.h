#pragma once

#include "Asset.h"
#include <vector>

// Displays the menu and handles the user's selection.
void RunAssetTracker();

// Returns false if the input stream closes.
bool AddAsset(std::vector<Asset>& assets, int& nextId);

// Displays all assets added during this session.
void ViewAssets(const std::vector<Asset>& assets);