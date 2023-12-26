#include "Game.h"

Game::Game(Texture *texture, Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;
    uvRect.width = static_cast<int>((float)(texture->getSize().x) / static_cast<float>(imageCount.x));
    uvRect.height = static_cast<int>((float)(texture->getSize().y) / static_cast<float>(imageCount.y));
}

void Game::update(int row, float delayTime, bool faceRight)
{
    currentImage.y = row;
    totalTime += delayTime;

    // Check if it's time to switch frames
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        // Reset to the first frame if we've reached the end
        if (currentImage.x >= imageCount.x)
            currentImage.x = 0;

        // Set the top coordinate of the texture rectangle
        uvRect.top = static_cast<int>(currentImage.y * uvRect.height);

        // Adjust the left coordinate and width based on the facing direction
        if (faceRight)
        {
            uvRect.left = static_cast<int>(currentImage.x * uvRect.width);
            uvRect.width = abs(uvRect.width);
        }
        else
        {
            uvRect.left = static_cast<int>((currentImage.x + 1) * abs(uvRect.width));
            uvRect.width = -abs(uvRect.width);
        }
    }
}
