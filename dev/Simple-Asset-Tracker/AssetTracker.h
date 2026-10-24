#pragma once

#include "Asset.h"
#include <vector>
#include <string>
#include "InputReader.h"

class AssetTracker
{
public:
    void Run();

private:
    std::vector<Asset> assets;
    int nextId = 1;

	const std::string dataFile = "assets.txt";

    bool AddAsset();
    void ViewAssets() const;
    InputReader input;
    bool DeleteAsset();

	void SaveAssets() const;
	void LoadAssets();
};