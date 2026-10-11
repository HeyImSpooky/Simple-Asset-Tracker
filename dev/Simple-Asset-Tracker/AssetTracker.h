#pragma once

#include "Asset.h"
#include <vector>

class AssetTracker
{
public:
    void Run();

private:
    std::vector<Asset> assets;
    int nextId = 1;

    bool AddAsset();
    void ViewAssets() const;
};